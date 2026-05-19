#include "common/core/debug.h"
#include "common/core/dbgassert.h"
#include "ui_ind/resources.h"
#include "app-resources/resources.h"
#include "whiteboard/ResourceProvider.h"
#include "whiteboard/integration/port.h"
#include "meas_acc/resources.h"

#include "DebugLogger.hpp"

#include "PostureService.h"
#include <algorithm>

const char *const PostureService::LAUNCHABLE_NAME = "PostureService";
static const wb::ExecutionContextId sExecutionContextId =
    WB_RES::LOCAL::CUSTOM_POSTURESERVICE::EXECUTION_CONTEXT;

static const wb::LocalResourceId sProviderResources[] = {
    WB_RES::LOCAL::CUSTOM_POSTURESERVICE::LID,
};

const int BUFFER_SIZE = 52; // Number of samples to keep for posture calculation
int32_t angleBuffer[52];    // Buffer to store the calculated angles for posture calculation
int bufferIndex = 0;        // Index to keep track of the current position in the angle buffer

PostureService::PostureService() : ResourceClient(WBDEBUG_NAME(__FUNCTION__), sExecutionContextId),
                                   ResourceProvider(WBDEBUG_NAME(__FUNCTION__), sExecutionContextId),
                                   LaunchableModule(LAUNCHABLE_NAME, sExecutionContextId),
                                   isAccRunning(false),
                                   lastPostureAngle(0)
{
}

PostureService::~PostureService()
{
}

bool PostureService::initModule()
{
    if (registerProviderResources(sProviderResources) != wb::HTTP_CODE_OK)
    {
        return false;
    }
    mModuleState = WB_RES::ModuleStateValues::INITIALIZED;
    return true;
}

void PostureService::deinitModule()
{
    unregisterProviderResources(sProviderResources);
    mModuleState = WB_RES::ModuleStateValues::UNINITIALIZED;
}

bool PostureService::startModule()
{
    // Start the accelerometer and subscribe to it, we will get the data in onNotify callback, where we can process the data and calculate posture value.
    wb::RequestId remoteRequestId;
    wb::Result result = startRunningAcc(remoteRequestId);
    if (!wb::RETURN_OKC(result))
    {
        DEBUGLOG("startRunningAcc threw error: %u", result);
    }
    mModuleState = WB_RES::ModuleStateValues::STARTED;
    return true;
}

void PostureService::stopModule()
{
    stopRunningAcc();
    mModuleState = WB_RES::ModuleStateValues::STOPPED;
}

/// @brief Handles GET requests for the posture service. Currently just returns a dummy posture value, but later we can implement the actual posture calculation logic here.
/// @param request
/// @param parameters
void PostureService::onGetRequest(const wb::Request &request, const wb::ParameterList &parameters)
{
    if (mModuleState != WB_RES::ModuleStateValues::STARTED)
    {
        returnResult(request, wb::HTTP_CODE_SERVICE_UNAVAILABLE);
        return;
    }

    switch (request.getResourceId().localResourceId)
    {
    case WB_RES::LOCAL::CUSTOM_POSTURESERVICE::LID:
    {
        // Just return some dummy data for testing
        WB_RES::PostureValue postureValue = lastPostureAngle; // Replace with actual posture calculation logic later

        // DebugLogger::info("Returning Posture Value: %d", postureValue);
        returnResult(request, wb::HTTP_CODE_OK, ResponseOptions::Empty, postureValue);

        break;
    }

    default:
        ASSERT(0); // would be a system error if we got here, trust the system and save rom.
    }
}

/// @brief Starts the accelerometer and subscribes to it. When data is received, we get callback to onNotify method of ResourceClient, where we can process the data and calculate posture value.
/// @param remoteRequestId [out] Request ID of the subscribe request, can be used to match the subscribe result in onSubscribeResult callback. Meaningful only if HTTP_CODE_ACCEPTED is returned.
/// @return HTTP_CODE_ACCEPTED if already running or starting successfully, error code otherwise.
wb::Result PostureService::startRunningAcc(wb::RequestId &remoteRequestId)
{
    DEBUGLOG("PostureService::startRunningAcc()");
    if (isAccRunning)
    {
        return wb::HTTP_CODE_ACCEPTED;
    }

    // Subscribe to LinearAcceleration resource at 13 Hz, when subscribe is done, we get callback
    wb::Result result = getResource("Meas/Acc/13", mMeasAccResourceId);
    if (!wb::RETURN_OKC(result))
    {
        return result;
    }
    result = asyncSubscribe(mMeasAccResourceId, AsyncRequestOptions(&remoteRequestId, 0, true));

    if (!wb::RETURN_OKC(result))
    {
        DEBUGLOG("asyncSubscribe threw error: %u", result);
        releaseResource(mMeasAccResourceId);
        return result;
    }
    isAccRunning = true;
    return wb::HTTP_CODE_ACCEPTED;
}

/// @brief  Stops the accelerometer and unsubscribes from it.
/// @return  HTTP_CODE_OK if successfully stopped, error code otherwise.
wb::Result PostureService::stopRunningAcc()
{
    DEBUGLOG("PostureService::stopRunningAcc()");

    if (!isAccRunning)
    {
        return wb::HTTP_CODE_OK;
    }

    wb::Result result = asyncUnsubscribe(mMeasAccResourceId);
    if (!wb::RETURN_OKC(result))
    {
        DEBUGLOG("asyncUnsubscribe threw error: %u", result);
        return result;
    }
    releaseResource(mMeasAccResourceId);
    isAccRunning = false;
    return wb::HTTP_CODE_OK;
}

void PostureService::onNotify(wb::ResourceId resourceId,
                              const wb::Value &value,
                              const wb::ParameterList &parameters)
{
    DEBUGLOG("PostureService::onNotify() called. resourceId: %u", resourceId.localResourceId);
    // Confirm that it is the correct resource
    switch (resourceId.localResourceId)
    {
    case WB_RES::LOCAL::MEAS_ACC_SAMPLERATE::LID:
    {
        const WB_RES::AccData &linearAccelerationValue =
            value.convertTo<const WB_RES::AccData &>();
        const wb::Array<wb::FloatVector3D> &arrayData = linearAccelerationValue.arrayAcc;

        for (size_t i = 0; i < arrayData.size(); i++)
        {
            const wb::FloatVector3D &accValue = arrayData[i];

            // Just for debugging
            int x = (int)(accValue.x * 1000.0f);
            int y = (int)(accValue.y * 1000.0f);
            int z = (int)(accValue.z * 1000.0f);
            DebugLogger::info("Received Acc Data x1000: x=%d, y=%d, z=%d", x, y, z);

            // Calculate the angle
            float radAngle = atan2f(accValue.y, sqrtf(accValue.x * accValue.x + accValue.z * accValue.z));
            int16_t degAngle = static_cast<int16_t>(radAngle * 180 / M_PI);
            // Consider the direction of the angle based on the z value
            if (accValue.z < 0 && degAngle > 0)
            {
                degAngle = 180 - degAngle;
            } else if (accValue.z < 0 && degAngle < 0)
            {
                degAngle = -180 - degAngle;
            }
            DebugLogger::info("Calculated Posture Value: %d", degAngle);
            addAngleToBuffer(degAngle);
        }

        break;
    }
    default:
        ASSERT(0); // would be a system error if we got here, trust the system and save rom.
    }
}

void PostureService::addAngleToBuffer(int16_t angle)
{
    // Store the angle in the buffer and update the index
    angleBuffer[bufferIndex] = angle;
    bufferIndex = (bufferIndex + 1) % BUFFER_SIZE;
    if (bufferIndex == 0)
    {
        // Buffer is full, we can calculate the median angle
        int32_t temp[BUFFER_SIZE];
        memcpy(temp, angleBuffer, sizeof(temp));

        std::sort(temp, temp + BUFFER_SIZE);

        int32_t medianAngle = temp[BUFFER_SIZE / 2];
        lastPostureAngle = medianAngle;
    }
}
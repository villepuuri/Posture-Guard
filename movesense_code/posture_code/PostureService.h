#pragma once

#include <whiteboard/LaunchableModule.h>
#include <whiteboard/ResourceProvider.h>


class PostureService FINAL : private wb::ResourceProvider,
                             private wb::ResourceClient, 
                             public wb::LaunchableModule

{
public:
    /** Name of this class. Used in StartupProvider list. */
    static const char* const LAUNCHABLE_NAME;
    PostureService();
    ~PostureService();

private:
    virtual bool initModule() OVERRIDE;
    virtual void deinitModule() OVERRIDE;
    virtual bool startModule() OVERRIDE;
    virtual void stopModule() OVERRIDE;

    virtual void onGetRequest(const wb::Request& request, 
                              const wb::ParameterList& parameters);
    virtual void onNotify(wb::ResourceId resourceId,
                          const wb::Value& value,
                          const wb::ParameterList& parameters) OVERRIDE;

private:
    wb::Result startRunningAcc(wb::RequestId& remoteRequestId);
    wb::Result stopRunningAcc();
    void addAngleToBuffer(int16_t angle);

    bool isAccRunning;
    wb::ResourceId	mMeasAccResourceId;

    int32_t lastPostureAngle;
};
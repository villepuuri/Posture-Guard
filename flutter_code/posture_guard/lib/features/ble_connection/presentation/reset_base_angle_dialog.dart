import 'package:flutter/material.dart';

class ResetBaseAngleDialog extends StatefulWidget {
  final Future<int?> Function() getPostureAngle;
  final Function(int baseAngle, bool inverted) returnValues;

  const ResetBaseAngleDialog({required this.getPostureAngle, super.key, required this.returnValues});

  @override
  State<ResetBaseAngleDialog> createState() => _ResetBaseAngleDialogState();
}

class _ResetBaseAngleDialogState extends State<ResetBaseAngleDialog> {
  int dialogState = 0;
  int? baseAngleValue;

  @override
  Widget build(BuildContext context) {
    return SimpleDialog(
      title: Text(
        "Set base angle",
        style: Theme
            .of(context)
            .textTheme
            .titleLarge,
      ),
      shadowColor: Colors.white60,
      elevation: 20,
      children: [
        if (dialogState == 0 || dialogState == 1)
          ElevatedButton(
              onPressed: () async {
                setState(() {
                  dialogState = 1;
                });
                baseAngleValue = await widget.getPostureAngle();
                debugPrint('BaseAngleValue: $baseAngleValue');
              if (baseAngleValue == null && context.mounted) {
                  Navigator.pop(context);
                }
                setState(() {
                  dialogState = 2;
                });
              },
              child: dialogState == 0
                  ? Text("Take a good posture and press this button")
                  : CircularProgressIndicator(),
          ),
        if (dialogState == 2 || dialogState == 3)
          ElevatedButton(
            onPressed: () async {
              setState(() {
                dialogState = 3;
              });
              bool inverted = false;
              int? badPostureValue = await widget.getPostureAngle();
              if (badPostureValue == null && badPostureValue! < baseAngleValue!) {
                inverted = true;
              }
              debugPrint('Inverted: $inverted');

              widget.returnValues(baseAngleValue!, inverted);

              if (context.mounted) {
                Navigator.pop(context);
              }
            },
            child: dialogState == 2
                ? Text("Take a bad posture and press this button")
                : CircularProgressIndicator(),
          ),

      ],
    );
  }
}

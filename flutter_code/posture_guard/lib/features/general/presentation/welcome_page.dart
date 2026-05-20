import 'package:flutter/material.dart';

class WelcomePage extends StatefulWidget {
  const WelcomePage({super.key});

  @override
  State<WelcomePage> createState() => _WelcomePageState();
}

class _WelcomePageState extends State<WelcomePage> {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: Padding(
        padding: const EdgeInsets.symmetric(horizontal: 20, vertical: 40),
        child: Column(
          mainAxisAlignment: MainAxisAlignment.end,
          crossAxisAlignment: CrossAxisAlignment.start,
          children: [
            Text("Welcome", style: Theme.of(context).textTheme.titleLarge),
            const SizedBox(height: 8,),
            TextButton(
              onPressed: () {
                Navigator.pushNamed(context, '/sensor_page');
              },
              child: Text("Search sensors"),
            ),
          ],
        ),
      ),
    );
  }
}

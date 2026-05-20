import 'package:flutter/material.dart';
import 'package:google_fonts/google_fonts.dart';

class AppThemeData {
  // Colors
  static final black = Color(0xFF000000);
  static final white = Color(0xFFFFFFFF);

  // Color schemes
  static final lightColorScheme = ColorScheme.light(
    primary: black,
    secondary: black,
    surface: white,
    outline: black,
  );

  static final darkColorScheme = ColorScheme.dark(
    primary: white,
    secondary: white,
    surface: black,
    outline: white,
  );

  // Text themes
  // todo: Change text themes to local from Google fonts
  static TextTheme textTheme(Color textColor) => TextTheme(
    // Titles are titles of pages
    titleLarge: GoogleFonts.slabo13px(
      fontSize: 50,
      color: textColor,
      height: 1.2,
      letterSpacing: -1,
      fontWeight: FontWeight.w300,
    ),
    titleMedium: GoogleFonts.slabo13px(
      fontSize: 32,
      color: textColor,
      height: 1.2,
      letterSpacing: -0.6,
    ),
    titleSmall: GoogleFonts.slabo13px(
      fontSize: 26,
      color: textColor,
      height: 1.2,
      letterSpacing: -0.6,
    ),

    // Headlines are in text chapters
    headlineLarge: GoogleFonts.slabo13px(fontSize: 24, color: textColor),
    headlineMedium: GoogleFonts.slabo13px(
      fontSize: 20,
      fontWeight: FontWeight.w400,
      color: textColor,
    ),
    headlineSmall: GoogleFonts.slabo13px(
      fontSize: 16,
      fontWeight: FontWeight.w500,
      color: textColor,
    ),

    // Body texts
    bodyLarge: GoogleFonts.slabo13px(
      fontSize: 18,
      fontWeight: FontWeight.w400,
      color: textColor,
      height: 1.4,
    ),
    bodyMedium: GoogleFonts.slabo13px(
      fontSize: 16,
      fontWeight: FontWeight.w400,
      color: textColor,
      height: 1.4,
    ),
    bodySmall: GoogleFonts.slabo13px(fontSize: 12, color: textColor, height: 1.4),

    /* Labels */

    // External links
    labelLarge: GoogleFonts.slabo13px(
      fontSize: 18,
      height: 1.4,
      color: textColor,
      fontWeight: FontWeight.w700,
    ),

    // Internal links
    labelMedium: GoogleFonts.slabo13px(
      fontSize: 18,
      height: 1.4,
      color: textColor,
      fontWeight: FontWeight.bold,
    ),

    // Small info texts
    labelSmall: GoogleFonts.slabo13px(
      fontSize: 16,
      height: 1.4,
      fontWeight: FontWeight.w700,
      color: textColor,
    ),
  );

  /* Button themes */

  static TextButtonThemeData textButtonTheme(
    TextTheme buttonTextTheme,
    Color foregroundColor,
  ) => TextButtonThemeData(
    style: ButtonStyle(
      elevation: WidgetStateProperty.all(1),
      minimumSize: WidgetStateProperty.all(Size(0, 0)),
      tapTargetSize: MaterialTapTargetSize.shrinkWrap,
      textStyle: WidgetStateProperty.all(buttonTextTheme.labelMedium),
      foregroundColor: WidgetStateProperty.all(foregroundColor),
      padding: WidgetStateProperty.all(
        EdgeInsets.zero,
        // EdgeInsets.symmetric(horizontal: 0, vertical: 4),
      ),
    ),
  );

  // Icon themes
  static final iconTheme = IconThemeData(color: black, size: 28);

  // App themes
  static final lightTheme = ThemeData(
    brightness: Brightness.light,
    primaryColor: white,
    colorScheme: lightColorScheme,
    textTheme: textTheme(black),
    iconTheme: iconTheme,
    dividerTheme: DividerThemeData(
      color: lightColorScheme.primary,
      thickness: 1,
      space: 3,
    ),
    listTileTheme: ListTileThemeData(
      iconColor: black,
      titleTextStyle: textTheme(black).bodyMedium,
      shape: RoundedRectangleBorder(
        borderRadius: BorderRadius.all(Radius.circular(18)),
      ),
    ),
    textButtonTheme: textButtonTheme(textTheme(black), lightColorScheme.primary),
  );

  static final darkTheme = ThemeData(
    brightness: Brightness.dark,
    primaryColor: black,
    colorScheme: darkColorScheme,
    textTheme: textTheme(white),
    iconTheme: iconTheme,
    dividerTheme: DividerThemeData(
      color: darkColorScheme.primary,
      thickness: 1,
      space: 3,
    ),
    listTileTheme: ListTileThemeData(
      iconColor: white,
      titleTextStyle: textTheme(white).bodyMedium,
      shape: RoundedRectangleBorder(
        borderRadius: BorderRadius.all(Radius.circular(18)),
      ),
    ),
    textButtonTheme: textButtonTheme(textTheme(white), white),
  );
}

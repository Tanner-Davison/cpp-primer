#ifndef ANSCII_HPP
#define ANSCII_HPP

#include <iostream>
#include <string>
#include <vector>

#ifdef _WIN32
#include <windows.h> // Required for Windows console functions
#endif
//
// REMEMBER TO CALL enableANSI();
//
class ANSIColors {
public:
  // Text Colors (30-37)
  static const std::string BLACK;
  static const std::string RED;
  static const std::string GREEN;
  static const std::string YELLOW;
  static const std::string BLUE;
  static const std::string MAGENTA;
  static const std::string CYAN;
  static const std::string WHITE;

  // Background Colors (40-47)
  static const std::string BG_BLACK;
  static const std::string BG_RED;
  static const std::string BG_GREEN;
  static const std::string BG_YELLOW;
  static const std::string BG_BLUE;
  static const std::string BG_MAGENTA;
  static const std::string BG_CYAN;
  static const std::string BG_WHITE;

  // Bright Text Colors (90-97)
  static const std::string BRIGHT_BLACK;
  static const std::string BRIGHT_RED;
  static const std::string BRIGHT_GREEN;
  static const std::string BRIGHT_YELLOW;
  static const std::string BRIGHT_BLUE;
  static const std::string BRIGHT_MAGENTA;
  static const std::string BRIGHT_CYAN;
  static const std::string BRIGHT_WHITE;

  // Text Styles
  static const std::string BOLD;
  static const std::string UNDERLINE;
  static const std::string ITALIC;
  static const std::string STRIKETHROUGH;
  static const std::string HIGHLIGHT;

  // Reset
  static const std::string RESET;

  // Cursor Movement
  static const std::string CLEAR_SCREEN;
  static const std::string CLEAR_LINE;
  static const std::string SAVE_CURSOR;
  static const std::string RESTORE_CURSOR;

  // RGB Color Functions
  static std::string rgb(int r, int g, int b) {
    return "\033[38;2;" + std::to_string(r) + ";" + std::to_string(g) + ";" +
           std::to_string(b) + "m";
  }

  static std::string bgRgb(int r, int g, int b) {
    return "\033[48;2;" + std::to_string(r) + ";" + std::to_string(g) + ";" +
           std::to_string(b) + "m";
  }

  // Original Predefined RGB Colors
  static std::string ORANGE() { return rgb(255, 165, 0); }
  static std::string PURPLE() { return rgb(128, 0, 128); }
  static std::string PINK() { return rgb(255, 192, 203); }
  static std::string LIME() { return rgb(50, 205, 50); }
  static std::string GOLD() { return rgb(255, 215, 0); }
  static std::string SILVER() { return rgb(192, 192, 192); }
  static std::string CRIMSON() { return rgb(220, 20, 60); }
  static std::string TURQUOISE() { return rgb(64, 224, 208); }
  static std::string CORAL() { return rgb(255, 127, 80); }
  static std::string INDIGO() { return rgb(75, 0, 130); }

  // NEW AWESOME COLORS! 🌈

  // Neon Colors
  static std::string NEON_GREEN() { return rgb(57, 255, 20); }
  static std::string NEON_PINK() { return rgb(255, 16, 240); }
  static std::string NEON_BLUE() { return rgb(4, 217, 255); }
  static std::string NEON_PURPLE() { return rgb(191, 0, 255); }
  static std::string ELECTRIC_LIME() { return rgb(204, 255, 0); }

  // Cyberpunk Colors
  static std::string CYBER_YELLOW() { return rgb(255, 241, 0); }
  static std::string MATRIX_GREEN() { return rgb(0, 255, 65); }
  static std::string SYNTHWAVE_PINK() { return rgb(255, 71, 139); }
  static std::string DIGITAL_BLUE() { return rgb(0, 191, 255); }

  // Pastel Colors
  static std::string PASTEL_PINK() { return rgb(255, 182, 193); }
  static std::string PASTEL_BLUE() { return rgb(174, 198, 207); }
  static std::string PASTEL_GREEN() { return rgb(119, 221, 119); }
  static std::string PASTEL_PURPLE() { return rgb(179, 158, 181); }
  static std::string PASTEL_ORANGE() { return rgb(255, 179, 71); }
  static std::string LAVENDER() { return rgb(230, 230, 250); }

  // Dark/Gothic Colors
  static std::string DARK_RED() { return rgb(139, 0, 0); }
  static std::string DARK_GREEN() { return rgb(0, 100, 0); }
  static std::string DARK_PURPLE() { return rgb(72, 61, 139); }
  static std::string MIDNIGHT_BLUE() { return rgb(25, 25, 112); }
  static std::string BLOOD_RED() { return rgb(102, 0, 0); }

  // Vibrant/Tropical Colors
  static std::string TROPICAL_ORANGE() { return rgb(255, 140, 0); }
  static std::string OCEAN_BLUE() { return rgb(0, 119, 190); }
  static std::string SUNSET_RED() { return rgb(255, 94, 77); }
  static std::string JUNGLE_GREEN() { return rgb(34, 139, 34); }
  static std::string SUNSET_YELLOW() { return rgb(255, 223, 0); }

  // Metallic Colors
  static std::string BRONZE() { return rgb(205, 127, 50); }
  static std::string COPPER() { return rgb(184, 115, 51); }
  static std::string PLATINUM() { return rgb(229, 228, 226); }
  static std::string STEEL_BLUE() { return rgb(70, 130, 180); }

  // Cool Unique Colors
  static std::string MINT() { return rgb(62, 180, 137); }
  static std::string PEACH() { return rgb(255, 218, 185); }
  static std::string TEAL() { return rgb(0, 128, 128); }
  static std::string VIOLET() { return rgb(238, 130, 238); }
  static std::string SALMON() { return rgb(250, 128, 114); }
  static std::string CHARTREUSE() { return rgb(127, 255, 0); }
  static std::string HOT_PINK() { return rgb(255, 105, 180); }
  static std::string ROYAL_BLUE() { return rgb(65, 105, 225); }

  // Gradient Helper
  static void printRainbow(const std::string &text) {
    std::vector<std::string> colors = {
        rgb(255, 0, 0),   // Red
        rgb(255, 127, 0), // Orange
        rgb(255, 255, 0), // Yellow
        rgb(0, 255, 0),   // Green
        rgb(0, 0, 255),   // Blue
        rgb(75, 0, 130),  // Indigo
        rgb(148, 0, 211)  // Violet
    };

    for (size_t i = 0; i < text.length(); ++i) {
      std::cout << colors[i % colors.size()] << text[i];
    }
    std::cout << RESET;
  }

  // Fire gradient
  static void printFire(const std::string &text) {
    std::vector<std::string> fireColors = {
        rgb(255, 0, 0),   // Red
        rgb(255, 69, 0),  // Red-Orange
        rgb(255, 140, 0), // Dark Orange
        rgb(255, 165, 0), // Orange
        rgb(255, 215, 0), // Gold
        rgb(255, 255, 0)  // Yellow
    };

    for (size_t i = 0; i < text.length(); ++i) {
      std::cout << fireColors[i % fireColors.size()] << text[i];
    }
    std::cout << RESET;
  }

  // Ocean gradient
  static void printOcean(const std::string &text) {
    std::vector<std::string> oceanColors = {
        rgb(0, 119, 190),   // Deep Blue
        rgb(0, 150, 199),   // Ocean Blue
        rgb(0, 180, 216),   // Sky Blue
        rgb(144, 224, 239), // Light Blue
        rgb(173, 216, 230), // Powder Blue
        rgb(240, 248, 255)  // Alice Blue
    };

    for (size_t i = 0; i < text.length(); ++i) {
      std::cout << oceanColors[i % oceanColors.size()] << text[i];
    }
    std::cout << RESET;
  }

  // NEW GRADIENT EFFECTS! ✨

  // Neon gradient
  static void printNeon(const std::string &text) {
    std::vector<std::string> neonColors = {
        rgb(57, 255, 20),  // Neon Green
        rgb(4, 217, 255),  // Neon Blue
        rgb(255, 16, 240), // Neon Pink
        rgb(191, 0, 255),  // Neon Purple
        rgb(204, 255, 0),  // Electric Lime
        rgb(255, 241, 0)   // Cyber Yellow
    };

    for (size_t i = 0; i < text.length(); ++i) {
      std::cout << neonColors[i % neonColors.size()] << text[i];
    }
    std::cout << RESET;
  }

  // Sunset gradient
  static void printSunset(const std::string &text) {
    std::vector<std::string> sunsetColors = {
        rgb(255, 94, 77),   // Sunset Red
        rgb(255, 154, 0),   // Orange
        rgb(255, 206, 84),  // Yellow
        rgb(255, 118, 117), // Pink
        rgb(162, 155, 254), // Purple
        rgb(116, 116, 191)  // Deep Purple
    };

    for (size_t i = 0; i < text.length(); ++i) {
      std::cout << sunsetColors[i % sunsetColors.size()] << text[i];
    }
    std::cout << RESET;
  }

  // Pastel gradient
  static void printPastel(const std::string &text) {
    std::vector<std::string> pastelColors = {
        rgb(255, 182, 193), // Pastel Pink
        rgb(255, 179, 71),  // Pastel Orange
        rgb(255, 255, 153), // Pastel Yellow
        rgb(119, 221, 119), // Pastel Green
        rgb(174, 198, 207), // Pastel Blue
        rgb(179, 158, 181)  // Pastel Purple
    };

    for (size_t i = 0; i < text.length(); ++i) {
      std::cout << pastelColors[i % pastelColors.size()] << text[i];
    }
    std::cout << RESET;
  }

  // Matrix/cyberpunk gradient
  static void printMatrix(const std::string &text) {
    std::vector<std::string> matrixColors = {
        rgb(0, 255, 65),   // Matrix Green
        rgb(0, 200, 50),   // Darker Green
        rgb(0, 150, 35),   // Even Darker
        rgb(0, 100, 20),   // Dark Green
        rgb(0, 255, 65),   // Back to bright
        rgb(100, 255, 100) // Light Green
    };

    for (size_t i = 0; i < text.length(); ++i) {
      std::cout << matrixColors[i % matrixColors.size()] << text[i];
    }
    std::cout << RESET;
  }

  // Galaxy gradient
  static void printGalaxy(const std::string &text) {
    std::vector<std::string> galaxyColors = {
        rgb(25, 25, 112),   // Midnight Blue
        rgb(72, 61, 139),   // Dark Slate Blue
        rgb(123, 104, 238), // Medium Slate Blue
        rgb(186, 85, 211),  // Medium Orchid
        rgb(255, 20, 147),  // Deep Pink
        rgb(255, 105, 180)  // Hot Pink
    };

    for (size_t i = 0; i < text.length(); ++i) {
      std::cout << galaxyColors[i % galaxyColors.size()] << text[i];
    }
    std::cout << RESET;
  }

  // STYLE COMBINATION FUNCTIONS
  static std::string bold(const std::string &color) { return BOLD + color; }

  static std::string underline(const std::string &color) {
    return UNDERLINE + color;
  }

  static std::string italic(const std::string &color) { return ITALIC + color; }

  static std::string strikethrough(const std::string &color) {
    return STRIKETHROUGH + color;
  }

  static std::string highlight(const std::string &color) {
    return HIGHLIGHT + color;
  }

  // Background combination
  static std::string withBackground(const std::string &textColor,
                                    const std::string &bgColor) {
    return textColor + bgColor;
  }

  // Multiple styles at once
  static std::string boldUnderline(const std::string &color) {
    return BOLD + UNDERLINE + color;
  }

  static std::string boldItalic(const std::string &color) {
    return BOLD + ITALIC + color;
  }

  static std::string italicUnderline(const std::string &color) {
    return ITALIC + UNDERLINE + color;
  }

  static std::string allStyles(const std::string &color) {
    return BOLD + ITALIC + UNDERLINE + color;
  }
};

// Style Builder Class for advanced combinations
class StyleBuilder {
private:
  std::string style_string = "";

public:
  StyleBuilder &bold() {
    style_string += ANSIColors::BOLD;
    return *this;
  }

  StyleBuilder &underline() {
    style_string += ANSIColors::UNDERLINE;
    return *this;
  }

  StyleBuilder &italic() {
    style_string += ANSIColors::ITALIC;
    return *this;
  }

  StyleBuilder &strikethrough() {
    style_string += ANSIColors::STRIKETHROUGH;
    return *this;
  }

  StyleBuilder &highlight() {
    style_string += ANSIColors::HIGHLIGHT;
    return *this;
  }

  StyleBuilder &color(const std::string &c) {
    style_string += c;
    return *this;
  }

  StyleBuilder &bg(const std::string &bg) {
    style_string += bg;
    return *this;
  }

  StyleBuilder &rgb(int r, int g, int b) {
    style_string += ANSIColors::rgb(r, g, b);
    return *this;
  }

  StyleBuilder &bgRgb(int r, int g, int b) {
    style_string += ANSIColors::bgRgb(r, g, b);
    return *this;
  }

  // Convert to string automatically
  operator std::string() const { return style_string; }

  // Reset for reuse
  StyleBuilder &reset() {
    style_string = "";
    return *this;
  }
};

// Define the constants
const std::string ANSIColors::BLACK = "\033[30m";
const std::string ANSIColors::RED = "\033[31m";
const std::string ANSIColors::GREEN = "\033[32m";
const std::string ANSIColors::YELLOW = "\033[33m";
const std::string ANSIColors::BLUE = "\033[34m";
const std::string ANSIColors::MAGENTA = "\033[35m";
const std::string ANSIColors::CYAN = "\033[36m";
const std::string ANSIColors::WHITE = "\033[37m";

const std::string ANSIColors::BG_BLACK = "\033[40m";
const std::string ANSIColors::BG_RED = "\033[41m";
const std::string ANSIColors::BG_GREEN = "\033[42m";
const std::string ANSIColors::BG_YELLOW = "\033[43m";
const std::string ANSIColors::BG_BLUE = "\033[44m";
const std::string ANSIColors::BG_MAGENTA = "\033[45m";
const std::string ANSIColors::BG_CYAN = "\033[46m";
const std::string ANSIColors::BG_WHITE = "\033[47m";

const std::string ANSIColors::BRIGHT_BLACK = "\033[90m";
const std::string ANSIColors::BRIGHT_RED = "\033[91m";
const std::string ANSIColors::BRIGHT_GREEN = "\033[92m";
const std::string ANSIColors::BRIGHT_YELLOW = "\033[93m";
const std::string ANSIColors::BRIGHT_BLUE = "\033[94m";
const std::string ANSIColors::BRIGHT_MAGENTA = "\033[95m";
const std::string ANSIColors::BRIGHT_CYAN = "\033[96m";
const std::string ANSIColors::BRIGHT_WHITE = "\033[97m";

const std::string ANSIColors::BOLD = "\033[1m";
const std::string ANSIColors::UNDERLINE = "\033[4m";
const std::string ANSIColors::ITALIC = "\033[3m";
const std::string ANSIColors::STRIKETHROUGH = "\033[9m";
const std::string ANSIColors::HIGHLIGHT = "\033[47m\033[30m";
const std::string ANSIColors::RESET = "\033[0m";

const std::string ANSIColors::CLEAR_SCREEN = "\033[2J\033[H";
const std::string ANSIColors::CLEAR_LINE = "\033[2K";
const std::string ANSIColors::SAVE_CURSOR = "\033[s";
const std::string ANSIColors::RESTORE_CURSOR = "\033[u";

// Cross-platform ANSI enable function
inline void enableANSI() {
#ifdef _WIN32
  HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
  DWORD dwMode = 0;
  GetConsoleMode(hOut, &dwMode);
  dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
  SetConsoleMode(hOut, dwMode);
#else
  // Nothing needed on Mac/Linux - ANSI works natively!
#endif
}

// Enhanced demo function to show all colors
void demonstrateColors() {
  enableANSI(); // Make sure ANSI is enabled

  std::cout << "=== Text Colors ===" << std::endl;
  std::cout << ANSIColors::RED << "Red text" << ANSIColors::RESET << std::endl;
  std::cout << ANSIColors::GREEN << "Green text" << ANSIColors::RESET
            << std::endl;
  std::cout << ANSIColors::BLUE << "Blue text" << ANSIColors::RESET
            << std::endl;
  std::cout << ANSIColors::YELLOW << "Yellow text" << ANSIColors::RESET
            << std::endl;

  std::cout << "\n=== Background Colors ===" << std::endl;
  std::cout << ANSIColors::BG_RED << ANSIColors::WHITE << " Red background "
            << ANSIColors::RESET << std::endl;
  std::cout << ANSIColors::BG_GREEN << ANSIColors::BLACK << " Green background "
            << ANSIColors::RESET << std::endl;
  std::cout << ANSIColors::BG_BLUE << ANSIColors::WHITE << " Blue background "
            << ANSIColors::RESET << std::endl;

  std::cout << "\n=== Text Styles ===" << std::endl;
  std::cout << ANSIColors::BOLD << "Bold text" << ANSIColors::RESET
            << std::endl;
  std::cout << ANSIColors::UNDERLINE << "Underlined text" << ANSIColors::RESET
            << std::endl;
  std::cout << ANSIColors::ITALIC << "Italic text" << ANSIColors::RESET
            << std::endl;
  std::cout << ANSIColors::HIGHLIGHT << "Highlighted text" << ANSIColors::RESET
            << std::endl;

  std::cout << "\n=== Original RGB Colors ===" << std::endl;
  std::cout << ANSIColors::ORANGE() << "Orange" << ANSIColors::RESET
            << std::endl;
  std::cout << ANSIColors::PURPLE() << "Purple" << ANSIColors::RESET
            << std::endl;
  std::cout << ANSIColors::PINK() << "Pink" << ANSIColors::RESET << std::endl;
  std::cout << ANSIColors::LIME() << "Lime" << ANSIColors::RESET << std::endl;
  std::cout << ANSIColors::GOLD() << "Gold" << ANSIColors::RESET << std::endl;
  std::cout << ANSIColors::CRIMSON() << "Crimson" << ANSIColors::RESET
            << std::endl;
  std::cout << ANSIColors::TURQUOISE() << "Turquoise" << ANSIColors::RESET
            << std::endl;
  std::cout << ANSIColors::CORAL() << "Coral" << ANSIColors::RESET << std::endl;
  std::cout << ANSIColors::INDIGO() << "Indigo" << ANSIColors::RESET
            << std::endl;

  std::cout << "\n=== NEW NEON COLORS! ===" << std::endl;
  std::cout << ANSIColors::NEON_GREEN() << "Neon Green" << ANSIColors::RESET
            << std::endl;
  std::cout << ANSIColors::NEON_PINK() << "Neon Pink" << ANSIColors::RESET
            << std::endl;
  std::cout << ANSIColors::NEON_BLUE() << "Neon Blue" << ANSIColors::RESET
            << std::endl;
  std::cout << ANSIColors::NEON_PURPLE() << "Neon Purple" << ANSIColors::RESET
            << std::endl;
  std::cout << ANSIColors::ELECTRIC_LIME() << "Electric Lime"
            << ANSIColors::RESET << std::endl;

  std::cout << "\n=== CYBERPUNK COLORS ===" << std::endl;
  std::cout << ANSIColors::CYBER_YELLOW() << "Cyber Yellow" << ANSIColors::RESET
            << std::endl;
  std::cout << ANSIColors::MATRIX_GREEN() << "Matrix Green" << ANSIColors::RESET
            << std::endl;
  std::cout << ANSIColors::SYNTHWAVE_PINK() << "Synthwave Pink"
            << ANSIColors::RESET << std::endl;
  std::cout << ANSIColors::DIGITAL_BLUE() << "Digital Blue" << ANSIColors::RESET
            << std::endl;

  std::cout << "\n=== PASTEL COLORS ===" << std::endl;
  std::cout << ANSIColors::PASTEL_PINK() << "Pastel Pink" << ANSIColors::RESET
            << std::endl;
  std::cout << ANSIColors::PASTEL_BLUE() << "Pastel Blue" << ANSIColors::RESET
            << std::endl;
  std::cout << ANSIColors::PASTEL_GREEN() << "Pastel Green" << ANSIColors::RESET
            << std::endl;
  std::cout << ANSIColors::LAVENDER() << "Lavender" << ANSIColors::RESET
            << std::endl;

  std::cout << "\n=== METALLIC COLORS ===" << std::endl;
  std::cout << ANSIColors::BRONZE() << "Bronze" << ANSIColors::RESET
            << std::endl;
  std::cout << ANSIColors::COPPER() << "Copper" << ANSIColors::RESET
            << std::endl;
  std::cout << ANSIColors::PLATINUM() << "Platinum" << ANSIColors::RESET
            << std::endl;
  std::cout << ANSIColors::STEEL_BLUE() << "Steel Blue" << ANSIColors::RESET
            << std::endl;

  std::cout << "\n=== UNIQUE COLORS ===" << std::endl;
  std::cout << ANSIColors::HOT_PINK() << "Hot Pink" << ANSIColors::RESET
            << std::endl;
  std::cout << ANSIColors::CHARTREUSE() << "Chartreuse" << ANSIColors::RESET
            << std::endl;
  std::cout << ANSIColors::TEAL() << "Teal" << ANSIColors::RESET << std::endl;
  std::cout << ANSIColors::ROYAL_BLUE() << "Royal Blue" << ANSIColors::RESET
            << std::endl;

  std::cout << "\n=== GRADIENT EFFECTS ===" << std::endl;
  std::cout << "Rainbow: ";
  ANSIColors::printRainbow("Hello Rainbow World!");
  std::cout << std::endl;

  std::cout << "Fire: ";
  ANSIColors::printFire("Blazing Fire Text!");
  std::cout << std::endl;

  std::cout << "Ocean: ";
  ANSIColors::printOcean("Deep Ocean Waves!");
  std::cout << std::endl;

  std::cout << "Neon: ";
  ANSIColors::printNeon("Neon Cyberpunk!");
  std::cout << std::endl;

  std::cout << "Sunset: ";
  ANSIColors::printSunset("Beautiful Sunset!");
  std::cout << std::endl;

  std::cout << "Pastel: ";
  ANSIColors::printPastel("Soft Pastel Colors!");
  std::cout << std::endl;

  std::cout << "Matrix: ";
  ANSIColors::printMatrix("The Matrix Code!");
  std::cout << std::endl;

  std::cout << "Galaxy: ";
  ANSIColors::printGalaxy("Cosmic Galaxy!");
  std::cout << std::endl;
}

#endif // ANSCII_HPP

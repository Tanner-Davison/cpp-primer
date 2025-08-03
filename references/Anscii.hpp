
#include <iostream>
#include <string>
#include <vector>

#ifdef _WIN32
#include <windows.h> // Required for Windows console functions
#endif

/*      //Add this in your project to enable ANSI colors on Windows
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
 * */
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

  // Predefined RGB Colors (True Color)
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

const std::string ANSIColors::RESET = "\033[0m";

const std::string ANSIColors::CLEAR_SCREEN = "\033[2J\033[H";
const std::string ANSIColors::CLEAR_LINE = "\033[2K";
const std::string ANSIColors::SAVE_CURSOR = "\033[s";
const std::string ANSIColors::RESTORE_CURSOR = "\033[u";

// Demo function to show all colors
void demonstrateColors() {
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

  std::cout << "\n=== RGB Colors ===" << std::endl;
  std::cout << ANSIColors::rgb(255, 0, 0) << "Pure Red RGB(255,0,0)"
            << ANSIColors::RESET << std::endl;
  std::cout << ANSIColors::rgb(0, 255, 0) << "Pure Green RGB(0,255,0)"
            << ANSIColors::RESET << std::endl;
  std::cout << ANSIColors::rgb(0, 0, 255) << "Pure Blue RGB(0,0,255)"
            << ANSIColors::RESET << std::endl;
  std::cout << ANSIColors::rgb(255, 165, 0) << "Orange RGB(255,165,0)"
            << ANSIColors::RESET << std::endl;
  std::cout << ANSIColors::rgb(128, 0, 128) << "Purple RGB(128,0,128)"
            << ANSIColors::RESET << std::endl;

  std::cout << "\n=== RGB Background Colors ===" << std::endl;
  std::cout << ANSIColors::bgRgb(255, 192, 203) << ANSIColors::BLACK
            << " Pink Background " << ANSIColors::RESET << std::endl;
  std::cout << ANSIColors::bgRgb(255, 215, 0) << ANSIColors::BLACK
            << " Gold Background " << ANSIColors::RESET << std::endl;
  std::cout << ANSIColors::bgRgb(64, 224, 208) << ANSIColors::BLACK
            << " Turquoise Background " << ANSIColors::RESET << std::endl;

  std::cout << "\n=== Predefined RGB Colors ===" << std::endl;
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

  std::cout << "\n=== Gradient Effects ===" << std::endl;
  std::cout << "Rainbow: ";
  ANSIColors::printRainbow("Hello Rainbow World!");
  std::cout << std::endl;

  std::cout << "Fire: ";
  ANSIColors::printFire("Blazing Fire Text!");
  std::cout << std::endl;

  std::cout << "Ocean: ";
  ANSIColors::printOcean("Deep Ocean Waves!");
  std::cout << std::endl;

  std::cout << "\n=== Combinations ===" << std::endl;
  std::cout << ANSIColors::BOLD << ANSIColors::rgb(255, 20, 147)
            << ANSIColors::bgRgb(0, 0, 0) << " Bold Pink on Black "
            << ANSIColors::RESET << std::endl;
}

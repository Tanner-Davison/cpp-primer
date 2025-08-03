#include <iostream>
#include <string>
#ifdef _WIN32
#include <windows.h>
#endif

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

  std::cout << "\n=== Combinations ===" << std::endl;
  std::cout << ANSIColors::BOLD << ANSIColors::RED << ANSIColors::BG_YELLOW
            << " Bold Red on Yellow " << ANSIColors::RESET << std::endl;

  std::cout << "\n=== Bright Colors ===" << std::endl;
  std::cout << ANSIColors::BRIGHT_RED << "Bright red" << ANSIColors::RESET
            << std::endl;
  std::cout << ANSIColors::BRIGHT_GREEN << "Bright green" << ANSIColors::RESET
            << std::endl;
  std::cout << ANSIColors::BRIGHT_BLUE << "Bright blue" << ANSIColors::RESET
            << std::endl;
}

int main() {
// Enable ANSI on Windows
#ifdef _WIN32
  HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
  DWORD dwMode = 0;
  GetConsoleMode(hOut, &dwMode);
  dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
  SetConsoleMode(hOut, dwMode);
#endif

  demonstrateColors();

  // Show the raw codes
  std::cout << "\n=== Raw Code Examples ===" << std::endl;
  std::cout << "Red text: \\033[31m" << std::endl;
  std::cout << "White background: \\033[47m" << std::endl;
  std::cout << "Bold: \\033[1m" << std::endl;
  std::cout << "Reset: \\033[0m" << std::endl;

  return 0;
}

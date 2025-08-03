#include <conio.h> // For Windows (_getch)
#include <iostream>
#include <string>
#include <vector>
// For Linux/Mac, use: #include <termios.h> and #include <unistd.h>

#ifdef _WIN32
#include <windows.h>
#define CLEAR_SCREEN "cls"
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_ENTER 13

void enableANSI() {
  HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
  DWORD dwMode = 0;
  GetConsoleMode(hOut, &dwMode);
  dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
  SetConsoleMode(hOut, dwMode);
}
#else
#include <termios.h>
#include <unistd.h>
#define CLEAR_SCREEN "clear"
#define KEY_UP 65
#define KEY_DOWN 66
#define KEY_ENTER 10
#endif

class TerminalMenu {
private:
  std::string title;
  std::vector<std::string> options;
  size_t selectedIndex;

  // ANSI color codes
  const std::string HIGHLIGHT =
      "\033[47m\033[30m";               // White background, black text
  const std::string RESET = "\033[0m";  // Reset to normal
  const std::string BLUE = "\033[34m";  // Blue text
  const std::string GREEN = "\033[32m"; // Green text

#ifndef _WIN32
  // Linux/Mac terminal setup
  struct termios old_termios;

  void enableRawMode() {
    tcgetattr(STDIN_FILENO, &old_termios);
    struct termios raw = old_termios;
    raw.c_lflag &= ~(ECHO | ICANON);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
  }

  void disableRawMode() { tcsetattr(STDIN_FILENO, TCSAFLUSH, &old_termios); }

  int getch() {
    int ch = getchar();
    if (ch == 27) { // ESC sequence
      getchar();    // skip '['
      ch = getchar();
    }
    return ch;
  }
#endif

public:
  TerminalMenu(const std::string &menuTitle,
               const std::vector<std::string> &menuOptions)
      : title(menuTitle), options(menuOptions), selectedIndex(0) {}

  void displayMenu() {
    system(CLEAR_SCREEN);
    std::cout.flush(); // Force the clear to happen immediately

    std::cout << "\n" << GREEN << title << RESET << "\n";
    std::cout << std::string(title.length(), '=') << "\n\n";

    for (size_t i = 0; i < options.size(); ++i) {
      if (i == selectedIndex) {
        std::cout << " " << HIGHLIGHT << " -> " << options[i] << " <- " << RESET
                  << "\n";
      } else {
        std::cout << "   " << BLUE << options[i] << RESET << "\n";
      }
    }

    std::cout << "\n"
              << BLUE << "Use ↑/↓ arrows to navigate, Enter to select" << RESET
              << "\n";
    std::cout.flush(); // Force output to appear immediately
  }

  int run() {
#ifdef _WIN32
    enableANSI(); // Enable ANSI colors on Windows
#endif
#ifndef _WIN32
    enableRawMode();
#endif

    while (true) {
      displayMenu();

#ifdef _WIN32
      int key = _getch();
      if (key == 224) { // Extended key prefix on Windows
        key = _getch();
      }
#else
      int key = getch();
#endif

      switch (key) {
      case KEY_UP:
        selectedIndex = (selectedIndex - 1 + options.size()) % options.size();
        break;

      case KEY_DOWN:
        selectedIndex = (selectedIndex + 1) % options.size();
        break;

      case KEY_ENTER:
#ifndef _WIN32
        disableRawMode();
#endif
        return selectedIndex;

      case 27: // ESC key
#ifndef _WIN32
        disableRawMode();
#endif
        return -1; // User cancelled
      }
    }
  }

  std::string getSelectedOption() { return options[selectedIndex]; }
};

int main() {
  // Example usage
  std::vector<std::string> menuOptions = {"View Library", "Add New Book",
                                          "Search Books", "Remove Book",
                                          "Exit Program"};

  TerminalMenu menu("Library Management System", menuOptions);

  int choice = menu.run();

  system(CLEAR_SCREEN);

  if (choice == -1) {
    std::cout << "Menu cancelled.\n";
  } else {
    std::cout << "You selected: " << menu.getSelectedOption() << "\n";
    std::cout << "Choice index: " << choice << "\n";

    // Handle the selection
    switch (choice) {
    case 0:
      std::cout << "Opening library view...\n";
      break;
    case 1:
      std::cout << "Opening add book dialog...\n";
      break;
    case 2:
      std::cout << "Opening search...\n";
      break;
    case 3:
      std::cout << "Opening remove book dialog...\n";
      break;
    case 4:
      std::cout << "Goodbye!\n";
      break;
    }
  }

  return 0;
}

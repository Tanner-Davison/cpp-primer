#include <functional>
#include <iostream>
#include <limits>
#include <map>

struct Person {
private:
  std::map<int, std::function<void()>> actions;
  std::string name;
  bool is_running{false};
  bool is_speaking{false};
  bool should_exit{false};

public:
  Person() {
    actions[1] = [this]() { toggle_run(); };
    actions[2] = [this]() { toggle_speak(); };
    actions[3] = [this]() { change_name(); };
    actions[4] = [this]() { get_player_state(); };
    actions[5] = [this]() { should_exit = true; };
  }

  void toggle_run() {
    clearScreen();
    is_running = !is_running;
    if (is_running) {
      std::cout << name << " Started running very fast\n" << std::endl;
    } else {
      std::cout << name
                << ", You stopped running. because you are a fat bitch.\n"
                << std::endl;
    }
    _continue();
  }

  void toggle_speak() {
    clearScreen();
    is_speaking = !is_speaking;
    if (is_speaking) {
      std::cout << name << " Started speaking about politics for some reason.\n"
                << std::endl;
    } else {
      std::cout << name << " Stopped talking with urgency.\n" << std::endl;
    }
    _continue();
  }

  void change_name() {
    clearScreen();
    std::cout << "Change Name: ";
    std::getline(std::cin, this->name);
    std::cout << "name updated success!\n";
    _continue();
  }

  void get_player_state() {
    clearScreen();
    std::cout << name << " is currently, ";
    if (is_running)
      std::cout << " running very fast,";
    else
      std::cout << " standing in a field,";
    if (is_speaking && is_running)
      std::cout << " While speaking nonsense to anyone willing to listen.\n";
    else if (is_speaking && !is_running)
      std::cout << " while whispering sweet nothings into void of the wind.\n";
    else
      std::cout << " thinking deeply about his next move.\n";
    _continue();
  }

  void _continue() {
    if (should_exit)
      return;

    std::cout << "continue? [Enter]->";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    char key = 0;
    while (key != '\n') {
      std::cin.get(key);
    }
  }

  void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
  }

  void display_options() {
    while (!should_exit) {
      if (name.empty()) {
        actions.find(3)->second();
      }
      if (should_exit)
        break;

      clearScreen();
      std::cout << "\n\t[Action Menu]\n";
      std::cout << "[1]: 'Toggle Run'\n";
      std::cout << "[2]: 'Toggle Speech'\n";
      std::cout << "[3]: 'Update Name'\n";
      std::cout << "[4]: 'Player State'\n";
      std::cout << "[5]: 'End'" << std::endl;

      int player_input;
      if (!(std::cin >> player_input)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input! Please enter a number.\n";
        continue;
      } else if (player_input >= 1 && player_input <= 5) {
        auto it = actions.find(player_input);
        if (it != actions.end()) {
          it->second();
        }
      } else {
        std::cout << "Please enter a number between 1 and 5.\n";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        char key = 0;
        while (key != '\n') {
          std::cin.get(key);
        }
      }
    }
    std::cout << "Goodbye!\n";
  }
};

int main() {
  Person person;
  person.display_options();
  return 0;
}

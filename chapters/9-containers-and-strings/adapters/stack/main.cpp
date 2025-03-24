#include <iostream>
#include <stack>
#include <string>

bool areParenthesesBalanced(const std::string &expression) {
  std::stack<char> stack;

  for (char c : expression) {
    if (c == '(' || c == '[' || c == '{') {
      // Push opening brackets onto the stack
      stack.push(c);
    } else if (c == ')' || c == ']' || c == '}') {
      // For closing brackets, check if stack is empty
      if (stack.empty()) {
        return false; // Closing bracket with no matching opening bracket
      }

      // Get the top element and check if it matches
      char top = stack.top();
      stack.pop();

      // Check for mismatched brackets
      if ((c == ')' && top != '(') || (c == ']' && top != '[') ||
          (c == '}' && top != '{')) {
        return false;
      }
    }
  }

  // If stack is empty, all brackets are balanced
  return stack.empty();
}

int main() {
  std::string expression1 = "{[()]}";
  std::string expression2 = "{[(])}";
  std::string expression3 = ")}"; // Closing without opening

  std::cout << expression1 << " is "
            << (areParenthesesBalanced(expression1) ? "balanced"
                                                    : "not balanced")
            << std::endl;

  std::cout << expression2 << " is "
            << (areParenthesesBalanced(expression2) ? "balanced"
                                                    : "not balanced")
            << std::endl;

  std::cout << expression3 << " is "
            << (areParenthesesBalanced(expression3) ? "balanced"
                                                    : "not balanced")
            << std::endl;

  return 0;
}

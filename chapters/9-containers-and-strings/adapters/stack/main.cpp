#include <iostream>
#include <stack>
#include <string>
#include <vector>

bool areParenthesesBalanced(const std::string &expression) {
  std::stack<char> stack;
  for (const auto c : expression) {
    if (c == '(' || c == '{' || c == '[') {
      stack.push(c);
    } else if (c == ')' || c == '}' || c == ']') {
      if (stack.empty()) {
        return false;
      }
      char top = stack.top();
      stack.pop();

      if ((c == ')' && top != '(') || (c == '}' && top != '{') ||
          (c == ']' && top != '[')) {
        return false;
      }
    }
  }

  return stack.empty();
}

int main() {
  std::vector<std::string> expressions{"{([])}", "{[(]}", "(", "([)", "([])"};
  std::string test =
      " const AnimatedQuote = ({ content }) => { const allQuotes = "
      "content.quotes.map((quote, index) => ( <QuoteContent className= quotes"
      " id={`quote-${index}`}> <Quote className= text "
      ">{quote.quote}</Quote> <Person className= text "
      ">{quote.person}</Person> </QuoteContent>));";
  std::string test2 =
      "content.quotes.map((quote, index) => ( <QuoteContent className= quotes"
      " id={`quote-${index}`}> <Quote className= text "
      ">{quote.quote}</Quote> <Person className= text "
      ">{quote.person}</Person> </QuoteContent>));";

  for (const auto &exp : expressions) {
    std::cout << (areParenthesesBalanced(exp) ? "balanced = "
                                              : "not balanced = ")
              << exp << std::endl;
  }
  std::cout << (areParenthesesBalanced(test) ? "\nbalanced =\n"
                                             : "\nnot balanced =\n")
            << test << "\n"
            << std::endl;
  std::cout << (areParenthesesBalanced(test2) ? "\nbalanced =\n\t"
                                              : "not balanced =\n\t")
            << test2 << "\n"
            << std::endl;
}

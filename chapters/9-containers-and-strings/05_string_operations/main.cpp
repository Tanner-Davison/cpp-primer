// Chapter 9.5: String Operations and Conversions
// Covers: string manipulation, conversions, string_view, and practical string
// operations

#include <algorithm>
#include <iostream>
#include <map> // Added for character frequency
#include <sstream>
#include <string>
#include <string_view>
#include <vector>

int main() {
  std::cout << "=== String Operations and Conversions ===\n\n";

  // 1. STRING CONVERSIONS
  std::cout << "1. String to Numeric Conversions:\n";

  std::string pi_string = "pi = 3.14159";
  std::string number_string = "42";
  std::string float_string = "2.718";

  // Extract and convert to double
  double pi_value =
      std::stod(pi_string.substr(pi_string.find_first_of("+-.0123456789")));
  std::cout << "   Original: '" << pi_string
            << "' -> Extracted double: " << pi_value << std::endl;

  // Convert string to int
  int int_value = std::stoi(number_string);
  std::cout << "   String: '" << number_string << "' -> Integer: " << int_value
            << std::endl;

  // Convert string to float
  float float_value = std::stof(float_string);
  std::cout << "   String: '" << float_string << "' -> Float: " << float_value
            << std::endl;

  // Convert numbers back to strings
  std::string back_to_string = std::to_string(int_value);
  std::cout << "   Integer: " << int_value << " -> String: '" << back_to_string
            << "'\n\n";

  // 2. STRING MANIPULATION
  std::cout << "2. String Manipulation:\n";

  std::string text = "Hello World C++ Programming";

  // Find and replace
  size_t pos = text.find("World");
  if (pos != std::string::npos) {
    text.replace(pos, 5, "C++");
  }
  std::cout << "   After replace: " << text << std::endl;

  // Substring operations
  std::string first_word = text.substr(0, text.find(' '));
  std::string last_word = text.substr(text.rfind(' ') + 1);
  std::cout << "   First word: '" << first_word << "'\n";
  std::cout << "   Last word: '" << last_word << "'\n\n";

  // 3. STRING_VIEW (C++17)
  std::cout << "3. String View (C++17):\n";

  std::string long_string =
      "This is a very long string that we want to process efficiently";
  std::string_view view(long_string);

  // Create substring view without copying
  std::string_view sub_view = view.substr(0, 10);
  std::cout << "   Original: '" << long_string << "'\n";
  std::cout << "   Substring view: '" << sub_view << "' (no copying)\n";

  // String view operations
  std::cout << "   View size: " << view.size() << std::endl;
  std::cout << "   View empty: " << (view.empty() ? "true" : "false")
            << std::endl;
  std::cout << "   View starts with 'This': "
            << (view.starts_with("This") ? "true" : "false") << std::endl;
  std::cout << "   View ends with 'efficiently': "
            << (view.ends_with("efficiently") ? "true" : "false") << std::endl;
  std::cout << "\n";

  // 4. STRING ALGORITHMS
  std::cout << "4. String Algorithms:\n";

  std::string mixed_case = "Hello World CPP Programming";

  // Convert to lowercase
  std::string lowercase = mixed_case;
  std::transform(lowercase.begin(), lowercase.end(), lowercase.begin(),
                 ::tolower);
  std::cout << "   Original: '" << mixed_case << "'\n";
  std::cout << "   Lowercase: '" << lowercase << "'\n";

  // Convert to uppercase
  std::string uppercase = mixed_case;
  std::transform(uppercase.begin(), uppercase.end(), uppercase.begin(),
                 ::toupper);
  std::cout << "   Uppercase: '" << uppercase << "'\n";

  // Remove whitespace
  std::string with_spaces = "  hello  world  ";
  with_spaces.erase(0, with_spaces.find_first_not_of(" \t"));
  with_spaces.erase(with_spaces.find_last_not_of(" \t") + 1);
  std::cout << "   Trimmed: '" << with_spaces << "'\n\n";

  // 5. STRING STREAMS
  std::cout << "5. String Streams:\n";

  std::string csv_data =
      "Alice,25,Engineer\nBob,30,Designer\nCharlie,35,Manager";
  std::istringstream iss(csv_data);
  std::string line;

  std::cout << "   Parsing CSV data:\n";
  while (std::getline(iss, line)) {
    std::istringstream line_stream(line);
    std::string name, age, job;

    std::getline(line_stream, name, ',');
    std::getline(line_stream, age, ',');
    std::getline(line_stream, job, ',');

    std::cout << "     Name: " << name << ", Age: " << age << ", Job: " << job
              << std::endl;
  }
  std::cout << "\n";

  // 6. PRACTICAL STRING OPERATIONS
  std::cout << "6. Practical String Operations:\n";

  // Word counting
  std::string paragraph = "The quick brown fox jumps over the lazy dog. The "
                          "fox is quick and brown.";
  std::istringstream word_stream(paragraph);
  std::string word;
  int word_count = 0;

  while (word_stream >> word) {
    word_count++;
  }
  std::cout << "   Word count: " << word_count << std::endl;

  // Character frequency
  std::string sample = "hello world";
  std::map<char, int> char_freq;
  for (char c : sample) {
    if (c != ' ') {
      char_freq[c]++;
    }
  }

  std::cout << "   Character frequency in '" << sample << "':\n";
  for (const auto &[ch, freq] : char_freq) {
    std::cout << "     '" << ch << "': " << freq << std::endl;
  }
  std::cout << "\n";

  // 7. STRING PERFORMANCE TIPS
  std::cout << "7. String Performance Tips:\n";
  std::cout << "   - Use string_view for read-only operations (C++17)\n";
  std::cout << "   - Reserve capacity when you know the final size\n";
  std::cout << "   - Use move semantics for string transfers\n";
  std::cout
      << "   - Prefer string literals over string objects for constants\n";
  std::cout << "   - Use string streams for complex parsing\n";

  return 0;
}

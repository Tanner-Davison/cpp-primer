
#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

using namespace std::placeholders;

// Lambdas syntax [capture list](parameter list) -> return type {function body};
// updated keymaps for bckspc->ctrl
bool isShorter(const std::string &str1, const std::string &str2) {
  return str1.size() < str2.size() ? true : false;
}
void elim_dups(std::vector<std::string> &strs) {
  std::sort(strs.begin(), strs.end());
  auto end_unique = std::unique(strs.begin(), strs.end());
  strs.erase(end_unique, strs.end());
}

bool check_size(std::string &s, std::string::size_type sz) {
  return s.size() < sz;
};

auto make_plural(std::size_t sz, const std::string &word,
                 const std::string &ending) {
  return (sz > 1) ? word + ending : word;
}

void biggies(std::vector<std::string> &words,
             std::vector<std::string>::size_type sz) {
  elim_dups(words);
  stable_sort(begin(words), end(words),
              [](const std::string &str1, const std::string &str2) {
                return str1.size() < str2.size();
              });

  auto wc = partition(words.begin(), words.end(), bind(check_size, _1, sz));

  auto count = words.end() - wc;

  std::cout << count << " " << make_plural(count, "word", "s") << " of length "
            << sz << " or longer" << std::endl;

  for_each(wc, words.end(),
           [](const std::string &s) { std::cout << s << ", "; });
};

int main() {
  std::vector<std::string> str_vec{"Susan", "Alan",  "Brad",   "Rebecca",
                                   "Troy",  "Roger", "Andrew", "Anthony"};
  biggies(str_vec, 7);
  std::cout << std::endl;
  return 0;
}

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

int main() {
  std::multimap<std::string, std::vector<std::string>> library;
  std::string author = "Tanner Davison";

  std::vector<std::string> tanners_books{
      "Dead of night", "Two cities", "no one returns ", "night of the cows "};

  std::sort(tanners_books.begin(), tanners_books.end());
  library.insert({author, tanners_books});

  auto tanners_inventory = library.find(author);
  auto book_list = tanners_inventory->second;

  for (const auto &book : book_list) {
    std::cout << book << " [by: " << tanners_inventory->first << "]"
              << std::endl;
  }
  return 0;
}

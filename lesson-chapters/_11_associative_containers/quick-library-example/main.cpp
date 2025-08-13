#include <algorithm>
#include <iostream>
#include <map>
#include <utility>
#include <vector>

int main() {
  std::multimap<std::string, std::vector<std::string>> library;
  auto tanners = std::make_pair(
      "Tanner Davison",
      std::vector<std::string>{"Dead of night", "Two cities", "no one returns ",
                               "night of the cows "});

  std::sort(tanners.second.begin(), tanners.second.end());
  library.insert(tanners);

  auto tanners_inventory = library.find(tanners.first);
  auto book_list = tanners_inventory->second;
  std::cout << "[Author]:\t\t\t[Published Work]\n";
  std::cout << "---------------------------------------------------\n";

  for (const auto &[author, book_list] : library) {
    std::cout << author << "\n";
    int count = 0;
    for (const auto &book : book_list) {
      std::cout << "\t\t\t\t" << (++count) << ". " << book << "\n";
    }
    std::cout << "\n";
  }
  return 0;
}

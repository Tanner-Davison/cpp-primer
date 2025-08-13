// Chapter 9.1: Sequential Containers Basics
// Covers: vector, list, deque fundamentals, construction, iteration, and basic operations

#include <algorithm>
#include <deque>
#include <iostream>
#include <list>
#include <string>
#include <vector>

int main() {
   std::cout << "=== Sequential Containers Basics ===\n\n";

   // 1. VECTOR BASICS
   std::cout << "1. Vector Container:\n";
   std::vector<std::string> day_of_the_week{"Monday", "Tuesday",  "Wednesday", "Thursday",
                                            "Friday", "Saturday", "Sunday"};
   // Vector construction from range
   std::vector<std::string> mid_week(day_of_the_week.begin() + 2, day_of_the_week.end() - 3);

   std::cout << "   Full week: ";
   for (const auto& day : day_of_the_week) {
      std::cout << day << " ";
   }
   std::cout << "\n   Mid week: ";
   for (const auto& day : mid_week) {
      std::cout << day << " ";
   }
   std::cout << "\n\n";

   // 2. LIST CONTAINER
   std::cout << "2. List Container:\n";
   std::list<std::deque<int>> list_of_deques{{1, 3, 4, 6, 5, 9, 7, 8}, {3, 2, 4, 1, 5, 6}};

   // Sort each deque in the list
   for (auto& dq : list_of_deques) {
      std::sort(dq.begin(), dq.end());
   }

   std::cout << "   List of sorted deques:\n";
   for (const auto& dq : list_of_deques) {
      std::cout << "     ";
      for (const auto& num : dq) {
         std::cout << num << " ";
      }
      std::cout << "\n";
   }
   std::cout << "\n";

   // 3. DEQUE CONTAINER
   std::cout << "3. Deque Container:\n";
   std::deque<int> numbers{3, 4, 5, 2, 1, 6, 8, 7};

   std::cout << "   Original deque: ";
   for (const auto& num : numbers) {
      std::cout << num << " ";
   }
   std::cout << "\n";

   // Sort in descending order
   std::sort(numbers.begin(), numbers.end(), std::greater<int>());

   std::cout << "   Sorted deque (descending): ";
   for (const auto& num : numbers) {
      std::cout << num << " ";
   }
   std::cout << "\n\n";

   // 4. ITERATOR OPERATIONS
   std::cout << "4. Iterator Operations:\n";

   // Iterator-based traversal - weekdays only
   std::cout << "   Weekdays (using iterators): ";
   auto it  = day_of_the_week.begin();
   auto end = day_of_the_week.begin() + 5;
   while (it < end) {
      std::string comma = ((it + 1) == end) ? "" : ", ";
      std::cout << *it++ << comma;
   }
   std::cout << "\n";

   // Iterator-based traversal - weekends only
   std::cout << "   Weekends (using iterators): ";
   auto begin = (day_of_the_week.end() - 2);
   end        = day_of_the_week.end();
   while (begin < end) {
      std::string comma = ((begin + 1) == end) ? "" : ", ";
      std::cout << *begin++ << comma;
   }
   std::cout << "\n\n";

   // 5. CONTAINER COMPARISON
   std::cout << "5. Container Characteristics:\n";
   std::cout << "   Vector: Random access, contiguous memory, fast iteration\n";
   std::cout << "   List: Bidirectional access, non-contiguous, fast insert/delete\n";
   std::cout << "   Deque: Random access, non-contiguous, fast front/back operations\n\n";

   return 0;
}

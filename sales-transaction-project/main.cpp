#include "Person.hpp"
#include "Sales_data_copy.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {
   const std::string SALES_DATA_PATH  = (argc > 1) ? argv[1] : "../text-files/input.txt";
   const std::string PERSON_DATA_PATH = (argc > 2) ? argv[2] : "../text-files/person.txt";

   std::fstream sales_file(SALES_DATA_PATH);
   std::fstream person_file(PERSON_DATA_PATH);

   if (!sales_file) {
      throw std::runtime_error("Could not open sales data file: " + SALES_DATA_PATH);
   }
   if (!person_file) {
      throw std::runtime_error("Could not open person data file: " + PERSON_DATA_PATH);
   }

   Sales_data               total_sales;
   std::vector<std::string> all_isbns;
   Person                   person;

   // Process sales data file
   if (read(sales_file, total_sales)) {
      all_isbns.emplace_back(total_sales.isbn());

      Sales_data current_transaction;

      while (read(sales_file, current_transaction)) {
         // Collect ISBN for unique list later
         all_isbns.emplace_back(current_transaction.isbn());

         // Check if this transaction is for the same book as our running total
         if (total_sales.compareIsbn(current_transaction.isbn())) {
            // Same book - combine the sales data
            total_sales.combine(current_transaction);
         } else {
            // Different book - print current total and start new total
            print(std::cout, total_sales);
            total_sales = current_transaction;
         }
      }

      // Print the final transaction total
      print(std::cout, total_sales);

      current_transaction.logTime(std::cout);
   } else {
      std::cerr << "No sales data found in file!" << std::endl;
   }

   sales_file.close();

   // Create unique ISBN list while preserving order of first appearance
   std::sort(all_isbns.begin(), all_isbns.end());
   auto beg_duplicates = std::unique(all_isbns.begin(), all_isbns.end());
   all_isbns.erase(beg_duplicates, all_isbns.end());

   // Display all unique ISBNs found
   std::cout << "All Unique ISBN's:\n";
   for (const auto& isbn : all_isbns) {
      std::cout << isbn << ", ";
   }
   std::cout << "\n\n";

   // Process and display person data
   const char* checkmark = " ✓ ";
   if (read_person(person_file, person)) {
      std::cout << "---- Person Data Available " << checkmark << "----\n";
      print_person(std::cout, person);
   }

   person_file.close();
   return 0;
}

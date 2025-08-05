
#include "../../../headers/Anscii.hpp"
#include "bucket_visualizer.hpp"
#include <algorithm>
#include <cmath>
#include <set>
#include <unordered_map>
#include <vector>
#include <windows.h>

const std::string cyan   = ANSIColors::BRIGHT_CYAN;
const std::string black  = ANSIColors::BRIGHT_BLACK;
const std::string red    = ANSIColors::BRIGHT_MAGENTA;
const std::string bold   = ANSIColors::BOLD;
const std::string yellow = ANSIColors::SUNSET_YELLOW();
const std::string mint   = ANSIColors::MINT();
const std::string reset  = ANSIColors::RESET;

/*
   unordered_map example including an exclude list

     1. uses insert with the check from the pointer to the position and the
        boolean whether it passed or failed

     2. uses the subscript operator with no check.

 */
void read_stats_hash_once(std::unordered_map<std::string, std::size_t>& word_count) {
   static bool has_hashed = false;

   auto bucketCount  = word_count.bucket_count();               // Number of buckets in use-
   auto nBucketSize  = word_count.bucket_size(bucketCount - 1); // Number of elements in the nth bucket-
   auto mBucketCount = word_count.max_bucket_count();           // Largest number of buckets this container can holder-
   auto loadFactor   = word_count.load_factor();                // Average number of elements per container-
   auto maxLoad      = word_count.max_load_factor();            // Avg bucket size word_count tries to maintain
                                                                // adds-buckets to keep load_factor <= max_load_factor-
   if (has_hashed) {
      std::cout << bold << yellow << "[Results After Hash]:\n" << reset << std::endl;
   }
   std::cout << bold << "Count # element's:       " << yellow << word_count.size() << reset << "\n";
   std::cout << bold << "Bucket's Count:          " << yellow << bucketCount << reset << "\n";
   std::cout << bold << "Bucket Size(last elem):  " << yellow << nBucketSize << reset << "\n";
   std::cout << bold << "Max Bucket Count:        " << yellow << mBucketCount << red << "(Theoretical size)\n" << reset;
   std::cout << bold << "Load factor              " << yellow << loadFactor << reset << "\n";
   std::cout << bold << "[MAX] Load factor:       " << yellow << maxLoad << reset << "\n";
   std::cout << std::endl;

   // Visualize Buckets
   visualize_buckets(word_count, bold, yellow, mint, black, reset);

   // Lets Rehash to a TOTAL of 20 elements
   std::size_t elements = 20;

   size_t buckets = static_cast<std::size_t>(std::ceil(elements / maxLoad));

   if (!has_hashed) {
      word_count.rehash(buckets);
      has_hashed = true;
   }
}

int main() {
   std::unordered_map<std::string, std::size_t> word_count;
   std::set<std::string> exclude_list{"The", "But", "And", "Or", "An", "A", "the", "but", "and", "or", "a"};
   std::vector<std::string> input_list{"hello",   "hello", "hate", "hate",  "warrior", "warrior", "warning",
                                       "warning", "Int",   "Int",  "Inner", "warning", "Inner",   "Inner"};

   auto word = input_list.begin();
   while (word != input_list.end()) {
      if (exclude_list.find(*word) == exclude_list.end()) {
         auto word_it = word_count.insert({*word, 1});
         if (!word_it.second) {
            ++(word_it.first->second);
         }
      }
      ++word;
   }
   std::cout << ANSIColors::CLEAR_SCREEN;
   for (const auto& words : word_count) {
      std::cout << black << "'" << cyan << words.first << black << "'" << " occurs: " << red << words.second << reset
                << black << ((words.second > 1) ? " times.\n" : " time.\n") << reset;
   }

   std::cout << std::endl;

   read_stats_hash_once(word_count);

   read_stats_hash_once(word_count);
   return 0;
}

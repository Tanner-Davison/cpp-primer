#ifndef BUCKET_VISUALIZER_HPP
#define BUCKET_VISUALIZER_HPP

#include <iomanip>
#include <iostream>
#include <string>
#include <unordered_map>

template <typename Key, typename Value>
inline void visualize_buckets(const std::unordered_map<Key, Value>& map, const std::string& empty_color = "",
                              const std::string& filled_color = "", const std::string& mint_color = "",
                              const std::string& black_color = "", const std::string& reset_color = "") {
   std::cout << empty_color << "Bucket Visualization:\n";

   // Print bucket indices header
   std::cout << "Index:  ";
   for (size_t i = 0; i < map.bucket_count(); ++i) {
      if (i < 10) {
         std::cout << " " << i << "  "; // " 1  " = 4 chars, number more centered
      } else {
         std::cout << " " << i << " "; // " 10 " = 4 chars
      }
   }
   std::cout << "\n";

   // Print bucket contents
   std::cout << "Bucket:";
   for (size_t i = 0; i < map.bucket_count(); ++i) {
      size_t bucket_size = map.bucket_size(i);

      if (bucket_size == 0) {
         std::cout << " [ ]";
      } else if (bucket_size == 1) {
         std::cout << " " << filled_color << "[x]" << reset_color;
      } else {
         // Multiple elements in bucket (collision)
         std::cout << " " << filled_color << "[" << bucket_size << "]" << reset_color;
      }
   }
   std::cout << "\n\n";

   // Print detailed bucket contents
   std::cout << empty_color << "Bucket Details:\n" << reset_color;
   for (size_t i = 0; i < map.bucket_count(); ++i) {
      if (map.bucket_size(i) > 0) {
         std::cout << empty_color << "Bucket " << std::setw(2) << i << ":" << " ";

         // Iterate through elements in this bucket
         for (auto it = map.begin(i); it != map.end(i); ++it) {
            std::cout << black_color << "\"" << mint_color << it->first << "\" " << black_color;
         }
         std::cout << "(" << map.bucket_size(i) << " element" << (map.bucket_size(i) > 1 ? "s" : "") << ")\n";
      }
      std::cout << reset_color;
   }
   std::cout << std::endl;
}

// Overload without colors for simple usage
template <typename Key, typename Value>
inline void visualize_buckets(const std::unordered_map<Key, Value>& map) {
   visualize_buckets(map, "", "", "");
}

#endif // BUCKET_VISUALIZER_HPP

#include <algorithm>
#include <chrono>
#include <iostream>
#include <map>
#include <random>
#include <unordered_map>
#include <vector>

class Timer {
private:
  std::chrono::high_resolution_clock::time_point start_time;

public:
  void start() { start_time = std::chrono::high_resolution_clock::now(); }

  double elapsed_ms() {
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(
        end_time - start_time);
    return duration.count() / 1000.0; // Convert to milliseconds
  }
};

void test_insertion(int num_elements) {
  std::cout << "\n=== INSERTION TEST (" << num_elements << " elements) ===\n";

  // Generate random data
  std::vector<int> data(num_elements);
  std::iota(data.begin(), data.end(), 0);
  std::random_device rd;
  std::mt19937 g(rd());
  std::shuffle(data.begin(), data.end(), g);

  Timer timer;

  // Test std::map insertion
  timer.start();
  std::map<int, int> ordered_map;
  for (int val : data) {
    ordered_map[val] = val * 2;
  }
  double map_time = timer.elapsed_ms();

  // Test std::unordered_map insertion
  timer.start();
  std::unordered_map<int, int> unordered_map;
  for (int val : data) {
    unordered_map[val] = val * 2;
  }
  double unordered_map_time = timer.elapsed_ms();

  std::cout << "std::map insertion: " << map_time << " ms\n";
  std::cout << "std::unordered_map insertion: " << unordered_map_time
            << " ms\n";
  std::cout << "Speedup: " << map_time / unordered_map_time << "x\n";
}

void test_lookup(int num_elements, int num_lookups) {
  std::cout << "\n=== LOOKUP TEST (" << num_elements << " elements, "
            << num_lookups << " lookups) ===\n";

  // Prepare data
  std::vector<int> data(num_elements);
  std::iota(data.begin(), data.end(), 0);
  std::random_device rd;
  std::mt19937 g(rd());
  std::shuffle(data.begin(), data.end(), g);

  // Fill both containers
  std::map<int, int> ordered_map;
  std::unordered_map<int, int> unordered_map;

  for (int val : data) {
    ordered_map[val] = val * 2;
    unordered_map[val] = val * 2;
  }

  // Generate random lookup keys
  std::vector<int> lookup_keys(num_lookups);
  std::uniform_int_distribution<int> dist(0, num_elements - 1);
  for (int &key : lookup_keys) {
    key = dist(g);
  }

  Timer timer;
  volatile int sum = 0; // Prevent compiler optimization

  // Test std::map lookup
  timer.start();
  for (int key : lookup_keys) {
    auto it = ordered_map.find(key);
    if (it != ordered_map.end()) {
      sum += it->second;
    }
  }
  double map_time = timer.elapsed_ms();

  // Test std::unordered_map lookup
  timer.start();
  for (int key : lookup_keys) {
    auto it = unordered_map.find(key);
    if (it != unordered_map.end()) {
      sum += it->second;
    }
  }
  double unordered_map_time = timer.elapsed_ms();

  std::cout << "std::map lookup: " << map_time << " ms\n";
  std::cout << "std::unordered_map lookup: " << unordered_map_time << " ms\n";
  std::cout << "Speedup: " << map_time / unordered_map_time << "x\n";
}

void test_iteration(int num_elements) {
  std::cout << "\n=== ITERATION TEST (" << num_elements << " elements) ===\n";

  // Prepare data
  std::vector<int> data(num_elements);
  std::iota(data.begin(), data.end(), 0);
  std::random_device rd;
  std::mt19937 g(rd());
  std::shuffle(data.begin(), data.end(), g);

  // Fill both containers
  std::map<int, int> ordered_map;
  std::unordered_map<int, int> unordered_map;

  for (int val : data) {
    ordered_map[val] = val * 2;
    unordered_map[val] = val * 2;
  }

  Timer timer;
  volatile long long sum = 0; // Prevent compiler optimization

  // Test std::map iteration
  timer.start();
  for (const auto &pair : ordered_map) {
    sum += pair.first + pair.second;
  }
  double map_time = timer.elapsed_ms();

  // Test std::unordered_map iteration
  sum = 0;
  timer.start();
  for (const auto &pair : unordered_map) {
    sum += pair.first + pair.second;
  }
  double unordered_map_time = timer.elapsed_ms();

  std::cout << "std::map iteration: " << map_time << " ms\n";
  std::cout << "std::unordered_map iteration: " << unordered_map_time
            << " ms\n";
  std::cout << "Speedup: " << map_time / unordered_map_time << "x\n";
}

void test_memory_usage(int num_elements) {
  std::cout << "\n=== MEMORY USAGE COMPARISON ===\n";

  std::vector<int> data(num_elements);
  std::iota(data.begin(), data.end(), 0);

  // Rough memory estimation (not precise, just for comparison)
  std::map<int, int> ordered_map;
  std::unordered_map<int, int> unordered_map;

  for (int val : data) {
    ordered_map[val] = val;
    unordered_map[val] = val;
  }

  // These are rough estimates - actual memory usage may vary
  size_t map_node_size =
      sizeof(int) * 2 +
      sizeof(void *) * 3; // key + value + 3 pointers (parent, left, right)
  size_t unordered_map_node_size =
      sizeof(int) * 2 + sizeof(void *); // key + value + next pointer

  std::cout << "Estimated memory per element:\n";
  std::cout << "std::map: ~" << map_node_size << " bytes per node\n";
  std::cout << "std::unordered_map: ~" << unordered_map_node_size
            << " bytes per node + bucket array\n";
  std::cout
      << "Note: Actual memory usage depends on implementation and alignment\n";
}

int main() {
  std::cout << "=== MAP vs UNORDERED_MAP PERFORMANCE TEST ===\n";

  // Test different sizes
  std::vector<int> test_sizes = {1000, 10000, 100000, 1000000};

  for (int size : test_sizes) {
    test_insertion(size);
    test_lookup(size, size / 10); // 10% of elements for lookup
    test_iteration(size);
    std::cout << "\n" << std::string(50, '-') << "\n";
  }

  test_memory_usage(10000);

  std::cout << "\n=== KEY TAKEAWAYS ===\n";
  std::cout << "• unordered_map is typically faster for insertion and lookup "
               "(O(1) avg vs O(log n))\n";
  std::cout << "• map provides ordered iteration and consistent O(log n) "
               "performance\n";
  std::cout << "• unordered_map performance can degrade with poor hash "
               "function or high load factor\n";
  std::cout << "• map uses slightly more memory per node but has predictable "
               "memory layout\n";

  return 0;
}

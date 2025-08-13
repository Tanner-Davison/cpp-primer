// Copyright (c) 2025 Tanner Davison. All Rights Reserved.
// Shared Pointer Example - Key Concepts

#include <iostream>
#include <memory>
#include <vector>

class Widget {
  int id_;

public:
  Widget(int id) : id_(id) { std::cout << "Widget " << id_ << " created\n"; }
  ~Widget() { std::cout << "Widget " << id_ << " destroyed\n"; }
  int getId() const { return id_; }
};

void useWidget(std::shared_ptr<Widget> w) {
  std::cout << "Using widget " << w->getId() << " (refs: " << w.use_count()
            << ")\n";
}

int main() {
  std::cout << "\n=== Basic Sharing ===\n";
  {
    auto w1 = std::make_shared<Widget>(1);
    std::cout << "w1 refs: " << w1.use_count() << "\n";

    auto w2 = w1; // Share ownership
    std::cout << "After w2 = w1, refs: " << w1.use_count() << "\n";

    auto w3 = w2; // Another owner
    std::cout << "After w3 = w2, refs: " << w1.use_count() << "\n";
  }
  std::cout << "All pointers out of scope\n";

  std::cout << "\n=== Containers ===\n";
  {
    auto widget = std::make_shared<Widget>(2);
    std::vector<std::shared_ptr<Widget>> vec;

    std::cout << "Initial refs: " << widget.use_count() << "\n";

    vec.push_back(widget);
    vec.push_back(widget);
    vec.push_back(widget);
    std::cout << "After 3 pushes, refs: " << widget.use_count() << "\n";

    vec.clear();
    std::cout << "After clear, refs: " << widget.use_count() << "\n";
  }

  std::cout << "\n=== Function Calls ===\n";
  {
    auto widget = std::make_shared<Widget>(3);
    std::cout << "Before function, refs: " << widget.use_count() << "\n";

    useWidget(widget); // Pass by value (copies)

    std::cout << "After function, refs: " << widget.use_count() << "\n";
  }

  std::cout << "\n=== Reset and Nullptr ===\n";
  {
    auto w1 = std::make_shared<Widget>(4);
    auto w2 = w1;
    std::cout << "Shared refs: " << w1.use_count() << "\n";

    w1.reset(); // w1 releases ownership
    std::cout << "After w1.reset(), w2 refs: " << w2.use_count() << "\n";
    std::cout << "w1 is " << (w1 ? "valid" : "null") << "\n";
  }

  std::cout << "\n=== Circular Reference Problem ===\n";
  {
    struct Node {
      int value;
      std::shared_ptr<Node> next;
      std::weak_ptr<Node> prev; // Use weak_ptr to break cycle

      Node(int v) : value(v) { std::cout << "Node " << v << " created\n"; }
      ~Node() { std::cout << "Node " << value << " destroyed\n"; }
    };

    auto n1 = std::make_shared<Node>(10);
    auto n2 = std::make_shared<Node>(20);

    n1->next = n2;
    n2->prev = n1; // weak_ptr doesn't increase ref count

    std::cout << "n1 refs: " << n1.use_count() << "\n";
    std::cout << "n2 refs: " << n2.use_count() << "\n";
  }

  return 0;
}

#include <iostream>
#include <memory>
#include <unordered_map>

struct Data {
  int x;
  Data(int v) : x(v) { std::cout << "Data(" << x << ")Created\n"; }
  ~Data() { std::cout << "Data(" << x << ")Destroyed\n"; }
};

struct OwningCache {
  std::unordered_map<int, std::shared_ptr<Data>> m;

  void put(int k, std::shared_ptr<Data> &value) {
    m[k] = value; // copy share ptr
  }

  std::shared_ptr<Data> get(int k) {
    auto item = m.find(k);
    if (item == m.end())
      return nullptr;
    return item->second;
  }
};

struct nonOwningCache {
  std::unordered_map<int, std::weak_ptr<Data>> data;

  void put(int k, std::shared_ptr<Data> &value) { data[k] = value; }

  std::shared_ptr<Data> get(int k) {
    auto item = data.find(k);
    if (item == data.end())
      return nullptr;
    return item->second.lock();
  }
};

int main() {
  nonOwningCache c;

  { // Create a scope
    auto p = std::make_shared<Data>(7);
    std::cout << "Use count: " << p.use_count() << "\n";
    c.put(1, p);
    std::cout << "After cache.put: " << p.use_count() << "\n";
  } // <-- p goes out of scope here!

  std::cout << "After scope ended:\n";
  auto q = c.get(1);
  std::cout << "cache.get(1) is " << (q ? "alive\n" : "expired\n");

  std::cout << "\n--- Now with OwningCache ---\n";

  OwningCache o;
  {
    auto x = std::make_shared<Data>(10);
    std::cout << "Use count: " << x.use_count() << "\n";
    o.put(1, x);
    std::cout << "After cache.put: " << x.use_count() << "\n";
  } // <-- x goes out of scope here!

  std::cout << "After scope ended:\n";
  auto y = o.get(1);
  std::cout << "cache.get(1) is " << (y ? "alive\n" : "null\n");

  return 0;
}
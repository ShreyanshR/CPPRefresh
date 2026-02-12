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
  auto p = std::make_shared<Data>(7);

  std::cout << "Use count after make_share nonOwning: " << p.use_count()
            << "\n";

  c.put(1, p);
  std::cout << "Use count after putting into nonOwning cache " << p.use_count()
            << "\n";
  p.reset();
  std::cout << "Objedt Got destroyed, count = " << p.use_count() << "\n";

  auto q = c.get(1);
  std::cout << "cache.get(1) is " << (q ? "alive\n" : "expired\n");

  OwningCache o;
  auto x = std::make_shared<Data>(10);
  std::cout << "Use count after make_share Owning: " << x.use_count() << "\n";
  o.put(1, x);
  std::cout << "Use count after putting into owning cache " << x.use_count()
            << "\n";

  x.reset();
  std::cout << "Objedt Got destroyed, count = " << x.use_count() << "\n";

  auto y = o.get(1);
  std::cout << "y is " << (y ? "alive\n" : "null\n");
  std::cout << "y.use_count = " << y.use_count() << "\n";

  o.m.erase(1);
  std::cout << "Objedt Got erased, count = " << x.use_count() << "\n";

  return 0;
}
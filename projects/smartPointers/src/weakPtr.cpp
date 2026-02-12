#include <iostream>
#include <memory>
#include <unordered_map>

struct Resource {
  Resource() { std::cout << "Resourse Created\n"; }
  ~Resource() { std::cout << "Resourse Created\n"; }
};

void useWeakPtr(std::weak_ptr<Resource> weakRes) {
  if (auto sharedRes = weakRes.lock())
    std::cout << "Using Resource\n";
  else {
    std::cout << "Resource no longer avaliable\n";
  }
}

class Cache {
  std::unordered_map<int, std::weak_ptr<int>> data;

public:
  void add(int key, std::shared_ptr<int> value) { data[key] = value; }

  std::shared_ptr<int> get(int key) {
    if (auto item = data[key].lock()) {
      return item;
    }
    return nullptr;
  }
};

int main() {
  std::shared_ptr<Resource> res = std::make_shared<Resource>();
  std::weak_ptr<Resource> weakRes(res);

  useWeakPtr(weakRes);
  res.reset();
  useWeakPtr(weakRes);

  auto cache = std::make_shared<Cache>();

  {
    auto value = std::make_shared<int>(42);
    cache->add(1, value);
  } // value goet out of scope

  auto item = cache->get(1);
  if (item) {
    std::cout << "Cached value: " << *item << "\n";
  } else {
    std::cout << "Cache miss\n";
  }
  return 0;
}

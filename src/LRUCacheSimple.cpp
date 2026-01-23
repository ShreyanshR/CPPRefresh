#include <list>
#include <unordered_map>
#include <utility>

class LRUCache {
private:
  std::unordered_map<int, std::pair<int, std::list<int>::iterator>> cache;
  std::list<int> order;
  int capacity;

public:
  LRUCache(int capacity) { this->capacity = capacity; }

  int get(int key) {
    if (cache.find(key) == cache.end())
      return -1;
    order.erase(cache[key].second);    // remove the key from it's old position
    order.push_back(key);              // push back to MRU(most recent used)
    cache[key].second = --order.end(); // update iterator to new position

    return cache[key].first;
  }

  void put(int key, int value) {
    if (cache.find(key) != cache.end()) {
      order.erase(cache[key].second);
    } else if (cache.size() == capacity) {
      int lru = order.front(); // least recently key used
      order.pop_front();
      cache.erase(lru);
    }

    order.push_back(key);
    cache[key] = {value, --order.end()};
  }
};
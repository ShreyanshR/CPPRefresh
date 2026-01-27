#include "LRUCacheSimple.h"
#include <utility>

LRUCache::LRUCache(int capacity) : capacity(capacity) {}

int LRUCache::get(int key) {
  auto it = cache.find(key);
  if (it == cache.end())
    return -1;
  order.erase(it->second.second);
  order.push_back(key);
  it->second.second = std::prev(order.end());
  return it->second.first;
}

void LRUCache::put(int key, int value) {
  if (capacity == 0)
    return;
  auto it = cache.find(key); // to check if the key already exists and update it

  if (it != cache.end()) {
    order.erase(it->second.second); // if the key is arlreay there erase it & we
                                    // will udpate in below steps
  } else if (cache.size() == static_cast<size_t>(capacity)) {
    int lru = order.front();
    order.pop_front();
    cache.erase(lru);
  }

  order.push_back(key);
  cache[key] = {value, std::prev(order.end())};
}
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
  auto it = cache.find(key);

  if (it != cache.end()) {
    order.erase(it->second.second);
  } else if (cache.size() == capacity) {
    int lru = order.front();
    order.pop_front();
    cache.erase(lru);
  }

  order.push_back(key);
  cache[key] = {value, std::prev(order.end())};
}
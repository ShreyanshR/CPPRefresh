#pragma once

#include <list>
#include <unordered_map>
#include <utility>

class LRUCache {
public:
  LRUCache(int capacity);
  int get(int key);
  int put(int key, int value);

private:
  std::unordered_map<int, std::pair<int, std::list<int>::iterator>> cache;
  std::list<int> order;
  int capacity;
};
#include <cstddef>
#include <cstdint>
#include <format>
#include <list>
#include <optional>
#include <print>
#include <stdexcept>
#include <tuple>
#include <unordered_map>
#include <utility>

namespace dev {
template <typename Key, typename Value,
          typename Container = std::unordered_map<
              Key, typename std::list<std::pair<Key, Value>>::iterator>>

class LRUCache {
  using lru_list_iterator = std::list<std::pair<Key, Value>>::iterator;

private:
  Container m_dict;
  std::list<std::pair<Key, Value>> m_lru_list;
  size_t m_capacity;

public:
  explicit LRUCache(size_t capacity)
      : m_dict{}, m_lru_list{}, m_capacity{capacity} {}

  void touch(lru_list_iterator it) {
    m_lru_list.splice(m_lru_list.begin(), m_lru_list, it);
  }

  std::optional<Value> get(Key key) {
    auto it = m_dict.find(key);
    std::optional<Value> result;
    if (it == m_dict.end()) {
      result = std::nullopt;
    } else {
      auto [k, value] = *((*it).second);
      result = value;
      touch(it->second);
    }
    return result;
  }

  void put(Key key, Value value) {
    auto it = m_dict.find(key);
    if (it == m_dict.end()) {
      if (m_lru_list.size() == m_capacity) {
        // Evict teh Least Recently Used (k,v) pair
        auto [lru_key, lru_value] = m_lru_list.back();
        m_dict.erase(lru_key);
        m_lru_list.pop_back();
      }

      m_lru_list.push_front(std::pair{key, value});
      m_dict[key] = m_lru_list.begin();
    } else {
      m_dict[key]->second = value;
    }
  }
};
} // namespace dev

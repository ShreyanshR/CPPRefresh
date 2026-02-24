#include "LRUCacheSimple.h"
#include <gtest/gtest.h>

TEST(LRUCacheSimpleTest, EvictsLeastRecentlyUsedItem) {
  LRUCache cache(2);

  cache.put(1, 10);
  cache.put(2, 20);
  cache.get(1);     // key 1 becomes most recently used
  cache.put(3, 30); // key 2 should be evicted

  EXPECT_EQ(cache.get(1), 10);
  EXPECT_EQ(cache.get(2), -1);
  EXPECT_EQ(cache.get(3), 30);
}

TEST(LRUCacheSimpleTest, UpdatesExistingKey) {
  LRUCache cache(2);

  cache.put(1, 10);
  cache.put(1, 99);

  EXPECT_EQ(cache.get(1), 99);
}

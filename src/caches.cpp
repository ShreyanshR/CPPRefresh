#include <atomic>
#include <chrono>
#include <iostream>
#include <thread>

struct Sequences {
  std::atomic<long> head{0}; // consumer updates this
  std::atomic<long> tail{0}; // producer updates this
};

Sequences seq;

void producer(int iterations) {
  for (int i = 0; i < iterations; ++i) {
    seq.tail.fetch_add(1, std::memory_order_relaxed);
  }
}

void consumer(int iterations) {
  for (int i = 0; i < iterations; ++i) {
    seq.head.fetch_add(1, std::memory_order_relaxed);
  }
}

int main() {
  constexpr int ITERS = 100000000;
  auto start = std::chrono::high_resolution_clock::now();
  std::thread prod(producer, ITERS);
  std::thread cons(consumer, ITERS);
  prod.join();
  cons.join();

  auto end = std::chrono::high_resolution_clock::now();

  std::cout << "time: "
            << std::chrono::duration_cast<std::chrono::milliseconds>(end -
                                                                     start)
                   .count()
            << " ms\n";
}

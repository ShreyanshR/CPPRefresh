#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

std::mutex mtx;
int shared_counter = 0;
void increment() {
  for (int i = 0; i < 1000000; i++) {
    shared_counter++; // read modify write
  }
}

void increment1() {
  for (int i = 0; i < 1000000; i++) {
    mtx.lock();       // acquire lock
    shared_counter++; // read modify write
    mtx.unlock();     // release lock
  }
}

int main() {
  std::vector<std::thread> threads;
  auto start = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < 4; i++) {
    threads.emplace_back(increment);
  }

  for (auto &t : threads)
    t.join();

  auto end = std::chrono::high_resolution_clock::now();

  std::cout << "Time elapsed non mutex: "
            << std::chrono::duration_cast<std::chrono::milliseconds>(end -
                                                                     start)
                   .count()
            << std::endl;

  std::vector<std::thread> threads1;
  auto start1 = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < 4; i++) {
    threads1.emplace_back(increment1);
  }

  for (auto &t : threads1)
    t.join();

  auto end1 = std::chrono::high_resolution_clock::now();

  std::cout << "Time elapsed mutex: "
            << std::chrono::duration_cast<std::chrono::milliseconds>(end1 -
                                                                     start1)
                   .count()
            << std::endl;
  return 0;
}

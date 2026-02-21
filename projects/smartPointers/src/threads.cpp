#include <functional>
#include <iostream>
#include <mutex>
#include <thread>

std::mutex mtx;
std::recursive_mutex rmtx;

void increment(int &counter) {
  for (int i = 0; i < 10; i++) {
    counter++;
  }
}

class Worker {
public:
  void doWork() { std::cout << "We are working" << std::endl; }
  void doWork1(int id) {
    std::cout << "We are working at id: " << id << std::endl;
  }
};

int main() {
  int counter = 0;
  std::thread t([&counter]() { increment(counter); });
  t.join();
  std::cout << "Counter " << counter << std::endl;

  Worker worker;
  std::thread t1(&Worker::doWork, &worker);
  std::thread t2(std::bind(&Worker::doWork1, &worker, 1));

  t1.join();
  t2.join();

  unsigned int cores = std::thread::hardware_concurrency();

  std::cout << cores << std::endl;
}

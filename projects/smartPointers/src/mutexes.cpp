#include <chrono>
#include <functional>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

std::mutex mtx, mtx1;
std::recursive_mutex rmtx;
std::vector<int> sharedData;

void addData(int num) {
  mtx.lock();
  sharedData.push_back(num);
  mtx.unlock();
}

void recursiveMutex(int num) {
  if (num <= 0) {
    return;
  }
  rmtx.lock();
  std::cout << "Count: " << num << std::endl;
  recursiveMutex(num - 1);
  rmtx.unlock();
}

void safeIncrement(int &num) {
  std::lock_guard<std::mutex> lock(mtx);
  num++;
} // it will unlock itself it it goes out of scope

void multipleMtx(int &num) {
  std::lock_guard<std::mutex> lock(mtx);
  num++;
  std::this_thread::sleep_for(std::chrono::milliseconds(50));
  std::lock_guard<std::mutex> lock1(mtx1);
  num++;
  std::cout << num << std::endl;
}

void multipleMtxSafe(int &num) {
  std::lock(mtx, mtx1);
  num++;
  std::lock_guard<std::mutex> lock1(mtx, std::adopt_lock);
  std::lock_guard<std::mutex> lock2(mtx1, std::adopt_lock);
  num++;
  std::cout << "safe multi mtx" << num << std::endl;
}

int main() {
  std::thread threads[10];

  for (int i = 0; i < 10; i++) {
    threads[i] = std::thread(addData, i);
  }

  for (auto &th : threads) {
    th.join();
  }

  std::cout << "Share data contains" << std::endl;
  for (auto &data : sharedData) {
    std::cout << " " << data;
  }

  std::cout << std::endl;

  auto before = std::chrono::steady_clock::now();

  std::thread t2(recursiveMutex, 5);
  t2.join();

  auto after = std::chrono::steady_clock::now();

  auto elapsed =
      std::chrono::duration_cast<std::chrono::nanoseconds>(after - before);

  std::cout << "With threads time: " << elapsed.count() << std::endl;

  int shr_value = 0;
  std::thread t3(safeIncrement, std::ref(shr_value));
  std::thread t4(safeIncrement, std::ref(shr_value));
  t3.join();
  t4.join();

  std::thread t5(multipleMtx, std::ref(shr_value));
  std::thread t6(multipleMtx, std::ref(shr_value));
  t5.join();
  t6.join();

  /*
    auto before1 = std::chrono::steady_clock::now();
  recursiveMutex(5);
  auto after1 = std::chrono::steady_clock::now();

  auto elapsed1 =
      std::chrono::duration_cast<std::chrono::nanoseconds>(after1 - before1);

  std::cout << "Without threads time: " << elapsed1.count() << std::endl;
*/

  int sum = 0;
  std::thread t7([&sum]() { sum += 10; });
  std::thread t8([&sum]() { sum += 10; });
  t7.join();
  t8.join();
  std::cout << "Sum without mutex: " << sum << std::endl;

  std::mutex mtx2;

  int sum1 = 0;
  std::thread t9([&sum1, &mtx2]() {
    std::lock_guard<std::mutex> lock(mtx2);
    sum1 += 10;
  });
  std::thread t10([&sum1, &mtx2]() {
    std::lock_guard<std::mutex> lock(mtx2);
    sum1 += 10;
  });
  t9.join();
  t10.join();
  std::cout << "Sum with mutex: " << sum1 << std::endl;
  return 0;
}
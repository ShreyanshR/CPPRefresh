#include <iostream>
#include <memory>
#include <vector>

class Observer {
public:
  virtual void onUpdate() = 0;
};

class Subject {
  std::vector<std::weak_ptr<Observer>> observers;

public:
  void addObserver(std::shared_ptr<Observer> observer) {
    observers.push_back(observer);
  }

  void notifyObservers() {
    for (auto it = observers.begin(); it != observers.end();) {
      if (auto observer = it->lock()) {
        observer->onUpdate(); // notify if still valid
        ++it;
      } else {
        std::cout << "Removing expired observer" << std::endl;
        it = observers.erase(it); // remove expired observers
      }
    }
  }
};

class ConcreteObserver : public Observer {
  void onUpdate() override { std::cout << "Observer update" << std::endl; }
};

int main() {

  auto subject = std::make_shared<Subject>();

  {
    auto observer = std::make_shared<ConcreteObserver>();
    subject->addObserver(observer);
  }

  subject->notifyObservers();

  return 0;
}
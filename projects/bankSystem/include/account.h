#include <iostream>
#include <string>

class Account {
private:
  std::string name_;
  int account_number_;
  float balance_;

public:
  Account(std::string name, int account_number, float balance = 0.0)
      : name_(name), account_number_(account_number), balance_(balance) {}

  void deposit(float amount) {
    if (amount <= 0) {
      std::cout << "Please enter a valid number" << std::endl;
    } else {
      balance_ += amount;
    }
  }
  void withdraw(float amount) {
    if (amount > balance_) {
      std::cout << "Please top up your account as current balance is "
                << balance_ << std::endl;
    } else {
      balance_ -= amount;
      std::cout << "Current balance after withdrawing " << balance_
                << std::endl;
    }
  }
  float get_balance() const { return balance_; }

  void print_details() const {
    std::cout << "Name : " << name_ << std::endl;
    std::cout << "Account No: " << account_number_ << std::endl;
    std::cout << "Balance: " << balance_ << std::endl;
  }
};
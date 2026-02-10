#include "account.h"
#include <iostream>
#include <vector>

int main() {
  std::vector<Account> accounts;
  int choice;
  while (true) {
    std::cout << "\n1. Create Account\n2. Deposit\n3. Withdraw\n"
              << "\n4. Check Balance\n2. Print Details\n3. Exit\n";
    std::cout << "Choose" << std::endl;
    std::cin >> choice;

    if (choice == 1) {
      std::string name;
      int account_number;
      float balance;
      std::cout << "Name: ";
      std::cin >> name;
      std::cout << "Account No.: ";
      std::cin >> account_number;
      std::cout << "Balance: ";
      std::cin >> balance;

      accounts.push_back(Account(name, account_number, balance));
    } else if (choice == 2) {
      float add_balance;
      std::cout << "Enter the amount you want to enter: ";
      std::cin >> add_balance;
    }
  }
  return 0;
}

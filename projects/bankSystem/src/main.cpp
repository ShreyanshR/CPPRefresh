#include "account.h"
#include <cstddef>
#include <iostream>
#include <ostream>
#include <vector>

int findAccount(std::vector<Account> &accounts, int acc_num) {
  for (std::size_t i = 0; i < accounts.size(); ++i) {
    if (accounts[i].get_account_number() == acc_num) {
      return static_cast<int>(i);
    }
  }
  return -1;
}

int whichAccount() {
  int acc_no;
  std::cout << "Which Account:" << std::endl;
  std::cin >> acc_no;
  return acc_no;
}

int getValidAccount(std::vector<Account> &accounts) {
  int acc_no = whichAccount();
  int acc_index = findAccount(accounts, acc_no);
  if (acc_index == -1) {
    std::cout << "Account not find!" << std::endl;
  }
  return acc_index;
}

int main() {
  std::vector<Account> accounts;
  int choice;
  while (true) {
    std::cout << "\n1. Create Account\n2. Deposit\n3. Withdraw\n"
              << "\n4. Check Balance\n5. Print Details\n6. Exit\n";
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
      int acc_index = getValidAccount(accounts);
      if (acc_index != -1) {
        float amount;
        std::cout << "Enter Amount:" << std::endl;
        std::cin >> amount;
        accounts[acc_index].deposit(amount);
      }
    } else if (choice == 3) {
      int acc_index = getValidAccount(accounts);
      if (acc_index != -1) {
        float amount;
        std::cout << "Enter Amount:" << std::endl;
        std::cin >> amount;
        accounts[acc_index].withdraw(amount);
      }
    } else if (choice == 4) {
      int acc_index = getValidAccount(accounts);
      if (acc_index != -1) {
        std::cout << "Balance: " << accounts[acc_index].get_balance()
                  << std::endl;
      }

    } else if (choice == 5) {
      int acc_index = getValidAccount(accounts);
      if (acc_index != -1) {
        accounts[acc_index].print_details();
      }
    } else if (choice == 6) {
      break;
    }
  }
  return 0;
}

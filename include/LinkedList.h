#include <ostream>
struct Node {
  int value;
  Node *next;
};

class LinkedList {
private:
  Node *head_;

public:
  LinkedList() : head_(nullptr) {}
  LinkedList(const LinkedList &other); // copy constructor when LList a = b;
  LinkedList &operator=(const LinkedList &other); // copy assignment a = b;

  LinkedList(
      LinkedList &&other) noexcept; // move constructor LList d(std::move(a))
  LinkedList &
  operator=(LinkedList &&other) noexcept; // move assignment e = std::move(a)

  void push_front(int value);
  void push_back(int value);
  void remove(int value);
  bool contains(int value);
  friend std::ostream &operator<<(std::ostream &os, const LinkedList &list);
  // ostream can't be a member of this class as it's as operator<< is not a
  // member fxn, so we have to declare is at a friend
  ~LinkedList();
};

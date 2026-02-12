#include "LinkedList.h"
#include <cstddef>
#include <iostream>
#include <ostream>

void LinkedList::push_front(int value) {
  Node *new_node = new Node;
  new_node->value = value;
  new_node->next = head_;
  head_ = new_node;
}

void LinkedList::remove(int value) {
  Node *curr = head_;
  Node *prev = nullptr;

  if (head_ != nullptr && head_->value == value) {
    Node *temp = head_;
    head_ = head_->next;
    delete temp;
    return;
  }

  while (curr) {
    if (curr->value == value && prev != nullptr) {
      prev->next = curr->next;
      delete curr;
      return;
    }
    prev = curr;
    curr = curr->next;
  }
}

bool LinkedList::contains(int value) {
  Node *curr = head_;

  while (curr) {
    if (curr->value == value)
      return true;
    curr = curr->next;
  }

  return false;
}

void LinkedList::push_back(int value) {
  Node *curr = head_;

  while (curr && curr->next) {
    curr = curr->next;
  }

  Node *new_node = new Node;
  new_node->value = value;
  new_node->next = nullptr;
  if (head_ == nullptr) {
    head_ = new_node;
  } else {
    curr->next = new_node;
  }
}

std::ostream &operator<<(std::ostream &os, const LinkedList &list) {
  Node *curr = list.head_;
  os << "[";

  while (curr) {
    os << "(" << curr << ":" << curr->value << ")";
    if (curr->next) {
      os << "->";
    }
    curr = curr->next;
  }
  os << "]";
  return os;
}

LinkedList::~LinkedList() {
  Node *curr = head_;
  while (curr) {
    Node *temp = curr;
    curr = curr->next;
    delete temp;
  }
  std::cerr << "Destroying list head = " << head_ << std::endl;
}

LinkedList::LinkedList(const LinkedList &other) : head_(nullptr) {
  if (!other.head_)
    return; // if it's null return

  head_ = new Node{other.head_->value, nullptr};
  Node *tail = head_;

  Node *curr = other.head_->next;
  while (curr) {
    tail->next = new Node{curr->value, nullptr};
    tail = tail->next;
    curr = curr->next;
  }
}

LinkedList &LinkedList::operator=(const LinkedList &other) {
  if (this == &other) {
    return *this;
  }

  // delete the current list(same logic as destructor)
  Node *curr = head_;
  while (curr) {
    Node *temp = curr;
    curr = curr->next;
    delete temp;
  }
  head_ = nullptr;
  if (!other.head_)
    return *this;

  head_ = new Node{other.head_->value, nullptr};
  Node *tail = head_;
  Node *src = other.head_->next;

  while (src) {
    tail->next = new Node{src->value, nullptr};
    tail = tail->next;
    src = src->next;
  }
  return *this;
}

LinkedList::LinkedList(LinkedList &&other) noexcept : head_(other.head_) {
  // so imagien if it's LL a(std::move(b)) we have to free the memory of b
  other.head_ = nullptr;
}

LinkedList &LinkedList::operator=(LinkedList &&other) noexcept {
  if (this == &other)
    return *this;
  // clear current list
  Node *curr = head_;
  while (curr) {
    Node *temp = curr;
    curr = curr->next;
    delete temp;
  }

  // move the contents
  head_ = other.head_;
  other.head_ = nullptr;

  return *this;
}

int main() {

  LinkedList a;
  a.push_back(5);
  a.push_back(10);
  a.push_front(15);
  std::cout << a << std::endl;

  LinkedList b = a;
  LinkedList c = std::move(a);

  std::cout << b << std::endl;
  std::cout << c << std::endl;

  LinkedList d;
  d = std::move(c);
  std::cout << d << std::endl;

  return 0;
}
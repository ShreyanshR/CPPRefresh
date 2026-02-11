#include "LinkedList.h"
#include <cstddef>
#include <iostream>

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

void LinkedList::print() {
  Node *curr = head_;

  while (curr) {
    std::cout << "Node: " << curr << "Value: " << curr->value << std::endl;
    curr = curr->next;
  }
}

LinkedList::~LinkedList() {
  Node *curr = head_;
  while (curr) {
    Node *temp = curr;
    curr = curr->next;
    delete temp;
  }
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

  while (curr) {
    tail->next = new Node{curr->value, nullptr};
    tail = tail->next;
    curr = curr->next;
  }
}
struct Node {
  int value;
  Node *next;
};

class LinkedList {
private:
  Node *head_;

private:
  LinkedList() : head_(nullptr) {}
  LinkedList(const LinkedList &other); // copy constructor
  LinkedList &operator=(const LinkedList &other);

  void push_front(int value);
  void push_back(int value);
  void remove(int value);
  bool contains(int value);
  void print();
  ~LinkedList();
};
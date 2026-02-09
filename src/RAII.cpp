#include <algorithm>
#include <cstddef>
class NaiveVector {
  int *ptr_;
  std::size_t size_;

public:
  NaiveVector() : ptr_(nullptr), size_(0) {}
  void push_back(int newValue) {
    int *newptr = new int[size_ + 1];
    std::copy(ptr_, ptr_ + size_, newptr);
    delete[] ptr_;
    ptr_ = newptr;
    ptr_[size_++] = newValue;
  }
  int operator[](std::size_t i) const { return ptr_[i]; }
  int &operator[](std::size_t i) { return ptr_[i]; }
  void swap(NaiveVector &other) noexcept {
    std::swap(ptr_, other.ptr_);
    std::swap(size_, other.size_);
  }
  ~NaiveVector() {
    delete[] ptr_;
  } // destrouctor to freeing resourses to avoid leaks

  NaiveVector(const NaiveVector &rhs) {
    // copy constructor, duplicating resources to avoid double frees.
    ptr_ = new int[rhs.size_];
    size_ = rhs.size_;
    std::copy(rhs.ptr_, rhs.ptr_ + size_, ptr_);
  }

  //= will call assignment operator
  NaiveVector &operator=(const NaiveVector &rhs) {
    NaiveVector copy = rhs;
    copy.swap(*this);
    return *this;
  }
};

#ifdef RAII_STANDALONE
#include <iostream>
int main() {
  NaiveVector v;
  v.push_back(1);
  {
    NaiveVector w = v; // both v & w are pointing to the same memory, this calls
                       // copy constructor
    // int dummy = 0;
  }
  // after the socpe ends the default destrcutor frees the memory both w & v are
  // pointing to, so we will get an error, so we need copy constructor for this.
  NaiveVector w;
  w = v; // This is an assignment to existing object w, it calls an assignment
         // operator

  std::cout << v[0] << std::endl;
  return 0;
}
#endif
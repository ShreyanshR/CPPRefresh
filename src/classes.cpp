class X {
public:
  X(int x);
  X();
  X(const X &);            // copy constructor
  X(X &&);                 // move constructor
  X &operator=(const X &); // copy assignement: clean up target & copy
  X &operator=(X &&);      // clean up target & move
  ~X();
};
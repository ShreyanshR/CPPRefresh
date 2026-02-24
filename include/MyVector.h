
#include <ostream>

template<typename T>
class MyVector {
private:
	int size;
	int capacity;
	T* data;
public:
	MyVector(): capacity(0), size(0), data(nullptr){}
	~MyVector();
	void push_back(T value);

	void resize();
	int vsize() const;
	T& operator[] (int index);
	MyVector(const MyVector& other);
	MyVector& operator=(const MyVector& other);
	MyVector(MyVector&& other); //move constructor
	MyVector& operator=(MyVector&& other);
	friend std::ostream& operator<<(std::ostream& os, MyVector& vec);
};

template<typename T>
void MyVector<T>::push_back(T value) {
	if (size == capacity) {
		resize();
	}
	data[size] = value;
	size++;
}

template<typename T>
void MyVector<T>::resize() {
	int newCapacity = capacity == 0 ? 1 : capacity * 2;
	T* newData = new T[newCapacity];

	for (int i = 0; i < size; i++ ) {
		newData[i] = data[i];
	}

	delete [] data;
	data = newData;
	capacity = newCapacity;
}

template<typename T>
MyVector<T>::~MyVector() {
	delete [] data;
}

template<typename T>
T &MyVector<T>::operator[](int index) {
	return data[index];
}

template<typename T>
int MyVector<T>::vsize() const {
	return size;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, MyVector<T>& vec) {
	for (int i = 0; i < vec.vsize(); i++) {
		os << vec[i] << "\n";
	}
	return os;
}

template<typename T>
MyVector<T>::MyVector(const MyVector &other) {
	this->data = new T[other.vsize()];
	this->size = other.vsize();
	this->capacity = other.capacity;
	for (int i = 0; i < this->size; i++) {
		this->data[i] = other[i];
	}
}

template<typename T>
MyVector<T> &MyVector<T>::operator=(const MyVector &other) {
	if (this == &other) {
		std::cout << "Same vector" << "\n";
		return *this;
	}

	delete [] data;

	this->data = new T[other.vsize()];
	this->size = other.vsize();
	this->capacity = other.capacity;
	for (int i = 0; i < this->size; i++) {
		this->data[i] = other[i];
	}

	return *this;
}

template<typename T>
MyVector<T>::MyVector(MyVector &&other) {
	this->data = other.data;
	this->size = other.size;
	this->capacity = other.capacity;

	other.data = nullptr;
	other.size = 0;
	other.capacity = 0;
}

template<typename T>
MyVector<T> &MyVector<T>::operator=(MyVector &&other) {
	if (this == &other) {
		std::cout << "Same vector" << "\n";
		return *this;
	}
	delete [] data;

	this->data = other.data;
	this->size = other.size;
	this->capacity = other.capacity;

	other.data = nullptr;
	other.size = 0;
	other.capacity = 0;

	return *this;
}
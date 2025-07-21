#ifndef DYNAMIC_ARRAY_HPP
#define DYNAMIC_ARRAY_HPP

#include <stdexcept>

template <typename T>
class DynamicArray {
public:
  DynamicArray();
  ~DynamicArray();

  void push_back(const T &value);
  void insert(int index, const T &value);
  void remove(int index);
  int size() const;
  int capacity() const;
  bool isEmpty() const;

  T &operator[](int index);
  const T &operator[](int index) const;

private:
  T *data_;
  int size_;
  int capacity_;

private:
  void resize(int newSize);
};


const int RESIZE_MULTIPLIER = 2;
const int SHRINK_FACTOR = 4;

template<typename T>
DynamicArray<T>::DynamicArray()
  : data_(nullptr), size_(0), capacity_(0) {}

template<typename T>
DynamicArray<T>::~DynamicArray() {
  delete[] data_;
}

template<typename T>
void DynamicArray<T>::push_back(const T& value) {
  if(size_ >= capacity_) {
    int newCapacity = (capacity_ == 0) ? 1 : capacity_ * RESIZE_MULTIPLIER;
    resize(newCapacity);
  }
  data_[size_] = value;
  size_++;
}

template<typename T>
void DynamicArray<T>::insert(int index, const T& value) {
  if(index < 0) throw std::out_of_range("Index out of bounds");
  if(size_ >= capacity_ || index >= capacity_) {
    int newCapacity = (capacity_ == 0) ? 1 : capacity_ * RESIZE_MULTIPLIER;
    resize(newCapacity);
  }

  for(int i = size_; i > index; --i) {
    data_[i] = data_[i - 1];
  }

  data_[index] = value;
  size_++;
}

template<typename T>
void DynamicArray<T>::remove(int index) {
  if(index < 0 || index >= size_) {
    throw std::out_of_range("Index out of bounds");
  }

  for(int i = index; i < size_ - 1; ++i) {
    data_[i] = data_[i + 1];
  }

  size_--;

  if(size_ > 0 && size_ <= capacity_ / SHRINK_FACTOR) {
    int newCapacity = capacity_ / RESIZE_MULTIPLIER;
    if(newCapacity < 1) newCapacity = 1;
    resize(newCapacity);
  }
}

template<typename T>
int DynamicArray<T>::size() const {
  return size_;
}

template<typename T>
int DynamicArray<T>::capacity() const {
  return capacity_;
}

template<typename T>
bool DynamicArray<T>::isEmpty() const {
  return size_ == 0;
}

template<typename T>
void DynamicArray<T>::resize(int newCapacity) {
  T* new_data = new T[newCapacity];
  for(int i = 0; i < size_; ++i) {
    new_data[i] = data_[i];
  }

  delete[] data_;
  data_ = new_data;
  capacity_ = newCapacity;
}

template<typename T>
T& DynamicArray<T>::operator[](int index) {
  if(index < 0 || index >= size_) {
    throw std::out_of_range("Index out of bounds");
  }
  return data_[index];
}


template<typename T>
const T& DynamicArray<T>::operator[](int index) const {
  if(index < 0 || index >= size_) {
    throw std::out_of_range("Index out of bounds");
  }
  return data_[index];
}

#endif

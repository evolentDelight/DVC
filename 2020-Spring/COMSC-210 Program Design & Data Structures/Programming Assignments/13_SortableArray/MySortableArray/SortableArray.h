#ifndef SortableArray_H
#define SortableArray_H

//Programmer Name: Benjamin Kwon
//Programmer ID:   1162854

#include <iostream>//ifndef test
#include <cassert>//ifndef test

template<typename T>
class SortableArray
{
  T* value;
  int cap;
  T dummy;

public:
  SortableArray(int=2);//constructor //Default capacity = 2
  SortableArray(const SortableArray<T>&);//copy constructor
  ~SortableArray();//destructor

  SortableArray<T>& operator = (const SortableArray<T>&);//assignment operator || When this object is being copied onto other instance
  int capacity() const;
  void capacity(int); //setter - capacity
  T operator[] (int) const;//getter - value
  T& operator[] (int);//setter - value

  void sort(int);
};

template<typename T>
SortableArray<T>::SortableArray(int cap) {//default constructor
  dummy = T();

  value = new T[cap];

  this->cap = cap;// == *(this).cap = cap;

  for (int i = 0; i < cap; i++) {
    value[i] = T();
  }
}

template<typename T>
SortableArray<T>::SortableArray(const SortableArray<T>& original) {//copy constructor
  cap = original.cap;

  value = new T[cap];

  for (int i = 0; i < cap; i++) {
    value[i] = original.value[i];
  }
  
  dummy = original.dummy;
}

template<typename T>
SortableArray<T>& SortableArray<T>::operator=(const SortableArray<T>& original)
{
  if (this != &original) { //Should not be a self-copy
    delete[] value;

    cap = original.cap;
    value = new T[cap];

    for (int i = 0; i < cap; i++) {
      value[i] = original.value[i];
    }

    dummy = original.dummy;
  }

  return *this;//returns a self reference

}

template<typename T>
int SortableArray<T>::capacity() const {

  return cap;

}

template<typename T>
void SortableArray<T>::capacity(int cap) {//setter - capacity

  T* temp = new T[cap];//Allocate new array within the new capacity

  int limit = (cap < this->cap ? cap : this->cap);//Get the lowest capacity

  for (int i = 0; i < limit; i++) {//Copy the contents from the lowest capacity
    temp[i] = value[i];
  }

  for (int i = limit; i < cap; i++) {//set added values to their defaults
    temp[i] = T();
  }

  delete[] value;//delete original array

  value = temp;//assign newly allocated array into the object

  this->cap = cap;//update this object's capacity
  
}

template<typename T>
T SortableArray<T>::operator[](int get) const {//getter

  if (get < cap && get > -1) {
    return value[get];
  }
  else
    return dummy;

}

template<typename T>
T& SortableArray<T>::operator[](int set) {//setter

  if (set < 0) {
    return dummy;
  }
  else if (set >= cap) {
    capacity(2 * set);
    return value[set];
  }
  else {
    return value[set];
  }
}

template<typename T>
void SortableArray<T>::sort(int position) {//parameter: index specifies how many elements to sort starting from 0

  T* temp = new T[position];

  for (int delta = 1; delta < position; delta *= 2) {
    int index = 0;
    for (int i = 0; i < position; i++) {
      temp[i] = value[i];
    }
    for (int i = 0; i < position; i += 2 * delta) {
      int left = i;
      int leftMax = (position < left + delta ? position : left + delta);
      int right = leftMax;
      int rightMax = (position < right + delta ? position : right + delta);

      while (left < leftMax || right < rightMax) {
        if (left == leftMax) value[index++] = temp[right++];
        else if (right == rightMax) value[index++] = temp[left++];
        else if (temp[right] < temp[left]) value[index++] = temp[right++];
        else value[index++] = temp[left++];
      }

    }
  }

  delete[] temp;
}

template<typename T>
SortableArray<T>::~SortableArray(){
  delete[] value;
}

#endif
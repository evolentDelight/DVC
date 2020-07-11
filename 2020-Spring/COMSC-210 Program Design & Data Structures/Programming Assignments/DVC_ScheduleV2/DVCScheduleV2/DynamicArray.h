#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

//Programmer Name: Benjamin Kwon
//Programmer ID:   1162854

//Partner Name: Tenzin Shakya 
//Partner ID:   1242034

//Partner Name: Hwan Kim
//Parter ID:    1151832

#include <iostream>//ifndef test
#include <cassert>//ifndef test

template<typename T>
class DynamicArray
{
  T* value;
  int cap;
  T dummy;

public:
  DynamicArray(int=2);//constructor //Default capacity = 2
  DynamicArray(const DynamicArray<T>&);//copy constructor
  ~DynamicArray();//destructor

  DynamicArray<T>& operator = (const DynamicArray<T>&);//assignment operator || When this object is being copied onto other instance
  int capacity() const;
  void capacity(int); //setter - capacity
  T operator[] (int) const;//getter - value
  T& operator[] (int);//setter - value
};

template<typename T>
DynamicArray<T>::DynamicArray(int cap) {//default constructor
  dummy = T();

  value = new T[cap];

  this->cap = cap;// == *(this).cap = cap;

  for (int i = 0; i < cap; i++) {
    value[i] = T();
  }
}

template<typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& original) {//copy constructor
  cap = original.cap;

  value = new T[cap];

  for (int i = 0; i < cap; i++) {
    value[i] = original.value[i];
  }
  
  dummy = original.dummy;
}

template<typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& original)
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
int DynamicArray<T>::capacity() const {

  return cap;

}

template<typename T>
void DynamicArray<T>::capacity(int cap) {//setter - capacity

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
T DynamicArray<T>::operator[](int get) const {//getter

  if (get < cap && get > -1) {
    return value[get];
  }
  else
    return dummy;

}

template<typename T>
T& DynamicArray<T>::operator[](int set) {//setter

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
DynamicArray<T>::~DynamicArray(){
  delete[] value;
}

#endif
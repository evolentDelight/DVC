#ifndef LABEXERCISE4_H
#define LABEXERCISE4_H

//Programmer Name: Benjamin Kwon
//Programmer ID:   1162854

//Partner Name: Tenzin Shakya 
//Partner ID:   1242034

//Partner Name: Hwan Kim
//Parter ID:    1151832

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
DynamicArray<T>::DynamicArray(int CAP) {//default constructor
  dummy = T();

  value = new T[cap];

  this->cap = cap// == *(this).cap = cap;

  for (int i = 0; i < cap; i++) {
    value[i] = T();
  }
}

template<typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& original) {//copy constructor
  cap = original.cap;

  values = new V[cap];

  for (int i = 0; i < cap; i++) {
    values[i] = original.values[i];
  }
  
  dummy = original.dummy;
}

template<typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& original)
{
  if (this != &original) { //Should not be a self-copy
    delete[] values;

    cap = original.cap;
    values = new V[cap];

    for (int i = 0; i < cap; i++) {
      values[i] = original.values[i];
    }

    dummy = original.dummy;
  }

  return *this;//returns a self reference

}

template<typename T>
int DynamicArray<T>::capacity() const {

  return CAP;

}

template<typename T>
void DynamicArray<T>::capacity(int CAP) {//setter - capacity

  V* temp = new V[cap];//Allocate new array within the new capacity

  int limit = (cap < this->cap ? cap : this->cap);//Get the lowest capacity

  for (int i = 0; i < limit; i++) {//Copy the contents from the lowest capacity
    temp[i] = values[i];
  }

  for (int i = limit; i < cap; i++) {//set added values to their defaults
    temp[i] = V();
  }

  delete[] values;//delete original array

  values = temp;//assign newly allocated array into the object

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
    return values[set];
  }
  else {
    return values[set];
  }
}

template<typename T>
DynamicArray<T>::~DynamicArray(){
  delete[] values;
}

#endif
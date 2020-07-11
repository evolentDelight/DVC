#pragma once

//Programmer Name: Benjamin Kwon
//Programmer ID:   1162854

//Parter Name:Tenzin Shakya 
//Partner ID: 1242034

//Partner Name: Hwan Kim
//Parter ID:    1151832

template<typename T, int CAP>
class StaticArray
{
  T value[CAP];
  T dummy;

public:
  StaticArray();
  int capacity() const;
  T operator[] (int) const;//getter
  T& operator[] (int);//setter
};

template<typename T, int CAP>
StaticArray<T, CAP>::StaticArray() {
  dummy = T();

  for (int i = 0; i < CAP; i++) {
    value[i] = T();
  }
}

template<typename T, int CAP>
int StaticArray<T, CAP>::capacity() const {

  return CAP;

}

template<typename T, int CAP>
T StaticArray<T, CAP>::operator[](int get) const {//getter

  if (get < CAP && get > -1) {
    return value[get];
  }
  else
    return dummy;

}

template<typename T, int CAP>
T& StaticArray<T, CAP>::operator[](int set) {//setter

  if (set < CAP && set > -1) {
    return value[set];
  }
  else
    return dummy;

}
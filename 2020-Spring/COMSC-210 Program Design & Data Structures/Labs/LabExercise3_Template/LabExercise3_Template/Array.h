#pragma once

//Programmer Name: Benjamin Kwon
//Programmer ID:   1162854

//Parter Name:Tenzin Shakya 
//Partner ID: 1242034

//Partner Name: Hwan Kim
//Parter ID:    1151832

template<typename T, int CAP>
class Array {
  T value[CAP];
  T dummy;

public:
  Array();
  int capacity() const { return CAP; };
  T operator[] (int) const;//getter
  T& operator[] (int);//setter
};

template<typename T, int CAP>
Array<T, CAP>::Array() {
  dummy = T();

  for (int i = 0; i < CAP; i++) {
    value[i] = 0;
  }
}

template<typename T, int CAP>
T Array<T, CAP>::operator[](int get) const{// getter
  if (get < CAP && get > -1) {
    return value[get];
  }
  else
    return dummy;

}

template<typename T, int CAP>
T& Array<T, CAP>::operator[](int set) {//setter

  if (set < CAP && set > -1) {
    return value[set];
  }
  else
    return dummy;

}

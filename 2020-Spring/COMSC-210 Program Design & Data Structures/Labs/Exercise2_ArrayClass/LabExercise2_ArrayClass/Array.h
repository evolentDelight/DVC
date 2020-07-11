#pragma once
//Programmer Name:  Benjamin Kwon
//Programmer ID:    1162854

//Partner Name:   Nathaniel Williams
//Partner ID:     1674601

class Array {
  int values[100];
  int dummy;

public:
  Array();//constructor prototype
  int capacity() const;
  int operator[](int) const;//Getter 
  int& operator[](int);//Setter
};

Array::Array() {

  dummy = 0;

  for (int i = 0; i < 100; i++) {
    values[i] = 0;
  }

}

int Array::capacity() const {

  return 100;

};


int Array::operator[](int get) const {//Getter

  if (get < 0 || get > 99) {
    return 0;
  }
  return values[get];

}


int& Array::operator[](int set) {//int set is an index | Setter

  if (set < 0 || set > 99) {
    return dummy;
  }
  return values[set];

}
#pragma once

//Programmer ID:
//Programmer: Benjamin Kwon
//Programmer's ID: 1162854

using namespace std;

template<typename V>
class PriorityQueue
{
  V* values;
  int cap;
  int siz;
  void capacity(int);

public:
  PriorityQueue(int = 2);
  PriorityQueue(const PriorityQueue<V>&);
  ~PriorityQueue() { delete[] values; };
  PriorityQueue<V>& operator=(const PriorityQueue<V>&);

  void push(const V&);
  void pop();

  V top() const { return siz == 0 ? V() : values[0]; };
  int size() const { return siz; };
  bool empty() const { return siz == 0 ? true : false; };
  void clear() { siz = 0; };

};

template<typename V>
PriorityQueue<V>::PriorityQueue(int cap)
{
  siz = 0;

  this->cap = cap;

  values = new V[cap];

  for (int i = 0; i < cap; i++) {
    values[i] = V();
  }
}

template <typename V>
PriorityQueue<V>::PriorityQueue(const PriorityQueue<V> & original) {

  cap = original.cap;
  siz = original.siz;
  values = new V[cap];

  for (int i = 0; i < cap; i++) {
    values[i] = original.values[i];
  }

}

template <typename V>
PriorityQueue<V>& PriorityQueue<V>::operator= (const PriorityQueue<V>& original) {

  if (this != &original) {

    delete[] values;

    cap = original.cap;
    siz = original.siz;
    values = new V[cap];

    for (int i = 0; i < cap; i++) {
      values[i] = original.values[i];
    }
  }

  return *this;

}

template <typename V>
void PriorityQueue<V>::capacity(int cap) {
  
  int oldcap = this->cap;

  this->cap = cap;

  V* temp = new V[cap];

  for (int i = 0; i < oldcap; i++) {
    V copy = values[i];
    temp[i] = copy;
  }
  for (int i = oldcap; i < cap; i++) {
    temp[i] = V();
  }

  delete[] values;

  values = new V[cap];

  for (int i = 0; i < cap; i++) {
    values[i] = temp[i];
  }

  delete[] temp;

}

template <typename V>
void PriorityQueue<V>::push(const V& value) {

  if (siz >= cap) capacity(cap * 2);

  values[siz] = value;

  int index = siz;
  int p_index = (index + 1) / 2 - 1;

  while (0 < index) {
    if (values[p_index] < values[index]) {
      //Swap values
      V temp = values[p_index];
      values[p_index] = values[index];
      values[index] = temp;

    }
    else
      break;

    index = p_index;
    p_index = int((index + 1) / 2) - 1;
  }

  siz++;

}

template <typename V>
void PriorityQueue<V>::pop() {
  if (siz == 0) return;

  int index = 0;
  int l_index = 2 * index + 1;
  int r_index = 2 * index + 2;

  while (1) {
    l_index = 2 * index + 1;
    r_index = 2 * index + 2;

    if (siz - 1 < l_index) break;
    if (r_index >= siz - 1) {
      values[index] = values[l_index];
      index = l_index;
    }
    else if(values[r_index] < values[l_index]){
      values[index] = values[l_index];
      index = l_index;
    }
    else {
      values[index] = values[r_index];
      index = r_index;
    }
  }

  siz--;

  values[index] = values[siz];

  while (1) {
    if (index == 0) break;

    int p_index = int((index + 1) / 2) - 1;

    if (values[index] < values[p_index]) break;

    V temp = values[p_index];
    values[p_index] = values[index];
    values[index] = temp;

    index = p_index;

  }

}

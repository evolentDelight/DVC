#pragma once

//Programmer ID:
//Programmer: Benjamin Kwon
//Programmer's ID: 1162854

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

  while (index > 0) {
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

  siz--;

  values[0] = values[siz];//use last node to replace the top

  int index = 0;
  int l_index = 2 * index + 1;
  int r_index = 2 * index + 2;

  while (l_index < siz) {//if there is a left child
    if (r_index >= siz) {//There is no right child
      if (values[index] < values[l_index]) {
      //prompt the left child
        values[index] = values[l_index];
        index = l_index;
      }
      else break;
    }
    else if (values[l_index] < values[r_index] && values[index] < values[r_index]) {
      //prompt the right child
      values[index] = values[r_index];
      index = r_index;
    }
    else if (values[index] < values[r_index]) {
      //prompt the left child
      values[index] = values[l_index];
      index = l_index;
    }
    else break;

    l_index = 2 * index + 1;
    r_index = 2 * index + 2;
    
  }

}


/*
template <typename V>
void PriorityQueue<V>::pop() {
  if (siz == 0) return;

  siz--;

  int index = 0;
  int l_index = 2 * index + 1;
  int r_index = 2 * index + 2;

  while (l_index < siz) {
    if (r_index >= siz) {
      if (values[l_index] < values[siz]) break;
      else {
        values[index] = values[l_index];
        index = l_index;
      }
    }
    else if (values[l_index] < values[siz] && values[r_index] < values[siz]) break;
    else if (values[l_index] < values[r_index]) {
      values[index] = values[r_index];
      index = r_index;
    }
    else {
      values[index] = values[l_index];
      index = l_index;
    }

    values[index] = values[siz];

  }

}
*/
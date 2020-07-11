#pragma once

#include <vector>

#include "Queue.h"

template<typename K, typename V>
class AssociativeArray {

  struct Node {
    K key;
    V value;
    Node* next;
  };

  Node* firstNode;
  int siz;

public:
  AssociativeArray() { firstNode = 0; siz = 0; };
  AssociativeArray(const AssociativeArray&);
  AssociativeArray<K, V>& operator= (const AssociativeArray<K, V>&);
  ~AssociativeArray();

  V operator[] (const K&) const;//getter
  V& operator[] (const K&);//setter
  bool containsKey(const K&) const;
  void deleteKey(const K&);

  Queue<K> keys() const;
  int size() { return siz;};
  void clear();

};

template<typename K, typename V>
AssociativeArray<K, V>::AssociativeArray(const AssociativeArray& original) {

  firstNode = 0;
  Node* lastNode = 0;//temporary tail

  siz = original.siz;

  for (Node* p = original.firstNode; p; p = p->next) {
    Node* temp = new Node;
    temp->key = p->key;
    temp->value = p->value;
    temp->next = 0;

    if (lastNode) lastNode->next = temp;
    else firstNode = temp;
    lastNode = temp;
  }

};


template<typename K, typename V>
AssociativeArray<K, V>& AssociativeArray<K, V>::operator=(const AssociativeArray<K, V>& original) {

  if (this != &original)
  {
    while (firstNode)//deallocate existing list
    {
      Node* p = firstNode;
      firstNode = firstNode->next;
      delete p;
    }

    //build new queue
    Node* lastNode = 0;//temporary tail
    for (Node* p = original.firstNode; p; p = p->next)
    {
      Node* temp = new Node;
      temp->key = p->key;
      temp->value = p->value;
      temp->next = 0;
      if (lastNode) lastNode->next = temp;
      else firstNode = temp;
      lastNode = temp;
    }

    siz = original.siz;
  }

  return *this;

}

template<typename K, typename V>
V AssociativeArray<K, V>::operator[](const K& key) const{//getter

  for (Node* p = firstNode; p; p = p->next)
    if (p->key == key)
      return p->value;

  return V();

}

template<typename K, typename V>
V& AssociativeArray<K, V>::operator[](const K& key) {//setter

  for (Node* p = firstNode; p; p = p->next)
    if (p->key == key)
      return p->value;

  ++siz;

  Node* temp = new Node;
  temp->key = key;
  temp->value = V();
  temp->next = firstNode;
  firstNode = temp;

  return firstNode->value;

}

template<typename K, typename V>
bool AssociativeArray<K, V>::containsKey(const K& key) const{

  for (Node* p = firstNode; p; p = p->next)
    if (p->key == key)
      return true;
  return false;

}

template<typename K, typename V>
void AssociativeArray<K, V>::deleteKey(const K& key) {

  Node *p, *prev;//Assign prev to previous node

  for (p = firstNode, prev = 0; p; prev = p, p = p->next)
    if (p->key == key)
      break;

  if (p) {//if p is not the end of the list

    --siz;
    if (prev) prev->next = p->next;
    else firstNode = p->next;

    delete p;
  }

}

template<typename K, typename V>
Queue<K> AssociativeArray<K, V>::keys() const{

  Queue<K> queue;

  for (Node* p = firstNode; p; p = p->next)
    queue.push(p->key);

  return queue;
}

template<typename K, typename V>
void AssociativeArray<K, V>::clear() {

  while (firstNode)
  {
    Node* p = firstNode;
    firstNode = firstNode->next;
    delete p;
    --siz;
  }

}

template<typename K, typename V>
AssociativeArray<K, V>::~AssociativeArray() {

  while (firstNode)
  {
    Node* p = firstNode;
    firstNode = firstNode->next;
    delete p;
  }

}
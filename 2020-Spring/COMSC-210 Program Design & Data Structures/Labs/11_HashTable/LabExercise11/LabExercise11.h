#pragma once

#include <queue>
#include <list>

//Programmer: Benjamin Kwon
//Programmer's ID: 1162854


using namespace std;

template<typename K, typename V, int CAP>
class HashTable {

  struct Node {
    K key;
    V value;
  };

  list<Node> data[CAP];//Chaining method
  int(*hashCode)(const K&);//Pointer to hashCode function in CPP file
  int siz;

public:
  HashTable(int(*)(const K&) = 0);
  double loadFactor() const { return 1.0 * siz / CAP; };

  V operator[] (const K&) const;//Getter
  V& operator[] (const K&);//Setter
  bool containsKey(const K&) const;
  void deleteKey(const K&);
  int size() const { return siz; };
  void clear();

  queue<K> keys() const;
};

template<typename K, typename V, int CAP>
HashTable<K, V, CAP>::HashTable(int(*hashCode)(const K&)) {
  this->hashCode = hashCode;
  siz = 0;
}

template<typename K, typename V, int CAP>
V HashTable<K, V, CAP>::operator[] (const K& key) const {//getter
  int index = hashCode(key) % CAP;
  if (index < 0) index += CAP;

  typename list<Node>::iterator it;
  for (it = data[index].begin(); it != data[index].end(); it++) {
    if (it->key == key)
      return it->value;
  }

  return V();//Not Found
}

template<typename K, typename V, int CAP>
V& HashTable<K, V, CAP>::operator[] (const K& key) {//setter
  int index = hashCode(key) % CAP;

  if (index < 0) index += CAP;

  typename list<Node>::iterator it;
  for (it = data[index].begin(); it != data[index].end(); it++) {
    if (it->key == key)
      return it->value;
  }

  if (data[index].empty()) siz++;

  Node temp = { key, V() };
  data[index].push_back(temp);

  return data[index].back().value;
}

template<typename K, typename V, int CAP>
bool HashTable<K, V, CAP>::containsKey(const K& key) const {
  int index = hashCode(key) % CAP;

  if (index < 0) index += CAP;

  typename list<Node>::const_iterator it;
  for (it = data[index].begin(); it != data[index].end(); it++) {
    if (it->key == key) return true;
  }

  if (it == data[index].end()) return false;
}

template<typename K, typename V, int CAP>
void HashTable<K, V, CAP>::deleteKey(const K& key) {
  int index = hashCode(key) % CAP;

  if (index < 0) index += CAP;

  typename list<Node>::const_iterator it;
  for (it = data[index].begin(); it != data[index].end(); it++) {
    if (it->key == key) {
      data[index].erase(it);
      siz--;
      break;
    }
  }

}

template<typename K, typename V, int CAP>
void HashTable<K, V, CAP>::clear() {
  for (int i = 0; i < CAP; i++) {
    data[i].clear();
  }
  siz = 0;
}

template<typename K, typename V, int CAP>
queue<K> HashTable<K, V, CAP>::keys() const {
  queue<K> key_queue;

  for (int i = 0; i < CAP; i++) {
    typename list<Node>::const_iterator it;
    for (it = data[i].begin(); it != data[i].end(); it++) {
      key_queue.push(it->key);
    }
  }
  return key_queue;
}
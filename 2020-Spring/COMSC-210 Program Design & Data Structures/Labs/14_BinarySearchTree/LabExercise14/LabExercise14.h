#pragma once

#include "Queue.h"

//Programmer ID:
//Programmer: Benjamin Kwon
//Programmer's ID: 1162854

template<typename K, typename V>
class BinarySearchTree {
  struct Node {
    K key;
    V value;
    Node* left;
    Node* right;
  };

  Node* rootNode;
  int siz;
  void keys(const Node*, Queue<K>& ) const;
  void clear(Node*);
  void copyTree(Node*, const Node*);

public:
  BinarySearchTree() { rootNode = 0; siz = 0; }
  BinarySearchTree(const BinarySearchTree&);
  BinarySearchTree<K, V>& operator=(const BinarySearchTree<K, V>&);
  ~BinarySearchTree();

  int size() { return siz; }
  V operator[](const K&) const;//getter
  V& operator[](const K&);//setter
  bool containsKey(const K&) const;
  void deleteKey(const K&);
  Queue<K> Keys() const;
  void clear();
};

template<typename K, typename V>
void BinarySearchTree<K, V>::keys(const Node* p, Queue<K>& q) const {
  if (!p) return;

  keys(p->left, q);
  q.push(p->key);
  keys(p->right, q);
}

template<typename K, typename V>
void BinarySearchTree<K, V>::clear(Node* p) {
  if (!p) return;

  clear(p->left);
  clear(p->right);
  delete p;
}

template<typename K, typename V>
void BinarySearchTree<K, V>::copyTree(Node* p, const Node* copiedTree) {
  p->key = copiedTree->key;
  p->value = copiedTree->value;
  p->left = p->right = 0;

  if (copiedTree->left) {
    copyTree(p->left = new Node, copiedTree->left);
  }
  if (copiedTree->right)
    copyTree(p->right = new Node, copiedTree->right);
}

template<typename K, typename V>
BinarySearchTree<K, V>::BinarySearchTree(const BinarySearchTree& original) {
  rootNode = 0;
  if (original.rootNode) copyTree(rootNode = new Node, original.rootNode);
  siz = original.siz;
}

template<typename K, typename V>
BinarySearchTree<K, V>& BinarySearchTree<K, V>::operator = (const BinarySearchTree<K, V>& original){
  rootNode = 0;
  if (original.rootNode) copyTree(rootNode = new Node, original.rootNode);
  siz = original.siz;

  return *this;
}

template<typename K, typename V>
BinarySearchTree<K, V>::~BinarySearchTree() {
  clear();
}

template<typename K, typename V>
V BinarySearchTree<K, V>::operator[](const K& key)const {//getter
  Node* p = rootNode;

  while (p) {
    if (p->key == key)break;
    
    if (p->key < key) p = p->right;
    else p = p->left;
  }

  if (p) return p->value;
  
  return V();
}

template<typename K, typename V>
V& BinarySearchTree<K, V>::operator[](const K& key) {//setter
  Node* p = rootNode;
  Node* prev = 0;

  while (p) {
    if (p->key == key) return p->value;

    prev = p;

    if (p->key > key) p = p->left;
    else p = p->right;
  }

  Node* temp = new Node{ key, V() };
  siz++;

  if (prev == 0) rootNode = temp;
  else {
    if (prev->key < key) prev->right = temp;
    else prev->left = temp;
  }

  return temp->value;
}

template<typename K, typename V>
bool BinarySearchTree<K, V>::containsKey(const K& key) const {
  Node* p = rootNode;

  while (p) {
    if (p->key == key) break;

    if (p->key < key) p = p->right;
    else p = p->left;
  }

  return p != 0;
}

template<typename K, typename V>
void BinarySearchTree<K, V>::deleteKey(const K& key) {
  Node* p = rootNode;
  Node* prev = 0;

  while (p) {
    if (p->key == key) break;

    prev = p;

    if (p->key < key) p = p->right;
    else p = p->left;
  }

  if (!p) return;//Case 1: Not Found

  if (p->left == 0) {
    if (p->right == 0) {
      if (prev == 0) {//Case 2: It is rootnode
        rootNode = 0;
      }
      if (prev->left == p) {//Case 3: p has no children
        prev->left == 0;
      }
      else {
        prev->right == 0;
      }
      delete p;
      siz--;
      return;
    }

    Node* pSave = p;
    prev = p;
    p = p->right;

    while (p->left) {
      prev = p;
      p = p->left;
    }
    
    pSave->key = p->key;
    pSave->value = p->value;
    if (prev->left == p) prev->left = p->right;
    else prev->right = p->right;

    delete p;
    siz--;
    return;
  }

  Node* pSave = p;
  prev = p;
  p = p->left;

  while (p->right) {
    prev = p;
    p = p->right;
  }

  pSave->key = p->key;
  pSave->value = p->value;

  if (prev->right == p) prev->right = p->left;
  else prev->left = p->left;
  delete p;
  siz--;
  return;
}

template<typename K, typename V>
Queue<K> BinarySearchTree<K, V>::Keys() const {
  Queue<K> result;
  keys(rootNode, result);
  return result;
}

template<typename K, typename V>
void BinarySearchTree<K, V>::clear() {
  clear(rootNode);
  rootNode = 0;
  siz = 0;
}
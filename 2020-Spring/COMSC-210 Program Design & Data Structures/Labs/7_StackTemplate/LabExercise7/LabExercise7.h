#ifndef LABEXERCISE7_H
#define LABEXERCISE7_H

//Programmer Name: Benjamin Kwon
//Programmer ID:   1162854

//Partner Name: Tenzin Shakya 
//Partner ID:   1242034

//Partner Name: Hwan Kim
//Partner ID:    1151832

template<typename V>
class Stack
{
  struct Node
  {
    V value;
    Node* next;
  };

  Node* firstNode; //head pointer
  int siz;
  V dummy;

public:
  Stack();//Main constructor
  Stack(const Stack<V>&);//copy constructor
  ~Stack();

  Stack<V>& operator= (const Stack<V>&);

  void push(const V&);
  const V& peek()const;
  void pop();
  void clear();
  int size() const;
  bool empty() const;
};

template<typename V>
Stack<V>::Stack()
{
  firstNode = 0;
  siz = 0;
}

template<typename V>
Stack<V>::Stack(const Stack<V>& original)
{
  firstNode = 0;
  Node* lastNode = 0;//temporary tail

  siz = original.siz;

  for (Node* p = original.firstNode; p; p = p->next) {
    Node* temp = new Node;
    temp->value = p->value;
    temp->next = 0;

    if (lastNode) lastNode->next = temp;
    else firstNode = temp;
    lastNode = temp;
  }

}

template<typename V>
Stack<V>& Stack<V>::operator=(const Stack<V>& original)
{
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

template<typename V>
void Stack<V>::push(const V& value)
{
  Node* temp = new Node;
  temp->value = value;
  temp->next = firstNode;
  firstNode = temp;
  ++siz;
}

template<typename V>
const V& Stack<V>::peek() const
{
  if (firstNode == 0) return dummy;

  return firstNode->value;
}

template<typename V>
void Stack<V>::pop()
{
  if (firstNode)
  {
    Node* p = firstNode;
    firstNode = firstNode->next;
    delete p;
    --siz;
  }
}

template<typename V>
void Stack<V>::clear() {

  while (firstNode)
  {
    Node* p = firstNode;
    firstNode = firstNode->next;
    delete p;
    --siz;
  }

}

template<typename V>
int Stack<V>::size() const
{
  return siz;
}

template<typename V>
bool Stack<V>::empty() const
{
  if (this.peek() == dummy) return true;
  else return false;
}


template<typename V>
Stack<V>::~Stack()
{
  while (firstNode)
  {
    Node* p = firstNode;
    firstNode = firstNode->next;
    delete p;
  }
}

#endif
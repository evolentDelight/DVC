#ifndef LABEXERCISE8_H
#define LABEXERCISE8_H

//Programmer:     Benjamin Kwon
//Programmer's ID:1162854

template<typename V>
class Queue
{
  struct Node
  {
    V value;
    Node* next;
  };

  int siz;//size
  Node* firstNode;
  Node* lastNode;
  V dummy;

public:
  Queue();
  Queue(const Queue&);// copy constructor
  Queue<V>& operator=(const Queue<V>&);
  ~Queue();
  void push(const V&);
  const V& front() const;//return an immutable reference to the oldest node
  const V& back() const;// return an immutable reference to the newest node
  void pop();//remove the oldest node
  int size() const { return siz; };
  bool empty() const { return siz == 0; };
  void clear();
};

template<typename V>
Queue<V>::Queue()
{
  firstNode = 0;
  lastNode = 0;
  siz = 0;
}

template<typename V>
Queue<V>::Queue(const Queue<V>& original)
{
  firstNode = 0;
  lastNode = 0;

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
Queue<V>& Queue<V>::operator=(const Queue<V>& original){
  if (this != &original)
  {
    while (firstNode)
    {
      Node* p = firstNode;
      firstNode = firstNode->next;
      delete p;
    }

    //build new queue
    lastNode = 0;
    for (Node* p = original.firstNode; p; p = p->next)
    {
      Node* temp = new Node;
      temp->value = p->value;
      temp->next = 0;
      
      if (lastNode) lastNode->next = temp;
      else firstNode = temp;
      lastNode = temp;
    }
  }

  return *this;
}

template<typename V>
void Queue<V>::push(const V& value)
{
  Node* temp = new Node;
  temp->value = value;
  temp->next = 0;

  if (lastNode) lastNode->next = temp;
  else firstNode = temp;
  lastNode = temp;
  ++siz;
}

template<typename V>
const V& Queue<V>::front() const
{
  if (siz == 0) {
    return dummy;
  }
  return firstNode->value;
}

template<typename V>
const V& Queue<V>::back() const
{
  if (siz == 0) {
    return dummy;
  }
  return lastNode->value;
}

template<typename V>
void Queue<V>::pop()
{
  if (firstNode)
  {
    Node* p = firstNode;
    firstNode = firstNode->next;
    delete p;
    --siz;
    if (siz == 0) lastNode = 0;
  }
}

template<typename V>
void Queue<V>::clear()
{
  while (firstNode)
  {
    Node* p = firstNode;
    firstNode = firstNode->next;
    delete p;
    --siz;
    if (siz == 0) lastNode = 0;
  }
}

template<typename V>
Queue<V>::~Queue()
{
  while (firstNode)
  {
    Node* p = firstNode;
    firstNode = firstNode->next;
    delete p;
  }
}

#endif
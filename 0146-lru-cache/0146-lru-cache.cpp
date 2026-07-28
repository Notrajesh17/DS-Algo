#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int key,val;
    Node*next;
    Node*prev;
    Node()
    {
        key = val=-1;
        next = prev= nullptr;
    }
    Node(int k, int value)
    {
        key=k;
        val=value;
        next=prev=nullptr;
    }
};
class LRUCache 
{
private:
    map<int, Node*>mpp;
    int cap;
    Node* head;
    Node* tail;

    void deleteNode(Node* node)
    {
        Node* prevNode = node->prev;
        Node* nextnode = node->next;

        prevNode->next=nextnode;
        nextnode->prev=prevNode;
    }

    void insertAfterHead(Node* node)
    {
        Node* nextnode = head->next;
        head->next=node;
        nextnode->prev=node;
        node->prev=head;
        node->next=nextnode;
    }
public:

  LRUCache(int capacity) 
  {
    cap= capacity;
    head = new Node();
    tail = new Node();
    head->next=tail;
    tail->prev=head;
    head->prev=nullptr;
    tail->next=nullptr;
   
  }

  int get(int key_) 
  {
    if(mpp.find(key_)==mpp.end())
    {
        return -1;
    }
    Node* node = mpp[key_];
    int value= node->val;

    deleteNode(node);
    insertAfterHead(node);
    return value;
 
  }

  void put(int key_, int value) 
  {
    if(mpp.find(key_) !=mpp.end())
    {
        Node* node = mpp[key_];
        node->val=value;
        deleteNode(node);
        insertAfterHead(node);
        return;
    }
    if(mpp.size()==cap)
    {
        Node* node = tail->prev;
        mpp.erase(node->key);
        deleteNode(node);
        delete node;
    }
    Node* newnode = new Node(key_, value);
    mpp[key_]=newnode;
    insertAfterHead(newnode);
  
  }
};

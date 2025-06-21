// Implementation of a simple stack using linked list in C++

#include <iostream>
using namespace std;

class Node 
{
    public:
        int val;
        Node* next = nullptr;
        // Constructor to initialize the node with a value
        Node(int val) : val(val) {}
};

class MyStack 
{
    public:
    Node *head = nullptr;

    // Function to push an item onto the stack
    void push(int item) 
    {
        Node* newNode = new Node(item);
        if(head == nullptr) 
        {
            head = newNode;
            return;
        } 
        else 
        {
            newNode->next = head;
            head = newNode;
        }
    }

    // Function to pop an item from the stack
    void pop() 
    {
        if(head->next == nullptr) 
        {
            delete head;
            head = nullptr;
            return;
        }
        Node* deleteNode = head;
        head = head->next;
        delete deleteNode;
    }

    // Function to get the top item of the stack
    void top()
    {
        cout << head->val << endl;
    }
};

int main()
{
    MyStack stk;
    stk.push(10);
    stk.push(20);
    stk.push(30);
    stk.pop();
    stk.top();
    return 0;
}
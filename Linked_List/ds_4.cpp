// Search in a linked list from line 42\\

#include <iostream>
using namespace std;
class node
{
public:
    int val;
    node *next;
    node(int value)
    {
        this->val = value;
        this->next = nullptr;
    }
};
class linked_list
{
public:
    node *head;
    node *tail;
    linked_list()
    {
        head = nullptr;
        tail = nullptr;
    }
    void insertinBack(int value)
    {
        node *newNode = new node(value);
        if (tail == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = nullptr;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void midValueofList(linked_list list)
    {
        node *slow = list.head;
        node *fast = list.head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        cout << slow->val << endl;
    }

    void Reverse(linked_list &list)
    {
        node *prev = nullptr;
        node *current = list.head;
        node *next = nullptr;
        list.tail = list.head;

        while (current != nullptr)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        list.head = prev;
    }
};

void printList(linked_list lst){
    node* temp = lst.head;
    while (temp!= nullptr)
    {
        cout<<temp->val<<' ';
        temp = temp->next;
    }
    
}

    int main()
    {
        linked_list list;
        list.insertinBack(5);
        list.insertinBack(10);
        list.insertinBack(8);
        list.insertinBack(9);
        list.insertinBack(2);
        list.insertinBack(7);
        list.insertinBack(4);
        list.insertinBack(6);
        list.insertinBack(3);

        
        printList(list);
        
        cout << endl << "The number at the middle of the list is: ";
        list.midValueofList(list);
        cout << endl;

        cout << "Reversed list is: ";
        list.Reverse(list);
        printList(list);
    }
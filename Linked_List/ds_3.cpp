// Size of list & Search in a linked list from line 42\\

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

    int listSize(linked_list list)
    {
        node *temp = list.head;
        int size = 0;
        while (temp != nullptr)
        {
            temp = temp->next;
            size++;
        }
        return size;
    }

    int search(int value)
    {
        node *temp = head;
        int pos = 1;
        while (temp != NULL)
        {
            if (temp->val == value)
            {
                return pos;
            }
            pos++;
            temp = temp->next;
        }
        return -1;
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

        cout << endl << "Size of list is: "<< list.listSize(list) << endl;
        
        cout << "Enter the value to search: ";
        int value;  
        cin >> value;
        cout << "Location of "<< value << " is: "<< list.search(value) << endl;
        
    }
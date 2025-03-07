// Pop Front, Back and at a position in a linked list from line 42\\

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

    void insertinFront(int value)
    {
        node *newNode = new node(value);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void pop_front()
    {
        if(head == nullptr)
        {
            cout<<"List is empty"<<endl;
            return;
        }
        node* temp = head;
        head = head->next;
        temp->next = nullptr;
        delete temp;
    }
    void pop_back()
    {
        if(head == nullptr)
        {
            cout<<"List is empty"<<endl;
            return;
        }
        node* temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
    }
    void deletePos(int pos)
    {
        if(pos <= 0)
        {
            cout << "Position should be greater than zero!\n";
            return;
        }
        if(head == nullptr)
        {
            cout << "List is Empty.\n";
            return;
        }

        node *temp = head;
        node *temp2 = head;
        if(pos == 1)
        {
            node *temp = head;
            head = head->next;
            delete temp;
            return;
        }
        int cnt = 1;
        while(cnt != pos - 1)
        {
            temp = temp->next;
            cnt++;
        }
        temp2 = temp->next->next;
        temp->next = temp2;
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

        list.pop_front();
        cout << "After popping front: ";
        printList(list);
        cout << endl;

        list.pop_back();
        cout << "After popping back: ";
        printList(list);
        cout << endl;

        list.deletePos(2);
        cout << "After deleting position 2: ";
        printList(list);


    }

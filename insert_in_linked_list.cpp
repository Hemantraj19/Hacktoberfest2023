#include <iostream>
using namespace std;

class Node
{
private:
    int data;
    Node *next;

public:
    void setData(int data)
    {
        this->data = data;
    }
    void setPointer(Node *next)
    {
        this->next = next;
    }
    int getData()
    {
        return data;
    }
    Node *getNode()
    {
        return next;
    }
};

Node *insert(Node *first, int value)
{
    if (first == NULL)
    {
        Node *temp = new Node;
        temp->setData(value);
        temp->setPointer(NULL);
        first = temp;
    }
    else
    {
        Node *p = first;
        while (p->getNode())
        {
            p = p->getNode();
        }
        Node *temp = new Node();
        temp->setData(value);
        temp->setPointer(NULL);
        p->setPointer(temp);
    }

    return first;
}

void printList(Node *first)
{
    Node *p = first;
    while (p)
    {
        cout<<p->getData()<<" ";
        p = p->getNode();
    }
}

int main()
{
    Node *first=NULL;
    int num;
    cout << "Enter first value: ";
    cin >> num;
    first = insert(first, num);
    cout << "Enter the numbers , press -1 to exit: ";
    while (num != -1)
    {
        cin >> num;
        if(num!=-1)
            insert(first, num);
    }
    printList(first);
}

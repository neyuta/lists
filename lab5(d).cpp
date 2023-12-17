#include <iostream>

using namespace std;

struct Node 
{
    int data;
    Node* next;
};

void push(Node** head, int newData) 
{
    Node* newNode = new Node;
    newNode->data = newData;
    newNode->next = *head;
    *head = newNode;
}

void printList(Node* head) 
{
    while (head != nullptr) 
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void insertionSort(Node** head) 
{
    Node* sortedList = nullptr;
    Node* current = *head;
    while (current != nullptr) 
    {
        Node* nextNode = current->next;
        Node* sortedCurrent = sortedList;
        Node* sortedPrev = nullptr;
        while (sortedCurrent != nullptr && sortedCurrent->data < current->data) 
        {
            sortedPrev = sortedCurrent;
            sortedCurrent = sortedCurrent->next;
        }
        if (sortedPrev == nullptr) 
        {
            current->next = sortedList;
            sortedList = current;
        }
        else 
        {
            current->next = sortedPrev->next;
            sortedPrev->next = current;
        }
        current = nextNode;
    }
    *head = sortedList;
}

int main() 
{
    Node* head = nullptr;

    push(&head, 9);
    push(&head, 2);
    push(&head, 7);
    push(&head, 4);
    push(&head, 5);

    cout << "the original list: ";
    printList(head);

    insertionSort(&head);

    cout << "an ordered list: ";
    printList(head);

    return 0;
}

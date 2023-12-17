#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* addNode(Node* head, int data) 
{
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;

    if (head == nullptr) 
    {
        head = newNode;
    }
    else 
    {
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }
    return head;
}

void printList(Node* head) 
{
    Node* temp = head;
    while (temp != nullptr) 
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* mergeLists(Node* head1, Node* head2) 
{
    Node* mergedHead = nullptr;

    if (head1 == nullptr)
        return head2;
    if (head2 == nullptr)
        return head1;

    if (head1->data <= head2->data) 
    {
        mergedHead = head1;
        mergedHead->next = mergeLists(head1->next, head2);
    }
    else 
    {
        mergedHead = head2;
        mergedHead->next = mergeLists(head1, head2->next);
    }

    return mergedHead;
}

int main() 
{
    Node* head1 = nullptr;
    head1 = addNode(head1, 1);
    head1 = addNode(head1, 3);
    head1 = addNode(head1, 5);

    Node* head2 = nullptr;
    head2 = addNode(head2, 2);
    head2 = addNode(head2, 4);
    head2 = addNode(head2, 6);

    Node* mergedList = mergeLists(head1, head2);

    cout << "Merged List: ";
    printList(mergedList);

    return 0;
}
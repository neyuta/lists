#include <iostream>

using namespace std;

struct Node 
{
    int data;
    Node* next;
};

class Stack 
{
private:
    Node* top;

public:
    Stack() 
    {
        top = nullptr;
    }

    void push(int value) 
    {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    void pop() 
    {
        if (isEmpty()) 
        {
            cout << "Стек пуст!" << endl;
            return;
        }

        Node* temp = top;
        top = top->next;
        delete temp;
    }

    int peek() 
    {
        if (isEmpty()) 
        {
            cout << "Стек пуст!" << endl;
            return -1;
        }

        return top->data;
    }

    bool isEmpty() 
    {
        return top == nullptr;
    }
};

int main() 
{
    int arr[5] = { 1, 2, 3, 4, 5 };

    Stack stack;

    for (int i = 0; i < 5; i++) 
    {
        stack.push(arr[i]);
    }

    while (!stack.isEmpty()) 
    {
        cout << stack.peek() << " ";
        stack.pop();
    }

    return 0;
}

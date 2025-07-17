#include <iostream>
#define LIMIT 5
using namespace std;

char stack[LIMIT];
int top = -1;

/*  isEmpty() - checks if the stack is empty
    isFull() - checks if the stack is full
    push(x) - adds a value on the top of the stack
    pop() - removes the top value from the stack
    peek() - returns the top value of the stack
    size() - returns the number of elements in the stack
    display() - displays the elements of the stack  */

bool isEmpty()
{
    return top == -1;
}

bool isFull()
{
    return top == LIMIT - 1;
}

void push(char data)
{
    if (isFull())
    {
        cout << "Stack Overflow!" << endl;
    }
    else
    {
        top++;
        stack[top] = data;
        cout << "Pushed: " << data << endl;
    }
}

void pop()
{
    if (isEmpty())
    {
        cout << "Stack Underflow!" << endl;
    }
    else
    {
        cout << "Popped: " << stack[top] << endl;
        stack[top] = NULL;
        top--;
    }
}

char peek()
{
    if (isEmpty())
    {
        cout << "Stack is empty!" << endl;
    }
    return stack[top];
}

int size()
{
    return top + 1;
}

void display()
{
    if (isEmpty())
    {
        cout << "Stack is empty!" << endl;
    }
    else
    {
        cout << "Stack elements: " << endl;
        for (int i = top; i >= 0; i--)
        {
            cout << stack[i] << endl;
        }
        cout << endl;
    }
}

int main()
{
    push('A');
    push('B');
    push('C');
    push('D');
    push('E');
    // push('F'); // Attempt to push when stack is full (stack overflow)

    pop();
    pop();
    pop();
    // pop(); // Attempt to pop from an empty stack (stack underflow)

    cout << "Top element: " << peek() << endl;

    cout << "Current stack size: " << size() << endl;

    display();

    return 0;
}
#include <iostream>
#define LIMIT 5
using namespace std;

char queue[LIMIT];
int front = -1, rear = -1;

/*  isEmpty() - checks if the queue is empty
    isFull() - checks if the queue is full
    enqueue() - adds an element to the end of the queue
    dequeue() - removes an element from the front of the queue
    peek() - returns the front element of the queue without removing it
    size() - returns the number of elements in the queue
    display() - displays all elements in the queue
*/

bool isEmpty()
{
    return front == -1 && rear == -1;
}

bool isFull()
{
    return rear == LIMIT - 1;
}

void enqueue(char data)
{
    if (isFull())
    {
        cout << "Queue is full!" << endl;
        return;
    }
    else if (isEmpty())
    {
        rear = 0;
        front = 0;
        queue[rear] = data; // add the first element
        cout << "Enqueued: " << data << endl;
    }
    else
    {
        rear++;
        queue[rear] = data; // add subsequent elements
        cout << "Enqueued: " << data << endl;
    }
}

void dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is empty!" << endl;
    }
    else if ((front + 1) > rear)
    {
        cout << "Dequeued: " << queue[front] << endl;
        queue[front] = NULL;
        front = -1; // reset queue
        rear = -1;
    }
    else
    {
        cout << "Dequeued: " << queue[front] << endl;
        queue[front] = NULL;
        front++;
    }
}

char peek()
{
    if (isEmpty())
    {
        cout << "Queue is empty!" << endl;
    }
    else
    {
        return queue[front];
    }
}

int size()
{
    return (rear - front) + 1;
}

int main()
{
    enqueue('A');
    enqueue('B');
    enqueue('C');
    enqueue('D');
    enqueue('E');
    // enqueue('F'); // should show that the queue is full

    dequeue(); // should remove 'A'
    dequeue(); // should remove 'B'
    /*  dequeue(); // should remove 'C'
        dequeue(); // should remove 'D'
        dequeue(); // should remove 'E'
        dequeue(); // should show that the queue is empty */

    cout << "Front element: " << peek() << endl; // should show 'C' after two dequeues

    cout << "Queue size: " << size() << endl; // should show 3

    return 0;
}
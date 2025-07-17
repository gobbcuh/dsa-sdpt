#include <iostream>
#define LIMIT 5
using namespace std;

string queue[LIMIT];
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

void enqueue(string data)
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
        queue[front] = "";
        front = -1; // reset queue
        rear = -1;
    }
    else
    {
        cout << "Dequeued: " << queue[front] << endl;
        queue[front] = "";
        front++;
    }
}

string peek()
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

void display()
{
    if (isEmpty())
    {
        cout << "Queue is empty!" << endl;
    }
    else
    {
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++)
        {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    enqueue("Facebook");
    enqueue("Instagram");
    enqueue("LinkedIn");
    enqueue("X");
    enqueue("GitHub");
    // enqueue("YouTube"); // should show that the queue is full

    dequeue(); // should remove 'Facebook'"
    dequeue(); // should remove 'Instagram'
    /*  dequeue(); // should remove 'LinkedIn'
        dequeue(); // should remove 'X'
        dequeue(); // should remove 'GitHub'
        dequeue(); // should show that the queue is empty */

    cout << "Front element: " << peek() << endl; // should show 'LinkedIn' after two dequeues

    cout << "Queue size: " << size() << endl; // should show 3

    display();

    return 0;
}
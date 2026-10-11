#include <iostream> //25K-3101
#include <string>
using namespace std;

class Stack {
public:
    string data[100];
    int top = -1;

    void push(string x) {
        top++;
        data[top] = x;
    }

    string pop() {
        string x = data[top];
        top--;
        return x;
    }

    bool isEmpty() {
        return top == -1;
    }
};

class Queue {
public:
    string data[100];
    int front = 0;
    int rear = -1;
    int count = 0;

    void enqueue(string x) {
        rear = (rear + 1) % 100;
        data[rear] = x;
        count++;
    }

    string dequeue() {
        string x = data[front];
        front = (front + 1) % 100;
        count--;
        return x;
    }

    void print() {
        for (int i = 0; i < count; i++) {
            cout << data[(front + i) % 100] << " ";
        }
        cout << endl;
    }
};

void reverseFirstK(Queue &q, int k) {
    if (k > q.count) {
        k = q.count;
    }

    Stack s;

    for (int i = 0; i < k; i++) {
        s.push(q.dequeue());
    }

    while (!s.isEmpty()) {
        q.enqueue(s.pop());
    }

    int rest = q.count - k;
    for (int i = 0; i < rest; i++) {
        q.enqueue(q.dequeue());
    }
}

int main() {
    Queue q;

    q.enqueue("J1");
    q.enqueue("J2");
    q.enqueue("J3");
    q.enqueue("J4");
    q.enqueue("J5");
    q.enqueue("J6");
    q.enqueue("J7");

    cout << "Before: ";
    q.print();

    reverseFirstK(q, 3);

    cout << "After:  ";
    q.print();

    return 0;
}

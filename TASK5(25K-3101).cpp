#include <iostream> //25K-3101
using namespace std;

class Stack {
public:
    int data[100];
    int top = -1;

    void push(int x) {
        top++;
        data[top] = x;
    }

    int pop() {
        int x = data[top];
        top--;
        return x;
    }

    bool isEmpty() {
        return top == -1;
    }
};

class MyQueue {
public:
    Stack inStack;
    Stack outStack;

    void enqueue(int item) {
        inStack.push(item);
    }

    int dequeue() {
        if (outStack.isEmpty()) {
            while (!inStack.isEmpty()) {
                outStack.push(inStack.pop());
            }
        }
        if (outStack.isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return outStack.pop();
    }
};

int main() {
    MyQueue q;

    q.enqueue('A');
    q.enqueue('B');
    cout << "dequeue: " << (char)q.dequeue() << endl;

    q.enqueue('C');
    cout << "dequeue: " << (char)q.dequeue() << endl;
    cout << "dequeue: " << (char)q.dequeue() << endl;

    return 0;
}

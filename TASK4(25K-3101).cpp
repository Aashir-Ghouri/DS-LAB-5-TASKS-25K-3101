#include <iostream> //25K-3101
using namespace std;

class CircularQueue {
public:
    int data[6];
    int front = 0;
    int rear = -1;
    int count = 0;

    bool isFull() {
        return count == 6;
    }

    bool isEmpty() {
        return count == 0;
    }

    void enqueue(int id) {
        if (isFull()) {
            cout << "Gate is full, passenger " << id << " cannot enter" << endl;
            return;
        }
        rear = (rear + 1) % 6;
        data[rear] = id;
        count++;
    }

    void board() {
        if (isEmpty()) {
            cout << "No passengers to board" << endl;
            return;
        }
        cout << "Boarded: " << data[front] << endl;
        front = (front + 1) % 6;
        count--;
    }

    void display() {
        cout << "Final boarding order: ";
        for (int i = 0; i < count; i++) {
            cout << data[(front + i) % 6] << " ";
        }
        cout << endl;
        cout << "Front position: " << front << endl;
        cout << "Rear position: " << rear << endl;
    }
};

int main() {
    CircularQueue q;

    for (int id = 101; id <= 106; id++) {
        q.enqueue(id);
    }

    for (int i = 0; i < 3; i++) {
        q.board();
    }

    for (int id = 107; id <= 109; id++) {
        q.enqueue(id);
    }

    for (int i = 0; i < 2; i++) {
        q.board();
    }

    q.enqueue(110);

    q.board();

    q.enqueue(111);
    q.enqueue(112);

    q.display();

    return 0;
}

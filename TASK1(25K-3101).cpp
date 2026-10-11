#include <iostream> //25K-3101
using namespace std;

const int MAX = 8;
int stk[MAX];
int top = -1;

bool isEmpty() {
    return top == -1;
}

bool isFull() {
    return top == MAX - 1;
}

void showTop() {
    if (isEmpty()) {
        cout << "Current top: stack is empty" << endl;
    } else {
        cout << "Current top: " << stk[top] << endl;
    }
}

void doOperation(int code) {
    if (isFull()) {
        for (int i = 0; i < MAX - 1; i++) {
            stk[i] = stk[i + 1];
        }
        top--;
    }
    top++;
    stk[top] = code;
    cout << "Operation " << code << " performed. ";
    showTop();
}

void undo() {
    if (isEmpty()) {
        cout << "Undo failed: stack is empty, nothing to undo." << endl;
        return;
    }
    cout << "Undo removed " << stk[top] << ". ";
    top--;
    showTop();
}

void displayStack() {
    cout << "Remaining operations (top to bottom): ";
    if (isEmpty()) {
        cout << "none";
    }
    for (int i = top; i >= 0; i--) {
        cout << stk[i] << " ";
    }
    cout << endl;
}

int main() {
    int ops[6] = {12, 25, 17, 31, 44, 19};

    for (int i = 0; i < 6; i++) {
        doOperation(ops[i]);
    }

    for (int i = 0; i < 3; i++) {
        undo();
    }

    doOperation(52);

    for (int i = 0; i < 2; i++) {
        undo();
    }

    displayStack();

    return 0;
}

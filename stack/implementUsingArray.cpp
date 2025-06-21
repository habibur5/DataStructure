#include <bits/stdc++.h>
using namespace std;
#define MAX 100  // Maximum size of the stack

class Stack {
private:
    int arr[MAX];  // Array to hold stack elements
    int top;       // Index of the top element

public:
    Stack() {
        top = -1;  // Initialize top to -1 indicating stack is empty
    }

    // Push an element onto the stack
    void push(int value) {
        if (top >= MAX - 1) {
            cerr << "Stack Overflow\n";
            return;
        }
        arr[++top] = value;
    }

    // Remove the top element
    void pop() {
        if (isEmpty()) {
            cerr << "Stack Underflow\n";
            return;
        }
        top--;
    }

    // Get the top element
    int peek() const {
        if (isEmpty()) {
            cerr << "Stack is empty\n";
            return -1;
        }
        return arr[top];
    }

    // Check if the stack is empty
    bool isEmpty() const {
        return top == -1;
    }

    // Get the size of the stack
    int size() const {
        return top + 1;
    }

    // Display the stack
    void display() const {
        cout << "Stack from top to bottom:\n";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << "\n";
        }
    }
};

int main() {
    Stack s;

    s.push(5);
    s.push(15);
    s.push(25);

    s.display();

    cout << "Top element: " << s.peek() << "\n";

    s.pop();
    s.display();
    return 0;
}

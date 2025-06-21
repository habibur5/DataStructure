#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Stack {
private:
    vector<T> data;

public:
    // Push element onto stack
    void push(T value) {
        data.push_back(value);
    }

    // Remove the top element
    void pop() {
        if (!isEmpty()) {
            data.pop_back();
        } else {
            cerr << "Stack Underflow\n";
        }
    }

    // Get the top element
    T top() const {
        if (!isEmpty()) {
            return data.back();
        } else {
            throw out_of_range("Stack is empty");
        }
    }

    // Check if the stack is empty
    bool isEmpty() const {
        return data.empty();
    }

    // Get the size of the stack
    int size() const {
        return data.size();
    }

    // Display the stack
    void display() const {
        cout << "Stack from top to bottom:\n";
        for (auto it = data.rbegin(); it != data.rend(); ++it) {
            cout << *it << "\n";
        }
    }
};

int main() {
    Stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.display(); // Output: 30 20 10

    cout << "Top element: " << s.top() << "\n";

    s.pop();
    s.display(); // Output: 20 10

    return 0;
}

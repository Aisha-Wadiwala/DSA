#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Top pointer
Node* top = nullptr;

// Check if stack is empty
bool isEmpty() {
    return top == nullptr;
}

// Push operation
void push(int val) {
    Node* newNode = new Node(val);
    newNode->next = top;
    top = newNode;

    cout << val << " pushed to stack." << endl;
}

// Pop operation
void pop() {
    if (isEmpty()) {
        cout << "Stack Underflow! Stack is empty." << endl;
        return;
    }

    Node* temp = top;
    cout << temp->data << " popped from stack." << endl;
    top = top->next;
    delete temp;
}

// Peek operation
void peek() {
    if (isEmpty()) {
        cout << "Stack is empty." << endl;
        return;
    }

    cout << "Top element: " << top->data << endl;
}

// Display stack
void display() {
    if (isEmpty()) {
        cout << "Stack is empty." << endl;
        return;
    }

    Node* temp = top;

    cout << "Stack (Top to Bottom): ";

    while (temp != nullptr) {
        cout << temp->data;

        if (temp->next != nullptr)
            cout << " -> ";

        temp = temp->next;
    }

    cout << endl;
}

// Free all allocated memory
void clearStack() {
    while (!isEmpty()) {
        pop();
    }
}

int main() {
    // Push elements
    push(29);
    push(13);
    push(40);
    push(55);

    cout << endl;

    // Display stack
    display();

    cout << endl;

    // Peek
    peek();

    cout << endl;

    // Pop one element
    pop();

    cout << endl;

    // Display again
    display();

    cout << endl;

    // Clear stack
    clearStack();

    cout << endl;

    // Check if empty
    display();

    return 0;
}
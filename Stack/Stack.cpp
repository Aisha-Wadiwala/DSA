#include <iostream>
using namespace std;

int top = -1;

// Push function
void push(int arr[], int size)
{
    if (top == size - 1)
    {
        cout << "Stack Overflow!" << endl;
        return;
    }

    int num;
    cout << "Enter number: ";
    cin >> num;

    top++;
    arr[top] = num;

    cout << "Element pushed successfully." << endl;
}

// Pop function
void pop(int arr[])
{
    if (top == -1)
    {
        cout << "Stack Underflow!" << endl;
        return;
    }

    cout << "Popped element: " << arr[top] << endl;
    top--;
}

// Display function
void display(int arr[])
{
    if (top == -1)
    {
        cout << "Stack is empty." << endl;
        return;
    }

    cout << "Stack elements (Top to Bottom): ";

    for (int i = top; i >= 0; i--)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

int main()
{
    int size;

    cout << "Enter stack size: ";
    cin >> size;

    int arr[size];

    push(arr, size);
    push(arr, size);
    push(arr, size);

    display(arr);

    pop(arr);

    display(arr);

    return 0;
}
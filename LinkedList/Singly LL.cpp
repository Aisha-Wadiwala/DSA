#include <iostream>
using namespace std;
// Node structure
struct Node
{
    int data;
    Node* next;
};

// Head pointer
Node* head = NULL;

// Insert at Beginning
void insertAtBeginning(int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// Insert at End
void insertAtEnd(int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Insert at Position (Middle)
void insertAtPosition(int value, int position)
{
    if (position == 1)
    {
        insertAtBeginning(value);
        return;
    }

    Node* newNode = new Node;
    newNode->data = value;

    Node* temp = head;

    for (int i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Invalid Position\n";
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete from Beginning
void deleteAtBeginning()
{
    if (head == NULL)
    {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
}

// Delete from End
void deleteAtEnd()
{
    if (head == NULL)
    {
        cout << "List is empty.\n";
        return;
    }

    if (head->next == NULL)
    {
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;

    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = NULL;
}

// Delete from Position (Middle)
void deleteAtPosition(int position)
{
    if (head == NULL)
    {
        cout << "List is empty.\n";
        return;
    }

    if (position == 1)
    {
        deleteAtBeginning();
        return;
    }

    Node* temp = head;

    for (int i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL)
    {
        cout << "Invalid Position\n";
        return;
    }

    Node* del = temp->next;
    temp->next = del->next;
    delete del;
}

// Display List
void display()
{
    if (head == NULL)
    {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

int main()
{
    insertAtBeginning(30);
    insertAtBeginning(20);
    insertAtBeginning(10);

    cout << "After inserting at beginning:\n";
    display();

    insertAtEnd(40);
    insertAtEnd(50);

    cout << "\nAfter inserting at end:\n";
    display();

    insertAtPosition(25, 3);

    cout << "\nAfter inserting 25 at position 3:\n";
    display();

    deleteAtBeginning();

    cout << "\nAfter deleting from beginning:\n";
    display();

    deleteAtEnd();

    cout << "\nAfter deleting from end:\n";
    display();

    deleteAtPosition(3);

    cout << "\nAfter deleting from position 3:\n";
    display();

    return 0;
}
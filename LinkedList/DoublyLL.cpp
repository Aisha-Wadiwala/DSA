#include <iostream>
using namespace std;

// Doubly Linked List Node
struct Node
{
    int data;
    Node* prev;
    Node* next;
};

// Create New Node
Node* createNode(int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert at Beginning
void insertAtBeginning(Node*& head, int value)
{
    Node* newNode = createNode(value);

    if (head != NULL)
        head->prev = newNode;

    newNode->next = head;
    head = newNode;
}

// Insert at End
void insertAtEnd(Node*& head, int value)
{
    Node* newNode = createNode(value);

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

// Insert at Position
void insertAtMiddle(Node*& head, int value, int position)
{
    if (position == 1)
    {
        insertAtBeginning(head, value);
        return;
    }

    Node* temp = head;

    for (int i = 1; i < position - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL)
    {
        cout << "Invalid Position\n";
        return;
    }

    Node* newNode = createNode(value);

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
}

// Delete from Beginning
void deleteAtBeginning(Node*& head)
{
    if (head == NULL)
    {
        cout << "List is Empty\n";
        return;
    }

    Node* temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    delete temp;
}

// Delete from End
void deleteAtEnd(Node*& head)
{
    if (head == NULL)
    {
        cout << "List is Empty\n";
        return;
    }

    if (head->next == NULL)
    {
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;

    delete temp;
}

// Delete at Position
void deleteAtMiddle(Node*& head, int position)
{
    if (head == NULL)
    {
        cout << "List is Empty\n";
        return;
    }

    if (position == 1)
    {
        deleteAtBeginning(head);
        return;
    }

    Node* temp = head;

    for (int i = 1; i < position && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL)
    {
        cout << "Invalid Position\n";
        return;
    }

    temp->prev->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    delete temp;
}

// Display
void display(Node* head)
{
    Node* temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

// Main Function
int main()
{
    Node* head = NULL;

    insertAtBeginning(head, 20);
    insertAtBeginning(head, 10);

    insertAtEnd(head, 40);
    insertAtEnd(head, 50);

    insertAtMiddle(head, 30, 3);

    cout << "Original List:\n";
    display(head);

    deleteAtBeginning(head);
    cout << "\nAfter Deleting Beginning:\n";
    display(head);

    deleteAtMiddle(head, 2);
    cout << "\nAfter Deleting Middle:\n";
    display(head);

    deleteAtEnd(head);
    cout << "\nAfter Deleting End:\n";
    display(head);

    return 0;
}
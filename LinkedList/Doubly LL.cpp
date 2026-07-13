#include <iostream>
using namespace std;

//==============================
// Doubly Linked List
//==============================

struct Node
{
    int data;
    Node* next;
    Node* prev;
};

// Create a new node
Node* createNode(int data)
{
    Node* newNode = new Node;

    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    return newNode;
}

// Insert at beginning
void insertAtBeginning(Node*& head, int data)
{
    Node* newNode = createNode(data);

    if (head != nullptr)
    {
        newNode->next = head;
        head->prev = newNode;
    }

    head = newNode;
}

// Insert at end
void insertAtEnd(Node*& head, int data)
{
    Node* newNode = createNode(data);

    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

// Insert after the second node
void insertAtMiddle(Node*& head, int data)
{
    if (head == nullptr || head->next == nullptr)
    {
        insertAtBeginning(head, data);
        return;
    }

    Node* secondNode = head->next;

    Node* newNode = createNode(data);

    newNode->next = secondNode->next;
    newNode->prev = secondNode;

    secondNode->next = newNode;

    if (newNode->next != nullptr)
    {
        newNode->next->prev = newNode;
    }
}

// Delete first node
void deleteAtBeginning(Node*& head)
{
    if (head == nullptr)
    {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;

    head = head->next;

    if (head != nullptr)
    {
        head->prev = nullptr;
    }

    delete temp;
}

// Display list
void display(Node* head)
{
    if (head == nullptr)
    {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;

    while (temp != nullptr)
    {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

// Free allocated memory
void deleteList(Node*& head)
{
    while (head != nullptr)
    {
        deleteAtBeginning(head);
    }
}

int main()
{
    Node* head = nullptr;

    insertAtBeginning(head, 3);
    insertAtBeginning(head, 2);
    insertAtBeginning(head, 1);

    insertAtEnd(head, 4);

    insertAtMiddle(head, 5);

    cout << "Original List:\n";
    display(head);

    deleteAtBeginning(head);

    cout << "\nAfter deleting first node:\n";
    display(head);

    deleteList(head);

    return 0;
}
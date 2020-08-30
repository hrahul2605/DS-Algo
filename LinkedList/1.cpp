// author: hrahul2605
// Doubly Linked list Insertion - Front, End, Intermediate
// Doubly Linked list Deletion - Front, End, Intermediate

#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

void addFront(Node **head, int data)
{
    Node *temp = *head;

    Node *newNode = new Node();
    newNode->data = data;
    newNode->prev = NULL;

    if (temp == NULL)
    {
        newNode->next = NULL;
    }
    else
    {
        newNode->next = temp;
        temp->prev = newNode;
    }

    *head = newNode;

    return;
}

void addEnd(Node **head, int data)
{
    Node *temp = *head;

    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;

    if (temp == NULL)
    {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;

    return;
}

void addIntermediate(Node **head, int pos, int data)
{
    Node *temp = *head;

    while (temp != NULL && temp->data != pos)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Given value was not found.\n";
        return;
    }

    Node *newNode = new Node();
    newNode->data = data;
    newNode->prev = temp;
    newNode->next = temp->next;
    temp->next = newNode;

    return;
}

void deleteFront(Node **head)
{
    Node *temp = *head;

    if (temp == NULL)
    {
        cout << "Nothing to Delete.\n";
        return;
    }
    else if (temp->next == NULL)
    {
        *head = NULL;
    }
    else
    {
        *head = temp->next;
    }

    delete temp;

    cout << "Deleted from Front.\n";

    return;
}

void deleteEnd(Node **head)
{
    Node *temp = *head;

    if (temp == NULL)
    {
        cout << "Nothing to Delete.\n";
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    if (temp->prev != NULL)
    {
        temp->prev->next = NULL;
    }
    else
    {
        *head = NULL;
    }

    delete temp;

    cout << "Deleted from End.\n";

    return;
}

void deleteIntermediate(Node **head, int pos)
{

    Node *temp = *head;
    if (temp == NULL)
    {
        cout << "Nothing to delete\n";
        return;
    }
    while (temp != NULL && temp->data != pos)
        temp = temp->next;

    if (temp == NULL)
    {
        cout << "Element was not found.\n";
        return;
    }

    if (temp->prev == NULL)
        *head = temp->next;
    else
    {
        temp->prev->next = temp->next;
    }

    delete temp;

    cout << "Element deleted.\n";

    return;
}

void print(Node *head)
{
    Node *temp = head;
    if (temp == NULL)
    {
        cout << "NOTHING TO PRINT.";
    }

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << "\nLIST PRINTED\n";
}

int32_t main()
{

    Node *head = NULL;

    int key = -1;

    while (key != 8)
    {
        cout << "1 to Add at Front\n2 to Add at End\n3 to Add at Intermediate\n4 to Delete from Front\n5 to Delete from End\n6 to Delete from Intermediate\n7 to Print List\n8 to EXIT\n";
        cin >> key;
        int data, pos;
        if (key == 1)
        {
            cout << "Enter value to add: ";
            cin >> data;
            addFront(&head, data);
        }
        else if (key == 2)
        {
            cout << "Enter value to add: ";
            cin >> data;
            addEnd(&head, data);
        }
        else if (key == 3)
        {
            cout << "Enter value to add: ";
            cin >> data;
            cout << "Enter the value after which you want to add: ";
            cin >> pos;
            addIntermediate(&head, pos, data);
        }
        else if (key == 4)
        {
            deleteFront(&head);
        }
        else if (key == 5)
        {
            deleteEnd(&head);
        }
        else if (key == 6)
        {
            cout << "Enter the value which you want to delete: ";
            cin >> pos;
            deleteIntermediate(&head, pos);
        }
        else if (key == 7)
        {
            print(head);
        }
    }
}
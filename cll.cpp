#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};
void insertAtHead(Node *&head, int val)
{
    Node *newNode = new Node(val);
    // edge cases (what if head is NULL)
    if (head == NULL)
    {
        newNode->next = newNode; // as its a circular linked list
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
    head = newNode;
    return;
}
void insertAtTail(Node *&head, int val)
{
    if (head == NULL)
    {
        insertAtHead(head, val);
        return;
    }
    Node *newNode = new Node(val);
    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
    return;
}
void print(Node *&head)
{
    Node *temp = head;
    do
    {
        cout << temp->data << "->";
        temp = temp->next;
    } while (temp != head);
    cout << "end of circular linked list" << endl;
    return;
}
Node *delAtHead(Node *&head)
{
    if (head == NULL)
    {
        cout << " cannot delete " << endl;
        return head;
    }
    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = head->next;
    Node *k = head;
    head = head->next;
    delete (k);
    return head;
}
Node *delAtEnd(Node *&head)
{
    Node *temp = head;
    while (temp->next->next != head)
    {
        temp = temp->next;
    }
    Node *toBeDeleted = temp->next;
    temp->next = head;
    delete (toBeDeleted);
    return head;
}
void deletion(Node *&head, int index)
{
    if (index == 0)
    {
        delAtHead(head);
        return;
    }
    if (index == 4)
    {
        delAtEnd(head);
        return;
    }
    int c = 1;
    Node *temp = head;
    while (c != index)
    {
        temp = temp->next;
        c++;
    }
    Node *toBedeleted = temp->next;
    temp->next = temp->next->next;
    delete (toBedeleted);
    // return;
}
int main()
{
    Node *head = NULL;
    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtTail(head, 40);
    // print(head);
    insertAtHead(head, 50);
    print(head);
    // delAtHead(head);
    // print(head);
    // delAtEnd(head);
    // print(head);
    deletion(head, 3);
    print(head);

}
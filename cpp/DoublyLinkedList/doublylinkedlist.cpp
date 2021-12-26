#include <stddef.h>

class Node
{
public:
    int *val;
    Node *prev;
    Node *next;

    Node(int *_val, Node *_prev, Node *_next)
    {
        val = _val;
        prev = _prev;
        next = _next;
    }
};

// dummy header and tail terminated
class DoublyLL
{

    DoublyLL()
    {
        head = new Node(NULL, NULL, NULL);
        tail = new Node(NULL, NULL, NULL);

        head->next = tail;
        tail->prev = head;

        size = 0;
    }

    void pushFront(int *val)
    {
        Node *newNode = new Node(val, NULL, NULL);

        // connect newNode with its following node
        head->next->prev = newNode;
        newNode->next = head->next;

        // connect newNode with previous node (dummy head)
        head->next = newNode;
        newNode->prev = head;

        // update size
        size++;
    }

    void pushBack(int *val)
    {
        Node *newNode = new Node(val, NULL, NULL);

        // connect newNode with its previous node
        tail->prev->next = newNode;
        newNode->prev = tail->prev;

        // connect newNode with its next node (dummy tail)
        tail->prev = newNode;
        newNode->next = tail;

        // update size
        size++;
    }

    int *popFront()
    {
        // check if ll empty
        if (isEmpty())
            return NULL;

        // access front node
        Node *curr = head->next;

        // detach it from linked list
        head->next = curr->next;
        curr->next->prev = head;

        // update size
        size--;

        return curr->val;
    }

    int *popBack()
    {
        // check if ll empty
        if (isEmpty())
            return NULL;

        // access last node
        Node *curr = tail->prev;

        // detach from ll
        tail->prev = curr->prev;
        curr->prev->next = tail;

        // update size
        size--;

        return curr->val;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return head->next == tail && tail->prev == head;
    }

private:
    Node *head;
    Node *tail;
    int size;
};
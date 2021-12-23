// implementation must be public to ensure that user has access to linked list modifications -- regardless of safety
// then implementation of data structures like stacks and queues can use private linked lists that are not viewable by the user
#include <stddef.h>
#include "singlylinkedlist.h"

class Node
{
public:
    int *val;
    Node *next;

    Node(int *_val, Node *_next)
    {
        val = _val;
        next = _next;
    }
};

class HeadSLL
{
public:
    HeadSLL()
    {
        head = NULL;
        length = 0;
    }

    void prepend(int *val)
    {
        Node *node = new Node(val, head);
        head = node;
        length++;
        return;
    }

    void append(int *val)
    {
        Node *newNode = new Node(val, NULL);
        length++;

        if (head == NULL)
        {
            head = newNode;
            return;
        }

        Node *curr = head;
        while (curr->next != NULL)
            curr = curr->next;
        curr->next = newNode;

        return;
    }

    int *popFront()
    {
        if (head == NULL)
            return NULL;

        int *val = head->val;
        head = head->next;
        length--;
        return val;
    }

    int *popBack()
    {
        if (head == NULL)
            return NULL;

        Node *prev = NULL;
        Node *curr = head;
        while (curr->next != NULL)
        {
            prev = curr;
            curr = curr->next;
        }

        if (prev != NULL)
            prev->next = NULL;

        length--;
        return curr->val;
    }

    int getLength()
    {
        return length;
    }

    bool isEmpty()
    {
        return head == NULL;
    }

private:
    Node *head;
    int length;
};

class HeadTailSLL
{
public:
    void prepend(int *val)
    {
        Node *newNode = new Node(val, head);
        length++;

        if (head == NULL)
            tail = newNode;
        head = newNode;

        return;
    }

    void append(int *val)
    {
        Node *newNode = new Node(val, NULL);
        length++;

        if (tail == NULL)
            head = newNode;
        else
            tail->next = newNode;

        tail = newNode;

        return;
    }

private:
    Node *head;
    Node *tail;
    int length;
};

int main()
{

    return 0;
}
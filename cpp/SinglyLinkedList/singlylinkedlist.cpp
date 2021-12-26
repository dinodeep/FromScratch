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
        size = 0;
    }

    void pushFront(int *val)
    {
        Node *node = new Node(val, head);
        head = node;
        size++;
        return;
    }

    void pushBack(int *val)
    {
        Node *newNode = new Node(val, NULL);
        size++;

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
        size--;
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

        size--;
        return curr->val;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return head == NULL;
    }

private:
    Node *head;
    int size;
};

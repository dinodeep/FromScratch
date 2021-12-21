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

    void prepend(int *value)
    {
        Node *node = new Node(value, head);
        head = node;
        length++;
        return;
    }

    void append(int *value)
    {
        Node *newNode = new Node(value, NULL);
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

        int *value = head->val;
        head = head->next;
        length--;
        return value;
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

int main()
{

    return 0;
}
#include "../SinglyLinkedList/singlylinkedlist.cpp"

class Stack
{
public:
    Stack()
    {
        ll = new HeadSLL();
    }

    void push(int *val)
    {
        ll->pushFront(val);
    }

    int *pop()
    {
        if (ll->isEmpty())
            return NULL;

        return ll->popFront();
    }

    int *peek()
    {
        if (ll->isEmpty())
            return NULL;

        int *val = ll->popFront();
        ll->pushFront(val);
        return val;
    }

    int getSize()
    {
        return ll->getSize();
    }

private:
    HeadSLL *ll;
};

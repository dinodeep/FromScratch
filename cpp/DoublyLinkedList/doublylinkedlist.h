

class DoublyLL
{
public:
    virtual void pushFront(int *val) = 0;
    virtual void pushBack(int *val) = 0;
    virtual int *popFront() = 0;
    virtual int *popBack() = 0;
    virtual int getSize() = 0;
    virtual bool isEmpty() = 0;
};
class Stack
{
public:
    virtual void push(int *val) = 0;
    virtual int *pop() = 0;
    virtual int *peek() = 0;
    virtual int getSize() = 0;
};
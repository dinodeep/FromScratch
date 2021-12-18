/*

GOOD DOCUMENTATION:
1. file header (name, file name, description/overview)
2. class + variable documentation
3. function documentation
    - function description
    - requires (prereqs)
    - ensures (postreqs)
4. well-written comments
    - mostly written for complicated pieces of code
    - LOOK AT 213 STYLE GUIDELINES

*/

/*
basic single linked list operations
    - key/value store
    - constructor/destructor
    - prepend
    - popFront
    - length
    - isEmpty

*/

// LOOK AT TEMPLATES
class SinglyLL
{
public:
    virtual void prepend(int key, int value) = 0;
    virtual int popFront() = 0;
    virtual int getLength() = 0;
    virtual bool isEmpty() = 0;
    virtual ~SinglyLL() = default; /* destructor */
};

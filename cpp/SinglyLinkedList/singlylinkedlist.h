/*
    Name: Deep Patel - 2021
    File Name: singlylinkedlist.h

    BRIEF:
    This file contains a pure interface for a singly-linked list class that stores values of type int
    Implementations are written in .cpp files in this directory

    Asymptotic Complexity Table by Implementation
    (HeadSLL)
    (HeadTailDLL)
        // fill in as made
*/

/*
GOOD DOCUMENTATION:
LOOK AT 213 C-STYLE GUIDELINES FOR ALL OF THIS

1. file header (name, file name, description/overview)
2. class + variable documentation
3. function documentation
    - function description
    - requires (prereqs)
    - ensures (postreqs)
4. well-written comments
    - mostly written for complicated pieces of code 
*/

// LOOK AT TEMPLATES - for generalization
class SinglyLL
{
public:
    /*
        BRIEF: adds node containing value to front of the linked list
        REQUIRES: true
        ENSURES: sll.getLength() > 0 
    */
    virtual void prepend(int *value) = 0;
    virtual void append(int *value) = 0;

    virtual int *popFront() = 0;
    virtual int *popBack() = 0;
    virtual int getLength() = 0;
    virtual bool isEmpty() = 0;
    virtual ~SinglyLL(); /* destructor */
};

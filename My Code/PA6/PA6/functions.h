/* ***       Author:  Wei Kian Chen with students in CSI-281
     *  Last Update:  October 25, 2021
     *        Class:  CSI-281
     *     Filename:  queue.h
     *
     *  Description:
     *      This is the template queue definition.
     *
     *  Certification of Authenticity:
     *     I certify that this assignment is entirely own work.
     ******************************************************************/
#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using namespace std;
template <typename T>
class Queue {
private:
    template <typename R>
    struct Node
    {
        R       mData;
        Node<R>* mNext;
        /*      Pre:  None
         *     Post:  This object is initialized using default values
         *  Purpose:  To initialize node object
         *************************************************************/
        Node()
        {
            mData = R();
            mNext = NULL;
        }
        /*      Pre:  None
         *     Post:  This object is initialized using specified data
         *  Purpose:  To initialize node object
         *************************************************************/
        Node(R data)
        {
            mData = data;
            mNext = NULL;
        }
    };
    Node<T>* mFront, * mRear;
    int     mCount;
public:
    Queue();
    ~Queue();
    int  getCount();
    void clear();
    T    dequeue();
    void display();
    void enqueue(T data);
    bool isEmpty();
    bool isExist(T searchKey);
};
/*      Pre:  The queue is instantiated
 *     Post:  Both mFront and mRear are initialized to NULL and mCount
 *            is set to zero
 *  Purpose:  To initialize queue object
 *********************************************************************/
template <typename T>
Queue<T>::Queue()
{
    mFront = NULL;
    mRear = NULL;
    mCount = 0;
}
/*      Pre:  The queue is instantiated
 *     Post:  The queue is removed and both mFront and mRear are
 *            reset to NULL and mCount is reset to zero
 *  Purpose:  To clear up a queue object
 *********************************************************************/
template <typename T>
Queue<T>::~Queue()
{
    clear();
}
/*      Pre:  The queue is instantiated
 *     Post:  The count for the queue object is returned
 *  Purpose:  To retrieve the count for a queue object
 *********************************************************************/
template <typename T>
int Queue<T>::getCount()
{
    return mCount;
}
/*      Pre:  The queue is instantiated
 *     Post:  The entire queue is cleared
 *  Purpose:  To clear the entire queue object
 *********************************************************************/
template <typename T>
void Queue<T>::clear()
{
    Node<T>* tmp;
    while (mFront != NULL)
    {
        tmp = mFront;
        mFront = mFront->mNext;
        tmp->mNext = NULL;
        delete tmp;
    }
    mRear = NULL;
    mCount = 0;
}
/*      Pre:  The queue is instantiated
 *     Post:  The data for the object in the front of the queue is
 *            returned and the node is removed
 *  Purpose:  To retrieve the data in the first node in the queue and
 *            delete the node
 *********************************************************************/
template <typename T>
T Queue<T>::dequeue()
{
    T data = T();
    Node<T>* tmp;
    if (mFront != NULL)
    {
        tmp = mFront;

        mFront = mFront->mNext;

        tmp->mNext = NULL;
        data = tmp->mData;
        delete tmp;
        mCount--;
    }
    return data;
}
/*      Pre:  The queue is instantiated
 *     Post:  The entire queue is displayed on the screen
 *  Purpose:  To display the entire queue from the front to the back
 *********************************************************************/
template <typename T>
void Queue<T>::display()
{
    Node<T>* tmp;
    if (isEmpty())
        cout << "Empty Queue\n";
    else
    {
        tmp = mFront;
        while (tmp != NULL)
        {
            cout << tmp->mData << " ";
            tmp = tmp->mNext;
        }
        cout << endl;
    }
}
/*      Pre:  The queue is instantiated
 *     Post:  A new node is added at the end of the queue
 *  Purpose:  To add a new data to the queue
 *********************************************************************/
template <typename T>
void Queue<T>::enqueue(T data)
{
    Node<T>* newNode;
    newNode = new Node<T>(data);
    if (newNode != NULL)
    {
        if (mFront == NULL)
        {
            mFront = newNode;
        }
        else
        {
            mRear->mNext = newNode;
        }
        mRear = newNode;
        mCount++;
    }
}
/*      Pre:  The queue is instantiated
 *     Post:  True if the queue is empty, otherwise false
 *  Purpose:  To determine if the queue is empty
 *********************************************************************/
template <typename T>
bool Queue<T>::isEmpty()
{
    return mCount == 0;
}
/*      Pre:  The queue is instantiated and a searchKey is available
 *     Post:  True if the searchKey existed in the queue,
 *            otherwise false
 *  Purpose:  To determine if a value existed in the queue
 *********************************************************************/
template <typename T>
bool Queue<T>::isExist(T searchKey)
{
    bool    found = false;
    Node<T>* tmp;
    if (!isEmpty())
    {
        tmp = mFront;
        while (tmp != NULL)
        {
            if (tmp->mData == searchKey)
            {
                found = true;
                break;
            }
            tmp = tmp->mNext;
        }
    }
    return found;
}
#endif


/* ***       Author:  Wei Kian Chen with students in CSI-281
     *  Last Update:  March 3, 2020
     *        Class:  CSI-281
     *     Filename:  stack.h
     *
     *  Description:
     *      This is the template stack definition.
     *
     *  Certification of Authenticity:
     *     I certify that this assignment is entirely own work.
     ******************************************************************/
#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;
template <typename T>
class Stack {
private:
    template <typename R>
    struct Node
    {
        R       mData;
        Node<R>* mNext;
        /*      Pre:  None
         *     Post:  This object is initialized using default values
         *  Purpose:  To initialize node object

*************************************************************************/
        Node()
        {
            mData = R();
            mNext = NULL;
        }
        /*      Pre:  None
         *     Post:  This object is initialized using specified data
         *  Purpose:  To initialize node object

*************************************************************************/
        Node(R data)
        {
            mData = data;
            mNext = NULL;
        }
    };
    Node<T>* mTop, * mBottom;
    int     mCount;
public:
    Stack();
    ~Stack();
    int  getCount();
    void clear();
    void display();
    bool isEmpty();
    bool isExist(T searchKey);
    T    pop();
    void push(T data);
};
/*      Pre:  The stack is instantiated
 *     Post:  Both mFont and mBottom are initialized to NULL and mCount
 *            is set to zero
 *  Purpose:  To initialize stack object
 *********************************************************************/
template <typename T>
Stack<T>::Stack()
{
    mTop = NULL;
    mBottom = NULL;
    mCount = 0;
}
/*      Pre:  The stack is instantiated
 *     Post:  The stack is removed and both mTop and mBottom are
 *            reset to NULL and mCount is reset to zero
 *  Purpose:  To clear up a stack object
 *********************************************************************/
template <typename T>
Stack<T>::~Stack()
{
    clear();
}
/*      Pre:  The stack is instantiated
 *     Post:  The count for the stack object is returned
 *  Purpose:  To retrieve the count for a stack object
 *********************************************************************/
template <typename T>
int Stack<T>::getCount()
{
    return mCount;
}
/*      Pre:  The stack is instantiated
 *     Post:  The entire stack is cleared
 *  Purpose:  To clear the entire stack object
 *********************************************************************/
template <typename T>
void Stack<T>::clear()
{
    Node<T>* tmp;
    while (mTop != NULL)
    {
        tmp = mTop;
        mTop = mTop->mNext;
        tmp->mNext = NULL;
        delete tmp;
    }
    mBottom = NULL;
    mCount = 0;
}
/*      Pre:  The stack is instantiated
 *     Post:  The entire stack is displayed on the screen
 *  Purpose:  To display the entire stack from the top to bottom
 *********************************************************************/
template <typename T>
void Stack<T>::display()
{
    Node<T>* tmp;
    if (isEmpty())
        cout << "Empty Stack\n";
    else
    {
        tmp = mTop;
        while (tmp != NULL)
        {
            cout << tmp->mData << " ";
            tmp = tmp->mNext;
        }
        cout << endl;
    }
}
/*      Pre:  The stack is instantiated
 *     Post:  True if the stack is empty, otherwise false
 *  Purpose:  To determine if the stack is empty
 *********************************************************************/
template <typename T>
bool Stack<T>::isEmpty()
{
    return mCount == 0;
}
/*      Pre:  The stack is instantiated and a searchKey is available
 *     Post:  True if the searchKey existed in the stack,
 *            otherwise false
 *  Purpose:  To determine if a value existed in the stack
 *********************************************************************/
template <typename T>
bool Stack<T>::isExist(T searchKey)
{
    bool    found = false;
    Node<T>* tmp;
    if (!isEmpty())
    {
        tmp = mTop;
        while (tmp != NULL)
        {
            if (tmp->mData == searchKey)
            {
                found = true;
                break;
            }
            tmp = tmp->mNext;
        }
    }
    return found;
}
/*      Pre:  The stack is instantiated
 *     Post:  The data for the object in the top of the stack is
 *            returned and the node is removed
 *  Purpose:  To retrieve the data in the top node in the stack and
 *            delete the node
 *********************************************************************/
template <typename T>
T Stack<T>::pop()
{
    T data = T();
    Node<T>* tmp;
    if (mTop != NULL)
    {
        tmp = mTop;
        mTop = mTop->mNext;
        tmp->mNext = NULL;
        data = tmp->mData;
        delete tmp;
        if (mTop == NULL)
            mBottom = NULL;
        mCount--;
    }
    return data;
}
/*      Pre:  The stack is instantiated
 *     Post:  A new node is added at the top of the stack
 *  Purpose:  To add a new data to the stack
 *********************************************************************/
template <typename T>
void Stack<T>::push(T data)
{
    Node<T>* newNode;
    newNode = new Node<T>(data);
    if (newNode != NULL)
    {
        if (mTop == NULL)
        {
            mBottom = newNode;
        }
        else
        {
            newNode->mNext = mTop;
        }
        mTop = newNode;
        mCount++;
    }
}
#endif

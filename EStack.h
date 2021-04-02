#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include "ExceptionStack.h"


template <typename T>
class EStack
{
private:
    T* stackPtr;
    const int size;
    int top;
public:
    EStack(int = 10);
    EStack(const EStack<T>&);
    ~EStack();

    inline void push(const T&);
    inline T pop();
    inline int getStackSize() const;
    inline T* getPtr() const;
    inline int getTop() const;

};




template <typename T>
EStack<T>::EStack(int maxSize) :
    size(maxSize)
{
    stackPtr = new T[size];
    top = 0;
}


template <typename T>
EStack<T>::EStack(const EStack<T>& otherStack) :
    size(otherStack.getStackSize())
{
    stackPtr = new T[size];
    top = otherStack.getTop();

    for (int ix = 0; ix < top; ix++)
        stackPtr[ix] = otherStack.getPtr()[ix];
}


template <typename T>
EStack<T>::~EStack()
{
    delete[] stackPtr;
}


template <typename T>
inline void EStack<T>::push(const T& value)
{
    if (size == top) { throw exc::StackOverFlow("Stack Overflow"); }

    stackPtr[top++] = value;

}


template <typename T>
inline T EStack<T>::pop()
{
    const char* Er = "Stack empty";
    if (top == NULL) { throw exc::StackEmpty("Stack Empty"); }
    stackPtr[--top];
}


template <typename T>
inline int EStack<T>::getStackSize() const
{
    return size;
}


template <typename T>
inline T* EStack<T>::getPtr() const
{
    return stackPtr;
}

template <typename T>
inline int EStack<T>::getTop() const
{
    return top;
}

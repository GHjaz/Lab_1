#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include "Exceptions.h"


/*.. Стэк реализован на массиве ..*/

template <typename T>
class EStack
{
private:
    T* stackPtr;    //.. Указатель на стэк
    int size;       //.. Размер Стэка
    int top;        //.. Номер верхушки стэка
public:
    EStack(int = 10); //.. По умолчанию размер стэка 10 элементов
    EStack(const EStack<T>&); //.. Конструктор копирования
    ~EStack();

    inline void push(const T&); //.. Закидываем в стэк
    inline T pop(); //.. Достаем из стэка
    inline int getStackSize() const;    //.. Возвращаем размер стэка
    inline T* getPtr() const;   //.. Возвращаем указатель на стэк
    inline int getTop() const; //.. Возвращаем номер верхнего элемента стэка

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
    if (!top) { throw exc::StackEmpty("Stack Empty"); }
    return stackPtr[--top];
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

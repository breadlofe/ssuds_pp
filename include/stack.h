#pragma once
#include "linkedlist.h"
#include <string>

namespace ssuds{
    template <class T>
    class Stack : private LinkedList<T>
    {
    public:
        void push(const T& val)
        {
            this->prepend(val);
        }
        using clear;
    };
}
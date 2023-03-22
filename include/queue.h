#pragma once
#include "linkedlist.h"
#include <string>

namespace ssuds{
    template <class T>
    class Queue
    {
    protected:
        LinkedList<T> mInternalList;
    public:
        void enqueue(const T& val)
        {
            mInternalList.append(val);
        }
    };
}
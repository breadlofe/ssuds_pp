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

        void dequeue()
        {
            if(mInternalList.size() > 0)
            {
                typename LinkedList<T>::Node* temp = mInternalList.mStart->mNext;
                delete mInternalList.mStart;
                mInternalList.mStart = temp;
                mInternalList.mSize--;
            }
            else
                throw std::out_of_range("Index out of range. List is empty!");
        }

        T& head()
        {
            if(mInternalList.size() > 0)
                return mInternalList[0];
            else
                throw std::out_of_range("Index out of range. List is empty!");
        }

        void clear()
        {
            while(mInternalList.size() > 0)
            {
                this->dequeue();
            }
        }

        unsigned int size()
        {
            return mInternalList.size();
        }

        bool empty()
        {
            if(mInternalList.size() == 0)
                return true;
            else
                return false;
        }
    };
}
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
        
        T& pop()
        {
            if(this->size() > 0)
            {
                T& value = this->get(0);
                typename LinkedList<T>::Node* temp = this->mStart->mNext;
                this->mStart = temp;
                this->mSize--;
                return value;
            }
            else
                throw std::out_of_range("Index out of range. List is empty!");
        }

        T& top()
        {
            if(this->size() > 0)
                return this->get(0);
            else
                throw std::out_of_range("Index out of range. List is empty!");
        }

        void clear()
        {
            while(this->size() != 0)
            {
                this->pop();
            }
        }

        bool empty()
        {
            if(this->size() == 0)
                return true;
            else
                return false;
        }

        friend std::ostream& operator<<(std::ostream& os, Stack& S)
        {
            return os << dynamic_cast<LinkedList<T>& >(S);
        }

        using LinkedList<T>::size;
        using LinkedList<T>::get;
        using LinkedList<T>::begin;
        using LinkedList<T>::end;
    };
}
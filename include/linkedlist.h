#pragma once
#include <string>

namespace ssuds{

//Decleration to use friend of class queue for has-a relationship.
template <class T>
class Queue;

///Class that holds given data in dynamic linked list. 
template <class T>
class LinkedList
{
protected:
    ///Holds individual information on nodes connecting linked list.
    class Node
    {
    public:
        ///Templated data stored in node.
        T mData;

        ///Pointer to the node after the current node
        Node* mNext;

        ///Pointer to the node before the current node
        Node* mPrev;

        ///Node constructor that assigns given value to mData and sets pointers to null.
        Node(const T& new_val)
        {
            mData = new_val;
            mNext = mPrev = nullptr;
        }
    };

    ///Node pointer that points to the very first node in the linked list.
    Node* mStart;

    ///Node pointer that points to the very last node in the linked list.
    Node* mEnd;

    ///Int that contains the size of the linked list.
    int mSize;

public:

    ///Iterator class for LinkedList
    class Iterator
    {
    protected:
        ///Int that holds position of iterator.
        int mIndex;

        ///Pointer to linked list.
        LinkedList* mList;

    public:
        ///Default constructor.
        Iterator()
        {
            //Default.
        }

        ///Constructor for iterator that takes start index and linked list pointer.
        Iterator(int index, LinkedList* linkedlist)
        {
            mIndex = index;
            mList = linkedlist;
        }

        ///Returns what value iterator is pointing at in linked list.
        T& operator*()
        {
            return (*mList)[mIndex];
        }

        ///Moves iterator one forward.
        void operator++()
        {
            if(mIndex >= mList->size() - 1)
            {
                mIndex = -1;
                mList = nullptr;
            }
            else
                mIndex++;
        }

        ///Comparison operator to see if two iterators hold same values and are pointing to same location.
        bool operator==(const Iterator& other)
        {
            if(mIndex == -1 && other.mIndex == -1)
                return true;
            else if(mIndex != -1 && other.mIndex == -1)
                return false;
            else{
                if(mList->size() != other.mList->size())
                    return false;
                for(int i =0; i < mList->size(); i++)
                {
                    if((*mList)[i] != (*other.mList)[i])
                        return false;
                }
                if((*mList)[mIndex] != (*other.mList)[other.mIndex])
                    return false;
                return true;
            }
        }

        ///Inverse of comparison operator above. 
        bool operator!=(const Iterator& other)
        {
            if(mIndex == -1 && other.mIndex == -1)
                return false;
            else if(mIndex != -1 && other.mIndex == -1)
                return true;
            else{
                if(mList->size() != other.mList->size())
                    return true;
                for(int i =0; i < mList->size(); i++)
                {
                    if((*mList)[i] != (*other.List)[i])
                        return true;
                }
                if((*mList)[mIndex] != (*other.mList)[other.mIndex])
                    return true;
                return false;
            }
        }

        ///Returns position of iterator. 
        int index()
        {
            return mIndex;
        }

    };

    ///Constructor for linked list class; sets size to 0 and pointers equal to null.
    LinkedList()
    {
        mSize = 0;
        mStart = mEnd = nullptr;
    }

    ///Destructor for linked list class; deletes individual nodes by going through linked 
    ///list one node at a time starting from the beginning.
    ~LinkedList()
    {
        Node* base = mStart;
        Node* next;
        while(base != nullptr)
        {
            next = base->mNext;
            delete base;
            base = next;
        }
    }

    ///Takes in new value and appends to end of linked list. If it is first node, start and end
    ///pointers are set to the node. If it is not the first, then the new node has previous 
    ///pointer set to the end of the pre-appended linked list, then the next pointer of that
    ///node is set to the new node. Lastly, the end is now reset to be the new node and size
    ///is increased.
    void append(const T& new_val)
    {
        Node* new_node = new Node(new_val);
        if(mSize == 0)
        {
            mStart = new_node;
            mEnd = new_node;
        }
        else
        {
            new_node->mPrev = mEnd;
            mEnd->mNext = new_node;
            mEnd = new_node;
        }
        mSize++;
    }

    ///Takes in new value and prepends it to the beginning of the linked list.
    void prepend(const T& new_val)
    {
        Node* new_node = new Node(new_val);
        if(mSize == 0)
        {
            mStart = new_node;
            mEnd = new_node;
        }
        else
        {
            new_node->mNext = mStart;
            mStart->mPrev = new_node;
            mStart = new_node;
        }
        mSize++;
    }

    ///Returns int of size of linked list.
    int size()
    {
        return mSize;
    }

    ///Takes ostream and LinkedList& and returns string of what values the linked list
    ///contains. Uses while loop to go through node by node to add values to ostream.
    friend std::ostream& operator<<(std::ostream& os, LinkedList& alist)
    {
        const LinkedList<T>::Node* cur_node = alist.mStart;
        os << "[";
        int i = 0;
        while(cur_node != nullptr)
        {
            os << cur_node->mData;
            if(i < alist.size() - 1)
            {
                os << ", ";
            }
            cur_node = cur_node->mNext;
            i++;
        }
        os << "]";
        return os;
    }

    ///Takes given index and returns value of node at that index. Goes through node by node,
    ///so it is O(n) instead of O(1).
    T& operator[](const int index)
    {
        if(index>(mSize-1) || index<0)
            throw std::out_of_range("Index out of range.");
        else
        {
            Node* cur_node = mStart;
            for(int i = 0; i < index; i++)
            {
                cur_node = cur_node->mNext;
            }
            return cur_node->mData;
        }
    }

    ///Returns iterator, if data is there, to beggining of ArrayList.
    Iterator begin()
    {
		if (mSize == 0)
			return Iterator(-1, nullptr);
		else
			return Iterator(0, this);
    }

    ///Return iterator of one after end of ArrayList.
    Iterator end()
    {
        return Iterator(-1, nullptr);
    }

    ///Takes item and returns iterator at location of item if found, returns end iterator if not. 
    Iterator find(const T item)
    {
        Node* cur_node = mStart;
        int i = 0;
        while(cur_node != nullptr)
        {
            if(cur_node->mData == item)
                return Iterator(i, this);
            i++;
            cur_node = cur_node->mNext;
        }
        return Iterator(-1, nullptr);
    }

    //Makes so I can use internal attributes in Queue.
    friend class Queue<T>;

};

}
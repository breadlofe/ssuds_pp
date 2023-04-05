#pragma once

namespace ssuds{

template <class T>
class Set
{
protected:
    class node
    {
    protected:
        T mData;
        node * mLeft, * mRight;
        node * mParent;
    public:
        node(T data) : mData(data), mLeft(NULL), mRight(NULL), mParent(NULL) {}
        void add_recursive(T val){}
    };

    node * mRoot;
    int mSize;
public:
    void add(T val)
    {
        if(mRoot == NULL)
        {
            mRoot = new node(val);
            mSize++;
        }
        else
            mRoot->add_recursive(val);
    }
};
}
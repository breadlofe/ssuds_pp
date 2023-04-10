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

        bool add_recursive(const T& val)
        {
            if(val < mData)
            {
                if(mLeft != NULL)
                {
                    return mLeft->add_recursive(val);
                }
                else
                {
                    mLeft = new node(val);
                    return true;
                }
            }
            else if(val > mData)
            {
                if(mRight != NULL)
                {
                    return mRight->add_recursive(val);
                }
                else
                {
                    mRight = new node(val);
                    return true;
                }
            }
            else
                return false;
        }

        /// @brief Recursive function for contains that checks fist if the value given
        ///         is in the root node. If not, then it checks the node to the right
        ///         and calls recusively until it there are no more right children.
        ///         It does the same for the left children as well.
        /// @param val Desired value that is being searched for in the tree.
        /// @return Returns bool representing results of if tree contains value.
        bool contains_recursive(T val)
        {
            if(mData == val) // Node we are on matches value.
                return true;
            else if(mData < val) // Go right.
            {
                if(mRight == NULL)
                    return false;
                else
                    return mRight->contains_recursive(val);
            }
            else if(mData > val) // Go left.
            {
                if(mLeft == NULL)
                    return false;
                else
                    return mLeft->contains_recursive(val);
            }
        }

        /// @brief Recursive function for height. Creates two local variables, left and right
        ///         height, and continues to increase them through recursion until both hit NULL
        ///         pointers. After, compares largest of integers and returns that.
        /// @return Returns unsigned int of largest of the local variables.
        unsigned int get_height_recursive()
        {
            unsigned int right_height = 0;
            unsigned int left_height = 0;
            if(mRight != NULL)
            {
                right_height++;
                right_height += mRight->get_height_recursive();
            }
            if(mLeft != NULL)
            {
                left_height++;
                left_height += mLeft->get_height_recursive();
            }
            if(right_height > left_height)
                return right_height;
            else
                return left_height;
        }
    };

    node * mRoot;
    int mSize;
public:
    Set() : mSize(0), mRoot(nullptr) {}

    bool add(const T& val)
    {
        if(mRoot == NULL)
        {
            mRoot = new node(val);
            mSize++;
            return true;
        }
        else
        {
            if(mRoot->add_recursive(val))
            {
                mSize++;
                return true;
            }
            else
                false;
        }
    }

    /// @brief Function that first checks if root is NULL. If not, calls contains_recursive().
    /// @param val Desired value that is being searched for by the user.
    /// @return Bool: true if value is in tree, false if not.
    bool contains(T val) 
    {
        if(mRoot == NULL)
            return false;
        else
            return mRoot->contains_recursive(val);
    }

    /// @brief Gets height of tree (single node = 1). Calls recursive function if not NULL.
    /// @return Returns unsigned int representing height of tree.
    unsigned int get_height()
    {
        if(mRoot != NULL)
        {
            unsigned int total_height = 1;
            return total_height + mRoot->get_height_recursive()
        }
        else
            return 0;
    }
};
}
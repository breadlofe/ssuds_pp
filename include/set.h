#pragma once
#include "arraylist.h"
#include "arraylist_utility.h"

namespace ssuds{

/// @brief Enum class that gives option of sorting types of traversal function.
enum class TraversalType {PRE, POST, SORT};

template <class T>
/// @brief Class of an ordered set, or tree.
class Set
{
protected:
    /// @brief Class containing the information of each individual node in the Set.
    class node
    {
    protected:
        /// @brief Data of type T stored in node class.
        T mData;

        /// @brief Pointers to children of current node.
        node * mLeft, * mRight;

        /// @brief Pointer to parent of current node.
        node * mParent;
    public:
        /// @brief Default constructor so C++ doesn't kill me. Unused.
        node() {}

        /// @brief Default constructor for node. Sets mData to given data and all
        ///         tree leaves to NULL.
        /// @param data Given data of first root node.
        node(T data) : mData(data), mLeft(nullptr), mRight(nullptr), mParent(nullptr) {}

        /// @brief Default descructor for node class. Deletes right and left for
        ///         "cascading" effect.
        ~node() 
        {
            if(mRight != nullptr)
                delete mRight;
            if(mLeft != nullptr)
                delete mLeft;
        }

        /// @brief Recursive function for add. Adds children based on the value being greater
        ///         or less than the value of what is stored in the current node.
        /// @param val Desired value to be inserted.
        /// @return Returns bool: true if value has been inserted, false if not.
        bool add_recursive(const T& val)
        {
            if(val < mData)
            {
                if(mLeft != nullptr)
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
                if(mRight != nullptr)
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
        bool contains_recursive(const T& val)
        {
            if(mData == val) // Node we are on matches value.
                return true;
            else if(mData < val) // Go right.
            {
                if(mRight == nullptr)
                    return false;
                else
                    return mRight->contains_recursive(val);
            }
            else if(mData > val) // Go left.
            {
                if(mLeft == nullptr)
                    return false;
                else
                    return mLeft->contains_recursive(val);
            }
        }

        /// @brief Recursive function for height. Creates two local variables, left and right
        ///         height, and continues to increase them through recursion until both hit nullptr
        ///         pointers. After, compares largest of integers and returns that.
        /// @return Returns unsigned int of largest of the local variables.
        unsigned int get_height_recursive()
        {
            unsigned int right_height = 0;
            unsigned int left_height = 0;
            if(mRight != nullptr)
            {
                right_height++;
                right_height += mRight->get_height_recursive();
            }
            if(mLeft != nullptr)
            {
                left_height++;
                left_height += mLeft->get_height_recursive();
            }
            if(right_height > left_height)
                return right_height;
            else
                return left_height;
        }

        /// @brief Recursive function that goes through and appends data to ArrayList.
        /// @param storage ArrayList given from original recursive function.
        /// @param tp Desired sorting type for the traversal.
        void traversal_recursive(ArrayList<T>& storage, TraversalType tp)
        {
            if(tp == TraversalType::PRE || tp == TraversalType::SORT)
            {
                storage.append(mData);
                if(mLeft != nullptr)
                    mLeft->traversal_recursive(storage, tp);
                if(mRight != nullptr) // Question 1
                    mRight->traversal_recursive(storage, tp);
            }
            else if(tp == TraversalType::POST)
            {
                if(mLeft != nullptr)
                    mLeft->traversal_recursive(storage, tp);
                if(mRight != nullptr)
                    mRight->traversal_recursive(storage, tp);
                storage.append(mData);
            }
        }

        /// @brief Recursive function for clear that sets current data to nullptr then goes to right
        ///         or left child.
        void clear_recursive()
        {
            mData = NULL;
            if(mLeft != nullptr)
            {
                mLeft->clear_recursive();
            }
            if(mRight != nullptr)
            {
                mRight->clear_recursive();
            }
        }

        /// @brief Recursive function for erase that goes through and erases value found.
        ///         3 cases are to occur: either the node to be deleted has no children, in
        ///         which case it is deleted completely; the node has one child, in which case
        ///         that child replaces the deleted node; lastly, the node has two children,
        ///         in which case the successor (left most child of right node) replaces node to
        ///         be deleted.
        /// @param val Given value to be erased.
        /// @return node*, usually nullptr to show that node has been deleted.
        node* erase_recursive(const T& val) // BAD NOT WORK
        {
            if(mData != val)
            {
                if(mLeft != nullptr)
                    mLeft = mLeft->erase_recursive(val);
                if(mRight != nullptr)
                    mRight = mRight->erase_recursive(val);
            }
            else
            {
                if(mLeft == nullptr && mRight == nullptr) //CASE 1
                {
                    return nullptr;
                }
                else if(mRight != nullptr && mLeft == nullptr) //CASE 2A
                {
                    node* temp = mRight;
                    mData = temp->mData;
                    mLeft = temp->mLeft;
                    mRight = temp->mRight;
                    delete temp;
                    return nullptr;
                }
                else if(mRight == nullptr && mLeft != nullptr) //CASE 2B
                {
                    node* temp = mLeft;
                    mData = temp->mData;
                    mLeft = temp->mLeft;
                    mRight = temp->mRight;
                    delete temp;
                    return nullptr;
                }
                else if(mLeft != nullptr && mRight != nullptr) //CASE 3
                {
                    node* temp = mRight;
                    while(temp->mLeft != nullptr)
                    {
                        temp = temp->mLeft;
                    }
                    mData = temp->mData;
                    delete temp;
                    return nullptr;
                }
                else
                {
                    throw std::out_of_range("What are you doing? How did you get here?");
                }
                return this;
            }
        }
    };

    /// @brief Pointer to the whole node which contains information of node class.
    node * mRoot;

    /// @brief Int representing the amount of nodes in the tree, NOT the height.
    int mSize;
public:
    /// @brief Default constructor for Set class. Sets mRoot to nullptr and mSize to 0.
    Set() : mSize(0), mRoot(nullptr) {}

    /// @brief Destructor for the whole set. Destroys from buttom up.
    ~Set()
    {
        delete mRoot;
    }

    /// @brief Adds, or inserts, node to tree based on value.
    /// @param val Desired value, inputed by user, to be inserted.
    /// @return Returns bool: true if insert was successful,false if not.
    bool add(const T& val)
    {
        if(mRoot == nullptr)
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

    /// @brief Function that first checks if root is nullptr. If not, calls contains_recursive().
    /// @param val Desired value that is being searched for by the user.
    /// @return Bool: true if value is in tree, false if not.
    bool contains(const T& val) 
    {
        if(mRoot == nullptr)
            return false;
        else
            return mRoot->contains_recursive(val);
    }

    /// @brief Gets height of tree (single node = 1). Calls recursive function if not NULL.
    /// @return Returns unsigned int representing height of tree.
    unsigned int get_height()
    {
        if(mRoot != nullptr)
        {
            unsigned int total_height = 1;
            return total_height + mRoot->get_height_recursive();
        }
        else
            return 0;
    }

    /// @brief Function for getting size of the set.
    /// @return Returns int for size of set.
    int size()
    {
        return mSize;
    }

    /// @brief Puts the nodes of the set into an array list of given order.
    /// @param tp Desired order for nodes to be put in array list.
    /// @return ArrayList.
    ArrayList<T> traversal(TraversalType tp)
    {
        ArrayList<T> A;
        mRoot->traversal_recursive(A, tp);
        if(tp == TraversalType::SORT)
            quicksort(A, 0, A.size()-1, ssuds::sort_type::ASCENDING);
        return A;
    }

    /// @brief Re-adds nodes into the set based on ascending sort.
    void rebalance()
    {
        ArrayList<T> A;
        A = traversal(TraversalType::SORT);
        //std::cout << A[0] << " A[0]" << std::endl;
        //std::cout << this->size() << " BEFORE" << std::endl;
        this->clear();
        //std::cout << this->size() << " AFTER" << std::endl;
        //std::cout << A.size() << " ARRAYLIST" << std::endl;
        for(int i = 0; i < A.size(); i++)
        {
            this->add(A[i]);
            //std::cout << A[i] << std::endl;
            //std::cout << this->size() << std::endl;
        }
    }

    /// @brief Calls recursive function to clear each individual node and set size to 0.
    void clear()
    {
        mRoot->clear_recursive();
        mSize = 0;
        mRoot = nullptr;
    }

    bool erase(const T& val) // BAD NOT WORK
    {
        if(!this->contains(val))
        {
            return false;
        }
        else
        {
            mSize--;
            if(mRoot->erase_recursive(val) == nullptr)
                return true;
            return false;
        }
    }
};
}
#pragma once
#include <string>

namespace ssuds{

///Class that stores given std::string in dynamic array. Allows for append, size, get, remove, remove_all, clear, and insert methods
template <class T>
class ArrayList
{
protected:

    ///Holds static value of minimum capacity allowed.
    const static int mMin_Capacity = 5;

    ///Tracks the string data held within the array. Type std::string
    T* mData;

    ///Tracks the overall size of the array. Type unsigned int
    unsigned int mSize;

    ///Tracks maximum capicity of array. Begins at 5.
    unsigned int mCapacity;

public:

    ///Iterator class for ArrayList. 
    class Iterator
    {
    protected:

        ///Tracks index pointer is at in iterator. Type int.
        int mIndex;

        ///Array list pointer that holds ArrayList.
        ArrayList* mArray;

    public:

        ///Default constructor.
        Iterator()
        {
            // Default.
        }

        ///Constructor for iterator that sets desired ArrayList and starting index.
        Iterator(int index, ArrayList* arrayList)
        {
            mIndex = index;
            mArray = arrayList;
        }

        ///Allows * operator to return value of what iterator is currently pointing to.
        T& operator*()
        {
            return (*mArray)[mIndex];
        }

        ///Moves iterator one forward in list. If at end, will set index to -1.
        void operator++()
        {
            if(mIndex >= mArray->size() - 1)
            {
                mIndex = -1;
                mArray = nullptr;
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
                if(mArray->size() != other.mArray->size())
                    return false;
                for(int i =0; i < mArray->size(); i++)
                {
                    if((*mArray)[i] != (*other.mArray)[i])
                        return false;
                }
                if((*mArray)[mIndex] != (*other.mArray)[other.mIndex])
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
                if(mArray->size() != other.mArray->size())
                    return true;
                for(int i =0; i < mArray->size(); i++)
                {
                    if((*mArray)[i] != (*other.mArray)[i])
                        return true;
                }
                if((*mArray)[mIndex] != (*other.mArray)[other.mIndex])
                    return true;
                return false;
            }
        }

    };

    ///Constructor for the array. Sets mData to nullptr and mSize to 0
    ArrayList()
    {
        mData = new T[mMin_Capacity];
        mSize = 0;
        mCapacity = mMin_Capacity;
    }

    ///Destructor for the array. Simply deletes array
    ~ArrayList()
    {
        delete[] mData;
    }

    ///Copy constructor.
    // ArrayList(const std::ArrayList<T>& alist)
    // {
    //     mCapacity = mMin_Capacity;
    //     mSize = alist.size()
    //     while(alist.size() > mCapacity)
    //     {
    //         mCapacity *= 2;
    //     }
    //     mData = new T[mCapacity];
    //     for(int i = 0; i < alist.size(); i++)
    //     {
    //         mData[i] = alist[i];
    //     }
    // }

    ///Initializer list constructor. Allows whole lists to be put in as one ArrayList.
    ArrayList(const std::initializer_list<T>& ilist)
    {
        mCapacity = mMin_Capacity;
        mSize = ilist.size();
        while(ilist.size() > mCapacity)
        {
            mCapacity *= 2;
        }
        mData = new T[mCapacity];
        for(int i = 0; i < ilist.size(); i++)
        {
            mData[i] = *(ilist.begin()+i);
        }
    }

    ///Append function for array. Adds given new_item to end of array. Array dynamically resizes
    void append(const T new_item)
    {
        if(mSize==mCapacity)
        {
            mCapacity *= 2u;
            T* temp = new T[mCapacity];
            for(int i=0; i<mSize; i++)
            {
                temp[i] = mData[i];
            }
            delete[] mData;
            mData = temp;
        }
        mData[mSize] = new_item;
        mSize++;
    }

    ///Size function that returns back int of the size of array
    int size()
    {
        return mSize;
    }

    ///Insertion function that takes new_item and index (type uint) and places new_item in given index. Resizes array and pushes back items after and on index back one place
    void insert(const T new_item, const unsigned int index)
    {
        if(index>(mSize-1) || index<0)
        {
            throw std::out_of_range("Index out of range.");
        }
        else
        {
            if(mSize==mCapacity)
            {
                mCapacity *= 2u;
                T* temp = new T[mCapacity];
                for(int i=0; i<mSize; i++)
                {
                    temp[i] = mData[i];
                }
                delete[] mData;
                mData = temp;
            }
            for(int i=mSize;i>index;i--)
            {
                mData[i] = mData[i-1];
            }
            mData[index] = new_item;
            mSize++;
        }
    }

    ///Getter for array. Returns item at given index (type uint)
    T get(const int index)
    {
      if(index>(mSize-1) || index<0)
      {
        throw std::out_of_range("Index out of range.");
      }
      else
      {
        return mData[index];
      }
    }

    ///Same as get method, but will now be able to use bracket operator in main to get item.
    T& operator[](const int index)
    {
      if(index>(mSize-1) || index<0)
        throw std::out_of_range("Index out of range.");
      else
        return mData[index];
    }

    ///Stream overload operation method. Allows array to be printed in formatted list. Must be static.
    friend std::ostream& operator<< (std::ostream& os, const ArrayList& f)
    {
        os << "[";
        for(int i=0; i<f.mSize; i++)
        {
            if(i!=(f.mSize-1))
                os << f.mData[i] << ", ";
            else
                os << f.mData[i];
        }
        os << "]";
        return os;
    }

    ///Equal operator overload. Deep copies old array and assigns it to new array (on LHS).
    ArrayList& operator=(const ArrayList& other)
    {
        if(mCapacity<other.mCapacity)
        {
            delete[] mData;
            mData = new T[other.mCapacity];
            mCapacity = other.mCapacity;
        }
        mSize = other.mSize;
        for(int i=0; i<other.mSize; i++)
        {
            mData[i] = other.mData[i];
        }
        return *this;
    }

    ///Clear function. Works similar to destructor, but resets mData and mSize variables to mMin_Capacity and 0 respectively
    void clear()
    {
        delete[] mData;
        mData = new T[mMin_Capacity];
        mSize=0;
        mCapacity=mMin_Capacity;
    }

    ///Finding function. Takes possible_item and start_index (type int) and returns int of index that matching item was in array
    int find(const T possible_item, const unsigned int start_index=0)
    {
        if(start_index>(mSize-1) || start_index<0) //had to change variable name since it defers in header and cpp file.
        {
            throw std::out_of_range("Index out of range.");
        }
        else{
        for(int i=start_index; i<mSize; i++)
        {
            if(mData[i] == possible_item)
                return i;
        }
        return -1;
        }
    }

    ///Removal function. Takes given index (type int) and removes item at index in array, then dynamically shrinks array by one
    void remove(const unsigned int index)
    {
        if(index>(mSize-1) || index<0)
        {
            throw std::out_of_range("Index out of range.");
        }
        else
        {
            if(mSize==(mCapacity/2u)&&mCapacity>=(mMin_Capacity*2u))
            {
                mCapacity /= 2u;
                T* temp = new T[mCapacity];
                for(int i=0; i<mSize; i++)
                {
                    temp[i] = mData[i];
                }
                delete[] mData;
                mData = temp;
            }
            for(int i=index; i<(mSize-1); i++)
            {
                mData[i]=mData[i+1];
            }
            mSize--;
        }
    }

    ///Similar to remove function, but instead takes item and finds all instances of it, then uses remove method to remove them
    void remove_all(const T possible_item, const unsigned int start_index = 0)
    {
        int index = 0;
        for(;;)
        {
            index = find(possible_item, start_index);
            if(index==-1)
                break;
            remove(index);
        }
    }

    ///Gets capacity. Returns as integer.
    unsigned int get_capacity()
    {
        return mCapacity;
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
};

class Foo
{
public:
    Foo(std::string name, unsigned int value)
    {
       std::string mName = name;
       unsigned int mValue = value;
    }
};

}

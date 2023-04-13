#include <functional>
namespace ssuds
{
    template <class K, class V>
    class UnorderedMap
    {
    protected:
        class node
        {
            K mKey;
            V mValue;
            node(){}
            node(K& key)
            {
                mKey = key;
            }
            node(K& key, V& value)
            {
                mKey = key;
                mValue = value;
            }
            ~node(){}
        };

        node** mTable; // An array of node*

        ///Holds static value of minimum capacity allowed.
        const static unsigned int mMin_Capacity = 10;

        unsigned int mCapacity;
        int mSize;

        bool search_helper(unsigned int* index, const K& the_key)
        {
            if(mTable[index] != the_key)
            {
                if(mTable[index] != NULL)
                {
                    (*index)++;
                    // question: will I have to check for wrap around cases?
                    return search_helper(index, the_key);
                }
                else
                    return true;
            }
            else
                return false;
        }

        node** grow_helper()
        {
            node** temp = new node*[mCapacity];
                //             for(int i=0; i<mSize; i++)
                // {
                //     temp[i] = mData[i];
                // }
                // delete[] mData;
                // mData = temp;
            for(int i=0; i<mSize; i++)
            {
                temp[i]->mValue = mTable[i]->mValue;
                temp[i]->mValue = this->operator[temp[i]->mKey]
            }
            return temp;
        }

    public:
        UnorderedMap()
        {
            mTable = new node*[mMin_Capacity];
            mSize = 0;
            mCapacity = mMin_Capacity;
        }

        ~UnorderedMap()
        {
            delete[] mTable;
        }

        V& operator[](const K& the_key)
        {
            //probably put grow here
            //find the index up here.
            std::hash<K> key_hash;
            unsigned int index = key_hash(the_key) % mCapacity;
            if(search_helper(index, the_key))
            {
                if(mSize >= (int)(mCapacity*0.7f))
                {
                    mCapacity *= 2u;
                    mTable = grow_helper();
                }
                node* new_pair = new node(the_key);
                mSize++;
                return new_pair->mValue;
            }
            else
            {
                return mTable[index]->mValue;
            }
        }
    };
}
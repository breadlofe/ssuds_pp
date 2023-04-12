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
        };

        node** mTable; // An array of Node*

        ///Holds static value of minimum capacity allowed.
        const static int mMin_Capacity = 10;

        int mCapacity;
        int mSize;

        bool search_helper(unsigned int* index, const K& the_key)
        {
            if(mTable[index] != the_key)
            {
                if(mTable[index] != NULL)
                {
                    (*index)++;
                    return search_helper(index, the_key);
                }
                else
                    return true;
            }
            else
                return false;
        }

    public:
        UnorderedMap()
        {
            mTable = new node*[mMin_Capacity];
            mSize = 0;
            mCapacity = mMin_Capacity;
        }

        V& operator[](const K& the_key)
        {
            //probably put grow here
            //find the index up here.
            std::hash<K> key_hash;
            unsigned int index = key_hash(the_key) % mCapacity;
            if(search_helper(index, the_key))
            {
                node* new_pair = new node(the_key);
                return new_pair->mValue;
            }
            else
            {
                return mTable[index]->mValue;
            }
        }
    };
}
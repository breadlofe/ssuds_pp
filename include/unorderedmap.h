#include <functional>
namespace ssuds
{
    template <class K, class V>
    class UnorderedMap
    {
    protected:
        class node
        {
        public:
            /// @brief Key of the Table of given type. Example would be "Bob" type string.
            K mKey;

            /// @brief Hash value of Key in table.
            V mValue;

            /// @brief Standard constructor for node class so C++ doesn't kill me.
            node(){}

            /// @brief Constructor that sets the key of a node class.
            /// @param key Given key.
            node(K& key)
            {
                mKey = key;
            }

            /// @brief Constructor that sets the key and hash value. Unused.
            /// @param key Given key.
            /// @param value Given hash value.
            node(K& key, V& value)
            {
                mKey = key;
                mValue = value;
            }

            /// @brief Default destructor for node class so C++ doesn't kill me.
            ~node(){}
        };

        /// @brief An array of node*
        node** mTable;

        /// @brief static value of minimum capacity allowed.
        const static unsigned int mMin_Capacity = 10;

        /// @brief Capacity that the table can hold.
        unsigned int mCapacity;

        /// @brief Current number of used slots in the table.
        int mSize;

        /// @brief Helper function for bracket operator. Finds if the given key is or is not 
        ///         in the table.
        /// @param index Unsigned int pointer that tracks the position of values in the table.
        /// @param the_key Given key that we are searching for.
        /// @return Bool: False if key found, true if not.
        bool in_table(unsigned int* index, K the_key)
        {
            // Understand that, because of the hashed index, we begin where the
            // value should be originaly placed. By checking if it is NULL first, 
            // we are saying that the slot we originally wanted to put it is empty,
            // thus it is not in the table.
            if(mTable[*index] == NULL)
                return false;
            else
            {
                if(mTable[*index]->mKey != the_key)
                {
                    (*index)++;
                    if((*index) == mCapacity)
                        (*index) = 0;
                    return in_table(index, the_key);
                }
                else
                    return true;
            }
        }

        /// @brief Helper function for bracket operator that increases capicity if 
        ///         number of used slots exceeds 70% of the previous capacity.
        /// @return An array of node*
        void grow_helper()
        {
            node** temp = mTable;
            mCapacity *= 2u;
            mTable = new node*[mCapacity];
            mSize = 0;      // Needed since we will be re-adding values.
            for(int i = 0; i < mCapacity; i++)
            {
                mTable[i] = nullptr;
            }
            for(int i = 0; i < (int)(mCapacity/2u); i++)
            {
                if(temp[i] != NULL)
                {
                    (*this)[temp[i]->mKey] = temp[i]->mValue;
                }
            }
        }

    public:
        /// @brief Default constructor for UnorederMap that sets mTable to capacity of 
        ///         mMin_Capacity and mSize to zero.
        UnorderedMap()
        {
            mTable = new node*[mMin_Capacity];
            mSize = 0;
            mCapacity = mMin_Capacity;
            for(int i = 0; i < mMin_Capacity; i++)
            {
                mTable[i] = nullptr;
            }
        }

        /// @brief Default destructor for UnorderedMap which deletes mTable as an array.
        ~UnorderedMap()
        {
            for(int i = 0; i < mCapacity; i++)
            {
                if(mTable[i] != nullptr)
                    mTable[i] = nullptr;
            }
            delete[] mTable;
        }

        /// @brief Bracket operator overload that will either insert given key in table 
        ///         and return its hash value, or returns hash value of key if it already exists
        /// @param the_key Given key that will either be inserted or searched for.
        /// @return Returns reference to hash value.
        V& operator[](K the_key)
        {
            std::hash<K> key_hash;
            if(mSize >= (int)(mCapacity*0.7f))
            {
                grow_helper();
            }
            unsigned int index = key_hash(the_key) % mCapacity;
            if(!in_table(&index, the_key))
            {
                node* new_pair = new node(the_key);
                mTable[index] = new_pair;
                mSize++;
                return new_pair->mValue;
            }
            else
            {
                return mTable[index]->mValue;
            }
        }

        /// @brief Simple function that gives capacity of map.
        /// @return unsigned int of capacity.
        unsigned int capacity()
        {
            return mCapacity;
        }

        /// @brief Simple function that gives amount of slots filled in map.
        /// @return int of mSize.
        int size()
        {
            return mSize;
        }
    };
}
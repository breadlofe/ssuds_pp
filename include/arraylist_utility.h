#pragma once
#include <string>
#include <random>
#include "arraylist.h"

namespace ssuds{

    enum class sort_type {ASCENDING, DESCENDING};

    template <class T>
    bool out_of_order(const T& val1, const T& val2, sort_type stype)
    {
        if(stype == sort_type::ASCENDING)
            return val1 > val2;
        else
            return val1 < val2;
    }

    template <class T>
    void shuffle(ArrayList<T>& alist)
    {
        int n = alist.size();
        std::default_random_engine generator;
        for(int i = (n-1); i > 0; i--)
        {
            std::uniform_int_distribution<int> distribution(0,i);
            int dice_roll = distribution(generator); 
            T temp_val = alist[i];
            alist[i] = alist[dice_roll];
            alist[dice_roll] = temp_val;
        }
    }

    template <class T>
    long int bubble_sort(ArrayList<T>& alist, sort_type stype)
    {
        int n = alist.size();
        unsigned int num_swaps = 0;
        for(int i = 0; i < (n-1); i++)
        {
            bool is_sorted = true;
            for(int j = 0; j < (n-1-i); j++)
            {
                if(out_of_order(alist[j], alist[j+1], stype))
                {
                    T temp_val = alist[j];
                    alist[j] = alist[j+1];
                    alist[j+1] = temp_val;
                    num_swaps++;
                    is_sorted = false;
                }
            }
            if(is_sorted)
                break;
        }
        return num_swaps;
    }

}
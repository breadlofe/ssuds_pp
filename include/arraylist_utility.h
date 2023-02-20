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

    template <class T>
    int binary_search(ArrayList<T>& sorted_list, T value, sort_type stype, long int* comp=nullptr)
    {
        int left_side = 0;
        int right_side = sorted_list.size() - 1;
        long int counter = 0;
        while(left_side <= right_side) //as in position, not value
        {
            int middle = (int)((right_side - left_side)/2 + left_side);
            if(sorted_list[middle] == value)
            {
                counter++;
                if(comp != nullptr)
                    *comp = counter;
                return middle;
            }
            else if(out_of_order(sorted_list[middle], value, stype)) //this is value, so should change.
            {
                counter++;
                right_side = middle - 1;
            }
            else
            {
                counter++;
                left_side = middle + 1;
            }
        }
        if(comp != nullptr)
            *comp = counter;
        return -1;
    }

    template <class T>
    void merge_sort(ArrayList<T>& alist)
    {
        merge_sort_recursive(alist, 0, alist.size()-1);
    }

    template <class T>
    void merge_sort_recursive(ArrayList<T>& alist, int left, int right)
    {
        if(left >= right)
            return;
        int middle = (int)((right_side - left_side)/2 + left_side);
        merge_sort_recursive(alist, left, middle);
        merge_sort_recursive(alist, middle + 1, right);
        merge(alist, left, middle, right);
    }

    template <class T>
    void merge(ArrayList<T>& alist, int left, int middle, int right)
    {
        return;
    }

}
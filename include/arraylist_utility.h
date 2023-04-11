#pragma once
#include <string>
#include <random>
#include "arraylist.h"

namespace ssuds{

    /// @brief enum class that makes it easy to change whether list is order in descending
    ///         or ascending order.
    enum class sort_type {ASCENDING, DESCENDING};

    /// @brief Uses the enum class to swap comparisons so order functions can order either in
    ///         ascending or descending order.
    /// @param val1 First value. 
    /// @param val2 Second value.
    /// @param stype enum class type.
    /// @return bool of comparison check.
    template <class T>
    bool out_of_order(const T& val1, const T& val2, sort_type stype)
    {
        if(stype == sort_type::ASCENDING)
            return val1 > val2;
        else
            return val1 < val2;
    }

    /// @brief Function that takes array list and shuffles elements randomly using <random>
    /// @param alist An ArrayList address.
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

    /// @brief Sorts an array list in either ascending or descending order; computes using 
    ///         bubble sort algorithm. O(n^2).
    /// @param alist ArrayList address.
    /// @param stype sort_type
    /// @return long long int of the number of swap operations performed.
    template <class T>
    long long int bubble_sort(ArrayList<T>& alist, sort_type stype)
    {
        int n = alist.size();
        long long int num_swaps = 0;
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
    long int merge_sort(ArrayList<T>& alist, sort_type stype)
    {
        long int operations = merge_sort_recursive(alist, 0, alist.size()-1, stype);
        return operations;
    }

    template <class T>
    long int merge_sort_recursive(ArrayList<T>& alist, int left, int right, sort_type stype)
    {
        if(left >= right)
            return 0;
        int middle = (int)((right - left)/2 + left);
        long int a = merge_sort_recursive(alist, left, middle, stype);
        long int b = merge_sort_recursive(alist, middle + 1, right, stype);
        long int c = merge(alist, left, middle, right, stype);
        return (a + b + c);
    }

    template <class T>
    long int merge(ArrayList<T>& alist, int left, int middle, int right, sort_type stype)
    {
        long int operations = 0;
        int n1 = middle - left + 1;
        int n2 = right - middle;
        ssuds::ArrayList<T> list1;
        ssuds::ArrayList<T> list2;
        for(int i = left; i <= middle; i++)
        {
            list1.append(alist[i]);
        }
        for(int j = (middle + 1); j <= right; j++)
        {
            list2.append(alist[j]);
        }
        int index1 = 0;
        int index2 = 0;
        int index_main = left;
        while(index1 < n1 && index2 < n2)
        {
            if(out_of_order(list2[index2], list1[index1], stype))
            {
                alist[index_main++] = list1[index1++];
                operations++;
            }
            else
            {
                alist[index_main++] = list2[index2++];
                operations++;
            }
        }
        while(index1 < n1)
        {
            alist[index_main++] = list1[index1++];
            operations++;
        }
        while(index2 < n2)
        {
            alist[index_main++] = list2[index2++];
            operations++;
        }
        return operations;
    }

    /// @brief Swap function used to swap to variables. Needs to have
    ///        pointers to actually alter variables outside function.
    /// @param a Value1 that is being swapped.
    /// @param b Value2 that is being swapped.
    template <class T>
    void swap(T* a, T* b)
    {
        T temp = *a;
        *a = *b;
        *b = temp;
    }

    template <class T>
    long int partition(ArrayList<T>& alist, int left, int right, sort_type stype, long int* op = nullptr)
    {
        T pivot = alist[right];
        int i = (left - 1);
        long int counter = 0;

        for(int j = left; j <= right - 1; j++)
        {
            if(out_of_order(pivot, alist[j], stype))
            {
                i++;
                swap(&alist[j], &alist[i]);
                counter++;
            }
        }
        swap(&alist[i + 1], &alist[right]);
        counter++;
        if(op != nullptr)
            *op += counter;
        return(i + 1);
    }

    template <class T>
    void quicksort(ArrayList<T>& alist, int left, int right, sort_type stype, long int* op = nullptr)
    {
        if(left < right)
        {
            int pi = partition(alist, left, right, stype, op);
            quicksort(alist, left, pi - 1, stype, op);
            quicksort(alist, pi + 1, right, stype, op);
        }
    }

    template <class T>
    long int heapify(ArrayList<T>& alist, int N, int i, sort_type stype)
    {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        long int counter = 0;
        if(left < N && out_of_order(alist[left], alist[largest], stype))
            largest = left;
        if(right < N && out_of_order(alist[right], alist[largest], stype))
            largest = right;
        if(largest != i)
        {
            swap(&alist[i], &alist[largest]);
            counter++;
            heapify(alist, N, largest, stype);
        }
        return counter;
    }

    template <class T>
    long int heapsort(ArrayList<T>& alist, int N, sort_type stype)
    {
        long int counter = 0;
        for(int i = N / 2 - 1; i >= 0; i--)
        {
            counter += heapify(alist, N, i, stype);
        }
        for(int i = N - 1; i >= 0; i--)
        {
            swap(&alist[0], &alist[i]);
            counter++;
            counter += heapify(alist, i, 0, stype);
        }
        return counter;
    }

    template <class T>
    void burnsort(ArrayList<T>& alist)
    {
        T max;
        T min;
        for(int j = 0; j < alist.size(); j++)
        {
            min = alist[j];
            max = alist[alist.size() - 1 - j];
            for(int i = j; i < alist.size() - j; i++)
            {
                if(alist[i] > max)
                    max = alist[i];
                if(alist[i] < min)
                    min = alist[i];
            }
            if(min < max){
            swap(&alist[alist.find(min)], &alist[j]);
            swap(&alist[alist.find(max)], &alist[alist.size() - 1 - j]);
            }
        }
    }

}
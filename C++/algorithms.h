// Copyright (c) Constantin Alexandru
// Licensed under the MIT License

#include <algorithm>

namespace algorithms{

    /*

        This section will contain different sorting algorithms

    */

    template<typename T>
    void sort(T* arr, std::size_t size)
    {
        for(std::size_t i = 0; i < size - 1; i++){
            for(std::size_t j = i + 1; j < size; j++){
                if(arr[i] > arr[j]){
                    std::swap(arr[i], arr[j]);
                }
            }
        }
    }

    template<typename T, class Compare>
    void sort(T* arr, std::size_t size, Compare comp)
    {
        for(std::size_t i = 0; i < size - 1; i++){
            for(std::size_t j = i + 1; j < size; j++){
                if(comp(arr[i], arr[j])){
                    std::swap(arr[i], arr[j]);
                }
            }
        }
    }

    template<typename T>
    void bubble_sort(T* arr, std::size_t size)
    {
        for(std::size_t i = 0; i < size; i++){
            bool swap = false;

            for(std::size_t j = 0; j < size - i - 1; j++){
                if(arr[j] > arr[j + 1]){
                    std::swap(arr[j], arr[j + 1]);
                    swap = true;
                }
            }

            if(!swap)
                return;
        }
    }

    template<typename T, class Compare>
    void bubble_sort(T* arr, std::size_t size, Compare comp)
    {
        for(std::size_t i = 0; i < size; i++){
            bool swap = false;

            for(std::size_t j = 0; j < size - i - 1; j++){
                if(comp(arr[j], arr[j + 1])){
                    std::swap(arr[j], arr[j + 1]);
                    swap = true;
                }
            }

            if(!swap)
                return;
        }
    }

    template<typename T>
    void insertion_sort(T* arr, std::size_t size)
    {
        for(std::size_t i = 1; i < size; i++){
            T key = arr[i];
            std::size_t j = i;

            while(j > 0 && arr[j - 1] > key){
                arr[j] = arr[j - 1];
                j--;
            }
            arr[j] = key;
        }
    }

    template<typename T, class Compare>
    void insertion_sort(T* arr, std::size_t size, Compare comp)
    {
        for(std::size_t i = 1; i < size; i++){
            T key = arr[i];
            std::size_t j = i;

            while(j > 0 && comp(arr[j - 1], key)){
                arr[j] = arr[j - 1];
                j--;
            }
            arr[j] = key;
        }
    }

    namespace {
        template<typename T>
        std::size_t partition (T* arr, std::size_t start, std::size_t end)
        {
            T pivot = arr[end];
            std::size_t i = (start - 1);

            for(std::size_t j = start; j < end; j++){
                if(arr[j] <= pivot){
                    i++;
                    std::swap(arr[i], arr[j]);
                }
            }

            std::swap(arr[i + 1], arr[end]);
            return (i + 1);
        }

        template<typename T, class Compare>
        std::size_t partition (T* arr, std::size_t start, std::size_t end, Compare comp)
        {
            T pivot = arr[end];
            std::size_t i = (start - 1);

            for(std::size_t j = start; j < end; j++){
                if(comp(pivot, arr[j])){
                    i++;
                    std::swap(arr[i], arr[j]);
                }
            }

            std::swap(arr[i + 1], arr[end]);
            return (i + 1);
        }

        template<typename T>
        void quick_sort(T* arr, int start, int end)
        {
            if(start < end){
                std::size_t pi = partition(arr, start, end);

                quick_sort(arr, start, pi - 1);
                quick_sort(arr, pi + 1, end);
            }
        }

        template<typename T, class Compare>
        void quick_sort(T* arr, int start, int end, Compare comp)
        {
            if(start < end){
                std::size_t pi = partition(arr, start, end, comp);

                quick_sort(arr, start, pi - 1, comp);
                quick_sort(arr, pi + 1, end, comp);
            }
        }
    }

    template<typename T>
    void quicksort(T* arr, std::size_t size)
    {
        quick_sort(arr, 0, size - 1);
    }

    template<typename T, class Compare>
    void quicksort(T* arr, std::size_t size, Compare comp)
    {
        quick_sort(arr, 0, size - 1, comp);
    }


    template<typename T>
    void selection_sort(T* arr, std::size_t size)
    {
        for(std::size_t i = 0; i < size - 1; i++){
            std::size_t imin = i;
            for(std::size_t j = i + 1; j < size; j++){
                if(arr[j] < arr[imin]){
                    imin = j;
                }
            }
            std::swap(arr[i], arr[imin]);
        }
    }

    template<typename T, class Compare>
    void selection_sort(T* arr, std::size_t size, Compare comp)
    {
        for(std::size_t i = 0; i < size - 1; i++){
            std::size_t imin = i;
            for(std::size_t j = i + 1; j < size; j++){
                if(comp(arr[imin], arr[j])){
                    imin = j;
                }
            }
            std::swap(arr[i], arr[imin]);
        }
    }
}

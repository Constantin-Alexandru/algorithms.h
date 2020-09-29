// Copyright (c) Constantin Alexandru
// Licensed under the MIT License

namespace algorithms{
    template<typename T>
    int search(T* arr, long long int size, T elem)
    {
        for(long long int i = 0; i < size; i++){
            if(arr[i] == elem)
                return i;
        }


        return -1;
    }

    template<typename T>
    int binary_search(T* arr, long long int size, T elem)
    {
        long long int start, end, mid;

        start = 0;
        end = size - 1;

        while(start <= end){
            mid = (start + end) / 2;

            if(elem == arr[mid])
                return mid;
            else if(elem < arr[mid]) end = mid - 1;
            else start = mid + 1;
        }

        return -1;
    }
}

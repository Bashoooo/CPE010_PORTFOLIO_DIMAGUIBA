#ifndef SORTING_H
#define SORTING_H
#include <thread>
#include <iostream>

template <typename T>
void insertionSort(T arr[], int arrSize){
    int k = 1, j;
    T temp;

    while (k < arrSize){
        temp = arr[k];
        j = k - 1;
        while(j >= 0 && temp <= arr[j]){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
        k++;
    }
}

template <typename T>
void merge(T arr[], int left, int middle, int right){

    int n1 = middle - left + 1;
    int n2 = right - middle;
    
    //temporary, creates 2 different arrays
    T L[n1];
    T R[n2];

    //copy to temporaries
    for(int i = 0; i < n1; i++){
        L[i] = arr[left + i];
    }

    for(int j = 0; j < n2; j++){
        R[j] = arr[middle + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    // Merge together
    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

     //Copy remaining L
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy remaining R
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

}

template <typename T>
void merge_sort(T arr[], int left, int right){
    //If N=1, Arr is already sorted
    if( left >= right){
        return;
    }

    int middle = (left + right)/2;

    merge_sort(arr, left, middle); //Call merge_sort(Arr,left,middle) =>sort first half recursively
    merge_sort(arr, middle + 1, right); //Call merge_sort(Arr,middle+1,right) => sort second half recursively
    merge(arr, left, middle, right); //Call merge(Arr, left, middle, right) to merge sorted arrays in above steps.

}






#endif
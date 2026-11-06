#include <iostream>
#include "sorting.h"
#include <thread>
#include <chrono>
#include <cstdlib>
#include <time.h>
const int maxSize = 10000; //Change this depending on the example

int main(){
    int dataset[maxSize];
    srand(time(0));
    for (int i = 0; i < maxSize; i++){
        dataset[i] = rand() % 10 + 1;
    }

    auto start = std::chrono::steady_clock::now();

    std::thread t1(insertionSort<int>, dataset, maxSize/2); //sorts one half (demonstrate parallelism)
    t1.join();
   

    auto end = std::chrono::steady_clock::now();

    auto elapsed = end - start;
    
    auto ms = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed);

    std::cout<< "Insertion Sort executed for "<< ms.count()<< " nanoseconds"<<std::endl;


    auto start2 = std::chrono::steady_clock::now();

    std::thread t2(merge_sort<int>, dataset, maxSize/2, maxSize); //sorts other half (demonstrate parallelism)
    t2.join();
    
    std::cout<<"\n";

    auto end2 = std::chrono::steady_clock::now();

    auto elapsed2 = end2 - start2;
    
    auto ms2 = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed2);

    std::cout<< "Merge sort executed for "<< ms2.count()<< " nanoseconds"<<std::endl;


    //Final Sort:
    insertionSort(dataset, maxSize); //faster since both sides are
    
    for(int i = 0; i < maxSize; i++){
        std::cout<<dataset[i]<<" ";
    }
    
    std::cout<<"\n";

    return 0;
}
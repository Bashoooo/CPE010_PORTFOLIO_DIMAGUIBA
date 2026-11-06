#include <iostream>
#include <vector>
#include <thread>

std::vector<int> numbers = {12, 45, 7, 89, 23, 56, 34, 78, 90, 11, 67, 5};
int target = 67;
int foundIndex = -1;

void linearSearch(int start, int end){
    for(int i = start; i < end; i++){
        if(numbers[i] == target){
            foundIndex = i;
            std::cout<<"Found "<<target<<" at index "<<i<<" (searched range "<<start<<"-"<<end-1<<")"<<std::endl;
            return;
        }
    }
    std::cout<<"Not found in range "<<start<<"-"<<end-1<<std::endl;
}

int main(){

    std::thread T1(linearSearch, 0, 4);
    std::thread T2(linearSearch, 4, 8);
    std::thread T3(linearSearch, 8, 12);

    T1.join();
    T2.join();
    T3.join();

    if(foundIndex == -1)
        std::cout<<"Target not found"<<std::endl;
    else
        std::cout<<"Result: "<<target<<" is at index "<<foundIndex<<std::endl;

    return 0;
}
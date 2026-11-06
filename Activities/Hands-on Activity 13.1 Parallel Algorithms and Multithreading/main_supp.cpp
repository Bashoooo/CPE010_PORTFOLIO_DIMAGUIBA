#include <iostream>
#include <vector>
#include <thread>

int globalInt = 67;

void add(int add){
    globalInt += add;
    std::cout<<globalInt<<std::endl;
}

int main(){

std::thread T1(add, 5);
std::thread T2(add, 10);
std::thread T3(add, 15);

std::cout<<globalInt<<std::endl;
T1.join();
T2.join();
T3.join();

 return 0;
}


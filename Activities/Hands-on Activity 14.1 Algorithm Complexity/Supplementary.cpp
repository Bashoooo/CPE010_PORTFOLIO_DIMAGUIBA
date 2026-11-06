#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <chrono>
#include <thread>

void linearSearch(int arrSize, int dataFind, const int list[]) {
    for (int i = 0; i < arrSize; i++) {
        if (dataFind == list[i]) {
            std::cout << "Linear Search: Searching is successful" << std::endl;
            return;
        }
    }
    std::cout << "Linear Search: Searching is Unsuccessful" << std::endl;
}

void bubbleSort(int arr[], int maxSize) {
    for (int i = 0; i < maxSize; i++) {
        for (int j = i+1; j < maxSize; j++) {
            if (arr[i] > arr[j]) {
                    std::swap(arr[i], arr[j]);
            }
        }
    }
}


void binarySearch(int arrSize, int dataFind, const int list[]) {
    int low = 0, up = arrSize - 1, middle;

    while (low <= up) {
        middle = low + (up - low) / 2;

        if (dataFind == list[middle]) {
            std::cout << "Binary Search: Searching is successful" << std::endl;
            return;
        }
        else if (dataFind < list[middle]) {
            up = middle - 1;
        }
        else {
            low = middle + 1;
        }
    }
    std::cout << "Binary Search: Searching is Unsuccessful" << std::endl;
}

const int max_size = 100000;

int main() {
    int dataset[max_size];
    int num;
    srand(time(0));

    for (int i = 0; i < max_size; i++) {
        dataset[i] = rand() % 10000 + 1;
    }
    bubbleSort(dataset, max_size);
    
    for (int i = 0; i < max_size; i++) {
        std::cout << dataset[i] << " ";
    }
    
    std::cout << "Input number to find: ";
    std::cin >> num;

    auto start = std::chrono::steady_clock::now();
    std::thread t1(linearSearch, max_size, num, dataset);
    t1.join();
    auto end = std::chrono::steady_clock::now();

    auto elapsed = end - start;
    auto ns = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed);
    std::cout << "Linear Search Function executed for " << ns.count() << " nanoseconds" << std::endl;

    
    
    auto start2 = std::chrono::steady_clock::now();
    std::thread t2(binarySearch, max_size, num, dataset);
    t2.join();
    auto end2 = std::chrono::steady_clock::now();

    auto elapsed2 = end2 - start2;
    auto ns2 = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed2); 
    std::cout << "Binary Search Function executed for " << ns2.count() << " nanoseconds" << std::endl;

    return 0;
}
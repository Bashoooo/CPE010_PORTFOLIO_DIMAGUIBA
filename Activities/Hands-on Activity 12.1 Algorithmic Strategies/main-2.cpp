#include <iostream>
#include <vector>
#include <chrono>

// m = number of rows & n = number of columns
int paths(std::vector<std::vector<int>> const &matrix, int cost);
int find(std::vector<std::vector<int>> const &matrix, int m, int n, int cost);


int main(){
    int cost;
    std::vector<std::vector<int>> matrix = {
        {4,7,1,6},
        {6,7,3,9},
        {3,8,1,2},
        {7,1,7,3}
    };
    std::cout<<"Path Finder\n\nEnter cost: ";
    std::cin>>cost;

    //start timer
    auto start = std::chrono::high_resolution_clock::now();
    //execution of func
    int total_paths = paths(matrix, cost);
    //end timer
    auto end = std::chrono::high_resolution_clock::now();
    auto duration_us = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    //will find the number of paths equal to that cost
    std::cout<<"Number of paths to get cost "<< cost<< " is: "<< paths(matrix,cost) << std::endl;
    std::cout << "Execution time: " << duration_us.count() << " microseconds" << std::endl;


    return 0;
}


int paths(std::vector<std::vector<int>> const &matrix, int cost){
    //starting case
    if(matrix.size() == 0){
        return 0;
    }

    // the matrix
    int m = matrix.size();
    int n = matrix[0].size();
    return find(matrix, m - 1, n - 1, cost);
}

int find(std::vector<std::vector<int>> const &matrix, int m, int n, int cost){

    // starting case
    if (cost < 0){
        return 0;
    }

    //checks if it is at the first cell
    if (m == 0 && n == 0){
        if (cost - matrix[0][0] == 0){
            return 1;
        }
        else {
            return 0;
        }
    }

    //finds the pathway backwards (technically still going right and down if starting from the left)
    // goes left if it is the first row
    if (m == 0) {
        return find(matrix, 0, n - 1, cost - matrix[m][n]);
    }

    //goes up if it is the first row
    if (n == 0) {
        return find(matrix, m - 1, 0, cost - matrix[m][n]);
    }

    //recursion for counting paths
    return find(matrix, m - 1, n, cost - matrix[m][n]) + find(matrix, m, n -1 , cost - matrix[m][n]);

}
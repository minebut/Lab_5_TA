#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace std::chrono;

vector<int> generateRandomArray(int size) {
    vector<int> arr(size);
    for (int& el : arr) {
        el = rand() % 10000; 
    }
    return arr;
}


pair<int, int> calculateSums(const vector<int>& arr) {
    int evenSum = 0, oddSum = 0;
    for (int el : arr) {
        if (el % 2 == 0)
            evenSum += el;
        else
            oddSum += el;
    }
    return { evenSum, oddSum };
}


int main() {
    srand(time(nullptr)); 

    vector<int> sizes = { 1000000, 5000000, 10000000, 50000000, 100000000 }; 
    int repetitions = 5; 

    for (int size : sizes) {
        long long totalDuration = 0;

        for (int i = 0; i < repetitions; ++i) {
            vector<int> arr = generateRandomArray(size);

            auto start = steady_clock::now();
            calculateSums(arr);
            auto finish = steady_clock::now();

            totalDuration += duration_cast<milliseconds>(finish - start).count();
        }

        long long averageDuration = totalDuration / repetitions;
        cout << "Size: " << size << ", Average Execution Time: " << averageDuration << " ms" << endl;
    }

    return 0;
}

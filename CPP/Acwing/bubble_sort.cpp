#include <iostream>
#include <vector>
#include <utility>

void bubbleSort(std::vector<int>& arr) {
    bool swapped;
    const size_t n = arr.size();
    
    for (size_t i = 0; i < n - 1; ++i) {
        swapped = false;
        
        for (size_t j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        
        if (!swapped) {
            break;
        }
    }
}

void printVector(const std::vector<int>& vec) {
    for (const auto& num : vec) {
        std::cout << num << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::vector<int> data = {64, 34, 25, 12, 22, 11, 90};
    
    std::cout << "Original array: ";
    printVector(data);
    
    bubbleSort(data);
    
    std::cout << "Sorted array: ";
    printVector(data);
    
    return 0;
}
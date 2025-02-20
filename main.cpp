/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/


#include <iostream>
#include <vector>
#include <sstream>
#include <cassert>
#include <chrono>
void Rec(std::vector<int>& arr, int k, int start, int depth, std::vector<int>& indices) {
    int n = arr.size();
    if (depth == k) {
        int sum = 0;
        for (int idx : indices) {
            sum += arr[idx];
        }
        if (sum == 0) {
            for (int idx : indices) {
                std::cout << idx << " ";
            }
            std::cout << std::endl;
        }
        return;
    }
    for (int i = start; i < n; ++i) {
        indices.push_back(i);
        Rec(arr, k, i + 1, depth + 1, indices);
        indices.pop_back();
    }
}

void findSubarrays(std::vector<int>& arr, int k) {
    std::vector<int> indices;
    Rec(arr, k, 0, 0, indices);
}

std::string captureOutput(std::vector<int> arr, int k) {
    std::ostringstream buffer;
    std::streambuf* prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());
    //buffer — строковый поток, куда будет направляться вывод вместо std::cout.
    //prevcoutbuf сохраняет стандартный поток вывода, чтобы потом его вернуть.
    findSubarrays(arr, k);
    std::cout.rdbuf(prevcoutbuf);
    return buffer.str();
}

void runTests() {
    // Все нули
    {
        std::vector<int> arr = {0, 0, 0};
        int k = 2;
        std::string output = captureOutput(arr, k);
        assert(!output.empty() && "Test 1 failed");
    }
    
    // Нет подмножеств с суммой 0
    {
        std::vector<int> arr = {1, 2, 3};
        int k = 2;
        std::string output = captureOutput(arr, k);
        assert(output.empty() && "Test 2 failed");
    }
    
    // Есть подмножество с суммой 0
    {
        std::vector<int> arr = {1, -1, 2, -2};
        int k = 2;
        std::string output = captureOutput(arr, k);
        assert(!output.empty() && "Test 3 failed");
    }
    
    // Один элемент 0
    {
        std::vector<int> arr = {0};
        int k = 1;
        std::string output = captureOutput(arr, k);
        assert(!output.empty() && "Test 4 failed");
    }
    
    //  Большие значения
    {
        std::vector<int> arr = {1000000, -1000000, 500000, -500000};
        int k = 2;
        std::string output = captureOutput(arr, k);
        assert(!output.empty() && "Test 5 failed");
    }
    
    // Пустой массив
    {
        std::vector<int> arr = {};
        int k = 1;
        std::string output = captureOutput(arr, k);
        assert(output.empty() && "Test 6 failed");
    }
    
    // k больше, чем размер массива
    {
        std::vector<int> arr = {1, -1};
        int k = 3;
        std::string output = captureOutput(arr, k);
        assert(output.empty() && "Test 7 failed");
    }
    
    std::cout << "All tests passed!\n";
}

int main() {
    runTests();

    int n, k;
    std::cin >> n;
    std::cin >> k;

    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    auto start = std::chrono::high_resolution_clock::now();
    findSubarrays(arr, k);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    std::cout << "Execution time: " << duration.count() << " ms" << std::endl;
}

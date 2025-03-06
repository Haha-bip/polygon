/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>

// Подсчет числа связей
std::vector<int> countConnections(const std::vector<std::vector<int>>& adjacencyMatrix) {
    int n = adjacencyMatrix.size();
    std::vector<int> connections(n, 0);
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (adjacencyMatrix[i][j] == 1) {
                connections[i]++;
            }
        }
    }
    return connections;
}

int main() {
    int n;
    std::cin >> n; // Ввод количества вершин графа
    
    std::vector<std::vector<int>> adjacencyMatrix(n, std::vector<int>(n));
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> adjacencyMatrix[i][j];
        }
    } // Задание связей между вершинами графа
    
    std::vector<int> connections = countConnections(adjacencyMatrix);
    
    for (int i = 0; i < n; ++i) {
        std::cout << "Unit " << i << ": " << connections[i]  << std::endl;
    } // Вывод результата
    
    return 0;
}

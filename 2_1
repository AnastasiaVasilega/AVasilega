#include <iostream>
#include <vector>
#include <string>

template <typename T>
void Print(const T& container, const std::string& delimiter) {
 for (auto it = container.begin(); it != container.end(); ++it) {
    std::cout << *it << delimiter;
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> data = {1, 2, 3};
    Print(data, ", ");  // Вывод: 1, 2, 3
    return 0;
}
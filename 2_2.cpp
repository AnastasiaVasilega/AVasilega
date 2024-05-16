#include <iostream>
#include <vector>
#include <algorithm>

void splitAndSort(const std::vector<int>& original, std::vector<int>& positive, std::vector<int>& negative) {
    for (int num : original) {
        if (num >= 0) {
            positive.push_back(num);
        } else {
            negative.push_back(num);
        }
    }

    std::sort(positive.begin(), positive.end());
    std::sort(negative.begin(), negative.end());
}

int main() {
    std::vector<int> original = {3, -1, 5, -2, 7, -4};

    std::vector<int> positive;
    std::vector<int> negative;

    splitAndSort(original, positive, negative);

    std::cout << "Положительные элементы: ";
    for (int num : positive) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "Отрицательные элементы: ";
    for (int num : negative) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
#include <iostream>
#include <map>
#include <string>

int main() {
    int N;
    std::cin >> N;

    std::map<std::string, int> heights; //отображение между именем элемента в генеалогическом древе и его высотой
    std::map<std::string, std::string> parents; // отображение между именами детей и их родителей.

    for (int i = 0; i < N - 1; ++i) {
        std::string child, parent;
        std::cin >> child >> parent;
        parents[child] = parent;
    } //добавляет в ассоциативный контейнер parents пару ключ(child)-значение(parent)

    // Находим высоту каждого элемента
    for (const auto& pair : parents) {
        std::string child = pair.first;
        std::string parent = pair.second;

        int height = 0;
        while (parent != "") {
            height++;
            parent = parents[parent];
        }
        heights[child] = height;
    }

    // Выводим элементы в лексикографическом порядке с их высотой
    for (const auto& pair : heights) {
        std::cout << pair.first << " " << pair.second << std::endl;
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <thread>
#include <algorithm>

// Функция для сортировки части массива
void sortPart(std::vector<int>& arr, size_t start, size_t end) {
    std::sort(arr.begin() + start, arr.begin() + end);
}

int main() {
    const int size = 1000;
    std::vector<int> numbers(size);

    // Заполнение массива случайными числами
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 1000);
    for (int i = 0; i < size; ++i) {
        numbers[i] = dis(gen);
    }

    // Разбиваем массив на две части и запускаем два потока для сортировки каждой части
    std::thread thread1(sortPart, std::ref(numbers), 0, size / 2);
    std::thread thread2(sortPart, std::ref(numbers), size / 2, size);

    //ожидание завершения работы определенного потока, прежде чем продолжить выполнение основного потока или других операций
    thread1.join();
    thread2.join();

    // Объединяем отсортированные части массива
    std::inplace_merge(numbers.begin(), numbers.begin() + size / 2, numbers.end());

    // Вывод отсортированного массива
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
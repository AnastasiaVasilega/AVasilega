#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>

int main() {
    // Создание генератора случайных чисел
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1, 10000);

    // Создание контейнера и заполнение случайными числами
    std::vector<int> numbers;
    for (int i = 0; i < 10000; ++i) {
        numbers.push_back(dis(gen));
    }

    // Копирование контейнера для каждой сортировки
    std::vector<int> numbers_copy1 = numbers;
    std::vector<int> numbers_copy2 = numbers;

    // Измерение времени для первой сортировки (например, сортировка пузырьком)
    auto start1 = std::chrono::steady_clock::now();
    // Здесь вызывается функция сортировки пузырьком
    auto end1 = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed1 = end1 - start1;

    // Измерение времени для второй сортировки (например, быстрая сортировка)
    auto start2 = std::chrono::steady_clock::now();
    // Здесь вызывается функция быстрой сортировки
    auto end2 = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed2 = end2 - start2;

    // Вывод результатов
    if (elapsed1 < elapsed2) {
        std::cout << "Сортировка 1 быстрее. Время: " << elapsed1.count() << " секунд" << std::endl;
    } else {
        std::cout << "Сортировка 2 быстрее. Время: " << elapsed2.count() << " секунд" << std::endl;
    }

    return 0;
}
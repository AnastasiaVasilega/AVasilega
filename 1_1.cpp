#include <iostream>
#include <vector>

int binarySearch(const std::vector<int>& arr, int key) {
    int left = 0;
    int right = arr.size() - 1; //тк нам нужен индекс, а size равняется длине

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            left = mid + 1; // отбрасываем всё, что меньше ключа
        } else {
            right = mid - 1; //отбрасываем всё, что больше ключа
        }
    }

    return -1; // Возвращаем -1, если элемент не найден
}

int main() {
    std::vector<int> arr = {1, 3, 5, 7, 9, 11, 13, 15};
    int target = 7;

    int result = binarySearch(arr, target);

    if (result != -1) {
        std::cout << "Элемент найден на позиции " << result << std::endl;
    } else {
        std::cout << "Элемент не найден" << std::endl;
    }

    return 0;
}
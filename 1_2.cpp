#include <iostream>
#include <unordered_set>

bool isHappy(int n) {
    std::unordered_set<int> seen; //создает пустой набор (set) для хранения уникальных целых чисел.

    while (n != 1 && seen.find(n) == seen.end()) { //проверяет, содержится ли значение n в множестве seen. Если find 
    //вернет итератор, указывающий за последний элемент, это означает, что значение n отсутствует в множестве.
        seen.insert(n);
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        n = sum;
    }

    return n == 1;
}

int main() {
    int num;
    std::cout << "Введите натуральное число: ";
    std::cin >> num;

    if (isHappy(num)) {
        std::cout << num << " является счастливым числом." << std::endl;
    } else {
        std::cout << num << " не является счастливым числом." << std::endl;
    }
    return 0;
}
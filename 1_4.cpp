#include <iostream>
#include <vector>
using namespace std;

void factorialRepresentation(int N) {
    vector<int> factorialDigits;
    int factorial = 1;
    while (N > 0) {
        factorialDigits.push_back(N % (factorial + 1));
        N /= (factorial + 1);
        factorial++;
    }
    for (int i = factorialDigits.size() - 1; i >= 0; i--) {
        if (i != factorialDigits.size() - 1) {
            cout << ".";
        }
        cout << factorialDigits[i];
    }
}

int main() {
    int number;
    cout << "Введите натуральное число: ";
    cin >> number;
    cout << "Представление в факториальной системе счисления: ";
    factorialRepresentation(number);
    return 0;
}
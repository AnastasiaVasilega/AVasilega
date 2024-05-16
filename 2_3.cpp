#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <algorithm>

std::string mostFrequentWord(const std::string& text) {
    std::map<std::string, int> wordFrequency;
    std::istringstream iss(text);
    std::string word;

    while (iss >> word) {
        // Приводим слово к нижнему регистру
        std::transform(word.begin(), word.end(), word.begin(), ::tolower); //диапазон, который нужно преобразовать,
        // 3е - начало диапазона, в который будут записываться результаты преобразования
        
        // Исключаем знаки пунктуации
        word.erase(std::remove_if(word.begin(), word.end(), ::ispunct), word.end()); //все символы пунктуации будут перемещены в конец диапазона
        // Увеличиваем частоту слова
        wordFrequency[word]++;
    }

    std::string mostFrequent;
    int maxFrequency = 0;

    for (const auto& pair : wordFrequency) // пара ключ-значение из контейнера 
    {
        if (pair.second > maxFrequency || (pair.second == maxFrequency && pair.first < mostFrequent)) {
            mostFrequent = pair.first;
            maxFrequency = pair.second;
        } //ключ - слово и значение - частота
    }

    return mostFrequent;
}

int main() {
    std::string text = "This is a sample text. It contains some words, and some words are repeated more often than others.";

    std::string mostFrequent = mostFrequentWord(text);

    std::cout << "Слово, которое встречается чаще всего и меньше всего в лексикографическом порядке: " << mostFrequent << std::endl;

    return 0;
}
#include <iostream>
#include <string>

#define TABLE_SIZE 10

class HashTable {
private:
    std::string* keys;
    int* values;
    int capacity;

    int hashFunction(const std::string& key) {
        int hash = 0;
        for (char c : key) {
            hash += c;
        }
        return hash % capacity;
    }

public:
    HashTable() {
        capacity = TABLE_SIZE;
        keys = new std::string[capacity];
        values = new int[capacity];
    }

    void insert(const std::string& key, int value) {
        int index = hashFunction(key);
        
        while (keys[index] != "") {
            index = (index + 1) % capacity;
        }

        keys[index] = key;
        values[index] = value;
    }
    // метод разрешения коллизий "Открытая адресация" (Linear Probing)

    int search(const std::string& key) {
        int index = hashFunction(key);

        while (keys[index] != "") {
            if (keys[index] == key) {
                return values[index];
            }
            index = (index + 1) % capacity;
        }

        return -1; // Ключ не найден
    }

};

int main() {
    HashTable hashtable;

    hashtable.insert("apple", 5);
    hashtable.insert("banana", 7);
    
    std::cout << "Value for key 'apple': " << hashtable.search("apple") << std::endl;
    std::cout << "Value for key 'banana': " << hashtable.search("banana") << std::endl;
    std::cout << "Value for key 'grape': " << hashtable.search("grape") << std::endl;

    return 0;
}
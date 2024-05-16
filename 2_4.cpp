#include <iostream>
#include <stack>
#include <string>

bool isValidParentheses(const std::string& s) {
    std::stack<char> st;

    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else if (c == ')' && !st.empty() && st.top() == '(')
        {
            st.pop(); 
        }
        //!st.empty() - проверка на то, пуст ли контейнер st. 
        // st.top() возвращает значение верхнего элемента стека, но не удаляет его из стека
        //st.pop() При вызове этого метода верхний элемент стека удаляется, и стек уменьшается на один элемент
         
         else if (c == ']' && !st.empty() && st.top() == '[') {
            st.pop();
        } else if (c == '}' && !st.empty() && st.top() == '{') {
            st.pop();
        } else {
            return false;
        }
    }

    return st.empty();
}

int main() {
    std::string input;
    std::cout << "Введите скобочную последовательность: ";
    std::cin >> input;

    if (isValidParentheses(input)) {
        std::cout << "Скобочная последовательность правильная." << std::endl;
    } else {
        std::cout << "Скобочная последовательность неправильная." << std::endl;
    }

    return 0;
}
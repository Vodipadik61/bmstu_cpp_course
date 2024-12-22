#include <cstring>
#include <iostream>

class SimpleString {
public:
    // Конструктор по умолчанию
    SimpleString() : data(nullptr), length(0) {}

    // Конструктор из C-строки
    SimpleString(const char* str) {
        if (str) {
            length = std::strlen(str);
            data = new char[length + 1];
            std::strcpy(data, str);
        } else {
            data = nullptr;
            length = 0;
        }
    }

    // Конструктор копирования
    SimpleString(const SimpleString& other) {
        length = other.length;
        if (length > 0) {
            data = new char[length + 1];
            std::strcpy(data, other.data);
        } else {
            data = nullptr;
        }
    }

    // Оператор присваивания
    SimpleString& operator=(const SimpleString& other) {
        if (this != &other) {
            delete[] data; // Освобождаем старую память
            length = other.length;
            if (length > 0) {
                data = new char[length + 1];
                std::strcpy(data, other.data);
            } else {
                data = nullptr;
            }
        }
        return *this;
    }

    // Деструктор
    ~SimpleString() {
        delete[] data;
    }

    // Получение длины строки
    size_t size() const {
        return length;
    }

    // Индексатор
    char& operator[](size_t index) {
        return data[index];
    }

    const char& operator[](size_t index) const {
        return data[index];
    }

    // Преобразование в C-строку
    const char* c_str() const {
        return data ? data : "";
    }

    // Оператор сложения
    SimpleString operator+(const SimpleString& other) const {
        SimpleString result;
        result.length = length + other.length;
        result.data = new char[result.length + 1];
        if (data) {
            std::strcpy(result.data, data);
        }
        if (other.data) {
            std::strcat(result.data, other.data);
        }
        return result;
    }

    // Оператор сравнения
    bool operator==(const SimpleString& other) const {
        if (length != other.length) return false;
        return std::strcmp(data, other.data) == 0;
    }

private:
    char* data; // Указатель на массив символов
    size_t length; // Длина строки
};

// Пример использования
int main() {
    SimpleString str1("Hello");
    SimpleString str2(" World");
    SimpleString str3 = str1 + str2;

    std::cout << str3.c_str() << std::endl; // Вывод: Hello World
    return 0;
}

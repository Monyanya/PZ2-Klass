#include <iostream>
#include <windows.h>
using namespace std;


class DynamicArray {
private:
    int* data;
    int size;

public:
    DynamicArray(int n) {
        size = (n > 0) ? n : 0;
        data = (size > 0) ? new int[size] : nullptr;
        for (int i = 0; i < size; i++) data[i] = 0;
    }

    DynamicArray(const DynamicArray& other) {
        size = other.size;
        data = new int[size];
        for (int i = 0; i < size; i++) data[i] = other.data[i];
    }

    ~DynamicArray() {
        delete[] data;
    }

    void setValue(int index, int value) {
        if (index < 0 || index >= size) {
            cout << "Ошибка индекса!" << endl;
            return;
        }
        if (value < -100 || value > 100) {
            cout << "Ошибка диапазона!" << endl;
            return;
        }
        data[index] = value;
    }

    void print() const {
        for (int i = 0; i < size; i++) cout << data[i] << " ";
        cout << endl;
    }

    // Сложение массивов
    DynamicArray add(const DynamicArray& other) const {
        int maxSize = (size > other.size) ? size : other.size;
        DynamicArray result(maxSize);

        for (int i = 0; i < maxSize; i++) {
            int valA = (i < size) ? data[i] : 0;
            int valB = (i < other.size) ? other.data[i] : 0;
            result.data[i] = valA + valB;
        }
        return result;
    }

    // Вычитание массивов
    DynamicArray subtract(const DynamicArray& other) const {
        int maxSize = (size > other.size) ? size : other.size;
        DynamicArray result(maxSize);

        for (int i = 0; i < maxSize; i++) {
            int valA = (i < size) ? data[i] : 0;
            int valB = (i < other.size) ? other.data[i] : 0;
            result.data[i] = valA - valB;
        }
        return result;
    }
};

int main() {
    SetConsoleOutputCP(CP_UTF8);

    cout << "=== Тест ЗАДАНИЕ 4 ===" << endl;

    DynamicArray a(3);
    a.setValue(0, 10);
    a.setValue(1, 20);
    a.setValue(2, 30);

    DynamicArray b(5);
    b.setValue(0, 1);
    b.setValue(1, 2);
    b.setValue(2, 3);
    b.setValue(3, 4);
    b.setValue(4, 5);

    cout << "A: "; a.print();
    cout << "B: "; b.print();

    DynamicArray sum = a.add(b);
    cout << "A + B: "; sum.print();

    DynamicArray diff = a.subtract(b);
    cout << "A - B: "; diff.print();

    return 0;
}

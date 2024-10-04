// ConsoleApplication3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void push_front(int value) {
        Node* new_node = new Node(value);
        if (!head) {
            head = tail = new_node;
        }
        else {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
    }

    void push_back(int value) {
        Node* new_node = new Node(value);
        if (!tail) {
            head = tail = new_node;
        }
        else {
            new_node->prev = tail;
            tail->next = new_node;
            tail = new_node;
        }
    }

    int pop_front() {
        if (!head) return -1;
        int value = head->data;
        Node* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        delete temp;
        return value;
    }

    int pop_back() {
        if (!tail) return -1;
        int value = tail->data;
        Node* temp = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;
        delete temp;
        return value;
    }

    void display() {
        Node* current = head;
        std::cout << "Список: ";
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    void sort() {
        if (!head || !head->next) return;

        bool sorted;
        do {
            sorted = true;
            Node* current = head;
            while (current && current->next) {
                if (current->data > current->next->data) {
                    std::swap(current->data, current->next->data);
                    sorted = false;
                }
                current = current->next;
            }
        } while (!sorted);
    }

    void remove_duplicates() {
        Node* current = head;
        while (current) {
            Node* runner = current->next;
            while (runner) {
                if (runner->data == current->data) {
                    if (runner->prev) runner->prev->next = runner->next;
                    if (runner->next) runner->next->prev = runner->prev;
                    if (runner == tail) tail = runner->prev;
                    if (runner == head) head = runner->next;
                    Node* toDelete = runner;
                    runner = runner->next;
                    delete toDelete;
                }
                else {
                    runner = runner->next;
                }
            }
            current = current->next;
        }
    }


private:
    Node* head;
    Node* tail;
};

void menu() {
    DoublyLinkedList dll;
    while (true) {
        std::cout << "\nМеню:\n";
        std::cout << "1. Добавить элемент в начало.\n";
        std::cout << "2. Добавить элемент в конец.\n";
        std::cout << "3. Удалить элемент с начала.\n";
        std::cout << "4. Удалить элемент с конца.\n";
        std::cout << "5. Отобразить список.\n";
        std::cout << "6. Сортировать список.\n";
        std::cout << "7. Удалить дубликаты.\n";
        std::cout << "8. Выйти.\n";

        int choice;
        std::cout << "Выберите опцию (1-8): ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            int value;
            std::cout << "Введите значение: ";
            std::cin >> value;
            dll.push_front(value);
            break;
        }
        case 2: {
            int value;
            std::cout << "Введите значение: ";
            std::cin >> value;
            dll.push_back(value);
            break;
        }
        case 3: {
            int value = dll.pop_front();
            if (value != -1) {
                std::cout << "Удалено: " << value << std::endl;
            }
            else {
                std::cout << "Список пуст." << std::endl;
            }
            break;
        }
        case 4: {
            int value = dll.pop_back();
            if (value != -1) {
                std::cout << "Удалено: " << value << std::endl;
            }
            else {
                std::cout << "Список пуст." << std::endl;
            }
            break;
        }
        case 5: {
            dll.display();
            break;
        }
        case 6: {
            dll.sort();
            std::cout << "Список отсортирован." << std::endl;
            break;
        }
        case 7: {
            dll.remove_duplicates();
            std::cout << "Дубликаты удалены." << std::endl;
            break;
        }
        case 8: {
            std::cout << "Выход из программы." << std::endl;
            return;
        }
        default:
            std::cout << "Неверный выбор. Пожалуйста, попробуйте еще раз." << std::endl;
        }
    }
}

int main() {
    menu();
    return 0;
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

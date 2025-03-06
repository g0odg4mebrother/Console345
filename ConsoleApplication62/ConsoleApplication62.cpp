#include <iostream>
#include <string>

using namespace std;

class Airplane {
private:
    string type;
    int maxPassengers;
    int currentPassengers;
public:
    Airplane(const string& t, int m) : type(t), maxPassengers(m), currentPassengers(0) {}

    const string& getType() const { return type; }
    int getMaxPassengers() const { return maxPassengers; }
    int getCurrentPassengers() const { return currentPassengers; }

    void operator++() {
        if (currentPassengers < maxPassengers) {
            ++currentPassengers;
        }
        else {
            cout << "Ошибка: невозможно добавить больше пассажиров, самолет заполнен." << endl;
        }
    }

    void operator--() {
        if (currentPassengers > 0) {
            --currentPassengers;
        }
        else {
            cout << "Ошибка: невозможно удалить пассажиров, самолет пуст." << endl;
        }
    }

    bool operator>(const Airplane& other) const {
        return maxPassengers > other.maxPassengers;
    }

    bool operator==(const Airplane& other) const {
        return type == other.type;
    }
};

void displayMenu(Airplane& plane1, Airplane& plane2) {
    system("cls"); 

    cout << "Меню управления самолетами:\n";
    cout << "1. Добавить пассажиров на первый самолет\n";
    cout << "2. Удалить пассажиров с первого самолета\n";
    cout << "3. Сравнить самолеты по максимальной вместимости\n";
    cout << "4. Проверить равенство типов самолетов\n";
    cout << "5. Показать текущие данные о первом самолете\n";
    cout << "6. Выход\n";
    cout << "Выберите действие (1-6): ";
}

int main() {
    setlocale(LC_ALL, "");

    Airplane plane1("Boeing 737", 200);
    Airplane plane2("Airbus A320", 180);

    int choice;
    do {
        displayMenu(plane1, plane2); 

        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Сколько пассажиров хотите добавить? ";
            int passengersToAdd;
            cin >> passengersToAdd;
            for (int i = 0; i < passengersToAdd; ++i) {
                ++plane1;
            }
            break;
        case 2:
            cout << "Сколько пассажиров хотите удалить? ";
            int passengersToRemove;
            cin >> passengersToRemove;
            for (int i = 0; i < passengersToRemove; ++i) {
                --plane1;
            }
            break;
        case 3:
            if (plane1 > plane2) {
                cout << "Первый самолет имеет большую максимальную вместимость, чем второй.\n";
            }
            else {
                cout << "Второй самолет имеет такую же или большую максимальную вместимость, чем первый.\n";
            }
            break;
        case 4:
            if (plane1 == plane2) {
                cout << "Самолеты одного типа.\n";
            }
            else {
                cout << "Самолеты разных типов.\n";
            }
            break;
        case 5:
            cout << "Тип первого самолета: " << plane1.getType() << endl;
            cout << "Максимальная вместимость первого самолета: " << plane1.getMaxPassengers() << endl;
            cout << "Текущая загрузка первого самолета: " << plane1.getCurrentPassengers() << endl;
            break;
        case 6:
            cout << "Завершение программы...\n";
            break;
        default:
            cout << "Неверный выбор. Попробуйте снова.\n";
        }

        if (choice != 6) {
            cout << "Нажмите любую клавишу для продолжения...";

        }
    } while (choice != 6);

    return 0;
}

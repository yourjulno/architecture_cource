#include <iostream>
#include <memory>
#include <limits>
#include <vector>
#include <Zoo.h>

using namespace jul::animals;

void display_main_menu() {
    std::cout << "\n=== МОСКОВСКИЙ ЗООПАРК - СИСТЕМА УЧЕТА ===\n";
    std::cout << "1. Добавить животное\n";
    std::cout << "2. Добавить вещь\n";
    std::cout << "3. Показать всех животных\n";
    std::cout << "4. Показать все вещи\n";
    std::cout << "5. Общее потребление еды\n";
    std::cout << "6. Полная инвентаризация\n";
    std::cout << "7. Выход\n";
    std::cout << "Выберите опцию: ";
}

std::shared_ptr<Animal> create_animal_interactive() {
    std::cout << "\n=== ДОБАВЛЕНИЕ ЖИВОТНОГО ===\n";
    std::cout << "1. Обезьяна\n";
    std::cout << "2. Кролик\n";
    std::cout << "3. Тигр\n";
    std::cout << "4. Волк\n";
    std::cout << "Выберите тип животного: ";

    int type;
    std::cin >> type;

    if (type < 1 || type > 4) {
        std::cout << "Неверный выбор!\n";
        return nullptr;
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string name;
    int food;
    bool healthy = true;

    std::cout << "Введите имя животного: ";
    std::getline(std::cin, name);

    std::cout << "Введите потребление еды (кг/день): ";
    std::cin >> food;

    std::cout << "Животное здорово? (1 - да, 0 - нет): ";
    std::cin >> healthy;

    std::shared_ptr<Animal> animal;

    switch(type) {
        case 1: { // Обезьяна
            animal = std::make_shared<Monkey>(name, food, healthy);
            break;
        }
        case 2: { // Кролик
            animal = std::make_shared<Rabbit>(name, food, healthy);
            break;
        }
        case 3: { // Тигр
            animal = std::make_shared<Tiger>(name, food, healthy);
            break;
        }
        case 4: { // Волк
            animal = std::make_shared<Wolf>(name, food, healthy);
            break;
        }
    }

    std::cout << "Животное создано успешно!\n";
    return animal;
}

std::shared_ptr<Thing> create_thing_interactive() {
    std::cout << "\n=== ДОБАВЛЕНИЕ ВЕЩИ ===\n";
    std::cout << "1. Стол\n";
    std::cout << "2. Компьютер\n";
    std::cout << "Выберите тип вещи: ";

    int type;
    std::cin >> type;

    if (type < 1 || type > 2) {
        std::cout << "Неверный выбор!\n";
        return nullptr;
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string name;
    int inventory_number;

    std::cout << "Введите название вещи: ";
    std::getline(std::cin, name);

    std::cout << "Введите инвентарный номер: ";
    std::cin >> inventory_number;

    std::shared_ptr<Thing> thing;

    switch(type) {
        case 1: { // Стол
            thing = std::make_shared<Table>(name, inventory_number);
            break;
        }
        case 2: { // Компьютер
            thing = std::make_shared<Computer>(name, inventory_number);
            break;
        }
    }

    std::cout << "Вещь создана успешно!\n";
    return thing;
}


void configureContainer(DiContainer& container) {
    container.register_type<IVeterinaryClinic, VeterinaryClinic>();
    container.register_factory<Zoo>([]() {
        auto clinic = std::make_shared<VeterinaryClinic>();
        auto diContainer = std::make_shared<DiContainer>();
        return std::make_shared<Zoo>(clinic, diContainer);
    });
}

int main() {
    try {

        DiContainer container;
        configureContainer(container);

        auto zoo = container.resolve<Zoo>();

        std::cout << "=== СИСТЕМА УЧЕТА МОСКОВСКОГО ЗООПАРКА ===\n";
        std::cout << "Система успешно инициализирована!\n";

        int choice;
        do {
            display_main_menu();
            std::cin >> choice;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            switch(choice) {
                case 1: { // Добавить животное
                    auto animal = create_animal_interactive();
                    if (animal) {
                        if (zoo->add_animal(animal)) {
                            std::cout << "✓ Животное успешно добавлено в зоопарк!\n";
                        } else {
                            std::cout << "✗ Животное не прошло ветеринарную проверку и не добавлено!\n";
                        }
                    }
                    break;
                }
                case 2: { // Добавить вещь
                    auto thing = create_thing_interactive();
                    if (thing) {
                        zoo->add_thing(thing);
                        std::cout << "✓ Вещь успешно добавлена в инвентарь!\n";
                    }
                    break;
                }
                case 3: // Показать всех животных
                    std::cout << "\n=== СПИСОК ВСЕХ ЖИВОТНЫХ ===\n";
                    zoo->display_all_animals();
                    break;
                case 4: // Показать все вещи
                    std::cout << "\n=== СПИСОК ВСЕХ ВЕЩЕЙ ===\n";
                    zoo->display_inventory();
                    break;
                case 6: // Общее потребление еды
                    std::cout << "\n=== ОБЩЕЕ ПОТРЕБЛЕНИЕ ЕДЫ ===\n";
                    std::cout << "Все животные потребляют: " << zoo->get_full_food() << " кг/день\n";
                    break;
                case 7: // Полная инвентаризация
                    std::cout << "\n=== ПОЛНАЯ ИНВЕНТАРИЗАЦИЯ ===\n";
                    zoo->display_inventory();
                    std::cout << "---\n";
                    std::cout << "Общее потребление еды: " << zoo->get_full_food() << " кг/день\n";
                    break;
                case 8: // Выход
                    std::cout << "Выход из системы...\n";
                    break;
                default:
                    std::cout << "Неверный выбор! Попробуйте снова.\n";
            }

            if (choice != 8) {
                std::cout << "\nНажмите Enter для продолжения...";
                std::cin.get();
            }

        } while (choice != 8);

        std::cout << "До свидания!\n";

    } catch (const std::exception& e) {
        std::cerr << "Критическая ошибка: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
#include "func.h"

void menu()
{
    int choice;
    do
    {    
        std::cout << "Выберите, что вы хотите сделать" << '\n'
                  << "1. Ввод данных о рейсах" << '\n' 
                  << "2. Просмотр данных о рейсах" << '\n'
                  << "3. Добавить рейс" << '\n'
                  << "4. Поиск рейса" << '\n'
                  << "5. Удалить рейс" << '\n'
                  << "6. Изменить данные о рейсе" << '\n'
                  << "7. Сортировать по номеру" << '\n'
                  << "0. Выход" << '\n';
        std::cin >> choice;

        switch(choice)
        {
            case 1:
                inputSelection();
                break;
            case 2:
                viewFlights();
                break;
            case 3:
                addFlightsToFile();
                break;
            case 4:
                searchFlight();
                break; 
            case 5:
                deletionFlight();
                break;
            case 6:
                changeFlight();
                break;
            case 7:
                sortingFlights();
                break;
            default: 
                break;
        }

    } while (choice != 0);
}
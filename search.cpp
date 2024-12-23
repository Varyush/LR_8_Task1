#include "func.h"
const char fileName[9] = "file.bin";

void searchFlight()
{
    FILE* workFile = fopen(fileName, "rb");

    if (!workFile) 
    {
        std::cout << "Ошибка открытия файла." << '\n';
        return;
    }

    int count = 0;
    while (fread(&flightsArr[count], sizeof(Flights), 1, workFile) == 1) 
    {
        count++;
    }

    if (count == 0) 
    {
        std::cout << "Нет доступных рейсов для поиска" << '\n';
        fclose(workFile);
        return;
    }

    int choice;
    std::cout << '\n' << "Выберите параметр для поиска: " << '\n';
    std::cout << "1. Номер рейса" << '\n' 
              << "2. Тип самолета" << '\n'
              << "3. Пункт назначения" << '\n'
              << "4. Время вылета" << '\n';
    std::cin >> choice;

    switch(choice)
    {
        case 1:
        {
            int searchNumber;
            std::cout << "Введите номер рейса: " << '\n';
            searchNumber = checkNum();
            bool found = 0;

            for (int i = 0; i < count; ++i) 
            {
                if (flightsArr[i].d.number == searchNumber) 
                {
                    found = 1;
                    std::cout << '\n' << "Номер рейса | Тип самолета | Пункт назначения | Время вылета" << '\n';
                    std::cout << flightsArr[i].d.number << " | "
                              << flightsArr[i].type << " | "
                              << flightsArr[i].destination << " | "
                              << flightsArr[i].time << '\n';
                }
            }
            if (!found)
                std::cout << "Рейс с номером " << searchNumber << " не найден." << '\n';
            break;
        }
        case 2:
        {
            char searchType[30];
            std::cout << "Введите тип самолета: " << '\n';
            std::cin >> searchType;
            bool found = 0;

            for (int i = 0; i < count; ++i) 
            {
                if (strcmp(flightsArr[i].type, searchType) == 0)
                {
                    found = 1;
                    std::cout << "Номер рейса | Тип самолета | Пункт назначения | Время вылета" << '\n';
                    std::cout << flightsArr[i].d.number << " | "
                              << flightsArr[i].type << " | "
                              << flightsArr[i].destination << " | "
                              << flightsArr[i].time << '\n';
                }
            }

            if (!found) 
                std::cout << "Рейсы с типом " << searchType << " не найдены." << '\n';
            break;
        }
        case 3:
        {
            char searchDestination[30];
            std::cout << "Введите пункт назначения: " << '\n';
            std::cin >> searchDestination;
            bool found = 0;

            for (int i = 0; i < count; ++i) 
            {
                if (strcmp(flightsArr[i].destination, searchDestination) == 0) 
                {
                    found = 1;
                    std::cout << "Номер рейса | Тип самолета | Пункт назначения | Время вылета" << '\n';
                    std::cout << flightsArr[i].d.number << " | "
                              << flightsArr[i].type << " | "
                              << flightsArr[i].destination << " | "
                              << flightsArr[i].time << '\n';
                }
            }

            if (!found) 
                std::cout << "Рейсы с пунктом назначения " << searchDestination << " не найдены." << '\n';
            break;
        }
        case 4:
        {
            char searchTime[6];
            std::cout << "Введите время вылета (HH:MM): " << '\n';
            std::cin >> searchTime;
            bool found = 0;

            for (int i = 0; i < count; ++i) 
            {
                if (strcmp(flightsArr[i].time, searchTime) == 0) 
                {
                    found = 1;
                    std::cout << "Номер рейса | Тип самолета | Пункт назначения | Время вылета" << '\n';
                    std::cout << flightsArr[i].d.number << " | "
                              << flightsArr[i].type << " | "
                              << flightsArr[i].destination << " | "
                              << flightsArr[i].time << '\n';
                }
            }

            if (!found) 
                std::cout << "Рейсы с временем вылета " << searchTime << " не найдены." << '\n';
            break;
        }
        default:
            std::cout << "Неверный выбор." << '\n';
            break;
    }

    fclose(workFile);
}
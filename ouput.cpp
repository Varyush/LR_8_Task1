#include "func.h"
const char fileName[9] = "file.bin";

void viewFlights() 
{
    FILE* workFile = fopen(fileName, "rb");

    if (!workFile) {
        std::cout << "Ошибка открытия файла" << '\n';
        return;
    }

    std::cout << "Выберите, что хотите вывести:" << '\n'
              << "1. Все доступные рейсы " << '\n'
              << "2. Рейсы, вылетающие в заданный пункт назначения" << '\n';
    int choice;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
    {
        std::cout << "Расписание рейсов:" << '\n';
        std::cout << "Номер рейса | Тип самолета | Пункт назначения | Время вылета" << '\n';

        Flights flight;
        int count = 0;
        while (fread(&flight, sizeof(Flights), 1, workFile) == 1) 
        {
            std::cout << flight.d.number << " | "
                    << flight.type << " | "
                    << flight.destination << " | "
                    << flight.time << '\n';
            count++;
        }
        std::cout << '\n';

        if (count == 0) 
        {
            std::cout << "Нет доступных рейсов." << '\n';
        }

        fclose(workFile);
        break;
    }
    case 2:
    {
        std::cout << "Введите нужный пункт назначения: ";
        char searchDestination[30];
        std::cin >> searchDestination;

        int count = 0;
        while (fread(&flightsArr[count], sizeof(Flights), 1, workFile) == 1) 
        {
            count++;
        }

        bool found = 0;
        std::cout << "Расписание рейсов с нужным пунктом назначения:" << '\n';
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
        std::cout << '\n';

        if (!found) 
            std::cout << "Рейсы с пунктом назначения " << searchDestination << " не найдены." << '\n';
        break;
    }
    }
}
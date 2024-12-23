#include "func.h"
const char fileName[9] = "file.bin";

void addFlightsToFile() 
{
    FILE* workFile;
    workFile = fopen(fileName, "ab");

    if (!workFile) 
    {
        std::cout << "Ошибка открытия" << std::endl;
        return;
    }

    int currentCount = 0;
    while (fread(&flightsArr[currentCount], sizeof(Flights), 1, workFile) == 1) 
    {
        currentCount++;
    }

    int newCount;
    std::cout << "Введите количество рейсов для добавления: ";
    newCount = check();
    std::cout << '\n';

    flightsArr = (Flights*) realloc(flightsArr, (currentCount + newCount) * sizeof(Flights));

    if (!flightsArr) 
    {
        std::cout << "Ошибка выделения памяти" << '\n';
        fclose(workFile);
        return;
    }

    for (int i = 0; i < newCount; ++i) 
    {
        Flights flight;
        std::cout << "Введите номер рейса: ";
        std::cin >> flight.d.number;
        std::cout << "Введите тип самолета: ";
        std::cin >> flight.type;
        std::cout << "Введите пункт назначения: ";
        std::cin >> flight.destination;
        std::cout << "Введите время вылета (HH:MM): ";
        std::cin >> flight.time;

        flightsArr[currentCount + i] = flight;
    }

    fseek(workFile, currentCount * sizeof(Flights), 0);
    fwrite(flightsArr + currentCount, sizeof(Flights), newCount, workFile);
    fclose(workFile);
}
#include "func.h"
const char fileName[9] = "file.bin";

void changeFlight()
{
    FILE* workFile = fopen(fileName, "r+b");

    if (!workFile) 
    {
        std::cout << "Ошибка открытия файла" << '\n';
        return;
    }

    int changeNumber;
    std::cout << "Введите номер рейса, который хотите изменнить" << '\n';
    std::cin >> changeNumber;

    Flights flight;
    bool found = false;
    int position = 0;

    while (fread(&flight, sizeof(Flights), 1, workFile) == 1)
    {
        if (flight.d.number == changeNumber) 
        {
            found = true;
            break;
        }
        position += sizeof(Flights);
    }

     if (!found) 
    {
        std::cout << "Рейс с номером " << changeFlight << " не найден." << '\n';
        fclose(workFile);
        return;
    }

    std::cout << "Введите новый тип рейса: ";
    std::cin >> flight.type;
    std::cout << "Введите новое направление: ";
    std::cin >> flight.destination;
    std::cout << "Введите новое время: ";
    std::cin >> flight.time;

    fseek(workFile, position, 0);
    fwrite(&flight, sizeof(Flights), 1, workFile);
    fclose(workFile);
}
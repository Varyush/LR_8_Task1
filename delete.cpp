#include "func.h"
const char fileName[9] = "file.bin";

void deletionFlight()
{
    FILE* workFile = fopen(fileName, "r+b");

    if (!workFile) 
    {
        std::cout << "Ошибка открытия файла" << '\n';
        return;
    }

    int deleteNumber;
    std::cout << "Введите номер рейса для удаления" << '\n';
    std::cin >> deleteNumber;

    Flights flight;
    bool found = 0;
    int position = 0;

    while (fread(&flight, sizeof(Flights), 1, workFile) == 1)
    {
        if (flight.d.number == deleteNumber) 
        {
            found = 1;
            break;
        }
        position += sizeof(Flights);
    }

    if (!found) 
    {
        std::cout << "Рейс с номером " << deleteNumber << " не найден." << '\n';
        fclose(workFile);
        return;
    }

    Flights nextFlight;
    long nextPosition;

    while (fread(&nextFlight, sizeof(Flights), 1, workFile) == 1) 
    {
        nextPosition = ftell(workFile) - sizeof(Flights);
        fseek(workFile, position, 0);
        fwrite(&nextFlight, sizeof(Flights), 1, workFile);
        position = nextPosition;
    }

    ftruncate(fileno(workFile), position); 
    std::cout << "Рейс с номером " << deleteNumber << " удалён." << '\n';

    fclose(workFile);
}
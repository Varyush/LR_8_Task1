#include "func.h"
const char fileName[9] = "file.bin";

void quickSort(Flights* arr, int start, int end)
{
    if (start >= end) return;
    int x = arr[start + (end - start) / 2].d.number;

    int L = start, R = end;

    while (L <= R)  
    {
        while (arr[L].d.number < x)
            L++;
        while (arr[R].d.number > x)
            R--;

        if (L <= R)
        {
            std::swap(arr[L], arr[R]);
            L++;
            R--;
        }
    }

    if (start < R) quickSort(arr, start, R);
    if (L < end) quickSort(arr, L, end);

    return;
}

void sortingFlights ()
{
    FILE* workFile = fopen(fileName, "r+b");

    if (!workFile) {
        std::cout << "Ошибка открытия файла" << '\n';
        return;
    }

    int count = 0;
    while (fread(&flightsArr[count], sizeof(Flights), 1, workFile) == 1) 
    {
        count++;
    }

    if (count == 0) 
    {
        std::cout << "Нет доступных рейсов для сортировки" << '\n';
        fclose(workFile);
        return;
    }

    quickSort(flightsArr, 0, count - 1);

    std::cout << "Расписание рейсов:" << '\n';
    std::cout << "Номер рейса | Тип самолета | Пункт назначения | Время вылета" << '\n';

    for(int i = 0; i < count; ++i)
    {
        std::cout << flightsArr[i].d.number << " | "
                  << flightsArr[i].type << " | "
                  << flightsArr[i].destination << " | "
                  << flightsArr[i].time << '\n';
    }
    std::cout << '\n';

    fwrite(flightsArr, sizeof(Flights), count, workFile);
    fclose(workFile);
}
#include "func.h"
const char fileName[9] = "file.bin";

int checkNum()
{
    int a;

    while(true)
    {
        std::cin >> a;

        if(std::cin.fail())
        {
            std::cout << '\n' << "Вы ввели неправильное значение, попробуйте ещё раз" << '\n';
            std::cin.clear();
            std::cin.ignore(32767, '\n'); //O(N)
        } 
        else return a;
    }
}

int check()
{
    int a;

    while(true)
    {
        std::cin >> a;

        if(std::cin.fail() || a > 30)
        {
            std::cout << '\n' << "Вы ввели неправильное значение, попробуйте ещё раз" << '\n';
            std::cin.clear();
            std::cin.ignore(32767, '\n'); //O(N)
        } 
        else return a;
    }
}

void input1() 
{
    FILE* workFile;
    workFile = fopen(fileName, "wb");

    if (!workFile)
    {
        std::cout << "Ошибка открытия";
        return;
    }

    int count;
    std::cout << "Введите количество рейсов: ";
    count = check();

    flightsArr = (Flights*)malloc(count * sizeof(Flights));
    for(int i = 0; i < count; ++i)
    {
        Flights flight;
        std::cout << "Введите номер рейса: ";
        flight.d.number = checkNum();
        std::cout << "Введите тип самолета: ";
        std::cin >> flight.type;
        std::cout << "Введите пункт назначения: ";
        std::cin >> flight.destination;
        std::cout << "Введите время вылета (HH:MM): ";
        std::cin >> flight.time;
        flightsArr[i] = flight;
        std::cout << '\n';
    }

    fwrite(flightsArr, sizeof(Flights), count, workFile);
    fclose(workFile);
}

void input2()
{
    FILE* workFile;
    workFile = fopen(fileName, "wb");

    if (!workFile)
    {
        std::cout << "Ошибка открытия";
        return;
    }

    std::cout << "Выберите признак" << '\n'
                  << "1. Номер" << '\n' 
                  << "2. Тип" << '\n'
                  << "3. Пункт назначения" << '\n'
                  << "4. Время вылета" << '\n';
    int input;
    std::cin >> input;
    int numberStop;
    char typeStop[30];
    char destinationStop[30];
    char timeStop[6];

    switch (input)
    {
        case 1:
            std::cin >> numberStop;
            break;
        case 2:
            std::cin >> typeStop;
            break;
        case 3: 
            std::cin >> destinationStop;
            break;
        case 4: 
            std::cin >> timeStop;
            break;
    }

    int i = 0;
    flightsArr = (Flights*) malloc (1 * sizeof(Flights));

    std::cout << typeStop << '\n';

    while (1)
    {
        Flights flight;
        std::cout << "Введите номер рейса: ";
        flight.d.number = checkNum();
        std::cout << "Введите тип самолета: ";
        std::cin >> flight.type;
        std::cout << "Введите пункт назначения: ";
        std::cin >> flight.destination;
        std::cout << "Введите время вылета (HH:MM): ";
        std::cin >> flight.time;
        flightsArr[i] = flight;

        bool f = 0;
        switch (input)
        {
            case 1:
            if(flightsArr[i].d.number == numberStop)
            f = 1;
            break;
        case 2:
            if(strcmp(flightsArr[i].type, typeStop) == 0)
            f = 1;
            break;
        case 3: 
            if(strcmp(flightsArr[i].destination, destinationStop) == 0)
            f = 1;
            break;
        case 4: 
            if(strcmp(flightsArr[i].time, timeStop) == 0)
            f = 1;
            break;
        }

        i++;
        if(f) break;

        flightsArr = (Flights*) realloc(flightsArr, (i + 1) * sizeof(Flights));
    }

    fwrite(flightsArr, sizeof(Flights), i, workFile);
    fclose(workFile);
}

void input3()
{
    FILE* workFile;
    workFile = fopen(fileName, "wb");

    if (!workFile)
    {
        std::cout << "Ошибка открытия";
        return;
    }

    flightsArr = (Flights*) malloc (1 * sizeof(Flights));
    int i = 0;

    while (1)
    {
        std::cout << "Введите данные " << i + 1 << "-го рейса: ";

        Flights flight;
        std::cout << "Введите номер рейса: ";
        flight.d.number = checkNum();
        std::cout << "Введите тип самолета: ";
        std::cin >> flight.type;
        std::cout << "Введите пункт назначения: ";
        std::cin >> flight.destination;
        std::cout << "Введите время вылета (HH:MM): ";
        std::cin >> flight.time;
        flightsArr[i] = flight;

        std::cout << "Введите 1, если хотите продолжить ввод и 2, если хотите прекратить: ";
        int check;
        std::cin >> check;
        bool f = 0;
        i++;

        switch (check)
        {
        case 1: 
            flightsArr = (Flights*) realloc(flightsArr, (i + 1) * sizeof(Flights));
            break;
        case 2:
            f = 1;
        default:
            break;
        }
         
        if (f)
            break;
    }

    fwrite(flightsArr, sizeof(Flights), i, workFile);
    fclose(workFile);
}

void inputSelection()
{
    std::cout << '\n' << "Выберите тип ввода" << '\n'
              << "1. Заранее заданного количество структур" << '\n'
              << "2. До появления структуры с заданным признаком" << '\n'
              << "3. Ввод с диалогом" <<'\n';
    int selection;
    std::cin >> selection;
    switch (selection)
    {
        case 1:
            input1();
            break;
        case 2: 
            input2();
            break;
        case 3:
            input3();
            break;
    }
}

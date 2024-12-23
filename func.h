#pragma once
#include <iostream>
#include <cstdlib>
#include <cstdio> 
#include <string>
#include <cstring>
#include <unistd.h>

//extern const char fileName[9] = "file.bin";

struct flights_t 
{
    union
    {
        int number;
        long numberL;
    } d;
    char type[30];
    char destination[30];
    char time[6];
}; 
typedef struct flights_t Flights;
extern Flights* flightsArr;

void menu();
void input1();
void input2();
void input3();
void inputSelection();
void viewFlights();
void addFlightsToFile();
void deletionFlight();
void searchFlight();
void changeFlight();
void quickSort(Flights* arr, int start, int end);
void sortingFlights();
int checkNum();
int check();
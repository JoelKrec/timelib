
#include <stdio.h>
#include <stdlib.h>

#include "time.h"


//Ueberprueft das gegebene Jahr auf Schaltjahre
int is_leapyear(int year)
{
    int leapyear = 0;

    if(year > 1582)
    {
        if(year % 400 == 0 || year % 100 != 0 && year % 4 == 0)
        {
            leapyear = 1;
        }
        else
        {
            leapyear = 0;
        }
    }
    else
    {
        leapyear = -1;
    }

    return leapyear;
}

//Gibt die maximale Anzahl an Tagen in einem gegebenen Monat und Jahr zurueck
int get_days_for_month(int month, int year)
{
    int days_in_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days = 0;
    int schaltjahr = is_leapyear(year);

    if(year >= 1582 && month <= 12 && month >= 1)
    {
        if(schaltjahr &&  month == 2)
        {
            days = 29;
        }
        else
        {
            days = days_in_month[month - 1];
        }
    }
    else
    {
        days = -1;
    }

    return days;
}

//Ueberprueft ein gegebenes Datum auf Validitaet
int exists_date(int day, int month, int year)
{
    int valid = 0;

    if(year >= 1582 && month <= 12 && month >= 1 && year <= 2400)
    {
        if(day <= get_days_for_month(month, year) && day >= 1)
        {
            valid = 1;
        }
        else
        {
            valid = 0;
        }
    }
    else
    {
        valid = 0;
    }
    return valid;
}

//Berechnet die Tage zu dem gegebenen Enddatum
int day_of_the_year(int day, int month, int year)
{
    int days = 0;
    for(int i = 1; i < month; i++)
    {
        days += get_days_for_month(i, year);
    }
    days += day;
    return days;
}


#include <stdio.h>
#include <stdlib.h>

#include "time.h"



//Ueberprueft das gegebene Jahr auf Schaltjahre
int is_leapyear(int year)
{
    int leapyear = 0;

    if(year > 1582)
    {
        if(year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
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
int exists_date(struct date target_date)
{
    int valid = 0;

    if(target_date.year >= 1582 && target_date.month <= 12 && target_date.month >= 1 && target_date.year <= 2400)
    {
        if(target_date.day <= get_days_for_month(target_date.month, target_date.year) && target_date.day >= 1)
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
int day_of_the_year(struct date target_date)
{
    int days = 0;
    for(int i = 1; i < target_date.month; i++)
    {
        days += get_days_for_month(i, target_date.year);
    }
    days += target_date.day;
    return days;
}
//Benutzung der Regel Zellers | Sonntag = 0, Montag = 1, usw... | Code erhalten auf https://www.rosettacode.org/wiki/Day_of_the_week#C
int get_week_day_in_int(struct date target_date)
{
    int adjustment, mm, yy;

	adjustment = (14 - target_date.month) / 12;
	mm = target_date.month + 12 * adjustment - 2;
	yy = target_date.year - adjustment;
	return (target_date.day + (13 * mm - 1) / 5 +
		yy + yy / 4 - yy / 100 + yy / 400) % 7;
}

//Berechnet den Wochentag eines Datums und gibt einen Zeiger char wieder
char *get_week_day(struct date target_date)
{
    int weekday = get_week_day_in_int(target_date);
    char *weekdays[7] = {"Sonntag", "Montag", "Dienstag", "Mittwoch", "Donnerstag", "Freitag", "Samstag"};

    return weekdays[weekday];
}

//Berechnet die Kalenderwoche f�r ein Datum nach ISO 8601: Erster Donnerstag des Jahres entspricht der ersten Kalenderwoche
int get_week_count(struct date target_date)
{

}

struct date input_date()
{
    int invalid = 0;
    struct date target_date;

    //Eingabe Jahr
    do
    {
        printf("Geben Sie ein Jahr ein - '-666' zum Beenden: ");
        scanf("%i", &target_date.year);

        if(target_date.year == -666)
        {
            return target_date;
        }
    }while(target_date.year < 1);


    //Eingabe Monat
    do
    {
        printf("\nGeben Sie einen Monat ein: ");
        scanf("%i", &target_date.month);
    }while(target_date.month < 1 || target_date.month > 12);

    //Eingabe Tag
    do
    {
        printf("\nGeben Sie einen Tag ein: ");
        scanf("%i", &target_date.day);

        if(target_date.day < get_days_for_month(target_date.month, target_date.year) && target_date.day > 0)
        {
            invalid = 0;
        }
        else
        {
            invalid = 1;
        }

    }while(invalid == 1);

    return target_date;
}

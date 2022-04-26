#include <stdio.h>
#include <stdlib.h>

int is_leapyear(int year);
int get_days_for_month(int month, int year);
int exists_date(int day, int month, int year);
int day_of_the_year(int day, int month, int year);


int main()
{
    int jahr = 0;
    int monat = 0;
    int tag = 0;
    int schaltjahr = 0;
    int tageImJahr = 0;

    int invalide = 0;

    while(1)
    {
        printf("***Tag des Jahres ***\n\n");

        //Eingabe Jahr
        do
        {
            printf("Geben Sie ein Jahr ein - '-666' zum Beenden: ");
            scanf("%i", &jahr);

            if(jahr == -666)
            {
                break;
            }
        }while(jahr < 1);

        //Abbruchbedingung
        if(jahr == -666)
        {
            break;
        }

        //Schaltjahrberrechnung
        schaltjahr = is_leapyear(jahr);

        //Eingabe Monat
        do
        {
            printf("\nGeben Sie einen Monat ein: ");
            scanf("%i", &monat);
        }while(monat < 1 || monat > 12);

        //Eingabe Tag
        do
        {
            printf("\nGeben Sie einen Tag ein: ");
            scanf("%i", &tag);

            int invalide = 1;

            if(tag < get_days_for_month(monat, jahr))
            {
                invalide = 0;
            }
            else
            {
                invalide = 1;
            }

        }while(invalide == 1);

        if(!exists_date(tag, monat, jahr))
        {
            printf("Ungueltiges Datum eingegeben.");
            break;
        }

        //TageImJahr berechnen
        tageImJahr = day_of_the_year(tag, monat, jahr);

        //Ausgabe
        printf("\nDer %02i.%02i.%04i ist der %i. Tag im Jahr\n \n***Ende Tag des Jahres***\n \n", tag, monat, jahr, tageImJahr);
    }
    return 0;
}

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

/**

Autor: Joel Krec

Datum: 26.04.2022

Ein Programm um ein Datum in die Anzahl an Tagen von dem Anfang des Jahres bis zu dem Datum herauszufinden.
Das Enddatum ist mit inklusive.

**/


#include <stdio.h>
#include <stdlib.h>

#include "time.h"

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

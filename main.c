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
    int tageImJahr = 0;

    int invalide = 0;

    while(1)
    {
        printf("***Tag des Jahres ***\n\n");

        do
        {
            input_date(&tag, &monat, &jahr);

            if(jahr == -666)
            {
                return 0;
            }

        }while(!exists_date(tag, monat, jahr));

        //TageImJahr berechnen
        tageImJahr = day_of_the_year(tag, monat, jahr);


        int kalenderwoche = get_week_count(tag, monat, jahr);
        //Ausgabe
        printf("\nDer %02i.%02i.%04i ist der %i. Tag im Jahr\nEs ist an dem Datum ein %s \n \n***Ende Tag des Jahres***\n \n", tag, monat, jahr, tageImJahr, get_week_day(tag, monat, jahr));
    }
    return 0;
}

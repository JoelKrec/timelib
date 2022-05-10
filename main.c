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
    struct date target_date;
    int tageImJahr = 0;

    while(1)
    {
        //Ueberschrift
        printf("***Tag des Jahres ***\n\n");

        //Eingabe und Abbruchueberpruefung
        do
        {
            //eingabe
            target_date = input_date();

            //Abbruchueberpruefung
            if(target_date.year == -666)
            {
                return 0;
            }

        }while(!exists_date(target_date));

        //TageImJahr berechnen
        tageImJahr = day_of_the_year(target_date);

        //Wochentag berechen
        int kalenderwoche = get_week_count(target_date);

        //Ausgabe
        printf("\nDer %02i.%02i.%04i ist der %i. Tag im Jahr\nEs ist an dem Datum ein %s \n \n***Ende Tag des Jahres***\n \n",
               target_date.day, target_date.month, target_date.year, tageImJahr, get_week_day(target_date));
    }
    return 0;
}

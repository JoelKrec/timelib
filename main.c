/**
*   Ein Programm um den Tag des Jahres aus einem Datum auszurechnen
*
*   Autor: Joel Krec
*   Datum: 29.03.2022
**/


#include <stdio.h>
#include <stdlib.h>

int jahr = 0;
int monat = 0;
int tag = 0;
int schaltjahr = 0;
int tageImMonat[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int tageImJahr = 0;

int invalide = 0;


void eingabe_jahr()
{
    do
    {
        printf("Geben Sie ein Jahr ein - '-666' zum Beenden: ");
        scanf("%i", &jahr);

        check_abbruchbedingung();
    }while(jahr < 1);
}

void check_abbruchbedingung()
{
    if(jahr == -666)
    {
        break;
    }
}

void check_schaltjahr()
{
    if(jahr % 400 == 0 || jahr % 100 != 0 && jahr % 4 == 0)
    {
        schaltjahr = 1;
    }
    else
    {
        schaltjahr = 0;
    }
}

void eingabe_monat()
{
    do
    {
        printf("\nGeben Sie einen Monat ein: ");
        scanf("%i", &monat);
    }while(monat < 1 || monat > 12);
}

void ausgabe_einleitung()
{
    printf("***Tag des Jahres ***\n\n");
}

void eingabe_tag()
{
    do
    {
        printf("\nGeben Sie einen Tag ein: ");
        scanf("%i", &tag);

        if(schaltjahr &&  monat == 2 && tag == 29)
        {
            invalide = 0;
        }
        else if(tageImMonat[monat - 1] >= tag || tag < 0)
        {
            invalide = 0;
        }
        else
        {
            invalide = 1;
        }
    }while(invalide == 1);
}

void tag_berechnen()
{
    tageImJahr = 0;

    for(int i = 0; i < monat - 1; i++)
    {
        tageImJahr += tageImMonat[i];
    }
    tageImJahr += tag;

    if(monat > 2 && schaltjahr > 0)
    {
        tageImJahr++;
    }
}

void ausgabe_ergebnis()
{
    printf("\nDer %02i.%02i.%04i ist der %i. Tag im Jahr\n \n***Ende Tag des Jahres***\n \n", tag, monat, jahr, tageImJahr);
}

int main()
{
    while(1)
    {
        ausgabe_einleitung();

        eingabe_jahr();

        check_abbruchbedingung();

        check_schaltjahr();

        eingabe_monat();

        eingabe_tag();

        tag_berechnen();

        ausgabe_ergebnis();
    }
    return 0;
}

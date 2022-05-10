#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

int is_leapyear(int year);
int get_days_for_month(int month, int year);
int exists_date(int day, int month, int year);
int day_of_the_year(int day, int month, int year);
int get_week_day_in_int(int day, int month, int year);
char *get_week_day(int day, int month, int year);
void *input_date(int *day, int *month, int *year);

#endif // TIME_H_INCLUDED

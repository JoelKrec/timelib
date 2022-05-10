#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

struct date
{
    int day;
    int month;
    int year;
};


int is_leapyear(int year);
int get_days_for_month(int month, int year);
int exists_date(struct date target_date);
int day_of_the_year(struct date target_date);
int get_week_day_in_int(struct date target_date);
char *get_week_day(struct date target_date);
struct date input_date();

#endif // TIME_H_INCLUDED

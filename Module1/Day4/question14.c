// 14. No of days elapsed

// Same question

// Count total number of days elapsed from a given date in string format
// 10/4/2015 -> 31 + 28 + 31 + 10 = 100 so 100 days elapsed

#include <stdio.h>
#include <string.h>

int countDaysElapsed(const char *dateStr) 
{
    int day, month, year, totalDays = 0, i;
    sscanf(dateStr, "%d/%d/%d", &day, &month, &year);   //Seperating date into day, month and year

    int totalDaysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    for (i = 0; i < month - 1; i++) 
    {
        totalDays += totalDaysInMonth[i];
    }

    totalDays += day;

    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0) && month >= 3) 
    {
        totalDays += 1;    // For leap year, if month is March or above
    }

    return totalDays;
}

int main() 
{
    char date[30];
    int daysElapsed;

    printf("Enter the date in dd/mm/yyyy format: ");
    scanf("%s", date);
    daysElapsed = countDaysElapsed(date);

    printf("Total days elapsed: %d\n", daysElapsed);

    return 0;
}

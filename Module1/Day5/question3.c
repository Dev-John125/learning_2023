// 3. Write a program using structures to calculate the difference between two time periods using a user-defined function.

#include <stdio.h>
#include<stdlib.h>

struct Time 
{
    int hours;
    int minutes;
    int seconds;
};

typedef struct Time time;

void calcDifference(time t1, time t2, time *diff)       // Converting both time periods to seconds and calculating the difference
{   
    int totalSec1, totalSec2, difference;

 
    totalSec1 = t1.hours * 3600 + t1.minutes * 60 + t1.seconds;

    totalSec2 = t2.hours * 3600 + t2.minutes * 60 + t2.seconds;

    difference = abs(totalSec2 - totalSec1);

    
    diff->hours = difference / 3600;
    difference %= 3600;
    diff->minutes = difference / 60;
    diff->seconds = difference % 60;
}

int main() {
    time period1, period2, timeDiff;

    printf("Enter the first time period (h m s format): ");
    scanf("%d %d %d", &period1.hours, &period1.minutes, &period1.seconds);

    printf("Enter the second time period (h m s format): ");
    scanf("%d %d %d", &period2.hours, &period2.minutes, &period2.seconds);

    calcDifference(period1, period2, &timeDiff);

    printf("Time difference: %d hours %d minutes %d seconds\n",
           timeDiff.hours, timeDiff.minutes, timeDiff.seconds);

    return 0;
}

// Compute Total seconds from a given string format.
// format: hh:mm:ss
// Use strtok & strtoul to split the string into hh mm ss

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long computeTotalSeconds(const char *timeStr) {
    char *token;
    char *hours, *minutes, *seconds;
    unsigned long totalSeconds = 0;

    char *timeCopy = strdup(timeStr); // strdup creates a copy of the a string
    token = strtok(timeCopy, ":"); // strtok splits the string using ":" delimiter

    hours = token;
    token = strtok(NULL, ":"); // second split
    minutes = token;
    token = strtok(NULL, ":"); // third split
    seconds = token;

    unsigned long h = strtoul(hours, NULL, 10);
    unsigned long m = strtoul(minutes, NULL, 10);
    unsigned long s = strtoul(seconds, NULL, 10);

    // Calculate the total seconds
    totalSeconds = (h * 3600) + (m * 60) + s;

    free(timeCopy); 

    return totalSeconds;
}

int main() {
    char timeStr[10];
    printf("Enter time in format 'hh:mm:ss': ");
    fgets(timeStr, sizeof(timeStr), stdin);
    timeStr[strcspn(timeStr, "\n")] = '\0';   // To remove trailing newline character

    unsigned long totalSeconds = computeTotalSeconds(timeStr);

    printf("Total seconds: %lu\n", totalSeconds);

    return 0;
}

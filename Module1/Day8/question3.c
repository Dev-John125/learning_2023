// 3. Data Viewer:
// Write an application to view the log stored in data.csv
// Example, say you have the following data in data.csv

// ------------------------------------

// EntryNo,sensorNo,Temperature,Humidity,Light,

// 1,S1,36.5,100,50,10:30:50
// 2,S3,30,100,50,10:30:55
// 3,S2,-6.6,100,10,10:31:00
// ------------------------------------

// a. Write a function to extract each line in the .csv file and store it in an array of structures. 

// b. Also implement functions to display the contents of the array of structures.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct 
{
    int entryNo;
    char sensorNo[10];
    float temperature;
    int humidity;
    int light;
    char time[9];
} Log;

// Function to extract each line from data.csv and store it in an array of structures
int extractLogData(Log data[]) 
{
    FILE *file;
    char line[50];
    char temp[50];
    int count = 0;

    file = fopen("temp.csv", "r");
    if (file == NULL) 
    {
        printf("Failed to open the file.\n");
        return 0;
    }



    int headerSkipped = 0;
    while (fgets(line, sizeof(line), file) != NULL) 
    {
        if (!headerSkipped) 
        {
            headerSkipped = 1;
            fgets(line, sizeof(line), file);
            continue; // Skip the header line
        }

        Log entry;
        char *token;
        int index = 0;

        token = strtok(line, ",");

        while (token != NULL) 
        {
            if (index == 0) 
            {
                entry.entryNo = atoi(token);
            } 
            else if (index == 1) 
            {
                strcpy(entry.sensorNo, token);
            } 
            else if (index == 2) 
            {
                entry.temperature = atof(token);
            } 
            else if (index == 3) 
            {
                entry.humidity = atoi(token);
            } 
            else if (index == 4) 
            {
                entry.light = atoi(token);
            } 
            else if (index == 5) 
            {
                strcpy(entry.time, token);
            }
            token = strtok(NULL, ",");
            index++;
        }

        data[count] = entry;
        count++;
    }

    fclose(file);
    return count;
}

// Function to display the contents of the array of structures
void displayLogData(Log data[], int count) 
{   
    int i;
    printf("EntryNo\tSensorNo\tTemperature\tHumidity\tLight\tTime\n");
    printf("-------------------------------------------------------------------------------\n");

    for (i = 0; i < count; i++) 
    {
        Log line = data[i];
        printf("%d\t%s\t\t%.1f\t\t%d\t\t%d\t%s\n", line.entryNo, line.sensorNo, line.temperature, line.humidity, line.light, line.time);
    }
}

int main() 
{
    Log data[50];
    int count = extractLogData(data);

    if (count > 0) 
    {
        displayLogData(data, count);
    } 
    else {
        printf("Nothing to display\n");
    }

    return 0;
}

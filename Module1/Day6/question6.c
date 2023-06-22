// 1. Data Parser:
//    A data logger transmits the data in ascii format as shown below
//    "S1-T:36.5-H:100-L:50"
//    Write a function to populate all the data in an array of structure. The output should be like
//    Sensor Info:
//    ---------------------
//    Sensor ID: S1
//    Temperature: 36.5 C
//    Humidity: 100
//    Light Intensity: 50%
//    ---------------------


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct 
{
    char sensorID[10];
    float temperature;
    int humidity;
    int lightIntensity;
} sensorInfo;

void parseData(const char* data, sensorInfo* log) 
{
    char temp[100];
    strcpy(temp, data);


    char* token = strtok(temp, "-");
    strcpy(log->sensorID, token);

    // Extract temperature
    token = strtok(NULL, "-");
    sscanf(token, "T:%f", &(log->temperature));
        

    token = strtok(NULL, "-");
    sscanf(token, "H:%d", &(log->humidity));


    token = strtok(NULL, "-");
    sscanf(token, "L:%d", &(log->lightIntensity));
    
}

int main() 
{
    const char* data = "S1-T:36.5-H:100-L:50";
    sensorInfo log;

    parseData(data, &log);

    printf("Sensor Info:\n");
    printf("---------------------\n");
    printf("Sensor ID: %s\n", log.sensorID);
    printf("Temperature: %.1f C\n", log.temperature);
    printf("Humidity: %d\n", log.humidity);
    printf("Light Intensity: %d%%\n", log.lightIntensity);
    printf("---------------------\n");

    return 0;
}

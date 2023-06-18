// Rotate a string by K places to the left or to the right
// abcdxyz  rotate left by 2 places -> cdxyzab
// abcdxyz  rotate right by 3 places -> xyzabcd

#include <stdio.h>
#include <string.h>

void rotateLeft(char *str, int k) 
{
    int len = strlen(str);
    
    char temp[k];
    strncpy(temp, str, k);                      // copies first k characters from str to temp
    memmove(str, str + k, len - k);             // used instead of memcpy, copies n char from (str+k) to str
    strncpy(str + len - k, temp, k);
}

void rotateRight(char *str, int k) 
{
    int len = strlen(str);
    
    char temp[k];
    strncpy(temp, str + len - k, k);
    memmove(str + k, str, len - k);
    strncpy(str, temp, k);
}

int main() 
{
    char str[100];
    int k, option; 

    printf("Enter a string to rotate: ");
    scanf("%s", str);

    printf("Enter the value of k: ");
    scanf("%d", &k);

    printf("Enter 1 to rotate left, 2 to rotate right: ");
    scanf("%d", &option);

    if (option == 1)
    {
        rotateLeft(str, k);
        printf("Rotated left by %d places: %s\n", k, str);
    }
    else if (option == 2)
    {
        rotateRight(str, k);
        printf("Rotated right by %d places: %s\n", k, str);
    }
    

    return 0;
}

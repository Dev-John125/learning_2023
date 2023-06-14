// 5. Write a program to encode any given string such that it gets converted into an unrecognizable form. 
// Also write a decode function to get back the original string
// Encryption process -> Incrementing Ascii value of every char by 2


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *encrypt(const char *str, int length) 
{   
    int i;
    char *encrypted = (char *)malloc((length + 1) * sizeof(char));

    for (i = 0; i < length; i++) 
    {
        encrypted[i] = str[i] + 2; 
    }

    encrypted[length] = '\0'; 
    return encrypted;
}

// Function to decrypt the string
char *decrypt(const char *encrypted, int length) 
{
    length = strlen(encrypted);
    char *decrypted = (char *)malloc((length + 1) * sizeof(char));

    for (int i = 0; i < length; i++) 
    {
        decrypted[i] = encrypted[i] - 2; 
    }

    decrypted[length] = '\0'; 
    return decrypted;
}

int main() 
{   
    int length;
    char string1[100];
    printf("Enter a string: ");
    scanf("%[^\n]s", string1);
    const char *pString = string1;
    length = strlen(pString);

    printf("Original string:  %s\n", string1);

    char *encrypted = encrypt(pString, length);
    printf("After Encryption: %s\n", encrypted);

    char *decrypted = decrypt(encrypted, length);
    printf("After Decryption: %s\n", decrypted);

    free(encrypted);
    free(decrypted);

    return 0;
}

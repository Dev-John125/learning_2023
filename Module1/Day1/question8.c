// 3. Write a function to find if a given character is vowel using switch case statements, 
//     - If vowel, return 1
//     - If not vowel, return 0;

// In main print,
// "Vowel" if return value is 1
// "Not Vowel" if return value is 1


#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int checkVowel(char alphabet) 
{

    switch (alphabet)
    {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return 1;
        
        default:
            return 0;
    }

}

int main()
{
    char letter;
    int result;
    printf("Enter an alphabet: ");
    scanf("%c", &letter);

    if(isalpha(letter))
    {
        letter = tolower(letter);
        result = checkVowel(letter);
    }
    else
    {
        printf("Not an alphabet, please try again!\n");
        exit(0);
    }

    if(result)
    {
        printf("Vowel\n");
    }
    else
    {
        printf("Not a Vowel\n");
    }

    return 0;
}
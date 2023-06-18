// Given a string, check if it's in valid e-mail format
// username@domain.ext
// username should be alphanumeric or dot is allowed
// Domain name and extension should be alphabets and lower case only.


#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool isValidEmail(const char *email) 
{
    int i, length; 
    
    length = strlen(email);
    int atloc = -1, dotloc = -1;

    if (length == 0 || length > 255)    // Max size of an email is 256
    {   
        return false;
    }


    for (i = 0; i < length; i++) 
    {
        char c = email[i];            // Check each character one by one

        if (isalnum(c) || c == '.' || c == '@')   // Check for alphanumeric char
        {

            if (c == '@') 
            {
                atloc = i;            // location of @
                if (i == 0 || i == length - 1) 
                {
                    return false;       // incorrect location of @
                }
            } 
            else if (c == '.')
            {
                dotloc = i;             // last dot position will get stored
                if (i == 0 || i == length - 1) 
                {
                    return false;
                }
            }
        } 
        else 
        {   
            return false;                // If invalid char is found
        }
    }


    if (atloc + 3 > dotloc) 
    {   
        return false;                   // If @ and . are too close to each other
    }

    if(length - dotloc > 4)
    {
        return false;                  // extention cannot be longer than 3 chars
    }

    for (i = atloc + 1; i < length; i++) 
    {
        if(email[i] == '.')
        {
            continue;
        }
        else if (!islower(email[i]))      // domain and ext can only contain alphabets
        {   
            return false;
        }
        
    }

    return atloc && dotloc;
}


int main() {
    char email[300];
    printf("Enter an email to validate: ");
    scanf("%s", email);

    if (isValidEmail(email)) 
    {
        printf("Valid email\n");
    } 
    else 
    {
        printf("Invalid email\n");
    }

    return 0;
}

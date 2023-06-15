
// 2. BCD to Decimal:
// https://1.bp.blogspot.com/-Tfj_D_f_AF0/VZO5QIIGAUI/AAAAAAAAAmI/5Rw6uIU3EiI/s1600/DS1307%2BTime%2BKeeper%2BRegister.PNG
// DS1307 has its time registers in BCD format as shown in the image found in the above link, To set the time we need to convert the decimal number to BCD format, hence, write a fucntion to convert decimal to BCD


#include <stdio.h>

void decimalToBcd(int n)
{
    if (n == 0) 
    {
        printf("0000");
        return;
    }

    int rev = 0;                              // Approach: Ex: 24 -> reversed to 42 , digits are extracted and binary form is printed till the num becomes 0
    while (n > 0) 
    {
        rev = rev * 10 + (n % 10);
        n /= 10;
    }

    while (rev > 0) 
    {
        int digit = rev % 10;
        int i;

        for (i = 3; i >= 0; i--)             // All digits from 0 to 9 has a 4 bit representation in binary form hence i starts from 3
        {
            int bit = (digit >> i) & 1;
            printf("%d", bit);
        }

        rev /= 10;
    }
}


int main()
{   
    int n;
    printf("Enter a decimal number: ");
    scanf("%d", &n);

    printf("The BCD representation is: ");
    decimalToBcd(n);
    printf("\n");
    return 0;
}

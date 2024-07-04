#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>

bool input_check(int count, string arr[]);
int cprt(int p, int k);
int cprtu(int p, int k);

int i;//i am using global variable
// to run for loop effect in fuction also
// i never expected it give me this much trouble
// i thought strings may work exactly like array
// but thats not the case
// details are damn they are two imp
//rembering basic is important


int main(int argc, string argv[])
{
    int t;
    int con;
    if (input_check(argc, argv))// checking input
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        t = atoi(argv[1]);// i was using these functions
        string p = get_string("plaintext:  "); // here cyphering starts
        int count = strlen(p);
        int c[count];
        printf("ciphertext: ");// always forget to add these semi colons here
        for (i = 0; i < count; i ++)
        {
            con =  p[i];
            con = (int)con;
            if (isupper(p[i]))
            {
                int n = cprtu(con, t);
                c[i] = n;
            }
            else if (islower(p[i])) // these fumctions have lot of usability but also bug
            {
                int n = cprt(con, t);
                c[i] = n;
            }
            else// this statement just to reject other statement
            {
                c[i] = p[i];
            }
            printf("%c", c[i]);

        }
        printf("\n");

    }
}

bool input_check(int count, string arr[])
{
    if (count != 2)// checking no. of arguments
    {
        return 1;
    }
    else
    {
        string n = arr[1];
        for (int j = 0 ; j < strlen(n) ; j++)
        {
            if (isdigit(n[j]) == 0) //cheking wheteher it is digit or not
            {
                // this function was good and easy function
                return 1;
            }
        }
    }
    return 0;
}


int text; // again global variable
int c = 0;

int cprtu(int p, int k)
{
    text = (p) - 65;
    c = (text + k) % 26;
    c += 65;
    return c;
}
int cprt(int p, int k)// have to add this function just to keep
{
    text = p - 97;
    c = (text + k) % 26;
    c += 97;
    return c;
}


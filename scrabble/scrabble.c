#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{

    // don't forget to initilize the every variable to 0 because when function is
    //called again it will keep the value from last function call
    int t = 0;
    int c = strlen(word) - 1;
    int i = 0;
    int n = 0;
    int p = 0;
    while (t <= c)
    {

        if (islower(word[i]))
        {
            n = word[i] - (65 + 32);
        }
        else
        {
            n =  word[i] - 65;
        }
        if (n < 0)         //your code is not well written
        {
            n = 0;
            p = p + n;
        }
        else
        {
            n = POINTS[n];
            p = p + n;
        }

        i++;
        t++;
    }
    return p;

}

#include <cs50.h>
#include <stdio.h>
#include <math.h>

int count_words(string para);
int count_letters(string para);
int count_sentences(string para);
int grade(double x);
double avg(double n, double d);
// also rember to check datatype
// because data handling can mess
// so keep track what type is being enterd
// and what type of data is coming out
int main(void)
{
    string text = get_string("Text: ");
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    //average the no.
    double L = avg(letters, words);
    double S = avg(sentences, words);
    double index = 0.0588 * L - 0.296 * S - 15.8;
    index = (int) round(index); // int convert in brackets convert value in the one in
    int y = grade(index);
    if (y == 0)
    {
        printf("Before Grade 1\n");
    }
    else if (y == 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", y);
    }

}


int count_words(string para)// counting word by checking character value from assci table
{
    int i = 0;
    int word_count = 0;
    while (para[i] != '\0')
    {
        if (para[i] == 32)
        {

            word_count++;
        }
        i++;
    }
    return word_count + 1;
}
int count_letters(string para) // comparing with space value from ascci
{
    int i = 0;
    int letter_count = 0;
    while (para[i] != '\0')
    {
        if (para[i] <= 90 && para[i] >= 65)
        {

            letter_count++;
        }
        else if (para[i] <= 122 && para[i] >= 97)
        {

            letter_count++;
        }
        i++;
    }
    return letter_count;

}
int count_sentences(string para) // comparing with specific value of character like 0,!,?
{
    int i = 0;
    int sentence_count = 0;
    while (para[i] != '\0')
    {
        if (para[i] == 63 || para[i] == 33 || para[i] == 46) // while copying kepping track of style
        {

            sentence_count++;
        }

        i++;
    }
    return sentence_count;
}

double avg(double n, double d)//keep track of return value
{
    double average = n / d * 100;
    return average;

}
int grade(double x)
{
    if (x < 1)
    {
        return 0;
    }
    else if (x > 0 && x < 16)// compare with two end value from alphabate of assci
    {
        return x;
    }
    else
    {
        return 16;
    }
}
// debugger is really best
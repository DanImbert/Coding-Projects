#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>



int main(void)
{


    // Get  user input
    string userinput = get_string("Text: ");

    // length
    int i = strlen(userinput);
    int letters = 0;
    int words = 0;
    int sentences = 0;

    // Loop counting
    for (int x = 0; x < i; x++)
    {
        // Count letters
        char c = userinput[x];
        if (isalpha(c) != 0)
        {
            letters++;
        }

        // Count words
        if (c == ' ')
        {
            words++;
        }

        // Count Sentences
        if (c == '.' || c == '!' || c == '?')
        {
            sentences++;
        }
    }

    // To account for last word
    words = words + 1;

    // Calculation
    float L = ((float)letters / (float)words) * 100;
    float s = ((float)sentences / (float)words) * 100;
    float subindex = 0.0588 * L - 0.296 * s - 15.8;
    int index = round(subindex);
    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }

}



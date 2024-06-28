#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;

    do
  {
      height = get_int("Height: \n");
  }
  while  ((height < 1) || (height > 8));


 // for loop to create the height of the row

    for (int row = 0; row < height; row++)
    {
        // for loop create the width of the piramid
        for (int hash = 0; hash < height; hash++)
        {
            // if row plus column is greater than or equal than height -1 space print the hashes
            if (row + hash >= height - 1)
                printf("#");



            // adding spaces
            else
            printf(" ");

        }

        printf("  ");


for (int hash = height + row + 1; hash > height; hash--)
        {
    printf("#");
}
        printf("\n");
    }

}
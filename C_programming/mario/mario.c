#include <stdio.h>
#include <cs50.h>


int main(void)
{
    int h;
    int i;
    int j;
    do
    {
        h= get_int("Height: \n");
    }
    while (h<1 || h>8);

    for ( i=1; i<=h; i++){

        for (j=0; j<h;j++){
            if (j>=(h-i)){
                printf("#");
            }
            else{
                printf(" ");

            }
        }



        printf("  ");
        for (j=0; j<i;j++){
            printf("#");
        }

        printf("\n");





    }
}

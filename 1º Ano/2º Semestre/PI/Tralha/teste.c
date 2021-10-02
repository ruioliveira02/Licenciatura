#include <stdio.h>

void one(int n)
{
    for(int i = 0; i < n;i++)
    {
        for(int j = 0; j < n;j++)
            putchar('#');

        putchar('\n');
    }
}

void xadrez(int n)
{
    for(int i = 0; i < n;i++)
    {
        for(int j = 0; j < n;j++)
            if(i % 2 == j % 2)
                putchar('#');
            else
                putchar('_');

        putchar('\n');
    }
}

void three(int n)
{
    int i = 1;

    for(; i <= 5; i++)
    {
        for(int j = 0; j < i; j++)
            printf("#");

        printf("\n");
    }

    i--;

    for(; i > 0; i--)
    {
        for(int j = 0; j < i; j++)
            printf("#");

        printf("\n");
    }
}

void threetwo(int n)
{
    int biggest = 2 * n - 1;

    for(int i = 1; i <= n; i++)
    {
        int toPrint = 2 * i - 1;

        for(int j = 0; j < (biggest - toPrint) / 2; j++)
            printf(" ");

        for(int j = 0; j < toPrint; j++)
            printf("#");

        for(int j = 0; j < (biggest - toPrint) / 2; j++)
            printf(" ");

        printf("\n");
    }
}

int full(int x, int y, int r)
{
    return (r - x) * (r - x) + (r - y) * (r - y) <= r * r;
}

int four(int n)
{
    int d = 2 * n + 1;

    for(int i = 0; i < d; i++)
    {
        for(int j = 0; j < d; j++)
            putchar((full(j,i,n)) ? '#' : ' ');

        putchar('\n');
    }
        
}


int main()
{
    one(4);
    xadrez(5);
    three(5);
    threetwo(5);
    four(4);
    return 0;
}
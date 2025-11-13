#include <stdio.h>

int main()
{
    int n, opt = 0;

    do {
        printf("Max numb :\n");
        scanf("%d", &n);
    } while (n>1000000);

    int T_all[n], T_premi[n];
    for (int i = 2; i <= n; i++)
    {
        printf("Nombre : %d :\t", i);
        for (int j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                opt = 1;
                break;
            }
        }

        if (opt == 1)
        {
            printf("n'est premier.");
            opt = 0;
        }
        else
        {
            printf("est premier.");
        }
        printf("\n");
    }
}
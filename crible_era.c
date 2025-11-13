#include <stdio.h>

int main()
{
    int n;
    int pas_pre = 0, pre = 0, opt = 0;

    do {
        printf("Max numb :\n");
        scanf("%d", &n);
    } while (n>1000000);

    int T_premi[n], T_n_premi[n];

    for (int i = 2; i <= n; i++) {
        for (int j = 2; j < i; j++)
        {
            if (i % j == 0){
                opt = 1;
                break;
            }
        }

        if (opt == 1) {
            T_n_premi[pas_pre] = i;
            pas_pre++;
            opt = 0;
        } else {
            T_premi[pre] = i;
            pre++;
        }
    }

    printf("Nombre Premiers \n");
    for (int k = 0; k<pre; k++)
        printf("|%d", T_premi[k]);
        
    printf("|");

    printf("\n\nNombre non Premiers \n");
    for (int k = 0; k<pas_pre; k++)
        printf("|%d", T_n_premi[k]);

    printf("|");
}
// Crée par : Rayane Sirri
#include <stdio.h>

int PGCD(int divis, int divid)
{
    int r;
    printf("Calcul du PGCD etape par etape :\n");

    // Boucle tant que le reste n'est pas nul
    while (divid != 0)
    {
        // Le reste de la division entière
        r = divis % divid;

        // Affichage correct : divis = divid * quotient + reste
        printf("%d = %d * %d + %d\n", divis, divid, divis / divid, r);

        // Mise à jour : le diviseur devient dividende, le reste devient dividende
        divis = divid;
        divid = r;
    }
    return divis;
}

// Fonction récursive pour l'algorithme d'Euclide étendu
int Reverse(int divis, int divid, int *x, int *y)
{
    if (divid == 0)
    {
        *x = 1;
        *y = 0;
        return divis;
    }

    int x1, y1;
    int d = Reverse(divid, divis % divid, &x1, &y1);

    *x = y1;
    *y = x1 - (divis / divid) * y1;
    return d;
}

/*
Application de la proposition 2 : pgcd(a, b)×ppcm(a, b) = |ab|
donc ppcm(a, b) = |ab|/pgcd(a, b)
*/
int PPCM(int a, int b)
{
    int d = PGCD(a, b);
    int pro = a * b;

    printf("Le resultat du ppcm(%d, %d) = |%dx%d|/pgcd(%d, %d) \n= %d/%d = %d", a, b, a, b, a, b, pro, d, pro / d);
}

int resPPCM1, resPPCM2, resPGCD1, resPGCD2;

int Premier()
{
    // Initionation des variables
    int n;
    int pas_pre = 0, pre = 0, opt = 0;

    // L'utilisation de repter justqu'a boucle : Afin d
    do
    {
        printf("Max numb :\n");
        scanf("%d", &n); // Lire la valeur maximal
    } while ((n) > 10000000);

    // Tableaux
    int T_premi[n], T_n_premi[n];

    // Boucle afin de reperer les nombres premiers et non premiers
    // Initionalisation de i par 2 à n; 2 pas 1 car tous les nombres sont divisible par 1
    for (int i = 2; i <= n; i++)
    {
        // Boucle qui cherche les nombres premiers et non premiers donc j doit partir de 2 à i - 1
        // Exemple si i = 9 donc on va rejoindre la deuxieme boucle dont j va de 2 à 9
        for (int j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                // D'apres l'exemple si i = 9 j sera 2 9%2 != 0 donc on doit incrimmenter j, j  = 3 9%3 ==0 donc i = 9 est non premier
                opt = 1; // Joue le role d'un boolean
                break;
            }
        }

        if (opt == 1)
        {
            T_n_premi[pas_pre] = i; // Impementation du nombre non premier au tableau
            pas_pre++;              // Conteur des nombres non premier
            opt = 0;                // retour du 'boolean' à 0
        }
        else
        {
            T_premi[pre] = i; // Impementation du nombre premier au tableau
            pre++;            // Conteur des nombres premier
        }
    }

    // L'affichage des tableaux, j'ai divisé le conteur en 2 afin d'avoir un affichage très elegent, pour les deux nombres; premiers et non premiers
    printf("Nombre Premiers \n");
    for (int w = 0; w <= pre / 2; w++)
        printf("|%d", T_premi[w]);
    printf("|\n");
    for (int w = pre / 2 + 1; w < pre; w++)
        printf("|%d", T_premi[w]);
    printf("|\n");

    printf("\nNombre non Premiers \n");
    for (int w = 0; w <= pas_pre / 2; w++)
        printf("|%d", T_n_premi[w]);
    printf("|\n");
    for (int w = pas_pre / 2 + 1; w < pas_pre; w++)
        printf("|%d", T_n_premi[w]);
    printf("|\n");
}

int main()
{
    int a, b, c, x, y, d;
    int option;

    do
    {
        do
        {
            printf("\n\nProgramme Math Arithmetique | Rayane Sirri GL\n1 : PGCD\n2 : PGCD Etendue\n3 : PGCD de trois variables\n4 : PPCM\n5 : Nombres premiers\n\n0 : Quitter\n");
            scanf("%d", &option);
        } while (option > 6);

        switch (option)
        {
        case 1:
            // Affichage du message pour l'utilisateur
            printf("Veuillez entrer les nombres pour le PGCD et l'equation :\n");
            printf("Entrer le premier nombre a :\t");
            scanf("%d", &a);
            printf("Entrer le deuxieme nombre b :\t");
            scanf("%d", &b);

            d = PGCD(a, b);
            printf("PGCD(%d, %d) = %d\n\n", a, b, d);
            break;
        case 2:
            // Affichage du message pour l'utilisateur
            printf("Veuillez entrer les nombres pour le PGCD et l'equation :\n");
            printf("Entrer le premier nombre a :\t");
            scanf("%d", &a);
            printf("Entrer le deuxieme nombre b :\t");
            scanf("%d", &b);
            printf("Entrer le troisieme nombre c :\t");
            scanf("%d", &c);

            d = PGCD(a, b);
            printf("PGCD(%d, %d) = %d\n\n", a, b, d);

            printf("Resolution de l'equation : %dx + %dy = %d\n\n", a, b, c);

            // Vérification correcte : si c n'est pas divisible par d, pas de solution
            if (c % d != 0)
            {
                printf("Pas de solution entiere car %d ne divise pas %d.\n", d, c);
                return 0;
            }

            printf("Il existe des solutions entieres.\n\n");

            // Calcul des coefficients de Bézout
            Reverse(a, b, &x, &y);

            // Calcul de la solution particulière
            int k = c / d;
            int x_part = y * k;
            int y_part = x * k;

            printf("Une solution particuliere est :\n");
            printf("x = %d, y = %d\n", x_part, y_part);
            printf("Verification : %d x %d + %d x %d = %d\n\n", b, x_part, a, y_part, a * y_part + b * x_part);

            // Affichage des solutions générales (corrigé : ajouté les %d manquants et la syntaxe)
            printf("Les solutions entieres de %dx + %dy = %d sont :\n", a, b, c);
            printf("(x, y) = (%d - %d x k, %d + %d x k)\n", x_part, a / d, y_part, b / d);
            printf("ou k est un entier relatif.\n");
            break;
        case 3:
            // Affichage du message pour l'utilisateur
            printf("Veuillez entrer les nombres pour le PGCD(a,b,c) :\n");
            printf("Entrer le premier nombre a :\t");
            scanf("%d", &a);
            printf("Entrer le deuxieme nombre b :\t");
            scanf("%d", &b);
            printf("Entrer le troisieme nombre c :\t");
            scanf("%d", &c);

            d = PGCD(a, b);
            int res = PGCD(d, c);
            printf("PGCD(%d, %d, %d) = %d\n\n", a, b, c, res);
            break;
        case 4:
            printf("Entrer ppcm(a, b) :\t");
            scanf("%d %d", &a, &b);
            PPCM(a, b);
            break;
        case 5:
            Premier();
            break;
        default:
            break;
        }
    } while (option != 0);
}
// Crée par : Rayane Sirri
#include <stdio.h>

// Declaration des fonctions
int PGCD(int divis, int divid);
int Reverse(int divis, int divid, int *x, int *y);
int PPCM(int a, int b);
int Premier();

int main()
{
    int option, a, b, c, x, y, d;

    do
    {
        do
        {
            printf("_______________________________________________\n");
            printf("| Programme Math Arithmetique | Rayane Sirri GL\n");
            printf("\n[?] Veuillez choisir entre les options suivants\n1 : PGCD(a, b)\n2 : PGCD Etendue : ax + by = c\n3 : PGCD(a, b, c)\n4 : PPCM\n5 : Nombres premiers\n\n0 : Quitter\n\n");
            printf("Votre choix : ");
            scanf("%d", &option);
        } while (option > 6);

        printf("_____________________________________________\n");
        switch (option)
        {
        case 1:
            printf("\nCalcule du PGCD :\n\n");
            // Affichage du message pour l'utilisateur
            printf("[:] Veuillez entrer les 2 nombres pour le PGCD :\n");
            printf("-> Entrer la valeur de a :\n: ");
            scanf("%d", &a);
            printf("-> Entrer la valeur de b :\n: ");
            scanf("%d", &b);

            d = PGCD(a, b);
            printf("\n-> PGCD(%d, %d) = %d\n", a, b, d);

            if (d == 1)
                printf("\n[-] Oh : %d et %d sont premiers entrer eux!\n", a, b);
            printf("\n");
            break;
        case 2:
            printf("\nCalcule du PGCD Etendue + Application de Bezout :\n\n");
            // Affichage du message pour l'utilisateur
            printf("[:] Veuillez entrer les valeurs pour ax + by = c\n");
            printf("-> Entrer la valeur de a :\n: ");
            scanf("%d", &a);
            printf("-> Entrer la valeur de b :\n: ");
            scanf("%d", &b);
            printf("-> Entrer la valeur de c :\n: ");
            scanf("%d", &c);

            d = PGCD(a, b);
            printf("-> PGCD(%d, %d) = %d\n\n", a, b, d);

            if (d == 1)
                printf("\n[-] Oh : %d et %d sont premiers entre eux!\n", a, b);

            printf("[:] Resolution de l'equation : %dx + %dy = %d\n\n", a, b, c);

            // Vérification correcte : si c n'est pas divisible par d, pas de solution
            if (c % d != 0)
            {
                printf("[!] Pas de solution entiere car %d ne divise pas %d.\n", d, c);
                return 0;
            }

            printf("[:] Il existe des solutions entieres.\n\n");

            // Calcul des coefficients de Bézout
            Reverse(a, b, &x, &y);

            // Calcul de la solution particulière
            int k = c / d;
            int x_part = x * k;
            int y_part = y * k;

            printf("[:] Une solution particuliere est :\n");
            printf("->  x = %d, y = %d\n", x_part, y_part);
            printf("[:] Verification : %d x %d + %d x %d = %d\n\n", a, x_part, b, y_part, a * x_part + b * y_part);

            // Affichage des solutions générales (corrigé : ajouté les %d manquants et la syntaxe)
            printf("[:] Les solutions entieres de %dx + %dy = %d sont :\n", a, b, c);
            printf("-> (x, y) = (%d + %d x k, %d - %d x k)", x_part, b / d, y_part, a / d);
            printf(" ou k est un entier relatif.\n\n");
            break;
        case 3:
            printf("\nCalcule du PGCD a trois valeurs:\n\n");
            // Affichage du message pour l'utilisateur
            printf("[:] Veuillez entrer les valeurs pour le PGCD(a,b,c) :\n");
            printf("-> Entrer la valeur de a :\n: ");
            scanf("%d", &a);
            printf("-> Entrer la valeur de b :\n: ");
            scanf("%d", &b);
            printf("-> Entrer la valeur de c :\n: ");
            scanf("%d", &c);

            d = PGCD(a, b);
            int res = PGCD(c, d);
            printf("-> PGCD(%d, %d, %d) = %d\n\n", a, b, c, res);
            break;
        case 4:
            printf("\nCalcule du PPCM\n\n");
            printf("[:] Entrer les valeurs pour calculer le PPCM:\n");
            printf("-> Entrer la valeur de a :\n: ");
            scanf("%d", &a);
            printf("-> Entrer la valeur de b :\n: ");
            scanf("%d", &b);
            PPCM(a, b);
            break;
        case 5:
            printf("\nCalcule des nombres Premiers et Non premiers:\n\n");
            Premier();
            break;
        default:
            break;
        }
    } while (option != 0);
}

int PGCD(int divis, int divid)
{
    if (divis < 0)
        divis = -divis;
    if (divid < 0)
        divid = -divid;
    if (divid == 0 || divis == 0)
        return 0;

    int r;
    printf("\nCalcul du PGCD etape par etape :\n");

    // Boucle tant que le reste n'est pas nul
    while (divid != 0)
    {
        // Le reste de la division entière
        r = divis % divid;

        // Affichage correct : divis = divid * quotient + reste
        printf(": %d = %d * %d + %d\n", divis, divid, divis / divid, r);

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
    if (a < 0)
        a = -a;
    if (b < 0)
        b = -b;
    if (a == 0 || b == 0)
        return 0;

    int d = PGCD(a, b);
    int pro = a * b;

    printf("-> Le resultat du ppcm(%d, %d) = |%dx%d|/pgcd(%d, %d) \n= %d/%d = %d\n\n", a, b, a, b, a, b, pro, d, pro / d);
}

int Premier()
{
    // Initionation des variables
    int n, pas_pre = 0, pre = 0, opt = 0;
    char opti = 'N';

    printf("[:] Entrer la valeur pour calculer les nombres premiers et non premiers:\n");

    // L'utilisation de repter justqu'a boucle : Afin de ne pas avoir une valeur tres grande
    do
    {
        printf("-> Entrer la valeur de n :\n: ");
        scanf("%d", &n); // Lire la valeur de n
    } while ((n) > 1000000);
    
    // Tableaux
    int T_premi[n], T_n_premi[n];

    if (n < 0)
        n = -n;

    printf("[?] Option : Voullez vous afficher les nombres non premiers [O/N] : ");
    scanf(" %c", &opti);

    switch (opti)
    {
    case 'N':
    case 'n':
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
        printf("[:] Nombre Premiers \n");
        for (int w = 0; w <= pre / 2; w++)
            printf("|%d", T_premi[w]);
        printf("|\n");
        for (int w = pre / 2 + 1; w < pre; w++)
            printf("|%d", T_premi[w]);
        printf("|\n");
        break;
    case 'O':
    case 'o':
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
        printf("[:] Nombre Premiers \n");
        for (int w = 0; w <= pre / 2; w++)
            printf("|%d", T_premi[w]);
        printf("|\n");
        for (int w = pre / 2 + 1; w < pre; w++)
            printf("|%d", T_premi[w]);
        printf("|\n");

        printf("\n[:] Nombre non Premiers \n");
        for (int w = 0; w <= pas_pre / 2; w++)
            printf("|%d", T_n_premi[w]);
        printf("|\n");
        for (int w = pas_pre / 2 + 1; w < pas_pre; w++)
            printf("|%d", T_n_premi[w]);
        printf("|\n");
        break;
    default:
        printf("\n[!] Le choix est in correct, retour..\n");
        break;
    }
    printf("\n");
}
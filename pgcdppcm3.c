//Crée par : Rayane Sirri GL
#include <stdio.h>

int resPPCM1, resPPCM2, resPGCD1, resPGCD2;

int PGCD(int divis, int divid) {
    int r;
    printf("Calcul du PGCD etape par etape :\n");
    
    // Boucle tant que le reste n'est pas nul
    while (divid != 0) {
        // Le reste de la division entière
        r = divis % divid;
        
        // Affichage correct : divis = divid * quotient + reste
        printf("%d = %d * %d + %d\n", divis, divid, divis / divid, r);
        
        // Mise à jour : le diviseur devient dividende, le reste devient diviseur
        divis = divid;
        divid = r;
    }
    return divis;
}

/*
Application de la proposition 2 : pgcd(a, b)×ppcm(a, b) = |ab|
donc ppcm(a, b) = |ab|/pgcd(a, b)
*/
int PPCM(int a, int b) {
    int d = PGCD(a,b);
    int pro = a*b;

    printf("Le resultat du ppcm(%d, %d) = |%dx%d|/pgcd(%d, %d) \n= %d/%d = %d\n\n", a, b, a, b, a, b, pro, d, pro/d);
    return pro/d;
}

//Tester les nombres qui verifie pgcd(a,b,c)xppcm(a,b,c)=|abc|
int main() {
    int a, b, c;

    printf("Entrer ppcm(a, b, c) :\t");
    scanf("%d %d %d", &a, &b, &c);
    resPPCM1 = PPCM(a, b);
    resPPCM2 = PPCM(resPPCM1, c);

    resPGCD1 = PGCD(a, b);
    resPGCD2 = PGCD(resPGCD1, c);

    int prod = a*b*c;
    printf("\nCalcul :\n\npgcd(%d, %d, %d) = %d\nppcm(%d, %d, %d) = %d\npgcd(%d, %d, %d)*ppcm(%d, %d, %d) = %d", a, b, c, resPGCD2, a, b, c, resPPCM2, a, b, c, a, b, c, resPGCD2*resPPCM2);

    if (resPPCM2*resPGCD2 == prod)
        printf("\ncorrect!!! cette methode a reussi!");

}
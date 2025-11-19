//Crée par : Rayane Sirri GL
#include <stdio.h>

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

    printf("Le resultat du ppcm(%d, %d) = |%dx%d|/pgcd(%d, %d) \n= %d/%d = %d", a, b, a, b, a, b, pro, d, pro/d);
}

int main() {
    int a, b;

    printf("Entrer ppcm(a, b) :\t");
    scanf("%d %d", &a, &b);
    PPCM(a, b);

}
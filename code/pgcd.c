//Creé par : Sirri Rayane GL
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

int main() {
    // Initialisation des variables
    int a, b;
    
    // Affichage du message pour l'utilisateur
    printf("Veuillez entrer les nombres pour le PGCD et l'equation :\n");
    printf("Entrer le premier nombre a :\t");
    scanf("%d", &a);
    printf("Entrer le deuxieme nombre b :\t");
    scanf("%d", &b);
    
    int d = PGCD(a, b);
    printf("PGCD(%d, %d) = %d\n\n", a, b, d);

    return 0;
}
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

// Fonction récursive pour l'algorithme d'Euclide étendu
int Reverse(int divis, int divid, int *x, int *y) {
    if (divid == 0) {
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

int main() {
    // Initialisation des variables
    int a, b, c, x, y;
    
    // Affichage du message pour l'utilisateur
    printf("Veuillez entrer les nombres pour le PGCD et l'equation :\n");
    printf("Entrer le premier nombre a :\t");
    scanf("%d", &a);
    printf("Entrer le deuxieme nombre b :\t");
    scanf("%d", &b);
    printf("Entrer le troisieme nombre c :\t");
    scanf("%d", &c);
    
    int d = PGCD(a, b);
    printf("PGCD(%d, %d) = %d\n\n", a, b, d);
    
    printf("Resolution de l'equation : %dx + %dy = %d\n\n", a, b, c);
    
    // Vérification correcte : si c n'est pas divisible par d, pas de solution
    if (c % d != 0) {
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
    printf("Verification : %d x %d + %d x %d = %d\n\n", a, x_part, b, y_part, a * x_part + b * y_part);
    
    // Affichage des solutions générales (corrigé : ajouté les %d manquants et la syntaxe)
    printf("Les solutions entieres de %dx + %dy = %d sont :\n", a, b, c);
    printf("(x, y) = (%d + %d x k, %d - %d x k)\n", x_part, b / d, y_part, a / d);
    printf("ou k est un entier relatif.\n");
    
    return 0;
}
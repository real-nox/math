//Creé par : Sirri Rayane GL

#include <stdio.h>

int main() {
    //initialisation des variables
    int divis, divid, r;

    //Deux variables pour affichage à la fin
    int a,b;

    //Affichage du message pour l'utilisateur
    printf("Veuillez entrer les nombres pour le PGCD :\n");

    //Entrées des données par l'utilisateur
    scanf("%d", &divis);
    scanf("%d", &divid);

    a = divis;
    b = divid;

    //Boucle TantQue le rest n'est pas nul
    while (divid!=0)
    {
        //Le reste de la division entière
        r = divis%divid;

        printf("%d = %d x %d + %d\n", divis, divid, divis / divid, r); //Note : dans printf j'ai utilisé (divis / divid) pour afficher le quotient entier

        divis = divid; //Le diviseur devient dividende
        divid = r;//Le dividende devient le reste
    }
    if (divis == 1) {
        printf("%d et %d sont premiers entre eux car pgcd(%d, %d) = 1",a,b,a,b);
    } else {
        printf("pgcd(%d,%d) = %d\n", a, b, divis);
    } 

}

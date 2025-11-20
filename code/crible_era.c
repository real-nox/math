//Crée par : Rayane Sirri
#include <stdio.h>

int main() {
    //Initionation des variables
    int n;
    int pas_pre = 0, pre = 0, opt = 0;

    //L'utilisation de repter justqu'a boucle : Afin d
    do {
        printf("Max numb :\n");
        scanf("%d", &n); //Lire la valeur maximal
    } while ((n)>10000000);

    //Tableaux
    int T_premi[n], T_n_premi[n];

    //Boucle afin de reperer les nombres premiers et non premiers
    //Initionalisation de i par 2 à n; 2 pas 1 car tous les nombres sont divisible par 1
    for (int i = 2; i <= n; i++) {
        //Boucle qui cherche les nombres premiers et non premiers donc j doit partir de 2 à i - 1
        //Exemple si i = 9 donc on va rejoindre la deuxieme boucle dont j va de 2 à 9
        for (int j = 2; j < i; j++) {
            if (i % j == 0){
                //D'apres l'exemple si i = 9 j sera 2 9%2 != 0 donc on doit incrimmenter j, j  = 3 9%3 ==0 donc i = 9 est non premier
                opt = 1;//Joue le role d'un boolean
                break;
            }
        }

        if (opt == 1) {
            T_n_premi[pas_pre] = i;//Impementation du nombre non premier au tableau
            pas_pre++;//Conteur des nombres non premier
            opt = 0;//retour du 'boolean' à 0
        } else {
            T_premi[pre] = i;//Impementation du nombre premier au tableau
            pre++;//Conteur des nombres premier
        }
    }

    //L'affichage des tableaux, j'ai divisé le conteur en 2 afin d'avoir un affichage très elegent, pour les deux nombres; premiers et non premiers
    printf("Nombre Premiers \n");
    for (int w = 0; w<=pre/2; w++)
        printf("|%d", T_premi[w]);
    printf("|\n");
    for (int w = pre/2+1; w<pre; w++)
        printf("|%d", T_premi[w]);
    printf("|\n");

    printf("\nNombre non Premiers \n");
        for (int w = 0; w<=pas_pre/2; w++)
        printf("|%d", T_n_premi[w]);
    printf("|\n");
    for (int w = pas_pre/2+1; w<pas_pre; w++)
        printf("|%d", T_n_premi[w]);
    printf("|\n");

}
#include <stdio.h>
#include <stdlib.h>
#include "tp4.h"

int main() {
    T_Element* liste = NULL;
    liste = ajouterInscription(liste, "NF02");
    liste = ajouterInscription(liste, "NF22");
    liste = ajouterInscription(liste, "AI15");
    liste = ajouterInscription(liste, "MT02");
    liste = ajouterInscription(liste, "MT45");
    liste = ajouterInscription(liste, "ZI01");
    if (liste == NULL) printf("LISTE VIDE");
    while (liste != NULL) {
        printf("%s\n", liste->code_uv);
        liste = liste -> suivant;
    }



    return 0;
}

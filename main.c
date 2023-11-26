#include <stdio.h>
#include <stdlib.h>
#include "tp4.h"

int main(){
    T_Arbre abr = NULL;
    // ============= MENU UTILISATEUR ============= */
    char choix = '0';
    while (choix != '6') {
        printf("\n======================================");
        printf("\n1. Inscrire un eleve à une UV");
        printf("\n2. Charger un fichier d'inscriptions");
        printf("\n3. Afficher tous les étudiants");
        printf("\n4. Afficher les inscrits à une UV");
        printf("\n5. Supprimer une inscription");
        printf("\n6. Quitter");
        printf("\n======================================");
        printf("\n   Votre choix ? ");

        choix = getchar();

        switch (choix) {
            case '1' :
               abr = inscrireEtuUV(abr);
                break;
            case '2' :
                abr = faireChargerFichier(abr);
                break;

            case '3' :
                if (abr == NULL) printf("\nAucun élève est inscrit !\n");
                else afficherInscriptions(abr);
                break;

            case '4' :
                faireAfficherInscriptionsUV(abr);
                break;

            case '5' :
                abr = faireSuppInscription(abr);

                break;

            case '6' :
                freeAbre(abr);
                printf("\n======== PROGRAMME TERMINE ========\n");
                break;

            default :
                printf("\n\nERREUR : votre choix n'est valide ! ");
        }
        printf("\n\n\n");
        viderBuffer(); // supprimer de l'entr�e standard le retour charriot et les �ventuels caract�res suppl�mentaires tap�s par l'utilisateur
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "tp4.h"

int main(){
    T_Arbre abr = NULL;
    abr = chargerFichier(abr,"liste_uv.txt");
    afficherInscriptions(abr);
////    printf("_________________________________________________________________________________________\n\n\n\n\n");
////
    abr = supprimerInscription(abr,"MARTIN","ROMANE","AI13");
    abr = supprimerInscription(abr,"MARTIN","ROMANE","MT11");
    afficherInscriptions(abr);
    // ============= MENU UTILISATEUR ============= */
//    char choix = '0';
//    while (choix != '6') {
//        printf("\n======================================");
//        printf("\n0. Avancer la date de n jours");
//        printf("\n1. Afficher la liste des blocs de la BlockChain");
//        printf("\n2. Afficher toutes les transactions d'un bloc");
//        printf("\n3. Afficher toutes les transactions du jour pour un etudiant");
//        printf("\n4. Afficher l'historique pour un etudiant");
//        printf("\n5. Crediter un compte");
//        printf("\n6. Quitter");
//        printf("\n======================================");
//        printf("\n   Votre choix ? ");
//
//        choix = getchar();
//
//        switch (choix) {
//            case '0' :
//                ma_chaine_de_blocs = avancerDate(ma_chaine_de_blocs);
//                break;
//            case '1' :
//                afficherBlockchain(ma_chaine_de_blocs);
//                break;
//            case '2' :
//                afficherUnBloc(ma_chaine_de_blocs);
//                break;
//
//            case '3' :
//                afficherTransactionsDuJour(ma_chaine_de_blocs);
//                break;
//
//            case '4' :
//                afficheHistorique(ma_chaine_de_blocs);
//                break;
//
//            case '5' :
//                crediterUnCompte(ma_chaine_de_blocs);
//                break;
//
//            case '6' :
//                payerUnRepas(ma_chaine_de_blocs);
//                break;
//
//            case '7' :
//                faireTransfert(ma_chaine_de_blocs);
//               break;
//
//            case '8' :
//                viderMemoire(ma_chaine_de_blocs);
//                printf("\n======== PROGRAMME TERMINE ========\n");
//                break;
//
//            default :
//                printf("\n\nERREUR : votre choix n'est valide ! ");
//        }
//        printf("\n\n\n");
//        viderBuffer(); // supprimer de l'entr�e standard le retour charriot et les �ventuels caract�res suppl�mentaires tap�s par l'utilisateur
//    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tp4.h"

T_Element* creerElement(char* code_uv) {
    T_Element* elt = (T_Element*)malloc(sizeof(T_Element));
    if (elt != NULL) {
    elt -> code_uv = (char*) malloc(sizeof(T_Element));
    strcpy(elt->code_uv,code_uv);
    }
    elt->suivant = NULL;
    return elt;
}
T_Noeud* creerNoeud(char* nom, char* prenom) {
    T_Noeud* nvNoeud = (T_Noeud*)malloc(sizeof(T_Noeud));
    if (nvNoeud != NULL) {
    nvNoeud->nom = (char*) malloc(strlen(nom) + 1);
    nvNoeud->prenom = (char*) malloc(strlen(prenom) + 1);
    if (nvNoeud->nom != NULL) strcpy(nvNoeud->nom, nom);
    if (nvNoeud->prenom != NULL) strcpy(nvNoeud->prenom, prenom);

    nvNoeud->listeInscriptions = NULL;

    nvNoeud->filsDroit = NULL;
    nvNoeud->filsGauche = NULL;

    return nvNoeud;
    } else {
        printf("Probleme dans l'allocation memoire\n");
        return NULL;
    }
}

T_Noeud* rechercheEtu(T_Arbre abr, char* nom, char* prenom) { // DONT KNOW IF I SHOULD USE THIS ONE
    T_Noeud* pt = abr;
    while (pt != NULL) {
        if (compareNoeud(pt,nom,prenom) == 0) {
            return pt;
        }
        if (compareNoeud(pt,nom,prenom) < 0) { // cas ou l'élève est superieur au noeud => on va a droite
                pt = pt->filsDroit;
        } else {
            pt = pt->filsGauche;
        }
     }
    return pt;
}

T_Noeud* pereMinAbre(T_Arbre abr, T_Noeud* pereArbre) { /* retourne le pere du minimum de l'abre, donc si on veut le min ca sera son fils gauche (c'est utile pour la suppression),
    si le min est le premier noeud de l'abre donc n'a pas de fils gauche, la fonction retourne simplement le pere */
    T_Noeud* pt = abr;
    if (pt == NULL) return NULL;
    if (pt->filsGauche == NULL) return pereArbre;
    pt = pt->filsDroit;
    while (pt->filsGauche->filsGauche != NULL) {
        pt = pt->filsGauche;
    }

    return pt;
}

char* removeSpace(char* str) {
    char* nstr = (char*)malloc(sizeof(str) + 1);
    int i;
    int j = 0;
    for (i = 0; i<strlen(str); ++i) {
        if (str[i] != ' ') {
            nstr[j] = str[i];
            j++;
        }
    }
    nstr[++j] = "\0";
    return nstr;
}
void upperCase(char* str) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = toupper(str[i]);
        }
        i++;
    }
}


int compareNoeud(T_Noeud* n1,char* nom, char* prenom ) { // retourn 0 si les noeuds sont egales, -1 si celui de gauche est plus petit, 1 sinon
    if (strcmp(n1->nom, nom) < 0) return -1;
    if (strcmp(n1->nom, nom) > 0) return 1;
    if (strcmp(n1->nom, nom) == 0) {
        if (strcmp(n1->prenom, prenom) < 0) return -1;
        if (strcmp(n1->prenom, prenom) > 0) return 1;
    };
    return 0;
};

void afficherNoeud(T_Noeud* n) {
    T_Element* liste_uv = n->listeInscriptions;
    printf("nom: %s prenom: %s",n->nom,n->prenom);
    if (liste_uv != NULL) {
        printf("\n LISTE UV: ");
        while (liste_uv != NULL) {
            printf(" %s ", liste_uv->code_uv);
            liste_uv = liste_uv->suivant;
        }
        printf("\n");
    }
}


T_Element* ajouterInscription(T_Element* liste, char* code) { // A TESTER
    int out = 0;
    int first = 1;
    T_Element* pt = liste;
    T_Element* prec = NULL;
    T_Element* uv = creerElement(code);
    if (liste == NULL) {
        uv->suivant = NULL;
        return uv;
    }
    while (pt != NULL && out == 0) {

        if (strcmp(code, pt->code_uv) == 0 ){ // cas ou l'UV existe deja
            out = 1;
            continue;
        }; // ? on peut afficher qlquchose dans le cas ou l'uv existe deja dans la liste...
        if (strcmp(code, pt->code_uv) < 0) { // cas ou le code de l'uv et plus petit que le code pt
            uv->suivant = pt;
            if (first == 1) { // cas on on insere en tete
                liste = uv;
            }
            else {
                prec->suivant = uv;
            }
            out = 1;
            continue;
        }
        if (strcmp(code, pt->code_uv) > 0) { //  cas ou le code de l'uv est plus grand que le code de pt
            prec = pt;
            pt = pt->suivant;
            first = 0;
        }
    }
    if (pt == NULL) { // dans le cas ou l'�l�ment est le dernier de la liste
        uv -> suivant = NULL;
        prec->suivant = uv;
    }
    return liste;
 }

 T_Arbre inscrire(T_Arbre abr, char* nom, char* prenom, char* code) {
     T_Noeud* prec = NULL;
     T_Noeud* pt = abr;
     T_Noeud* nvNoeud;
     while (pt != NULL) {
        if (compareNoeud(pt,nom,prenom) == 0) { // cas ou l'eleve existe deja
        //printf("Eleve existe\n");
            pt->listeInscriptions = ajouterInscription(pt->listeInscriptions,code);
            return abr;
        }
        prec = pt; //prec est le pere du noeud pt
        if (compareNoeud(pt,nom,prenom) < 0) { // cas ou l'élève est superieur au noeud => on va a droite
                pt = pt->filsDroit;
        } else {
            pt = pt->filsGauche;
        }
     }
        nvNoeud = creerNoeud(nom, prenom);
        nvNoeud->listeInscriptions = ajouterInscription(nvNoeud->listeInscriptions,code);
    if (prec == NULL) { //cas ou l'abre est vide
        abr = nvNoeud;
        return abr;
     }
    if (compareNoeud(prec,nom,prenom) < 0) { // on lie le nouveau neoud a son pere, a droite si il est superieur, a gauche sinon
        prec->filsDroit = nvNoeud;
    } else {
        prec->filsGauche = nvNoeud;
        }
    return abr;
 }

T_Arbre chargerFichier(T_Arbre abr, char* filename) {
    char prenom[50];
    char nom[50];
    char code[5];
    int i;
    int j;
    FILE* ptfile;
    ptfile = fopen(filename, "r");
    if (ptfile == NULL) return NULL;  // cas ou le fichier n'a pas pu ètre ouvert
    char line[200];
    while (fgets(line, 200, ptfile) != NULL) {
       // printf("line: %s \n", line);
        i = 0;
        j = 0;
        while (line[i] != ';') {
            nom[j] = line[i];
            i++;
            j++;
        }
        i++;
       nom[j] = '\0';
       j = 0;

        while (line[i] != ';') {
            prenom[j] = line[i];
            j++;
            i++;

        }
        i++;
       prenom[j] = '\0';
        j = 0;
        while (line[i] != '\n' && line[i] != '\r' ) {
            code[j] = line[i];
            j++;
            i++;

        }
       // printf("code: %s", code);
       code[j] = '\0';

       upperCase(nom);
       upperCase(prenom);
       upperCase(code);

       abr = inscrire(abr, nom, prenom, code);

    }
    fclose(ptfile);
    return abr;
}

void afficherInscriptions(T_Arbre abr) { //parcours infixe pour conserver l'ordre
    if (abr != NULL){
        afficherInscriptions(abr->filsGauche);
        afficherNoeud(abr);
        afficherInscriptions(abr->filsDroit);
    }

}

T_Element* supprimerUV(T_Element* liste, char* code) {
    T_Element* pt = liste;
    T_Element* prec = NULL;
    int found = 0;
    while (pt != NULL && found == 0) {
        if (strcmp(pt->code_uv, code) == 0) found = 1;
        else {
            prec = pt;
            pt = pt->suivant;
        }
    }
    if (found == 0) return liste;
    if (prec == NULL) {
        liste = pt->suivant;
        free(pt);
    }
    else {
        prec->suivant = pt->suivant;
        free(pt);
    }
    return liste;

}

T_Arbre supprimerInscription(T_Arbre abr, char* nom, char* prenom, char* code) {
    T_Noeud* pt;
    T_Noeud* pere = NULL;
    int found = 0;
    if (abr == NULL) {
        printf("L'abre est vide, il n'y a rien a supprimer.");
        return NULL;
    }
    pt = abr;
    while (pt != NULL && found == 0) {
        if (compareNoeud(pt, nom, prenom) == 0) found = 1;
        else {
            pere = pt;
            if (compareNoeud(pt, nom, prenom) == -1) pt=pt->filsDroit;
            else pt=pt->filsGauche;
        }
    }

    if (found == 0) {
        printf("Il n'y avait pas cette incription dans l'abre.");
        return abr;
        }                                         //si l'eleve n'est pas incrit on change juste pas l'abre
    pt->listeInscriptions = supprimerUV(pt->listeInscriptions,code);
    if (pt->listeInscriptions == NULL) abr = supprimerNoeud(abr, pere, pt);
    printf("Succes de l'opération.");
    return abr;
}


void afficherInscriptionsUV(T_Arbre abr, char* code) {
    T_Element* elt;
    int found = 0;
    if (abr != NULL){
        afficherInscriptionsUV(abr->filsGauche, code);
        elt = abr -> listeInscriptions;
        while (elt != NULL && found == 0) {
            if (strcmp(elt->code_uv,code) == 0) {
                found = 1;
            }
            else {

                elt = elt->suivant;
            }

        }
        if (found == 1) printf("nom: %s prenom: %s\n",abr->nom, abr->prenom);
        afficherInscriptionsUV(abr->filsDroit, code);
    }
}

T_Arbre supprimerNoeud(T_Arbre abr, T_Noeud* noeudPere, T_Noeud* noeud) {
    T_Noeud* succ;
    T_Noeud* pereSucc;
    if (abr == NULL || noeud == NULL) return NULL; // Cas ou l'abre est vide ou le noeud qu'on veut supprimer n'éxiste pas

    if (noeud->filsGauche == NULL && noeud->filsDroit == NULL) { // si le neoud est une feuille on le détache de son père
        if (noeudPere == NULL) { // si c'est la racine après suppression on a l'abre vide
           freeNoeud(noeud);
           return NULL;
        }
        if (noeud == noeudPere->filsDroit) {
            noeudPere->filsDroit = NULL;
        }
        else noeudPere->filsGauche = NULL;
    }
    else {
        if (noeud->filsDroit == NULL) {                         // si le neoud a que un fils gauche on attache son fils gauche a son père
           if (noeudPere == NULL) {                             // si c'est la racine, la nouvelle racine devient le fils gauche
               abr = noeud-> filsGauche;
               freeNoeud(noeud);
               return abr;
           }
           if (noeud == noeudPere->filsGauche) {
               noeudPere->filsGauche = noeud->filsGauche;
           } else {
               noeudPere->filsDroit = noeud->filsGauche;
           }
        }
        else {
            if (noeud->filsGauche == NULL) {                     // si le neoud a que un fils droit on attache son fils droit a son père
            if (noeudPere == NULL) {                            // si c'est la racine, la nouvelle racine devient le fils droit
               abr = noeud->filsDroit;
               freeNoeud(noeud);
               return abr;
            }

            if (noeud == noeudPere->filsGauche) {
                noeudPere->filsGauche = noeud->filsDroit;
            }
            else {
                noeudPere->filsDroit = noeud->filsDroit;
            }
        }
            else {                                            // si le noeud a deux fils, on remplace les valeurs du noeud par celles de son succeseur et on supprime son successeur
                pereSucc = pereMinAbre(noeud->filsDroit, noeud);       // on trouve le successeur et son pere pour pourvoir le supprimer ensuite
                if (pereSucc == noeud) {                            // si le la fonction retourn le noeud cela veut dire que le minimum du sous arbre droit est la racine de celui ci
                    succ = pereSucc->filsDroit;
                } else {
                    succ = pereSucc->filsGauche;
                }

                //on change les valeurs du neoud a celles de son successeur
                noeud->listeInscriptions = succ->listeInscriptions;
                noeud ->nom = succ->nom;
                noeud ->prenom = succ->prenom;
                // on supprime le successeur
                abr = supprimerNoeud(abr, pereSucc, succ);
            }
        }
    }
    freeNoeud(noeud);
    return abr;
}


// FONCTIONS POUR MENU

void viderBuffer() {
    int c = 0;
    while (c != '\n' && c != EOF) {
        c = getchar();
    }
}

T_Arbre inscrireEtuUV(T_Arbre abr) {   //Inscrire un étudiant à une UV
    char nom[50];
    char prenom[50];
    char codeUV[6];
    int read;
    printf("NOM: ");
    read = scanf("%s", &nom);
    while (read == 0) {
        viderBuffer();
        printf("\n Mavaise saisie veuillez réssayer: ");
        read = scanf("%s", &nom);
    }
    printf("\nPRENOM: ");
    read = scanf("%s", &prenom);
    while (read == 0) {
        viderBuffer();
        printf("\n Mavaise saisie veuillez réssayer: ");
        read = scanf("%s", &prenom);
    }
    printf("\nCODE UV: ");
    read = scanf("%s", &codeUV);
    while (read == 0) {
        viderBuffer();
        printf("\n Mavaise saisie veuillez réssayer: ");
        read = scanf("%s", &codeUV);
    }

    upperCase(nom);
    upperCase(prenom);
    upperCase(codeUV);

    abr = inscrire(abr, nom, prenom, codeUV);

    return abr;
}

T_Arbre faireChargerFichier(T_Arbre abr) {
   char nomFichier[50];
   int read;
   T_Arbre new_abr;
    printf("\nNOM DU FICHIER (il doit ètre dans le mème fichier que le programme): ");
    read = scanf("%s", &nomFichier);
    while (read == 0) {
        viderBuffer();
        printf("\n Mavaise saisie veuillez réssayer: ");
        read = scanf("%s", &nomFichier);
    }
    new_abr = chargerFichier(abr, nomFichier);
    if (new_abr == NULL) {
        printf("\nLe fichier n'a pas pu ètre chargé");
        return abr;
    }
    printf("Succes de l'opération.");
    return new_abr;
}

void faireAfficherInscriptionsUV(T_Arbre abr) {
    char codeUV[6];
    int read;
    printf("\nCODE UV: ");
    read = scanf("%s", &codeUV);
    while (read == 0) {
        viderBuffer();
        printf("\n Mavaise saisie veuillez réssayer: ");
        read = scanf("%s", &codeUV);
    }
    upperCase(codeUV);
    afficherInscriptionsUV(abr,codeUV);

}

T_Arbre faireSuppInscription(T_Arbre abr) {
    char prenom[50];
    char nom[50];
    char codeUV[6];
    int read;
    printf("NOM: ");
    read = scanf("%s", &nom);
    while (read == 0) {
        viderBuffer();
        printf("\n Mavaise saisie veuillez réssayer: ");
        read = scanf("%s", &nom);
    }
    printf("\nPRENOM: ");
    read = scanf("%s", &prenom);
    while (read == 0) {
        viderBuffer();
        printf("\n Mavaise saisie veuillez réssayer: ");
        read = scanf("%[^\n]s", &prenom);
    }
    printf("\nCODE UV: ");
    read = scanf("%s", &codeUV);
    while (read == 0) {
        viderBuffer();
        printf("\n Mavaise saisie veuillez réssayer: ");
        read = scanf("%s", &codeUV);
    }

    upperCase(nom);
    upperCase(prenom);
    upperCase(codeUV);

    abr = supprimerInscription(abr, nom, prenom, codeUV);

    return abr;
}

// FONCTIONS DE LIBERATION DE MEMOIRE

void freeNoeud(T_Noeud* noeud) {
    T_Element* elt = noeud->listeInscriptions;
    T_Element* tmp;
    while (elt != NULL) {
        tmp = elt;
        elt = elt->suivant;
        free(tmp);
    }
    free(noeud->nom);
    free(noeud->prenom);
    free(noeud);
}

void freeAbre(T_Arbre abr) {
    if (abr != NULL) {
        freeAbre(abr->filsGauche);
        freeNoeud(abr);
        freeAbre(abr->filsDroit);
    }
}

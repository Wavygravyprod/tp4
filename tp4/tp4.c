#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tp4.h"

char* removeSpace(char* str) {
    char* nstr;
    int i;
    for (i = 0; i<strlen(str); ++i) {
        if (str[i] != " ") nstr = strcat(nstr,str);
        i++;
    }
    return nstr;
}
int compareUV(char* code1, char* code2) { // 1 si code1 plus petit 2 sinon, 0 si egal
    int diff = 0;
    int result = 0;
    int i = 0;
    while (diff == 0 && i<strlen(code1)) {
        if (code1[i] == code2[i]) {
            ++i;
            continue;
        };
        if (code1[i] < code2[i]) {
            result = 1;
            diff = 1;
        };
        if (code1[i] > code2[i]) {
            result = 2;
            diff = 1;
        };
    }
    return(result);

}

/* int compareNoms(char* nom1, char* nom2) {
    int i = 0;
    int result = 0;
    int diff = 0;
    char* nom1 = removeSpace(char* nom1);
    while (diff == 0 && i< min(strlen(nom1), strlen(nom2)) {

    }

} */



 T_Element* ajouterInscription(T_Element* liste, char* code) {
    int out = 0;
    int first = 1;
    T_Element* pt = liste;
    T_Element* prec = NULL;
    T_Element* uv = (T_Element*)malloc(sizeof(T_Element));
    uv -> code_uv = code;
    if (liste == NULL) {
        printf("Dans le cas lise vide\n");
        uv->suivant = NULL;
        return uv;
    }
    while (pt != NULL && out == 0) {

       printf("compare: %d\n", compareUV(code, pt->code_uv));
        if (compareUV(code, pt->code_uv) == 0 ){ // cas ou l'UV existe deja
            out = 1;
            continue;
        }; // ? on peut afficher qlquchose dans le cas ou l'uv existe deja dans la liste...
        if (compareUV(code, pt->code_uv) == 1) { // cas ou le code de l'uv et plus petit que le code pt
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
        if (compareUV(code, pt->code_uv) == 2) { //  cas ou le code de l'uv est plus grand que le code de pt
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

 /* T_Arbre inscrire(T_Arbre abr, char* nom, char* prenom, char* code) {
     T_Noeud* y = NULL;
     T_Noeud* x = abr;
     while (x != NULL) {
        y = x;
        if (compareNom(nom , x->nom)== 1) {

        }
     }

 } */



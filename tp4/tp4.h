#ifndef TP4_H_INCLUDED
#define TP4_H_INCLUDED

typedef struct Element {
    char* code_uv;
    struct Element* suivant;
}T_Element;

typedef struct Noeud {
    char* nom;
    char* prenom;
    T_Element* listeInscriptions;
    struct Noeud* filsGauche;
    struct Noeud* filsDroit;
}T_Noeud;

typedef T_Noeud* T_Arbre;

 //FONCTIONS DE BASE

 T_Element* ajouterInscription(T_Element* liste, char* code);

 T_Arbre inscrire(T_Arbre abr, char* nom, char* prenom, char* code);

 T_Arbre chargerFichier(T_Arbre abr, char* filename);
 //si l'abre et deja cree on ajoute le contenu ,ON NE CREER PAS UN ARBRE POUR CHAQUE FICHIER

 void afficherInscriptionsUV(T_Arbre abr, char* code);

 T_Arbre supprimerInscription(T_Arbre abr, char* nom, char* prenom, char* code);

 //fonction extra
 int compareUV(char* code1, char* code2);
 char* removeSpace(char* str);


#endif // TP4_H_INCLUDED

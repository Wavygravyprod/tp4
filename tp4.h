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

 //fonctions extra
 char* removeSpace(char* str);
 int compareNoeud(T_Noeud* n1,char* nom, char* prenom);
 void upperCase(char* str);
 T_Noeud* creerNoeud(char* nom, char* prenom);
 T_Element* creerElement(char* code_uv);
 T_Element* pereMinArbre(T_Arbre abr);
 T_Arbre supprimerNoeud(T_Arbre abr, T_Noeud* noeudPere, T_Noeud* noeud);
 T_Element* supprimerUV(T_Element* liste, char* code);
 

 void viderBuffer();
 T_Arbre inscrireEtuUV(T_Arbre abr);
 T_Arbre faireChargerFichier(T_Arbre abr);
 T_Arbre faireSuppInscritpion(T_Arbre abr);
 void freeNoeud(T_Noeud* noeud);


#endif // TP4_H_INCLUDED

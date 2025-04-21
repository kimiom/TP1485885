#include<stdio.h>
#include<stdlib.h>
typedef struct Noeud{
    int valeur;
    struct Noeud *sui,hhhhhhhhhhhhhhhvant;
}Noeud;

Noeud * cree(int _value){
    Noeud *NV;
    NV=(Noeud*)malloc(sizeof(Noeud));
    NV->valeur=_value;
    NV->suivant=NULL;
    return NV;
}
void affiche (Noeud * debut)
{
    Noeud * courant;
    courant = debut;
    while(courant!=NULL)
    { 
        printf("la valeur est %d\n",courant->valeur);
        courant= courant->suivant;
    }
}
Noeud * ajouterD(Noeud *debut, int _value)
{
    Noeud *NV;
    NV=(Noeud*)malloc(sizeof(Noeud*));
    NV->valeur=_value;
    NV->suivant=NULL;
    if(debut == NULL)
    {
        debut=NV;
    }
    NV->suivant=debut;
    debut= NV;
    return debut;
}

Noeud * ajouterF(Noeud *debut, int _value)
{
    Noeud *NV;
    NV=(Noeud*)malloc(sizeof(Noeud*));
    NV->valeur=_value;
    NV->suivant=NULL;
    if(debut == NULL)
    {
        debut=NV;
    }
    Noeud *courant; 
    courant = debut;
    while(courant->suivant!=NULL)
    {
        courant = courant->suivant;
    }
    courant->suivant=NV;
    return debut;
}
void rechercher(Noeud *debut, int _value)
{   int trouve;
    Noeud *courant;
    courant=debut;
    while(courant != NULL)
    {  
        if(courant->valeur == _value)
        {
            trouve =1;
        break;
        }
        else
        {
            trouve = 0;
        }
        courant =courant->suivant;
    } 
    if(trouve==1)
    printf("la valeur existe\n");
    else
    printf("la valeur n'existe pas\n");
}
int taille(Noeud *debut)
{
    int taille=0;
    Noeud *courant;
    courant = debut;
    while(courant!=NULL)
    {
        taille++;
        courant=courant->suivant;
    }
    return taille;
}

Noeud * insertion(Noeud * debut, int pos, int val)
{
    Noeud *NV,*courant;
    NV=(Noeud*)malloc(sizeof(Noeud*));
    NV->valeur=val;
    NV->suivant=NULL;
    int size = taille(debut);
    if(pos<1 || pos>size+1)
    {
        printf("la position est incorrecte");
    }
    else if (pos==1)
    {
        NV->suivant = debut;
        debut = NV;
    }
    else{
        courant = debut;
        for(int i =1 ; i< pos-1 ; i++)
        {
            courant = courant->suivant;
        }
        NV->suivant=courant->suivant;
        courant->suivant=NV;
    }
return debut;
}
Noeud * suppressionD(Noeud *debut)
{   Noeud *P;
    P=debut;
    if(debut == NULL)
    {printf("la liste est vide");}
    else{
        debut = debut->suivant;
        free(P);
    }
    return debut;
}
Noeud * suppressionF(Noeud *debut)
{
    if (debut == NULL)
    printf("la liste est vide");
    Noeud *courant;
    courant=debut;
    if(courant->suivant == NULL)
    {
        free(courant);
        printf("l'element a été bien supprimé");
    }
    while(courant->suivant->suivant!=NULL)
    {
        courant=courant->suivant;
    }
    free(courant->suivant);
    courant->suivant=NULL;
    return debut;
}
Noeud *suppressionP(Noeud* debut, int pos)
{   Noeud *courant,*tmp;
    courant=debut;
    tmp=debut;
    int i;
    if(debut == NULL)
    {printf("la liste est vide");
    return NULL;}
    int size= taille(debut);
    if(pos<1 || pos>size)
    {printf("la position est invalide");
    return debut;}
    if (pos==1)
    {
        debut=debut->suivant;
        free(courant);
        return debut;
    }
    for(i=1;i<pos-1;i++)
    {
        courant= courant->suivant;
    }
    tmp=courant->suivant;
    courant->suivant=tmp->suivant;
    free(tmp);
    return debut;

}
Noeud* modifierD(Noeud * debut, int _value)
{
    if(debut == NULL)
    return NULL;
    debut->valeur=_value;
    return debut;
}
Noeud * modifierF(Noeud * debut, int _value)
{
    if(debut == NULL)
    {
        printf("la liste est vide");
        return NULL;
    }
    Noeud *courant;
    courant=debut;
    while(courant->suivant!= NULL)
    {
        courant=courant->suivant;
    }
    courant->valeur=_value;
    return debut;

}
Noeud * modifierP(Noeud *debut, int pos, int _value)
{ int i;
    if(debut == NULL)
    {
        printf("la liste est vide");
        return NULL;
    }
    Noeud *courant;
    courant=debut;
    for(i=1; i<pos;i++)
    {
        courant=courant->suivant;
    }
    courant->valeur=_value;
    return debut;
}

int main()
{
    Noeud *debut=NULL;
    Noeud *P = cree(10);
    Noeud *D = cree(20);
    Noeud *T = cree(30);
    printf("adreese du noeud debut : %p\n",debut);
    printf("adreese du noeud P : %p\n",P);
    printf("adreese du noeud D : %p\n",D);
    printf("adreese du noeud T :  %p\n",T);
    debut=P;
    P->suivant=D;
    D->suivant=T;
    T->suivant=NULL;
    printf("----------------------\n");
    printf("adreese du noeud %p\n",debut);
    printf("adreese du noeud P suivant %p\n",P->suivant);
    printf("adreese du noeud D suivant %p\n",D->suivant);
    printf("adreese du noeud T suivant %p\n",T->suivant);
    printf("---------------Affichage----------------------\n");
    affiche(debut);
    printf("---------------Ajout au debut----------------------\n");
    debut = ajouterD(debut,100);
    affiche(debut);
    printf("---------------Affichage ajout à la Fin----------------------\n");
    debut = ajouterF(debut,2100);
    affiche(debut);
    printf("---------------Recherche----------------------\n");
    rechercher(debut,2100);
    printf("---------------Taille de la liste----------------------\n");
    printf("la taille est %d\n",taille(debut));
    printf("---------------Insertion à une position----------------------\n");
    debut= insertion(debut, 9, 555);
    affiche(debut);
    printf("---------------Suppression au debut----------------------\n");
    debut = suppressionD(debut);
    affiche(debut);
    printf("---------------Suppression à la fin----------------------\n");
    debut = suppressionF(debut);
    affiche(debut);
    printf("---------------Suppression à une position----------------------\n");
    debut = suppressionP(debut,4);
    affiche(debut);
    printf("---------------Modifier au debut----------------------\n");
    debut = modifierD(debut,2024);
    affiche(debut);
    printf("---------------Modifier à la fin----------------------\n");
    debut = modifierF(debut,3521);
    affiche(debut);
    printf("---------------Modifier à une position----------------------\n");
    debut = modifierP(debut,1,2000);
    affiche(debut);
    return 0;
}

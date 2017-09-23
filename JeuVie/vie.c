// ***************************************************************
// Patricia Shimizu et Diana Soares
// vie.c
// 19 decembre 2016
// Affiche le jeu de la vie pendant 50 générations pour une grille
// initialisée dans initialiserGrille.
// ***************************************************************

#include <stdio.h>
#include <stdlib.h>
#include "vie.h"
#include "io.h"
#include <time.h>
#include <unistd.h>


//static const int NB_RANGEES = 50;
//static const int NB_COLONNES = 50;
//static const int NB_GEN = 51;
//static const char VIVANT = '0';
//static const char MORT = '.';

// ***************************************************************
// int main(int argc, char* argv [])
//
// Imprime à la console sa liste d'arguments.
// Puis affiche les NB_GEN premières générations du jeu de la vie
// de Conway pour la grille donnée dans initialiserGrille.
//
// ***************************************************************
int main(int argc, char* argv [])
{
    printf("Nombre d'arguments = %d\n", argc);
    
    for(int i = 0; i < argc; i++)
    {
        printf("argv[%d] = %s\n", i, argv[i]);
    }
    
    // Initialisation de la grille de jeu
    Gen jeu;
    
    jeu.rangees = NB_RANGEES;
    jeu.colonnes = NB_COLONNES;
    
    jeu.grille = (int**)malloc(jeu.rangees * sizeof(int *));
    
    if(jeu.grille == NULL)
    {
        fprintf(stderr, "malloc echoue\n");
        return -1;
    }
    for(int i = 0; i < jeu.rangees; i++)
    {
        jeu.grille[i] = (int *)malloc(jeu.colonnes * sizeof(int));
        if(jeu.grille[i] == NULL)
        {
            fprintf(stderr, "malloc echoue\n");
            return -1;
        }
    }
    
    
    initialiserGrille(&jeu);
    char automatique;
    // Imprimer les NB_GEN premières générations
    printf("Vous voulez imprimir toutes les generations automatiquement?(o/n)");
    scanf("%c", &automatique);
    
    
    switch (automatique)
    {
        case 'o':
        {
            //Case imprime les grilles automatiquement avec un laps de temps de choix d'utilisateur (secondes)
            int lapse;
            printf("Quel laps de secondes vous voulez?");
            scanf("%i", &lapse);
            for (int i = 0; i < NB_GEN; i++)
            {
                int del = lapse*1000000;
                //imprime les grilles avec le laps demandé
                imprimerGrille(&jeu);
                mettreAJourGrille(&jeu);
                usleep(del);
            }
        }
            break;
            
        case 'n':
            
            for (int i = 0; i < NB_GEN; i++)
            {
                //montre les grilles a chaque retour de chariot de l'ulitilisateur
                char copier;
                imprimerGrille(&jeu);
                mettreAJourGrille(&jeu);
                
                printf("\n");
                //L'utilisateur fait le choix s'il veut exporter la grille à un fichier.vie
                printf("Vous voulez copier cette generation a une fichier.vie? (o/n) ");
                scanf("%c", &copier);
                
                switch (copier)
                {
                    case 'o':
                    {
                        char *nombreFichier = "Fichier.vie";
                        char lignes[100];
                        //Appel de la fonction exporter
                        exporter(nombreFichier, lignes);
                    }
                        break;
                        
                }
                getchar();
                
                
            }
            break;
            
            
            
    }
    
    free(jeu.grille);
}

// ***************************************************************
// int competeVivants(Gen* grille);
//
// Compte le nombre de vivantes que la grille contient en chaque génération
//
// input :
// grille : un pointeur vers la grille.
//
// output: entier avec le nombre de vivants de la grille
// ***************************************************************

int compteVivants(Gen* grille)
{
    int countViv = 0;
    
    for (int i = 0; i < grille->rangees; i++)
    {
        for (int j = 0; j < grille->colonnes; j++)
        {
            if (grille->grille[i][j])
            {
                countViv++;
            }
        }
    }
    return countViv;
}
// ***************************************************************
// imprimerGrille(Gen* grille);
//
// Imprime la grille dans g, précédé du numéro de génération et des vivants.
//
// input :
// g : un pointeur vers la grille à imprimer.
// ***************************************************************
void imprimerGrille(Gen* grille)
{
    int nbVivant = compteVivants(grille);
    printf("Génération %d contient %d vivants\n", grille->generation, nbVivant);
    for (int i = 0; i < grille->rangees; i++)
    {
        for (int j = 0; j < grille->colonnes; j++)
        {
            if (grille->grille[i][j])
            {
                printf("%c ", VIVANT);
                
            }
            else
                printf("%c ", MORT);
        }
        printf("\n");
    }
    
}


// ***************************************************************
// initialiserGrille(Gen* grille);
//
// Remplit la grille avec des informations importées par Gen importer(char* fichier)
// de manière à créer le patron du jeu (géneration 0).
//
// input :
// g : un pointeur vers la grille à initialiser
// ***************************************************************
void initialiserGrille(Gen* grille)
{
    // Cette méthode doit importer la grille dans le fichier
    // donné en arguments au main, plutôt que l'écrire en clair.
    
    //Gen grilleTemp = importer("/Users/eleves/Desktop/enonce/gosperglidergun.vie");
    Gen grilleTemp = importer("/Users/eleves/Desktop/enonce/acorn.vie");
    
    grille->generation = grilleTemp.generation;
    grille->rangees = grilleTemp.rangees;
    grille->colonnes = grilleTemp.colonnes;
    
    for (int i = 0; i < grille->rangees; i++)
    {
        for (int j = 0; j < grille->colonnes; j++)
        {
            grille->grille[i][j] = grilleTemp.grille[i][j];
        }
    }
    
}

// ***************************************************************
// copierGrille(Gen* s, Gen* d);
//
// Copie la grille de source dans la grille de destination.
// Les deux grilles doivent avoir les mêmes dimensions.
//
// input :
// s : un pointeur vers la grille source
// d : un pointeur vers la grille destination
// ***************************************************************
void copierGrille(Gen* source, Gen* destination)
{
    for (int i = 0; i < source->rangees; i++)
    {
        for (int j = 0; j < source->colonnes; j++)
        {
            destination->grille[i][j] = source->grille[i][j];
        }
    }
}

// ***************************************************************
// nbVoisins(Gen* gen, int i, int j);
//
// Calcule le nombre de voisins vivants de la case [i][j] de la
// grille de gen.
//
// Une case a un maximum de 8 voisins potentiels (les diagonales
// comptent comme des cases voisines).
//
// input :
// gen : un pointeur vers la grille
// i : l'indice de la rangée
// j : l'indice de la colonne
// ***************************************************************
int nbVoisins(Gen* gen, int i, int j)
{
    int voisins= 0;
    
    // Parcourir les cellules de la rangées au dessus
    if (i > 0)
    {
        voisins += gen->grille[i-1][j];
        if (j > 0)
        {
            voisins += gen->grille[i-1][j-1];
        }
        if (j < gen->rangees - 1)
        {
            voisins += gen->grille[i-1][j+1];
        }
    }
    
    // Parcourir le voisin gauche et droit
    if (j > 0)
    {
        voisins += gen->grille[i][j-1];
    }
    if (j < gen->rangees - 1)
    {
        voisins += gen->grille[i][j+1];
    }
    
    // Parcourir les cellules de la rangées au dessous
    if (i < gen->rangees - 1)
    {
        voisins += gen->grille[i+1][j];
        if (j > 0)
        {
            voisins += gen->grille[i+1][j-1];
        }
        if (j < gen->rangees -1)
        {
            voisins += gen->grille[i+1][j+1];
        }
    }
    return voisins;
}

// ***************************************************************
// mettreAJourGrille(Gen* g);
//
// Fait passer la grille g à la génération suivante selon
// les règles du jeu de la vie.
//
// input :
// g : un pointeur vers la grille à mettre à jour
// ***************************************************************
void mettreAJourGrille(Gen* courante)
{
    Gen temp;
    
    temp.rangees = courante->rangees;
    temp.colonnes = courante->colonnes;
    
    temp.grille = (int**)malloc(temp.rangees * sizeof(int *));
    
    if(temp.grille == NULL)
    {
        fprintf(stderr, "malloc echoue\n");
        return;
    }
    for(int i = 0; i < temp.rangees; i++)
    {
        temp.grille[i] = (int *)malloc(temp.colonnes * sizeof(int));
        if(temp.grille[i] == NULL)
        {
            fprintf(stderr, "malloc echoue\n");
            return;
        }
    }
    
    
    copierGrille(courante, &temp);
    
    
    for (int i = 0; i < courante->rangees; i++)
    {
        for (int j = 0; j < courante->colonnes; j++)
        {
            // compter le nombre de voisins vivants
            int voisins = nbVoisins(&temp, i, j);
            
            // Mettre à jour la grille
            if (voisins == 0 || voisins == 1 || voisins >= 4)
            {
                courante->grille[i][j] = 0;
            }
            else if (voisins == 3)
            {
                courante->grille[i][j] = 1;
            }
        }
    }
    courante->generation++;
    
    free(temp.grille);
}

// **************************************************************
// Patricia Shimizu et Diana Soares
// Fichier io.c
// 19 décembre 2016
// Permet d'importer et d'exporter du texte dans des fichiers.
// **************************************************************

#include <stdio.h>
#include "stdlib.h"
#include "io.h"
#include <string.h>
#include <malloc/malloc.h>
#include "vie.h"

// **************************************************************
// int exporter(char* fichier, char* ligne)
//
// Ajoute à la fin du fichier "fichier" la ligne "ligne". Si
// le fichier n'existe pas, il est créé.
//
// input :
// fichier : le nom du fichier dans lequel écrire.
// ligne   : la ligne à ajouter au fichier.
//
// output :
// -1 si l'ouverture du fichier a échoué
//  0 sinon.
// **************************************************************
int exporter(char* fichier, char* ligne)
{
    Gen *grille;
    
    FILE * fp;
    fp = fopen(fichier, "w+"); // ‘wb’ c’est pour write
    if (fp == NULL)
    {
        
        return(-1);
    }
    else
    {
        imprimerGrille(grille);
        int Vivant = compteVivants(grille);
        fprintf(fp,"Génération %d contient %d vivants\n", grille->generation, Vivant);
        
        for (int i = 0; i < grille->rangees; i++)
        {
            for (int j = 0; j < grille->colonnes; j++)
            {
                if (grille->grille[i][j])
                {
                    fprintf(fp,"%c ", VIVANT);
                    
                }
                else
                    fprintf(fp,"%c ", MORT);
            }
            fprintf(fp, "%s", ligne);
        }
        
    }
    
    fprintf(fp,"\n");
    fclose(fp);
    return (0);
    
}

// **************************************************************
// Gen importer(char* fichier)
//
//  Imprime ligne par ligne le contenu du fichier "fichier".
//  Il prends les informations qui contient dans le fichier, il identifie la taille du tableau desirée pour initialiser le jeu.
//  Prends aussi les vivants declarées comment '*' et les donne valeur pour que la grille crée dans une autre fonction peut les
//  identifier et les convertir a le character desiré.
//
// input :
// fichier : le nom du fichier Ã  lire. Le programme lire le fichier et lui convert à une nouveau jeu.
//
//
// output :
// Struct du type Gen avec des informations du tableau* de entiers, rangées, colonnes et generation.
// **************************************************************
Gen importer(char* fichier)
{
    FILE * fp = fopen(fichier, "r");
    int rangee = 0;
    Gen grille;
    char ligne[100];
    ligne[0] = '\0';
    
    grille.generation = 0;
    grille.colonnes = 0;
    grille.rangees = 0;
    
    if (fp == NULL)
    {
        printf("Fichier non ouvert\n");
    }
    
    char c;
    char c2[2];
    int r = 0;
    int tailleLigne = 0;
    printf("%d : ", rangee);
    
    while ((c = fgetc(fp)) && (c != EOF))
    {
        // chaque fois que lire un char, ajouter dans la ligne
        c2[0] = c;
        c2[1] = '\0';
        strcat(ligne, c2);
        
        printf("%c", c);
        
        if (c == '\n')
        {
            tailleLigne = (int)strlen(ligne);
            //printf("%s", ligne);
            //printf("Taille: %d\n", tailleLigne);
            
            // ligne[0] == '#'
            if (ligne[0] == '#')
            {
                ligne[0] = '\n';
            }
            
            // ligne[0] == chiffre
            else if (ligne[0] == '1' || ligne[0] == '2' || ligne[0] == '3' || ligne[0] == '4' || ligne[0] == '5'
                     || ligne[0] == '6' || ligne[0] == '7' || ligne[0] == '8' || ligne[0] == '9')
            {
                sscanf(ligne, "%zd,%zd", &grille.rangees, &grille.colonnes);
                grille.grille = (int**)malloc(grille.rangees * sizeof(int *));
                
                if(grille.grille == NULL)
                {
                    fprintf(stderr, "malloc echoue\n");
                    //return -1;
                }
                for(int i = 0; i < grille.rangees; i++)
                {
                    grille.grille[i] = (int *)malloc(grille.colonnes * sizeof(int));
                    if(grille.grille[i] == NULL)
                    {
                        fprintf(stderr, "malloc echoue\n");
                        
                    }
                }
                
                for (int i = 0; i < grille.rangees; i++)
                {
                    for (int j = 0; j < grille.colonnes; j++)
                    {
                        grille.grille[i][j] = 0;
                    }
                }
            }
            
            else
            {
                for (int j = 0; j < tailleLigne-1; j++) //tailleLigne-1
                {
                    if (ligne[j] != '*')
                    {
                        grille.grille[r][j] = 0;
                        
                    }
                    else
                    {
                        grille.grille[r][j] = 1;
                    }
                    
                }
                r++;
            }
            
            
            // effacer la ligne
            ligne[0] = '\0';
            printf("%d : ", ++rangee);
            
        }
    }
    
    printf("%c", '\n');
    
    fclose(fp);
    return grille;
}

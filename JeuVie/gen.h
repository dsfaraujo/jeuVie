// **************************************************************
// Patricia Shimizu et Diana Soares
// Fichier gen.h
// 19 décembre 2016
// **************************************************************

#pragma once

// ***************************************************************
// La structure Gen_t de type Gen
// contient une matrice d'entier et un numéro de génération.
//
// grille : matrice d'entier
// rangees : nombre de rangées dans grille
// colonnes : nombre de colonnes dans grille
// generation : numéro de la génération en cours
//
// grille[i][j] est le contenu de grille à la
// i^e rangée et à la j^e colonne.
//
// Une cellule vivante est représentée par un 1
// Une cellule morte est représentée par un 0.
// ***************************************************************

typedef struct Gen_t{
    int** grille;
    size_t rangees;
    size_t colonnes;
    int generation;
} Gen;

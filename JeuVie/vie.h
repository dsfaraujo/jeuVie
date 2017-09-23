// **************************************************************
// Patricia Shimizu et Diana Soares
// Fichier vie.h
// 19 décembre 2016
// **************************************************************

#pragma once
#include "gen.h"

//Constants declarées ici pour pouvoir etre appelées dans vie.c et io.c
static const int NB_RANGEES = 50;
static const int NB_COLONNES = 50;
static const int NB_GEN = 51;
static const char VIVANT = '0';
static const char MORT = '.';

// ***************************************************************
// imprimerGrille(Gen* g);
//
// Imprime la grille dans g, précédé du numéro
// de génération.
//
// input :
// g : un pointeur vers la grille à imprimer.
// ***************************************************************
void imprimerGrille(Gen* g);


// ***************************************************************
// initialiserGrille(Gen* g);
//
// Remplit la grille avec un patron quelconque.
//
// input :
// g : un pointeur vers la grille à initialiser
// ***************************************************************
void initialiserGrille(Gen* g);

// ***************************************************************
// mettreAJourGrille(Gen* g);
//
// Fait passer la grille g à la génération suivante selon
// les règles du jeu de la vie.
//
// input :
// g : un pointeur vers la grille à mettre à jour
// ***************************************************************
void mettreAJourGrille(Gen* g);

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
void copierGrille(Gen* s, Gen* d);


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
int nbVoisins(Gen* gen, int i, int j);

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

int compteVivants(Gen* grille);


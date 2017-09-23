// **************************************************************
// Patricia Shimizu et Diana Soares
// Fichier io.h
// 19 décembre 2016
// **************************************************************

#pragma once
#include "gen.h"

// **************************************************************
// int importer(char* fichier)
//
// Imprime ligne par ligne le contenu du fichier "fichier".
//
// input :
// fichier : le nom du fichier à lire.
//
// output :
// -1 si l'ouverture du fichier a échoué
//  0 sinon.
// **************************************************************
Gen importer(char* fichier);



//***************************
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
int exporter(char* fichier, char* ligne);

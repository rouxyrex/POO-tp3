/*************************************************************************
                       Trajet_Compose  -  Classe fille
                             -------------------
    début                : 21/11/2018
    copyright            : (C) 2018 par LOKUGE, RAMSAHA
    e-mail               : sadsitha97@pediatrician.com
*************************************************************************/

//-- Interface de la classe <Trajet_Compose> (fichier Trajet_Compose.h) --
#ifndef TRAJET_COMP_H
#define TRAJET_COMP_H

//--------------------------------------------------- Interfaces utilisées
#include <fstream>
#include <string>
using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Trajet_Compose>
// Definir un trajet nommé constitué de plusiers sous trajets(de type Trajet_Simple ou Trajet_Compose)
// Classe fille de la classe trajet
//------------------------------------------------------------------------




class Trajet_Compose : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    
    void Renvoyer(int& nombre, Trajet** Contains); 
	// modifie un tableau(Trajet** Contains) afin qu'il contienne les pointers sur tous les trajets simples contenu dans ce trajet composé 
	// cette méthode servira à la recherche de trajets dans Catalogue  

    const char* get_Trans(); // renvoie le moyen de transport du trajet
    
    void SauvTrajet(ofstream& fic, int& ref, int TypeTraj) const; //sauvegarde le trajet dans fic à la position ref si TypeTraj =0 ou 2

	void SauvTrajet(ofstream& fic, int& ref, int memberOf, int TypeTraj, int SelecVille, string villes []) const; //sauvegarde le trajet dans fic à la position ref si il est du type spécifié
	

//-------------------------------------------- Constructeurs - destructeur
	Trajet_Compose (const char* Nom, const char* Ville_Dep, const char* Ville_Arriv,Trajet** trajets, int nums); 
	// Constructeur

	virtual ~Trajet_Compose( );
	// Destructeur

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	Trajet** Tab; //Tableau contenant les pointers de trajets (simples et composés) contenus dans ce trajet composé

	int number; //Nombre de pointers de trajets (simples et composés) contenus dans ce trajet composé
		//sera utilisé afin de savoir combien de trajet sont dans un trajet composé courrant 
};

#endif 


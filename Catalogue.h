/*************************************************************************
                                   Catalogue
                             -------------------
    début                : 21/11/2018
    copyright            : (C) 2018 par LOKUGE, RAMSAHA
    e-mail               : sadsitha97@pediatrician.com
*************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) --------------
#if ! defined ( Catalogue_H )
#define Catalogue_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
// Contenir tous les trajets actuellement disponible
// Implémenter plusieurs fontionnalités : Recherche de Trajets, Affichage du Catalogue et ajout de trajets simples et composés 
//------------------------------------------------------------------------
#include "Trajet.h"

class Catalogue
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	void AjoutTrajSimp();// ajouter un trajet simple
	void AjoutTrajComp(); // ajouter un trajet composé
	void AjoutTrajSimp2(Trajet** Tab,int& pos); 
	// méthode utilisée dans AjoutTrajComp() pour que le trajet composé soit constitué uniquement de trajets simples
    
	void Rechercher(const char* a, const char* b);  //recherche simple: a = départ; b =arrivée
    	void Rechercher2(const char* a, const char* b);  //recherche avancée: a = départ; b =arrivée
        //Méthode utilisée pour la recherche avancée
        //Algorithme:
        //Parcourir le tableau de trajets, et pour chaque trajets dont la ville de depart correspond, appliquer la methode suivante
	//creer un pointeur sur tableau de pointeur sur tableau (Tableau 2D) sur des trajets. Chaque colonne du tableau(ou sous-tableau de pointeur sur tableau) represente une combinaison possible de trajets
	// ajouter les trajets possible 1 a 1, et si pour un trajet donne, deux ou plus trajets sont des suites possible, on duplique le tableau dans une autre case
	// ainsi on parcours toutes combinaisons possible
	// avant chaque insertion, on verifie que le trajet n'a pas deja ete ajoute
	// on s'arrete des que la ville d'arrivee correspond

	bool Deja_ajoute(Trajet ** tableau, int taille, Trajet * traj); // verifie si on a deja ajoute un dit trajet a un tableau de trajet dont on connait la taille


	void Afficher();
        //Afficher tous les trajets contenus dans ce catalogue
	Bool RecupTrajets();
	//Recupérer des trajets à partir d'un fichier
	Bool SauvTrajets();
	//Sauvegarder les trajets courants dans un fichier
    	void test();
        //Une methode pour ajouter quelques trajets automatiquement au catalogue afin de rendre les tests plus facile

//-------------------------------------------- Constructeurs - destructeur
	Catalogue ();
	    // Constructeur de la classe Catalogue

	 ~Catalogue( );
	    // Destructeur de la classe Catalogue

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
	void AddTrajet(Trajet* A); //ajouter un trajet au catalogue
    	void cherche(int i,const char* a, const char* b);
//----------------------------------------------------- Attributs protégés

	Trajet** Tab_trajet; //un tableu qui contient des pointeurs sur tous les trajets contenus dans ce catalogue
	int count; //le nombre de trajets contenus dans ce catalogue
	int sizeTab;  //la taille maximale du tableau Tab_trajet
	int num_results; //le nombre de resultats trouvé par recherche 2
};

#endif

/*************************************************************************
                                   Catalogue
                             -------------------
    début                : 21/11/2018
    copyright            : (C) 2018 par LOKUGE, RAMSAHA, DEBORD
    e-mail               : sadsitha97@pediatrician.com
*************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) --------------
#if ! defined ( Catalogue_H )
#define Catalogue_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <fstream>
#include "Trajet.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
// Contenir tous les trajets actuellement disponible
// Implémenter plusieurs fontionnalités : Recherche de Trajets, Affichage du Catalogue et ajout de trajets simples et composés 
//------------------------------------------------------------------------


class Catalogue
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	void AjoutTrajSimp();// ajouter un trajet simple
	void AjoutTrajComp(); // ajouter un trajet composé
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

	void Afficher();
	//Afficher tous les trajets contenus dans ce catalogue
	bool RecupCatalogue(ifstream& fic, int TypeTraj, int SelecVille, string villes [], int intervalle []);
	//Recupérer des trajets du type spécifié depuis un fichier avec spécification sur la ville de départ/arrivée et sur un intervalle
	bool SauvCatalogue(ofstream& fic, int TypeTraj, int SelecVille, string villes [], int intervalle []);
	//Sauvegarder les trajets du type spécifié dans un fichier avec spécification sur la ville de départ/arrivée et sur un intervalle
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
	void ReadLine(string thisString, string token []);
    void cherche(int i,const char* a, const char* b);
    bool Deja_ajoute(Trajet ** tableau, int taille, Trajet * traj); // verifie si on a deja ajoute un dit trajet a un tableau de trajet dont on connait la taille
    void AjoutTrajSimp(string token[]);// ajouter un trajet simple - automatique
    void AjoutTrajSimp2(Trajet** Tab,int pos); 
	// méthode utilisée dans AjoutTrajComp() pour que le trajet composé soit constitué de trajets simples
	void AjoutTrajSimp2(Trajet** Tab,int pos, string token []);
	// méthode utilisée dans AjoutTrajComp() pour que le trajet composé soit constitué  de trajets simples - automatique
	void AjoutTrajComp(string token[],ifstream &fic); // ajouter un trajet composé - automatique
	void AjoutTrajComp(Trajet** Tab,int pos,string token[],ifstream &fic); // ajouter un trajet composé qui est contenu dans un trajet composé - automatique
	void Sauteligne(int& skip,ifstream &fic); // sauter les nombre de lignes spécifié par skip
	bool checkVille(string token [], int SelecVille, string villes []); //verifier que le trajet satisfait les critères de séléction de villes
	bool checkIntervalle(string token [], int intervalle []); //verifier que le trajet satisfait les critères d'intervalle
//----------------------------------------------------- Attributs protégés

	Trajet** Tab_trajet; //un tableu qui contient des pointeurs sur tous les trajets contenus dans ce catalogue
	int count; //le nombre de trajets contenus dans ce catalogue
	int sizeTab;  //la taille maximale du tableau Tab_trajet
	int num_results; //le nombre de resultats trouvé par recherche 2
};

#endif

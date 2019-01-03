/*************************************************************************
               Interface de la classe <Menu> (fichier Menu.h)
                             -------------------
    début                : 21/11/2018
    copyright            : (C) 2018 par LOKUGE, RAMSAHA
    e-mail               : sadsitha97@pediatrician.com
*************************************************************************/

//---------- Interface de la classe <Menu> (fichier Menu.h) -------------------

#if ! defined ( MENU_H )
#define MENU_H



//--------------------------------------------------- Interfaces utilisées
#include <iostream>
#include <string.h>
#include "Trajet.h"
#include "Catalogue.h"

using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <MENU>
//L'interface utilisateur ou on implémente un cataloge
//
//------------------------------------------------------------------------

class Menu
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	void mainmenu(Catalogue& cat1); // méthode qui initie l'interface et les différentes options possible


//----------------------------------------------------- Attributs public


//-------------------------------------------- Constructeurs - destructeur
	Menu ();
	    // Constructeur de la classe Catalogue

	 ~Menu( );
	    // Destructeur de la classe Catalogue

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
    bool openfileread(ifstream &fic); // méthode pour qui va ouvrir un fichir donné par 'path'
    bool openfilewrite(ofstream &fic); // méthode pour qui va ouvrir un fichir donné par 'path'(ofstream &fic)
    void displayoptions();
    void test(Catalogue& cat1); // méthode pour l'insertion du test demandé dans le cahier des charges

//----------------------------------------------------- Attributs protégés


};


#endif



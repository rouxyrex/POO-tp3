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
#include "Trajet.h"
#include "Catalogue.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <MENU>
//L'interface utilisateur ou on implémente un cataloge
//
//------------------------------------------------------------------------

class Test
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	int main (Catalogue& cat1);
	void test(Catalogue& cat1); // méthode pour l'insertion du test demandé dans le cahier des charges
	static void mainmenu(); // méthode qui initie l'interface et les différentes options possible


//----------------------------------------------------- Attributs public


};


#endif



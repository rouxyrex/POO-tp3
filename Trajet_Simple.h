/*************************************************************************
                           Trajet_Simple  -  Classe fille
                             -------------------
    début                : 21/11/2018
    copyright            : (C) 2018 par LOKUGE, RAMSAHA
    e-mail               : sadsitha97@pediatrician.com
*************************************************************************/

//---------- Interface de la classe <Trajet_Simple> (fichier Trajet.h) --------------
#ifndef TRAJET_SIMP_H
#define TRAJET_SIMP_H

//--------------------------------------------------- Interfaces utilisées
#include <fstream>
using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Trajet_Simple>
// Definir un trajet avec un moyen de transport
// Classe fille de la classe Trajet
//------------------------------------------------------------------------


class Trajet_Simple : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

	void Renvoyer(int& nombre, Trajet** Contains); //Renvoie le pointeur sur lui-même qui sevira pour la rechercher de Trajet dans Catalogue
    
	const char* get_Trans() const; // renvoie le moyen de transport de ce trajet
	
	void SauvTrajet(ofstream& fic, int& ref) const; //sauvegarde le trajet dans fic à la position ref

//-------------------------------------------- Constructeurs - destructeur
	Trajet_Simple ( const Trajet_Simple & unTrajet_Simple );
        // Constructeur de copie


	Trajet_Simple (const char* Nom, const char* Ville_Dep, const char* Ville_Arriv, const char* Trans);
	    // Constructeur


	virtual ~Trajet_Simple( );
	    // Destructeur


//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

	const char* Moyen_Trans; // Paramètre pour le moyen de transport

};

#endif


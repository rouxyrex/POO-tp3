/*************************************************************************
                           Trajet  -  Classe mère
                             -------------------
    début                : 21/11/2018
    copyright            : (C) 2018 par LOKUGE, RAMSAHA, DEBORD
    e-mail               : sadsitha97@pediatrician.com
*************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) --------------
#ifndef TRAJET_H
#define TRAJET_H

//--------------------------------------------------- Interfaces utilisées
#include <fstream>
#include <string>
using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Trajet>
// Definir un voyage nommé d'une ville A à une ville B
// Servira de classe mère pour Trajet_Simple et Trajet_Compose afin qu'on puisse appliquer le polymorphisme 
//------------------------------------------------------------------------



class Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

	
	const char* get_Depart() const; //renvoie la ville de depart du trajet
	const char* get_Arrivee() const; //renvoie la ville d'arrivee du trajet
	const char* get_Nom() const; //renvoie le nom du trajet
	virtual void SauvTrajet(ofstream& fic, int& ref, int TypeTraj) const //sauvegarde le trajet dans fic à la position ref si il est du type spécifié
	{
	}
	virtual void SauvTrajet(ofstream& fic, int& ref, int memberOf, int TypeTraj,int SelecVille, string villes []) const //sauvegarde le trajet dans fic à la position ref si il est du type spécifié
	{
	}

    virtual const char* get_Trans() const 
	//renvoyer le moyen de transport du trajet courant
	//La methode est décrite en tant que virtual afin de permettre au compilateur de trouver la bonne méthode à appliquer dans les classes filles
    {
        const char* ret = "NA";
        return ret;
    }


    virtual void Renvoyer(int& nombre, Trajet** Contains) {}; 
    //renvoie un tableu contenant les pointers des tous les trajets simples contenu dans ce trajet. Cette méthode sera appelée dans les classes filles pour la recherche de trajets
	

//-------------------------------------------- Constructeurs - destructeur
    
	Trajet ( const Trajet & unTrajet );
	// Constructeur de copie :

	Trajet (const char* Nom, const char* Ville_Dep, const char* Ville_Arriv); //Affecte à un trajet un Nom, une ville de départ et une ville d'arrivée
    // Constructeur du trajet:


	virtual ~Trajet( );
    // Destructeur du trajet

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

	const char* Nom_Trajet;	// Attribut de Nom du Trajet
	const char* Ville_Depart;// Attribut de Ville de Départ du Trajet
	const char* Ville_Arrivee;// Attribut d'Arrivée du Trajet

};

#endif 


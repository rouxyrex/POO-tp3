/*************************************************************************
                           Trajet  -  Classe mère
                             -------------------
    début                : 21/11/2018
    copyright            : (C) 2018 par LOKUGE, RAMSAHA
    e-mail               : sadsitha97@pediatrician.com
*************************************************************************/

//---------- Réalisation de la classe <Trajet> (fichier Trajet.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstdlib>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

	const char* Trajet::get_Depart ( ) const
	{
		return Ville_Depart;
	} //----- Fin de Méthode

	const char* Trajet::get_Arrivee ( ) const
	{
		return Ville_Arrivee;
	} //----- Fin de Méthode

    const char* Trajet::get_Nom( ) const
	{
		return Nom_Trajet;
	} //----- Fin de Méthode


    void Renvoyer(int& nombre, Trajet** Contains) 
	// ne fait rien parce qu'elle est de type virtual et a pour but d'être utilisée dans les classes filles
    {
    }



//-------------------------------------------- Constructeurs - destructeur
	Trajet::Trajet ( const Trajet & unTrajet ) // définition du constructeur de copie
	{
    	Ville_Depart=unTrajet.get_Depart();
		Ville_Arrivee=unTrajet.get_Arrivee();
        Nom_Trajet=unTrajet.get_Nom();
    	#ifdef MAP
       		 cout << "Appel au constructeur de copie de <Trajet>" << endl;
    	#endif
    	} //----- Fin de Trajet (constructeur de copie)

	Trajet::Trajet (const char* Nom, const char * Depart, const char * Arrivee) // définition du constructeur 
	{
		Ville_Depart=Depart;
		Ville_Arrivee=Arrivee;
       		Nom_Trajet = Nom;

		#ifdef MAP
		    cout << "Appel au constructeur de <Trajet>" << endl;
		#endif
	} //----- Fin de Trajet


	Trajet::~Trajet ( ) 
	{

		#ifdef MAP
		    cout << "Appel au destructeur de <Trajet>" << endl;
		#endif
	} //----- Fin de ~Trajet



//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées


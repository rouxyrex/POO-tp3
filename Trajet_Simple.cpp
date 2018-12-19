/*************************************************************************
                           Trajet_Simple  -  Classe fille
                             -------------------
    début                : 21/11/2018
    copyright            : (C) 2018 par LOKUGE, RAMSAHA
    e-mail               : sadsitha97@pediatrician.com
*************************************************************************/

//---------- Réalisation de la classe <Trajet_Simple> (fichier Trajet_Simple.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <fstream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Trajet.h"
#include "Trajet_Simple.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC



//----------------------------------------------------- Méthodes publiques


    void Trajet_Simple::Renvoyer(int& nombre, Trajet** Contains) 
    {
        Contains[nombre]=this;
        ++nombre;
    }

    const char* Trajet_Simple::get_Trans() const
    { 
        return Moyen_Trans;
    }


    void Trajet_Simple::SauvTrajet(ofstream &thisFile, int &i) const
    {
	cout << "appel a sauvtrajet-simple" << endl;
	thisFile << i << "," <<get_Nom()<< "," <<get_Depart()<< "," <<get_Arrivee()<< "," <<get_Trans()<< "," <<"1"<< "," <<"0"<<"\n";
    } 

//-------------------------------------------- Constructeurs - destructeur

    Trajet_Simple::Trajet_Simple ( const Trajet_Simple & unTrajet_Simple ) : Trajet(unTrajet_Simple.get_Nom(),unTrajet_Simple.get_Depart(),unTrajet_Simple.get_Arrivee()), Moyen_Trans(get_Trans())
	// définition du constructeur de copie de Trajet_Simple
    {
       
        #ifdef MAP
            cout << "Appel au constructeur de copie de <Trajet_Simple>" << endl;
        #endif
    } //----- Fin de Trajet_Simple (constructeur de copie)

    Trajet_Simple::Trajet_Simple (const char* Nom, const char* Ville_Dep, const char* Ville_Arriv, const char* Trans) : Trajet(Nom, Ville_Dep, Ville_Arriv), Moyen_Trans(Trans) 
  
    {
        #ifdef MAP
            cout << "Appel au constructeur de <Trajet_Simple>" << endl;
        #endif
    } //----- Fin de Trajet_Simple


    Trajet_Simple::~Trajet_Simple ( ) 
    
    {
        delete [] Moyen_Trans;
        delete [] Ville_Depart;
        delete [] Ville_Arrivee;
        delete [] Nom_Trajet;
        #ifdef MAP
            cout << "Appel au destructeur de <Trajet_Simple>" << endl;
        #endif
    } //----- Fin de ~Trajet_Simple


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées


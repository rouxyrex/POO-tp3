/*************************************************************************
                           Trajet_Simple  -  Classe fille
                             -------------------
    début                : 21/11/2018
    copyright            : (C) 2018 par LOKUGE, RAMSAHA, DEBORD
    e-mail               : sadsitha97@pediatrician.com
*************************************************************************/

//---------- Réalisation de la classe <Trajet_Simple> (fichier Trajet_Simple.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
#include <stdlib.h>
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
	
	
	void Trajet_Simple::SauvTrajet(ofstream& fic, int& ref, int memberOf, int TypeTraj, int SelecVille, string villes []) const
	{
		int condSatisfied = 0;
		if (TypeTraj!=2)
		{
			//verifier les villes de départ/arrivée
			if (SelecVille==1)
			{
				if (strcmp((villes[0]).c_str(),Ville_Depart)==0)
				{
					condSatisfied = 1;
				}
			} else if (SelecVille==2)
			{
				if (strcmp((villes[1]).c_str(),Ville_Arrivee)==0)
				{
					condSatisfied = 1;
				}
			} else if (SelecVille==3)
			{
				if ((strcmp((villes[0]).c_str(),Ville_Depart)==0) && (strcmp((villes[1]).c_str(),Ville_Arrivee)==0))
				{
					condSatisfied = 1;
				}
			} else //if SelecVille==0
			{
				condSatisfied = 1;
			}
			
			if (condSatisfied==1)
			{
				fic << ref << "," << Nom_Trajet << "," << Ville_Depart << "," << Ville_Arrivee << "," << Moyen_Trans << "," << 0 << "," << memberOf <<  "\n";
				++ref;
			}
		}
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


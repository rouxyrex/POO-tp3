/*************************************************************************
                           Trajet_Compose  -  Classe fille
                             -------------------
    début                : 21/11/2018
    copyright            : (C) 2018 par LOKUGE, RAMSAHA, DEBORD
    e-mail               : sadsitha97@pediatrician.com
*************************************************************************/

// Réalisation de la classe <Trajet_Compose> (fichier Trajet_Compose.cpp)--

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Trajet.h"
#include "Trajet_Compose.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


    void Trajet_Compose::Renvoyer(int& nombre, Trajet** Contains) // 
	{
        for(int i =0; i< number; i++)
		{   
            Tab[i]->Renvoyer(nombre, Contains);
		}
	}


    const char* Trajet_Compose::get_Trans() // retourne "NA" pour les trajets composés vue qu'il n'y a pas un seul genre de moyen de transport 
    {
        const char* ret = "NA";
        return ret;
    }

	void Trajet_Compose::SauvTrajet(ofstream& fic, int& ref, int memberOf, int TypeTraj, int SelecVille, string villes []) const
	{
		int condSatisfied = 0;
		if (TypeTraj!=1)
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
				cout << "came here" << endl;
				cout << villes[0] << endl;
				cout << villes[1] << endl;
				cout << Ville_Depart << endl;
				cout << Ville_Arrivee << endl;
				if ((strcmp((villes[0]).c_str(),Ville_Depart)==0) && (strcmp((villes[1]).c_str(),Ville_Arrivee)==0))
				{
					cout << "cond satisfied" << endl;
					condSatisfied = 1;
				}
			} else //if SelecVille==0
			{
				condSatisfied = 1;
			}
			
			if (condSatisfied==1)
			{
				fic << ref << "," << Nom_Trajet << "," << Ville_Depart << "," << Ville_Arrivee << "," << "NA" << "," << number << "," << memberOf << "\n";
				++ref;
			
				for (int i=0; i < number; ++i)
				{
					Tab[i]->SauvTrajet(fic,ref,memberOf,0,0,villes);
				}
			}
		}
	}
//-------------------------------------------- Constructeurs - destructeur
	Trajet_Compose::Trajet_Compose (const char* Nom, const char* Ville_Dep, const char* Ville_Arriv, Trajet** trajets, int nums) : Trajet(Nom, Ville_Dep, Ville_Arriv), Tab(trajets), number(nums)
	{
	#ifdef MAP
	    cout << "Appel au constructeur de <Trajet_Compose>" << endl;
	#endif
	} //----- Fin de Trajet_Compose


	Trajet_Compose::~Trajet_Compose ( )
	{
        for (int i=0; i<number;i++) // destruction de tous les trajets inclus dans le trajet composé
        {
            delete Tab[i];
        }
  
        delete [] Nom_Trajet;
		free(Tab); 
	#ifdef MAP
	    cout << "Appel au destructeur de <Trajet_Compose>" << endl;
	#endif
	} //----- Fin de ~Trajet_Compose


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées


﻿/*************************************************************************
               Realisation de la classe <Menu> (fichier Menu.cpp)
                             -------------------
    début                : 21/11/2018
    copyright            : (C) 2018 par LOKUGE, RAMSAHA
    e-mail               : sadsitha97@pediatrician.com
*************************************************************************/

//---------- Realisation de la classe <Menu> (fichier Menu.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Menu.h"
#include "Catalogue.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


void test(Catalogue& cat1)
{
    cat1.test();
}

static void mainmenu(Catalogue& cat1)
{
	

	//partie interactive de la modelisation
	cout<< "Voici les differentes touches et leur fonction dans ce catalogue:" << endl;
	cout << "1 - Ajouter un nouveau trajet simple" << endl;
	cout << "2 - Ajouter un nouveau trajet compose" <<endl;
	cout << "3 - Recherche de trajets" <<endl;	
    cout << "4 - Recherche de trajets (Avancée)" << endl;
	cout << "5 - Affichage du catalogue courrant" << endl;
	cout << "6 - Ajouter des trajets predetermines au catalogue (Test)" << endl;
	cout << "7 - Sauvegarder le catalogue courant"<< endl;
	cout << "8 - Sortir du catalogue"<< endl;

	char instruct ='0';
	
	cin >>instruct;

	while(instruct!= '8')
	{
		
		if(instruct == '1') // ajout d'un nouveau trajet simple au catalogue
		{	
            cat1.AjoutTrajSimp();
			cout << "Trajet enregistre dans le catalogue "<< endl;
			cout<<endl;
			cout << "Inserez une nouvelle commande" <<endl;	
					
		}

		if(instruct == '2') // ajout d'un nouveau trajet composé au catalogue
		{	
			cat1.AjoutTrajComp();
			cout << "Trajet compose enregistre dans le catalogue "<< endl;
			cout<<endl;
			cout << "Inserez une nouvelle commande" <<endl;			
		}

		if(instruct == '3') // recherche standard des trajets
		{
		   	cout << "Veuillez entrer votre ville de depart"<< endl;
            const char* Depart1;
            const char* Arrivee1;
            char* Departtmp = new char [4];
            char* Arriveetmp = new char [4];
		    cin >> Departtmp;
            Depart1=Departtmp;
		    cout << "Veuillez entrer votre ville d'arrivee"<< endl;
		    cin >> Arriveetmp;
           	Arrivee1=Arriveetmp;
		    cat1.Rechercher(Depart1,Arrivee1);
		    delete [] Depart1;	
            delete [] Arrivee1;
			cout<<endl;
            cout << "Inserez une nouvelle commande" <<endl;
		}
        
        	if(instruct == '4') // recherche avancée des trajets
		{
		    cout << "Veuillez entrer votre ville de depart"<< endl;
            const char* Depart1;
			const char* Arrivee1;
			char* Departtmp = new char [4];
			char* Arriveetmp = new char [4];
		    cin >> Departtmp;
           	Depart1=Departtmp;
		    cout << "Veuillez entrer votre ville d'arrivee"<< endl;
		    cin >> Arriveetmp;
            Arrivee1=Arriveetmp;
		    cat1.Rechercher2(Depart1,Arrivee1);
		    delete [] Depart1;	
            delete [] Arrivee1;
            cout << "Inserez une nouvelle commande" <<endl;
		}

		if(instruct == '5') // Affichage des trajets courrants
		{
			cat1.Afficher();
			cout<<endl;
			cout << "Inserez une nouvelle commande" <<endl;
		}

		if(instruct == '6') // test
		{
			test(cat1);
            cout<<endl;
			cout << "Inserez une nouvelle commande" <<endl;
		}

	    
	    if(instruct == '7') // test
		{
			cat1.SauvCatalogue();
            cout<<endl;
			cout << "Inserez une nouvelle commande" <<endl;
		}

	    	cin >> instruct; // enregistrer la nouvelle instruction	

	    }
	
}

int main ()
{
	Catalogue cat1; // creation du catalogue	
	mainmenu(cat1);
	return 0;
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées


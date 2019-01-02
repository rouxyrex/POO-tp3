/*************************************************************************
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
#include <string.h>
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
	cout << "7 - Sauvegarder des trajets dans un fichier (séléction par ville et/ou type)"<< endl;
	cout << "S - Sauvegarder des trajets dans un fichier (séléction par intervalle)"<< endl;
	cout << "8 - Récupérer des trajets depuis un fichier (séléction par ville et/ou type)"<< endl;
	cout << "R - Récupérer des trajets depuis un fichier (séléction par intervalle)"<< endl;
	cout << "9 - Sortir du catalogue"<< endl;

	char instruct ='0';
	
	cin >>instruct;
	cin.ignore();

	while(instruct!= '9')
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
            char* Departtmp = new char [20];
            char* Arriveetmp = new char [20];
            scanf ("%[^\n]%*c",Departtmp);
            Depart1=Departtmp;
		    cout << "Veuillez entrer votre ville d'arrivee"<< endl;
		    scanf ("%[^\n]%*c",Arriveetmp);
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
			char* Departtmp = new char [20];
			char* Arriveetmp = new char [20];
            scanf ("%[^\n]%*c",Departtmp);
           	Depart1=Departtmp;
		    cout << "Veuillez entrer votre ville d'arrivee"<< endl;
		    scanf ("%[^\n]%*c",Arriveetmp);
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
	    
	    if(instruct == '7') // sauvegarder des trajets
		{
			//ouvrir le fichier
			ofstream fic;
			fic.open("TrajetsFile.csv");
			
			int intervalle [] = {0,0,0};

			cout << "Choisir le type de trajets vous voulez sauvegarder:" << endl;
			cout << "1 - Tout" << endl;
			cout << "2 - Trajets Simples" <<endl;
			cout << "3 - Trajets Composés" <<endl;
			char instructSauvTraj ='0';
			
			cin >>instructSauvTraj;
			while(instructSauvTraj!='1' && instructSauvTraj!='2' && instructSauvTraj!='3') {
				cout << "Erreur, ceci n'est pas une option valable" << endl;
				cout << "Veuillez réessayer" << endl;
				cin.clear();
				cin.ignore(256,'\n');
				cin >> instructSauvTraj;
			}
			
			cout << "Voulez-vous specifier la ville d'arrivée et/ou la ville de départ?" << endl;
			cout << "1 - Pas de spécification" << endl;
			cout << "2 - Spécifier la ville de départ" <<endl;
			cout << "3 - Spécifier la ville d'arrivée" <<endl;
			cout << "4 - Spécifier la ville de départ et la ville d'arrivée" <<endl;
			char instructSauvVille ='0';
			
			cin >>instructSauvVille;
			while(instructSauvVille!='1' && instructSauvVille!='2' && instructSauvVille!='3'&& instructSauvVille!='4') {
				cout << "Erreur, ceci n'est pas une option valable" << endl;
				cout << "Veuillez réessayer" << endl;
				cin.clear();
				cin.ignore(256,'\n');
				cin >> instructSauvVille;
			}
			
			string villes [2];
			villes[0]="";
			villes[1]="";
			
			cin.ignore(); //necessaire quand on passe d'un "cin <<" à un getline(cin,)
			if (instructSauvVille=='2' || instructSauvVille=='4')
			{
				cout << "Veuillez taper la ville de départ : ";
				getline(cin,villes[0]);
			}
			if (instructSauvVille=='3' || instructSauvVille=='4')
			{
				cout << "Veuillez taper la ville d'arrivée : ";
				getline(cin,villes[1]);
			}
			switch (instructSauvTraj)
			{
				case '1': //tout trajets
					switch (instructSauvVille)
					{
						case '1':
							//all villes
							cat1.SauvCatalogue(fic,0,0,villes,intervalle);
							break;
						case '2':
							//specific ville de depart
							cat1.SauvCatalogue(fic,0,1,villes,intervalle);
							break;
						case '3':
							//specific ville d'arrivée
							cat1.SauvCatalogue(fic,0,2,villes,intervalle);
							break;
						case '4':
							//specific ville de depart et d'arrivée
							cat1.SauvCatalogue(fic,0,3,villes,intervalle);
							break;
						default :
							cout << instructSauvVille <<" n'est pas une option valable pour la sélection de ville"<<endl;
					}
					break;
				case '2': //traj simple
					switch (instructSauvVille)
					{
						case '1':
							//all villes
							cat1.SauvCatalogue(fic,1,0,villes,intervalle);
							break;
						case '2':
							//specific ville de depart
							cat1.SauvCatalogue(fic,1,1,villes,intervalle);
							break;
						case '3':
							//specific ville d'arrivée
							cat1.SauvCatalogue(fic,1,2,villes,intervalle);
							break;
						case '4':
							//specific ville de depart et d'arrivée
							cat1.SauvCatalogue(fic,1,3,villes,intervalle);
							break;
						default :
							cout << instructSauvVille <<" n'est pas une option valable pour la sélection de ville"<<endl;
					}
					break;
				case '3': //traj composé
					switch (instructSauvVille)
					{
						case '1':
							//all villes
							cat1.SauvCatalogue(fic,2,0,villes,intervalle);
							break;
						case '2':
							//specific ville de depart
							cat1.SauvCatalogue(fic,2,1,villes,intervalle);
							break;
						case '3':
							//specific ville d'arrivée
							cat1.SauvCatalogue(fic,2,2,villes,intervalle);
							break;
						case '4':
							//specific ville de depart et d'arrivée
							cat1.SauvCatalogue(fic,2,3,villes,intervalle);
							break;
						default :
							cout << instructSauvVille <<" n'est pas une option valable pour la sélection de ville"<<endl;
					}
					break;
				default :
					cout << instructSauvTraj <<" n'est pas une option valable pour la séléction du type de trajets"<<endl;
			}
			//fermer le fichier
            fic.close();
            
            cout<<endl; 
			cout << "Inserez une nouvelle commande" <<endl;
		}
		
		if(instruct == 'S') // sauvegarder des trajets par intevalle
		{
			//ouvrir le fichier
			ofstream fic;
			fic.open("TrajetsFile.csv");
			
			string villes [2];
			villes[0]="";
			villes[1]="";
			cout << "Voulez-vous specifier un intervalle de trajets à sauvegarder ?" << endl;
			cout << "1 - Oui" << endl;
			cout << "2 - Non" <<endl;
			char instructIntervalle ='0';
			int instructIntervalleN =0; //pas une bonne idée d'utiliser des int pour des cin
			int instructIntervalleM =0;
			
			cin >>instructIntervalle;
            
            while(instructIntervalle!='1' && instructIntervalle!='2') {
				cout << "Erreur, ceci n'est pas une option valable" << endl;
				cout << "Veuillez réessayer" << endl;
				cin.clear();
				cin.ignore(256,'\n');
				cin >> instructIntervalle;
			}
            cout<<endl;
            
            if (instructIntervalle=='1')
            {
				cout << "Veuillez taper la borne de commencement (trouve le mot!!) : ";
				cin >> instructIntervalleN;
				while(cin.fail()) {
					cout << "Erreur, l'entrée n'est probablement pas un entier" << endl;
					cout << "Veuillez réessayer" << endl;
					cin.clear();
					cin.ignore(256,'\n');
					cin >> instructIntervalleN;
				}
				cout<<endl;
				cout << "Veuillez taper la borne de finition (trouve le mot!!) : ";
				cin >> instructIntervalleM;
				while(cin.fail()) {
					cout << "Erreur, l'entrée n'est probablement pas un entier" << endl;
					cout << "Veuillez réessayer" << endl;
					cin.clear();
					cin.ignore(256,'\n');
					cin >> instructIntervalleM;
				}
				cout<<instructIntervalleN<< "  "<< instructIntervalleM;
				cout<<endl;
				int intervalle []= {1,instructIntervalleN,instructIntervalleM};
				cat1.SauvCatalogue(fic,0,0,villes,intervalle);
			} else {
				int intervalle []= {0,instructIntervalleN,instructIntervalleM};
				cat1.SauvCatalogue(fic,0,0,villes,intervalle);
			}
			fic.close();
			cout << "Inserez une nouvelle commande" <<endl;
		}
		
		if(instruct == '8') // récupérer des trajets
		{
			//ouvrir le fichier
			ifstream fic;
			fic.open("TrajetsFile.csv");
			
			int intervalle [] = {0,0,0};
			
			cout<< "Choisir le type de trajets vous voulez récupérer:" << endl;
			cout << "1 - Tout" << endl;
			cout << "2 - Trajets Simples" <<endl;
			cout << "3 - Trajets Composés" <<endl;
			char instructRecupTraj ='0';
			
			cin >>instructRecupTraj;
			while(instructRecupTraj!='1' && instructRecupTraj!='2' && instructRecupTraj!='3') {
				cout << "Erreur, ceci n'est pas une option valable" << endl;
				cout << "Veuillez réessayer" << endl;
				cin.clear();
				cin.ignore(256,'\n');
				cin >> instructRecupTraj;
			}
			
			cout<< "Voulez-vous specifier la ville d'arrivée et/ou la ville de départ?" << endl;
			cout << "1 - Pas de spécification" << endl;
			cout << "2 - Spécifier la ville de départ" <<endl;
			cout << "3 - Spécifier la ville d'arrivée" <<endl;
			cout << "4 - Spécifier la ville de départ et la ville d'arrivée" <<endl;
			char instructRecupVille ='0';
			
			cin >>instructRecupVille;
			while(instructRecupVille!='1' && instructRecupVille!='2' && instructRecupVille!='3'&& instructRecupVille!='4') {
				cout << "Erreur, ceci n'est pas une option valable" << endl;
				cout << "Veuillez réessayer" << endl;
				cin.clear();
				cin.ignore(256,'\n');
				cin >> instructRecupVille;
			}
			
			string villes [2];
			villes[0]="";
			villes[1]="";
			
			cin.ignore(); //necessaire quand on passe d'un "cin <<" à un getline(cin,)
			if (instructRecupVille=='2' || instructRecupVille=='4')
			{
				cout << "Veuillez taper la ville de départ : ";
				getline(cin,villes[0]);
			}
			if (instructRecupVille=='3' || instructRecupVille=='4')
			{
				cout << "Veuillez taper la ville d'arrivée : ";
				getline(cin,villes[1]);
			}
			switch (instructRecupTraj)
			{
				case '1': //tout trajets
					switch (instructRecupVille)
					{
						case '1':
							//all villes
							cat1.RecupCatalogue(fic,0,0,villes,intervalle);
							break;
						case '2':
							//specific ville de depart
							cat1.RecupCatalogue(fic,0,1,villes,intervalle);
							break;
						case '3':
							//specific ville d'arrivée
							cat1.RecupCatalogue(fic,0,2,villes,intervalle);
							break;
						case '4':
							//specific ville de depart et d'arrivée
							cat1.RecupCatalogue(fic,0,3,villes,intervalle);
							break;
						default :
							cout << instructRecupVille <<" n'est pas une option valable pour la sélection de ville"<<endl;
					}
					break;
				case '2': //traj simple
					switch (instructRecupVille)
					{
						case '1':
							//all villes
							cat1.RecupCatalogue(fic,1,0,villes,intervalle);
							break;
						case '2':
							//specific ville de depart
							cat1.RecupCatalogue(fic,1,1,villes,intervalle);
							break;
						case '3':
							//specific ville d'arrivée
							cat1.RecupCatalogue(fic,1,2,villes,intervalle);
							break;
						case '4':
							//specific ville de depart et d'arrivée
							cat1.RecupCatalogue(fic,1,3,villes,intervalle);
							break;
						default :
							cout << instructRecupVille <<" n'est pas une option valable pour la sélection de ville"<<endl;
					}
					break;
				case '3': //traj composé
					switch (instructRecupVille)
					{
						case '1':
							//all villes
							cat1.RecupCatalogue(fic,2,0,villes,intervalle);
							break;
						case '2':
							//specific ville de depart
							cat1.RecupCatalogue(fic,2,1,villes,intervalle);
							break;
						case '3':
							//specific ville d'arrivée
							cat1.RecupCatalogue(fic,2,2,villes,intervalle);
							break;
						case '4':
							//specific ville de depart et d'arrivée
							cat1.RecupCatalogue(fic,2,3,villes,intervalle);
							break;
						default :
							cout << instructRecupVille <<" n'est pas une option valable pour la sélection de ville"<<endl;
					}
					break;
				default :
					cout << instructRecupTraj <<" n'est pas une option valable pour la séléction du type de trajets"<<endl;
			}
			//fermer le fichier
            fic.close();
            
            
            cout<<endl;
			cout << "Inserez une nouvelle commande" <<endl;
		}
		
		if(instruct == 'R') // récupérer des trajets par intevalle
		{
			//ouvrir le fichier
			ifstream fic;
			fic.open("TrajetsFile.csv");
			
			string villes [2];
			villes[0]="";
			villes[1]="";
			cout << "Voulez-vous specifier un intervalle de trajets à récupérer ?" << endl;
			cout << "1 - Oui" <<endl;
			cout << "2 - Non" <<endl;
			char instructIntervalle ='0';
			int instructIntervalleN =0; //pas une bonne idée d'utiliser des int pour des cin
			int instructIntervalleM =0;
			
			
			cin >>instructIntervalle;
            
            while(instructIntervalle!='1' && instructIntervalle!='2') {
				cout << "Erreur, ceci n'est pas une option valable" << endl;
				cout << "Veuillez réessayer" << endl;
				cin.clear();
				cin.ignore(256,'\n');
				cin >> instructIntervalle;
			}
			cout<<endl;
            
            if (instructIntervalle=='1')
            {
				cout << "Veuillez taper la borne de comencement (trouve le mot!!) : ";
				cin >> instructIntervalleN;
				while(cin.fail()) {
					cout << "Erreur, l'entrée n'est probablement pas un entier" << endl;
					cout << "Veuillez réessayer" << endl;
					cin.clear();
					cin.ignore(256,'\n');
					cin >> instructIntervalleN;
				}
				cout<<endl;
				cout << "Veuillez taper la borne de finition (trouve le mot!!) : ";
				cin >> instructIntervalleM;
				while(cin.fail()) {
					cout << "Erreur, l'entrée n'est probablement pas un entier" << endl;
					cout << "Veuillez réessayer" << endl;
					cin.clear();
					cin.ignore(256,'\n');
					cin >> instructIntervalleM;
				}
				cout<<endl;
				int intervalle []= {1,instructIntervalleN,instructIntervalleM};
				cat1.RecupCatalogue(fic,0,0,villes,intervalle);
			} else {
				int intervalle []= {0,instructIntervalleN,instructIntervalleM};
				cat1.RecupCatalogue(fic,0,0,villes,intervalle);
			}
			fic.close();
			cout << "Inserez une nouvelle commande" <<endl;
		}
		
		cin>>instruct;
	    // enregistrer la nouvelle instruction	
	    cin.ignore();

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


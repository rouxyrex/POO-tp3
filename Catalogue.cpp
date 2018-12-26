/*************************************************************************
                         	    Catalogue
                             -------------------
    début                : 21/11/2018
    copyright            : (C) 2018 par LOKUGE, RAMSAHA
    e-mail               : sadsitha97@pediatrician.com
*************************************************************************/

//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <cstring>
#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

//------------------------------------------------------ Include personnel


#include "Catalogue.h"
#include "Trajet_Simple.h"
#include "Trajet_Compose.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC



//----------------------------------------------------- Méthodes publiques

	void Catalogue::AjoutTrajSimp()
	{
        	 
        const char* Nom1; // variables dont on se servira afin de stocker les informations requises pour la creation du trajet simple
        const char* Depart1;
        const char* Arrivee1;
        const char* Trans1;

		// variables transitoires dont on se servira afin de stocker les informations
		// elles sont nécessaire puisqu'on ne peut pas insérer une valeure dans un const char * en utilisant un cin
        char* Nomtmp = new char [4]; 
        char* Departtmp = new char [4];
        char* Arriveetmp = new char [4];
        char* Transtmp = new char [4];

		cout<<"Veuillez inserer le nom de ce trajet s'il vous plait "<< endl;
	    cin >> Nomtmp;

	    cout<<"Veuillez inserer la ville de depart de ce trajet s'il vous plait "<< endl;	
	    cin >> Departtmp;
	
	   	cout<<"Veuillez inserer la ville d'arrivee de ce trajet s'il vous plait "<< endl;
	   	cin >> Arriveetmp;
	
	   	cout<<"Veuillez inserer le moyen de transport de ce trajet s'il vous plait "<< endl;
	    cin >> Transtmp;

		Nom1=Nomtmp;        
		Depart1=Departtmp;
		Arrivee1=Arriveetmp;
		Trans1=Transtmp;

	    Trajet* Traj1 ;
       	Traj1 = new Trajet_Simple( Nom1, Depart1, Arrivee1, Trans1);
        
	    AddTrajet(Traj1);
 	}

	void Catalogue::AjoutTrajSimp2(Trajet** Tab,int& pos) 
    	{
         
        cout<<"Sous trajet numéro : "<< (pos+1) << endl;
		const char* Nom1; // variables dont on se servira afin de stocker les informations requises pour la creation du trajet simple
		const char* Depart1;
		const char* Arrivee1;
		const char* Trans1;

		// variables transitoires dont on se servira afin de stocker les informations 
		// elles sont nécessaire puisqu'on ne peut pas insérer une valeure dans un const char * en utilisant un cin
        	char* Departtmp = new char [4];
		char* Arriveetmp = new char [4];
		char* Transtmp = new char [4];
    

        char* Nomtmp = new char [4]; //Nom n'est pas important dans ce cas
        strcpy(Nomtmp,"TK1");

        if (pos==0)
        {
		    cout<<"Veuillez inserer la ville de depart de ce trajet s'il vous plait "<< endl;	
		    cin >> Departtmp;
        } else {
            strcpy(Departtmp,Tab[pos-1]->get_Arrivee());
        }
		
		cout<<"Veuillez inserer la ville d'arrivee de ce trajet s'il vous plait "<< endl;
		cin >> Arriveetmp;

		cout<<"Veuillez inserer le moyen de transport de ce trajet s'il vous plait "<< endl;
		cin >> Transtmp;
	     
        Nom1=Nomtmp;
        Depart1=Departtmp;
        Arrivee1=Arriveetmp;
        Trans1=Transtmp;
        
		Trajet* Traj1 ;
		Traj1 = new Trajet_Simple( Nom1, Depart1, Arrivee1, Trans1);
		Tab[pos]=Traj1;
	}

	void Catalogue::AjoutTrajComp()
    	{
		cout << "Veuillez inserer le nom de ce trajet compose s'il vous plait"<< endl;
		const char* NomC1;
		char* NomCtmp = new char [4];
		cin >> NomCtmp;
		NomC1=NomCtmp;
            
		cout<<"Veuillez inserer le nombre de trajets simples que vous voudriez ajouter a ce trajet compose s'il vous plait "<< endl;
		int num_Traj;
		cin >> num_Traj;
			
		Trajet ** Tab;
		Tab = (Trajet **) malloc(num_Traj*sizeof(Trajet*)); // allocation memoire correspondant aux nombres de trajets simples que nous aurons a ajouter 
		for(int i = 0; i < num_Traj ; i++)
		{	
			AjoutTrajSimp2(Tab,i);			
		}

		Trajet* TrajC1;
		TrajC1 = new Trajet_Compose(NomC1,Tab[0]->get_Depart(),Tab[num_Traj-1]->get_Arrivee(), Tab, num_Traj); // création du trajet composé avec ville de départ et arrivée correspondant à celle du premier et dernier trajet respectivement
		cout << TrajC1 ->get_Depart() << endl << TrajC1 ->get_Arrivee()<<endl;
		AddTrajet(TrajC1); 
	}



	void Catalogue::Afficher()
	{
        for (int i=0; i < count; i++)
        {
            int nombre = 0;
            Trajet** Contains = (Trajet**)malloc(100*sizeof(Trajet*)); //possibilite de reallouer de la memoire si necessaire
            Tab_trajet[i]->Renvoyer(nombre,Contains); // modifira Contains afin qu'il contienne le(s) pointeur(s) sur les trajets simples contenus le trajet courrant du catalogue
            cout << (i+1) << " : "<< Tab_trajet[i]->get_Nom() << " =";
            for (int j=0; j < nombre; j++)
            {
                if (j==(nombre-1))
                {
                    cout <<  " de " << Contains[j]->get_Depart() << " à "<< Contains[j]->get_Arrivee() <<  " en " << Contains[j]->get_Trans();
                }     
                else 
                {
                    cout <<  " de " << Contains[j]->get_Depart() << " à "<< Contains[j]->get_Arrivee() <<  " en " << Contains[j]->get_Trans() <<  " -";
                }
            }
            cout << "\r\n";
            free(Contains);
        }
	}

	void Catalogue::Rechercher(const char* a, const char* b)
	{
		int count1=0;
		Trajet** Tabret; //tableau pour stocker les résultats positifs
		Tabret = (Trajet**)malloc(sizeof(Trajet*));
    
		for(int i =0; i< count; i++)
		{
			if (strcmp(a,Tab_trajet[i]->get_Depart())==0 && strcmp(b,Tab_trajet[i]->get_Arrivee())==0)
            {
                Tabret[count1]=Tab_trajet[i];
                ++count1;
                Tabret=(Trajet **)realloc(Tabret,(count+1)*sizeof(Trajet *));
            }
		}

        //Afficher les resultats
        if (count1==0)
        {
            cout << "Aucun parcours trouvé\r\n";
        }
        else
        {
            cout << count1 << " parcours possibles : \r\n";
		    for (int i=0; i < count1; i++)
		    {
                cout << (i+1) << " : "<< Tabret[i]->get_Nom() << "\r\n";
		    }
        }
        free(Tabret);

	}


	bool Catalogue:: Deja_ajoute(Trajet ** tableau, int taille, Trajet * traj){
		for(int i = 0; i< taille +1; i++)
		{
			if(tableau[i]== traj)
			{
				return true;
			}
		}
		return false;
	}


    void Catalogue::Rechercher2(const char* a, const char* b)
	{
       	num_results = 0;
		for(int i = 0; i < count; i ++)
		{
			if(strcmp(a,Tab_trajet[i]->get_Depart() )==0 && strcmp(b,Tab_trajet[i]->get_Arrivee() )==0) // si le trajet correspond deja en totalite a ce qu'on veut
			{
				cout<< Tab_trajet[i]->get_Nom() << endl;
                ++num_results;
			}	
			else if(strcmp(a,Tab_trajet[i]->get_Depart() )==0 ) // si c'est la ville de depart qu'on veut
			{
                cherche(i, a ,b);
            }
				
		}
        cout<<num_results<<" parcours possibles"<<endl;		
	}

    void Catalogue::cherche(int i,const char* a, const char* b)
    {

		int size = 1; // current num of permutations
		//bool alreadythere = false; // variable utilise pour verifier si l'on est deja a destination
		bool no_more_traj = false; // variable utilise pour savoir si on a ajoute aucun nouveau resultat
		int numelems =1; // corresponds au nombre d'elements dans une combinaison
		Trajet *** tab; // declaration du tableau contenant toutes les combinaisons possible
		tab =(Trajet***)malloc(100 *sizeof(Trajet**)); // creation du tableau pour les combinaisons, on tentera avec un realloc apres
		int length[100]; // tableau qui garde la taille de chaque combinaison
		for(int h =0; h < 100 ; h++)
		{	
			tab[h] = (Trajet**)malloc(count * sizeof(Trajet*));
		}
		tab[0][0] = Tab_trajet[i]; // premier element de la premiere combinaison egal a la ville qu'on a trouve dont 

		int duplicate =0;  // variable utilise pour savoir si pour un trajet, il ya deux ou plus trajets qui peuvent etre des suites valable
		int count1=0; // sera l'index pour la combinaison courante						
		
		while(count1<size)
		{// tant qu'on a pas atteint la taille actuelle du tableau 
			for(int pos=(numelems - 1); pos< count; pos++) // on commence a partir de la position du dernier element ajoute
			{
				if (!no_more_traj)
				{
					
				    if((strcmp(tab[count1][pos]->get_Arrivee(),b)!=0))
					{
					    for(int j =0; j<count; j++)
					    {
			                //cout << "count1 is " << count1 << " of 100 pos is " << pos << " out of "<< count<< endl;
												

	
							    if(duplicate==1 && strcmp(tab[count1][pos]->get_Arrivee(),Tab_trajet[j]->get_Depart())==0 && !Deja_ajoute(tab[count1], pos, Tab_trajet[j]))
							    {
								
								    size++;
								    for(int t =0; t< pos + 1; t++) // duplique la combinaison dans une autre colonne
								    {
									    tab[size -1][t] = tab[count1][t];// copie du tableau, element par element
								    }
								    tab[size- 1][pos+1] = Tab_trajet[j];
								    length[size-1] = numelems;
							    }

							    else if(strcmp(tab[count1][pos]->get_Arrivee(),Tab_trajet[j]->get_Depart())==0 && !Deja_ajoute(tab[count1], pos, Tab_trajet[j]))
							    {

								    numelems++;
								    length[count1] = numelems;
								    tab[count1][pos+1] = Tab_trajet[j];
								    duplicate =1;
							    }
						

						        if(duplicate ==0 && j == count -1) // si aucun nouvel element a pu etre rajoute a la combinaison
						        {
							        no_more_traj = true; // plus possible de rajouter des trajets, on passe a la prochaine combinaison/colonne
							        break;	
						        }
						
					    }
					    //passe a la prochaine position dans la colonne/combinaison
					    duplicate =0; //remise de duplicate a 0

						} else
						{
							//affichage solution
							for(int p = 0; p< numelems-1; p++)
							{
								cout <<  tab[count1][p]->get_Nom() << " + ";
							}
							cout<< tab[count1][numelems-1]->get_Nom()<<endl;
							num_results++;
							break;
						}
					}
							
				}
				
			    //passer a la prochaine colonne
			    numelems = length[count1 +1]; //affecter a numelems la valeur du nombre d'element de la prochaine colonne
			    no_more_traj = false;
			    //alreadythere = false;
			    count1++;								

		}
	    for (i=0; i<100;++i)
		{
			free(tab[i]);
		}

		free(tab);
	
    }


    void Catalogue::test()
    {
		//cette methode sert de créer quelques trajets automatiquement
		//afin de rendre les tests plus rapides
	    const char* Depart1;
        char* Depart1tmp = new char [4];
        strcpy(Depart1tmp,"A");
        Depart1=Depart1tmp;
	    const char* Arriv1;
        char* Arriv1tmp = new char [4];
        strcpy(Arriv1tmp,"B");
        Arriv1=Arriv1tmp;
	    const char* Trans1;
        char* Trans1tmp = new char [4];
        strcpy(Trans1tmp,"MT1");
        Trans1=Trans1tmp;
	    const char* Nom1;
        char* Nom1tmp = new char [4];
        strcpy(Nom1tmp,"TS1");
        Nom1=Nom1tmp;	
	
	    const char* Depart2;
        char* Depart2tmp = new char [4];
        strcpy(Depart2tmp,"B");
        Depart2=Depart2tmp;
	    const char* Arriv2;
        char* Arriv2tmp = new char [4];
        strcpy(Arriv2tmp,"C");
        Arriv2=Arriv2tmp;
	    const char* Trans2;
        char* Trans2tmp = new char [4];
        strcpy(Trans2tmp,"MT1");
        Trans2=Trans2tmp;
	    const char* Nom2;
        char* Nom2tmp = new char [4];
        strcpy(Nom2tmp,"TS2");
        Nom2=Nom2tmp;

	    const char* Depart3;
        char* Depart3tmp = new char [4];
        strcpy(Depart3tmp,"B");
        Depart3=Depart3tmp;
	    const char* Arriv3;
        char* Arriv3tmp = new char [4];
        strcpy(Arriv3tmp,"Y");
        Arriv3=Arriv3tmp;
	    const char* Trans3;
        char* Trans3tmp = new char [4];
        strcpy(Trans3tmp,"MT3");
        Trans3=Trans3tmp;
	    const char* Nom3;
        char* Nom3tmp = new char [4];
        strcpy(Nom3tmp,"TK1");
        Nom3=Nom3tmp;	
	    	
	    const char* Depart4;
        char* Depart4tmp = new char [4];
        strcpy(Depart4tmp,"Y");
        Depart4=Depart4tmp;
	    const char* Arriv4;
        char* Arriv4tmp = new char [4];
        strcpy(Arriv4tmp,"C");
        Arriv4=Arriv4tmp;
	    const char* Trans4;
        char* Trans4tmp = new char [4];
        strcpy(Trans4tmp,"MT2");
        Trans4=Trans4tmp;
	    const char* Nom4;
        char* Nom4tmp = new char [4];
        strcpy(Nom4tmp,"TK2");
        Nom4=Nom4tmp;

	    const char* Depart5;
        char* Depart5tmp = new char [4];
        strcpy(Depart5tmp,"A");
        Depart5=Depart5tmp;
	    const char* Arriv5;
        char* Arriv5tmp = new char [4];
        strcpy(Arriv5tmp,"Z");
        Arriv5=Arriv5tmp;
	    const char* Trans5;
        char* Trans5tmp = new char [4];
        strcpy(Trans5tmp,"MT2");
        Trans5=Trans5tmp;
	    const char* Nom5;
        char* Nom5tmp = new char [4];
        strcpy(Nom5tmp,"TK3");
        Nom5=Nom5tmp;	
	    	
	    const char* Depart6;
        char* Depart6tmp = new char [4];
        strcpy(Depart6tmp,"Z");
        Depart6=Depart6tmp;
	    const char* Arriv6;
        char* Arriv6tmp = new char [4];
        strcpy(Arriv6tmp,"C");
        Arriv6=Arriv6tmp;
	    const char* Trans6;
        char* Trans6tmp = new char [4];
        strcpy(Trans6tmp,"MT1");
        Trans6=Trans6tmp;
	    const char* Nom6;
        char* Nom6tmp = new char [4];
        strcpy(Nom6tmp,"TK4");
        Nom6=Nom6tmp;			

	    int num1 = 2;
	    const char* Nom7;
        char* Nom7tmp = new char [4];
        strcpy(Nom7tmp,"TC1");
        Nom7=Nom7tmp;

	    int num2 = 2;
	    const char* Nom8;
        char* Nom8tmp = new char [4];
        strcpy(Nom8tmp,"TC2");
        Nom8=Nom8tmp;
    
	    Trajet* S1 = new Trajet_Simple( Nom1, Depart1, Arriv1, Trans1);
        AddTrajet(S1);

	    Trajet ** Tab1;
	    Tab1 = (Trajet **) malloc(num1*sizeof(Trajet*));
	    Trajet* C11 = new Trajet_Simple( Nom3, Depart3, Arriv3, Trans3);
	    Tab1[0] = C11;
	    Trajet* C12 = new Trajet_Simple( Nom4, Depart4, Arriv4, Trans4);
	    Tab1[1] = C12;
	    Trajet* TC1;
	    TC1 = new Trajet_Compose(Nom7,Tab1[0]->get_Depart(),Tab1[1]->get_Arrivee(), Tab1, num1);
        AddTrajet(TC1);

	    Trajet* S2 = new Trajet_Simple( Nom2, Depart2, Arriv2, Trans2);
        AddTrajet(S2);

	    Trajet ** Tab2;
	    Tab2 = (Trajet **) malloc(num2*sizeof(Trajet*));
	    Trajet* C21 = new Trajet_Simple( Nom5, Depart5, Arriv5, Trans5);
	    Tab2[0] = C21;
	    Trajet* C22 = new Trajet_Simple( Nom6, Depart6, Arriv6, Trans6);
	    Tab2[1] = C22;
	    Trajet* TC2;
	    TC2 = new Trajet_Compose(Nom8,Tab2[0]->get_Depart(),Tab2[1]->get_Arrivee(), Tab2, num2);
        AddTrajet(TC2);

    }

	bool Catalogue::SauvCatalogue() {
		ofstream fic;
		fic.open("TrajetsFile.csv");

		fic << "Ref,Nom,Départ,Arrivée,Trans,Count\n";
		
		int ref = 0; //compteur pour le nombre de trajets enregistré
		for (int i =0; i < count; ++i)
		{
			Tab_trajet[i]->SauvTrajet(fic, ref);
		}

		fic.close();
	}

//-------------------------------------------- Constructeurs - destructeur
	Catalogue::Catalogue () 
	{
		count=0;
		sizeTab=10;
		Tab_trajet = (Trajet **) malloc (sizeTab* sizeof(Trajet *)); // allocation mémoire pour le tableau de trajets
		
	    #ifdef MAP
	        cout << "Appel au constructeur de <Catalogue>" << endl;
	    #endif
	} //----- Fin de Catalogue


	Catalogue::~Catalogue ( )
	{
        for (int i=0; i<count;i++)
        {
            delete Tab_trajet[i];
        }
		free(Tab_trajet);
        
	    #ifdef MAP
	        cout << "Appel au destructeur de <Catalogue>" << endl;
	    #endif
	} //----- Fin de ~Catalogue


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
	void Catalogue::AddTrajet(Trajet * A)
	{
		if (count>=sizeTab)
		{
			//si le tableau est rempli, rajouter de la mémoire
			Tab_trajet=(Trajet **)realloc(Tab_trajet,(sizeTab+10)*sizeof(Trajet *));
			sizeTab=sizeTab+10;
		}
		Tab_trajet[count] = A;
		count++;
	}


/*!
 *\file
 *\brief
 *
 *Plik zawiera funkcje z klasy simplex
 *
 */
#include "../inc/simplex.hh"

using namespace std;

simplex::simplex(){
	n = 0;
}

simplex::~simplex(){
	for (int i = 0; i < n; i++)
		delete [] tab[i];
	delete [] tab;
	delete [] ograniczenia;
}

void simplex::wprowadz_dane(){
	cout<<"podaj ilosc rownan : ";
	cin>>n;

	tab = new double *[n];
	ograniczenia = new double[n];

	for (int i = 0; i < n; i++)
		tab[i] = new double[2];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 2; j++)
		tab[i][j]=0;
	int k=1;
	cout<<"Podaj wspolczyniki : "<<endl;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 2; j++){
		cout<<"Wspolczynnik "<<k++<<" ( "<<j+1<<" z 2 ) : ";
		cin>>tab[i][j];
	}

	cout<<"Podaj ograniczenia : "<<endl;
	for (int i = 0; i < n; i++){
		cout<<"Ogranieczenie "<<i+1<<" ( nie moze byc ujemne ) : ";
		cin>>ograniczenia[i];
	}

	cout<<"Podaj koszta : "<<endl;
	for (int i = 0; i < 2; i++){
		cout<<"koszt "<<i+1<<" ( musza byc dodatnie ) : ";
		cin>>koszt[i];
	}

}

void simplex::wyswietl(){
	cout<<"Wartosc tablicy : "<<endl;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < 2; j++){
			if (j == 0)
				if (tab[i][j] != 0)
					cout<<" "<<tab[i][j]<<"*x ";
				else
					cout<<"     ";
			else
				if (tab[i][j] != 0)
					cout<<" + "<<tab[i][j]<<"*y ";
				else
					cout<<"       ";
		}
	cout<<" <= "<<ograniczenia[i]<<endl;
	}
}

void simplex::oblicz(){
	int m=0;
	x[0]=9999,y[0]=9999;

	for (int i = 0; i < n; i++)
		if ((tab[i][0] != 0) && (tab[i][1] != 0))
			m=i;

	for (int i = 0; i < n; i++)
		if ((tab[i][0] != 0) || (tab[i][1] != 0)){
			if ((tab[i][0] != 0) && (ograniczenia[i] < x[0]))
				x[0] = ograniczenia[i] / tab[i][0];//prosta
			if ((tab[i][1] != 0) && (ograniczenia[i] < y[0]))
				y[0] = ograniczenia[i] / tab[i][1];
		}
	x[1] = 0;//0
	y[1] = 0;
	if ((ograniczenia[m] - (y[0]*tab[m][1]))/tab[m][0] < 0)
		x[2] = 0;
	else
		x[2] = (ograniczenia[m] - (y[0]*tab[m][1]))/tab[m][0];//linia
	if ((ograniczenia[m] - (x[0]*tab[m][0]))/tab[m][1] <0)
		y[2] = 0;
	else
		y[2] = (ograniczenia[m] - (x[0]*tab[m][0]))/tab[m][1];
	
	x[3] = ograniczenia[m]/tab[m][0];
	y[3] = ograniczenia[m]/tab[m][1];

	if (y[0] < y[3])
		zysk[0] = (x[1]*koszt[0]) + (y[0]*koszt[1]);
	else
		zysk[1] = (x[1]*koszt[0]) + (y[3]*koszt[1]);
	if (x[0] < x[3])
		zysk[2] = (x[0]*koszt[0]) + (y[1]*koszt[1]);
	else
		zysk[3] = (x[3]*koszt[0]) + (y[1]*koszt[1]);
	if ((y[2] != 0 ) || (x[2] != 0)){
	
	if ( ((x[0]+y[0]) < (x[2]+y[0]) ) || ((x[0]+y[0]) < (x[0]+y[2]) ) )
		zysk[4] = (x[0]*koszt[0]) + (y[0]*koszt[1]);
	else{
		if ((x[2]*koszt[0]) + (y[0]*koszt[1]) < (x[0]*koszt[0]) + (y[2]*koszt[1]))
			zysk[5] = (x[0]*koszt[0]) + (y[2]*koszt[1]);
		else
			zysk[6] = (x[2]*koszt[0]) + (y[0]*koszt[1]);
	}
	}
	int indeks=0;
	double zysk_max = 0, x_max = 0, y_max = 0 ;

	for (int i = 0; i < 7; i++){
		if (zysk[i] > zysk_max){
			zysk_max = zysk[i];
			indeks = i;
		}
	}
	switch(indeks){
		case 0: x_max = x[1] ; y_max = y[0]; break;
		case 1: x_max = x[1] ; y_max = y[3]; break;
		case 2: x_max = x[0] ; y_max = y[1]; break;
		case 3: x_max = x[3] ; y_max = y[1]; break;
		case 4: x_max = x[0] ; y_max = y[0]; break;
		case 5: x_max = x[0] ; y_max = y[2]; break;
		case 6: x_max = x[2] ; y_max = y[0]; break;
		default : cout<<"blad"; break;

	}

	cout<<"Maksymalny zysk to : "<<zysk_max<<" . Zostal osiagniety dla punktow : "<<endl;
	cout<<" x = "<<x_max<<endl;
	cout<<" y = "<<y_max<<endl;

}
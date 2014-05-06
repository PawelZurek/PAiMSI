#include "../inc/kolejka_lista.hh"
#include <iostream>

//using namespace std;

	bool kolejka_lista::isempty(){
		if ( licznik == 0)
		{
			return 1;
		}
		else return 0;
	}

	unsigned kolejka_lista::size(){
		cout<<"Rozmiar to: "<<licznik<<endl;
		return licznik;
	}

	elementk *kolejka_lista::push(elementk *p){
		if(tyl) tyl->nastepny = p;
		p->nastepny = NULL;
		tyl = p;
		if(!przod) przod = tyl;
		licznik++;
		return tyl;
	}

	elementk *kolejka_lista::pop(){
		elementk *p;
		if(przod){
			p = przod;
			przod = przod -> nastepny;
			if(!przod) tyl = NULL;
			licznik--;
			return p;
		}
		else{
			cout<<"Lista jest pusta."<<endl;
		 return NULL;
		 
		}
	}

	void kolejka_lista::pokaz_elementy(){
		elementk *p;

		if(!przod) cout<<"Lista jest pusta."<<endl;
		else
		{
			p = przod;
			cout<<"Zawartosc tablicy to :\n";
			while(p)
			{	
				cout<<p->klucz<<" \n";
				p = p->nastepny;
			}
			cout<<endl;
		}
	}

	void kolejka_lista::dodaj_element(int a){
	elementk *p;
	p = new elementk;
	p->klucz = a;
	push(p);
	}

	void kolejka_lista::wczytaj_dane(){
	int tmp=0;
	string nazwa;
	cout<<"Podaj nazwe pliku: ";
	cin>>nazwa;
   	nazwa="dane/"+nazwa;
	ifstream liczby(nazwa.c_str());
	if (!liczby){
        cout << "\n***********Nie mozna otworzyc pliku !!**********\n";
        getchar();
    }
    else{
    		while (liczby>>tmp)
       		dodaj_element(tmp);

    	}
}
void kolejka_lista::wczytaj_dane(string nazwa){
	int tmp=0;
   	nazwa="dane/"+nazwa;
	ifstream liczby(nazwa.c_str());
	if (!liczby){
        cout << "\n***********Nie mozna otworzyc pliku !!**********\n";
        getchar();
    }
    else{
    		while (liczby>>tmp)
       		dodaj_element(tmp);

    	}
}



#include "../inc/stos_lista.hh"
#include <iostream>

using namespace std;


	bool stos_lista::isempty(){
		if ( licznik == 0)
		{
			return 1;
		}
		else return 0;
	}

	unsigned stos_lista::size(){
		//cout<<endl<<"Rozmiar to: "<<licznik<<endl;
		return licznik;
	}

	element *stos_lista::push(element *p){
		p->nastepny = przod;
		przod = p;
		if(!tyl) tyl  = przod;
		licznik++;
		return przod;
	}

	element *stos_lista::pop(){
		element *p;
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

	int stos_lista::usun(){
		element *p;
		if(przod){
			p = przod;
			przod = przod -> nastepny;
			if(!przod) tyl = NULL;
			licznik--;
			return p->klucz;
		}
		else{
			cout<<"Lista jest pusta."<<endl;
			return 0;
		 
		}
	}

	void stos_lista::usun(int tmp){
		element *p;
		p=przod;
		while(p){
			if (p->klucz == tmp){
			p = p->nastepny;
			licznik--;
			break;			
			}
			p = p->nastepny;
		}
	}

	void stos_lista::pokaz_elementy(){
		element *p;

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

	void stos_lista::dodaj_element(int a){
	element *p;
	p = new element;
	p->klucz = a;
	push(p);
	}

	void stos_lista::wczytaj_dane(){
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

void stos_lista::wczytaj_dane(string nazwa){
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

int stos_lista::top(){
	if (przod)
		return przod->klucz;
	else
		return 0;
}

bool stos_lista::znajdz(int a){
	element *p;
	bool znaleziony =0;
	if(!przod) cout<<"Lista jest pusta."<<endl;
	else
	{
		p = przod;
		while(p)
		{	
			if (p->klucz == a){
				znaleziony = 1;
				break;
			}
			p = p->nastepny;
		}
		cout<<endl;
	}
	return znaleziony;
}



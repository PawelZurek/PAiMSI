#include "../inc/tab_hash.hh"

using namespace std;

bool tab_hash::pusta(){
	if (ilosc == 0){
		cout<<"Tablica pusta\n";
		return 1;
	}
	else{
		cout<<"Tablica NIE pusta !! \n";
		return 0;
	}
}

int tab_hash::size(){
	cout<<"rozmiar to : "<<rozmiar<<endl<<"Ilosc elementow to : "<<ilosc<<endl;
	return rozmiar;
}

void tab_hash::zaczynamy(){
	string wartosc;
	cout<<"Podaj wartosc do tablicy hashujacej :";
	cin>>wartosc;
	przydziel(hash_function(wartosc),wartosc);
}

int tab_hash::hash_function(string s){
	int indeks = 0;
	int sum = 0;
	for (unsigned int i = 0; i < s.size(); i++) {
   		sum += s[i];
	}
	indeks = sum%rozmiar;
	return indeks;
}

void tab_hash::znajdz(){
	string s;
	cout<<"Podaj element do znalezienia : ";
	cin>>s;
	pokaz(s, hash_function(s));
}

void tab_hash::pokaz(string s, int n){
	int i=n;
	//bool Znaleziono = 0;
	do{
		if (dane[i]==s){
			//cout<<"***HASH****Znaleziono element "<<s<<" na pozycji "<<i+1<<" w tablicy"<<endl;
			//Znaleziono = 1;
			break;
		}
		else
			i = (i+1)%rozmiar;
	}while(i != n);

	//if (Znaleziono == 0){
	//	cout<<"****HASH***W tablicy nie Znaleziono elementu : "<<s<<endl;
	//}
}

void tab_hash::usun(){
	string s;
	cout<<"Podaj element do znalezienia : ";
	cin>>s;
	usuwanie(s);
}

void tab_hash::usuwanie(string s){
	int n = hash_function(s);
	int i=n;
	bool Znaleziono = 0;
	do{
		if (dane[i]==s){
			dane[i]="";
			cout<<"Usunieto element "<<s<<" na pozycji "<<i+1<<" w tablicy"<<endl;
			Znaleziono = 1;
			ilosc--;
			break;
		}
		else
			i = (i+1)%rozmiar;
	}while(i != n);

	if (Znaleziono == 0){
		cout<<"W tablicy nie Znaleziono elementu : "<<s<<endl;
	}
}

void tab_hash::przydziel(int n, string w){

	if (ilosc == rozmiar){
		cout<<"Tablica zapelniona !!!!"<<endl;
	}
	else{
		int i = n;
		do{
			if (dane[i]==""){
				dane[i]=w;
				ilosc++;
				break;
			}
			else
				i = (i+1)%rozmiar;	
		}while(i != n);
	}
}

void tab_hash::wyswietl(){
	cout<<"Wartosci tablicy to : "<<endl;
	for (int i = 0; i < rozmiar; i++){
		cout<<i+1<<". "<<dane[i]<<endl;
	}
}

void tab_hash::wypelnij(string nazwa){
	string tmp;
   	nazwa="dane/"+nazwa;
	ifstream liczby(nazwa.c_str());
	if (!liczby){
        cout << "\n***********Nie mozna otworzyc pliku !!**********\n";
    }
    else
    	while (liczby>>tmp)
       			przydziel(hash_function(tmp),tmp);	
}
	

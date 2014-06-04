/*!
 *\file
 *\brief
 *
 *Plik zawiera funkcje z klasy graf
 *
 */
#include "../inc/Dijkstry.hh"

using namespace std;

Graf::Graf(){
	V = 0, E = 0, wierzcholki = 0;
}
Graf::~Graf(){
	if (V !=0){
		delete [] lista_sasiadujaca;
		delete [] wierzcholki;
	}
}
//Funkcja tylko do maina
void Graf::dowolny_plik(){
	cout<<endl<<" W pliku maja byc same polaczenia miedzy wierzcholkami. "<<endl;
	string nazwa;
	cout<<"Podaj nazwe pliku ( . txt ) :";
	cin>>nazwa;
	przerob_z_fb(nazwa,"przerobiony.txt");
	cout<<"Przerobiono plik ! "<<endl
		<<"Tworzenie grafu...";
	stworz_wierzcholki("przerobiony.txt");
	cout<<" ... ";
	stworz_liste_z_pliku(nazwa);
	cout<<"Stworzono graf !"<<endl;
}
//Funkcja tylko do maina
void Graf::domyslny_plik(){
	string nazwa="fb.txt";
	przerob_z_fb(nazwa,"przerobiony.txt");
	cout<<"Przerobiono plik ! "<<endl
		<<"Tworzenie grafu...";
	stworz_wierzcholki("przerobiony.txt");
	cout<<" ... ";
	stworz_liste_z_pliku(nazwa);
	cout<<"Stworzono graf !"<<endl;
}
//Funkcja tylko do maina
void Graf::testowy_plik(){
	string nazwa="test.txt";
	przerob_z_fb(nazwa,"przerobiony_test.txt");
	cout<<"Przerobiono plik ! "<<endl
		<<"Tworzenie grafu...";
	stworz_wierzcholki("przerobiony_test.txt");
	cout<<" ... ";
	stworz_liste_z_pliku(nazwa);
	cout<<"Stworzono graf !"<<endl;
}

//Funkcja tylko do maina
void Graf::losowe_dijkstry(){
	cout<<"Losowaanie...";
	int indeks1= rand() % V;
	int indeks2= rand() % V;
	cout<<"... wylosowano !";
	
	dijkstry(wierzcholki[indeks1], wierzcholki[indeks2]);
	
}
//przerabianie pliku
void Graf::przerob_z_fb( string typ ,string wyjscie){
	std::vector<int> v;
	int tmp=0, bylo = 0;
	typ="dane/"+typ;
	ifstream plik(typ.c_str());
	int k=0;//do sprawdzenia polaczen
	while( plik >> tmp){
		k++;
		for (unsigned int i = 0; i < v.size(); i++){
			if (v[i] == tmp){
				bylo = 1;
			}

		}
		if (bylo == 0)
			v.push_back(tmp);
		bylo = 0;

	}
	wyjscie="dane/"+wyjscie;
	ofstream plok(wyjscie.c_str());
	plok<<v.size()<<endl;
	for (unsigned int i = 0; i < v.size(); i++)
		plok<<v[i]<<endl;
}
//przerabianie pliku
void Graf::stworz_liste_z_pliku(string nazwapliku){
	if (V != 0)	{

	nazwapliku="dane/"+nazwapliku;
	ifstream plik;
	Wierzcholek pomoc;
	int v1, v2, wg = 1;// wage dla kazdego polaczenie uznajemy jako 1
	plik.open(nazwapliku.c_str());
	//plik >> V;  // liczba wierzcholkow
	//plik >> E;  // liczba krawedzi
	lista_sasiadujaca = new vector<Wierzcholek>[V];
	while (plik >> v1 >> v2 )
	{	
		if ( czy_bylo(v1,v2) == false){
		pomoc.sasiad = przypisz_indeks(v2);
		pomoc.waga = wg;
		lista_sasiadujaca[przypisz_indeks(v1)].push_back(pomoc);
		if (v1 != v2)
		{
			pomoc.sasiad = przypisz_indeks(v1);
			pomoc.waga = wg;
			lista_sasiadujaca[przypisz_indeks(v2)].push_back(pomoc);
		}
	}
	}

	}
	else
		cout<<"Prosze wprowadzic najpierw wierzcholki !!!"<<endl;

}

bool Graf::czy_bylo(int v1, int v2){
	bool bylo =false;
	for (unsigned int i = 0; i < lista_sasiadujaca[przypisz_indeks(v1)].size(); i++)
		 if (lista_sasiadujaca[przypisz_indeks(v1)][i].sasiad == przypisz_indeks(v2)){
			bylo = true;
			break;
		}

	return bylo;
}

int Graf::przypisz_indeks(int id){
	int indeks = -1;
	for (int i = 0; i < V; i++)
		if (wierzcholki[i] == id)
			indeks = i;

	if (indeks == -1)
		cerr<<"blad !!!!"<<endl;

	return indeks;		
}

void Graf::stworz_wierzcholki(string nazwapliku){
	nazwapliku="dane/"+nazwapliku;
	ifstream plik;
	int v1;
	plik.open(nazwapliku.c_str());
	plik >> V;  // liczba wierzcholkow
	wierzcholki = new int[V];
	int i =0;
	while (plik >> v1){
		wierzcholki[i++] = v1;
	}
}

void Graf::wyswietl(){
	for (int i = 0; i < V; i++){	

		cout << endl << setw(4) <<"  "<< wierzcholki[i] << ":";
		for (unsigned int j = 0; j < lista_sasiadujaca[i].size(); j++){
			cout << setw(4) << wierzcholki[lista_sasiadujaca[i][j].sasiad];
		}
	}

	cout << endl;
}

bool Graf::czy_poprawne( int a, int b){
	int ok =0;
	for (int i = 0; i < V; i++)	{
		if (wierzcholki[i] == a)
			ok++;
		if (wierzcholki[i] == b)
			ok++;
	}

	if (ok == 2){
		cout<<"Wierzcholki poprawne :)"<<endl;
		return 1;
	}
	else{
		cout<<"Wierzcholki nie poprawne !!!"<<endl;
		return 0;
	}
}

int Graf::dijkstry(int a, int b){
	cout<<endl<<"Wynik dzialania algorytmu : "<<endl;
	if (czy_poprawne(a,b)==1){
		a= przypisz_indeks(a);
		b= przypisz_indeks(b);
		bool poszlo=0;
	int d;
	priority_queue<Wezel, vector<Wezel>, por > S;  // zbior wierzcholkow 
	bool *odwiedzone = new bool[V];  // tablica odwiedzonych wierzcholkow
	bool *czy_w_kolejce = new bool[V]; // tablica, ktora sprawdza, czy dany wezel jest juz w kolejce priorytetowej
	int *droga = new int[V];  // tablica z poprzednimi wierzcholkami 
	Wezel *koszt = new Wezel[V];   // tablica z wierzcholkami, po ktorych sie poruszamy  

	for (int i = 0; i < V; i++){
		droga[i] = -1;      // wierzcholek, ktorego na pewno nie ma w grafie 
		odwiedzone[i] = false;
		czy_w_kolejce[i] = false;
		koszt[i].g = 123245;  // wartosc, zawsze wieksza od drogi 
		koszt[i].nr = i;  // numeruje wierzcholki 
	}

	koszt[a].g = 0;  // wartosc drogi do poczatkowego wierzcholka ustawiam na zero
	S.push(koszt[a]);  // dodaje pierwszy wierzcholek do zbioru

	while (!S.empty())
	{
		Wezel y = S.top();
		int x = y.nr;
		S.pop();
		czy_w_kolejce[x] = false;  // sciagamy wezel z kolejki 
		for (unsigned int i = 0; i < lista_sasiadujaca[x].size(); i++)
		{
			if (odwiedzone[lista_sasiadujaca[x][i].sasiad] == false)
			{
				if (koszt[lista_sasiadujaca[x][i].sasiad].g > koszt[x].g + lista_sasiadujaca[x][i].waga)
				{
					koszt[lista_sasiadujaca[x][i].sasiad].g = koszt[x].g + lista_sasiadujaca[x][i].waga;
					droga[lista_sasiadujaca[x][i].sasiad] = x;
				}
				if (czy_w_kolejce[lista_sasiadujaca[x][i].sasiad] == false)  // sprawdzam, czy dany wezel juz nie jest w kolejce
				{
					S.push(koszt[lista_sasiadujaca[x][i].sasiad]);  // dodaje sasiadow
					czy_w_kolejce[lista_sasiadujaca[x][i].sasiad] = true;  // wezel jest juz w kolejce 
				}
			}
			odwiedzone[x] = true;  // ustawiam odwiedzony wierzcholek
		}
		if (odwiedzone[b] == true)
		{
			cout<<"\n***********************************************************\n";
			cout<<"Polaczenie zostalo znalezione ! "<<endl;
			cout << endl << "Ilosc potrzebnych osob do poznania numeru " << wierzcholki[a] << " z " << wierzcholki[b] << " to : " << koszt[b].g -1;
			if (koszt[b].g == 1)
				cout<<"\nOsoba "<<wierzcholki[a]<<" zna sie bezposrednio z osoba "<<wierzcholki[b]<<" !"<<endl;
			else{
			cout << endl << "Sciezka poznania osob wyglada nastepujaco : " << wierzcholki[b];
			d = b;
			while (droga[d] != a)
			{
				d = droga[d];
				cout << " > "  << wierzcholki[d];
			}
			cout << " > " << wierzcholki[a];
			}
			cout<<"\n***********************************************************\n";
			poszlo = 1;
			return 0;

		}
	}

	if (poszlo == 0){
		cout<<"\n***********************************************************\n";
		cout<<" Nie ma polaczenia miedzy tymi osobami ! :( ";
		cout<<"\n***********************************************************\n";
		return 1;
	}

	delete [] czy_w_kolejce;
	delete [] odwiedzone;
	delete [] koszt;
	delete [] droga;
}
	
	
}

Wierzcholek &Wierzcholek::operator= (Wierzcholek const& c1){
	Wierzcholek temp;
	temp.sasiad = c1.sasiad;
	temp.waga = c1.waga;
	sasiad = c1.sasiad;
	waga = c1.waga;
	return temp;
}
//do generowanych losowo
bool Graf::czy_spojny(){
	Wierzcholek pomoc;
	int licznik = 0;
	stack<Wierzcholek> stos;

	bool *wizyta = new bool[V];
	for (int i = 0; i < V; i++)
		wizyta[i] = false;

	pomoc.waga = lista_sasiadujaca[0][0].waga;
	pomoc.sasiad = lista_sasiadujaca[0][0].sasiad;
	stos.push(pomoc);

	while (!stos.empty())
	{
		pomoc = stos.top();
		stos.pop();
		if (wizyta[pomoc.sasiad] != true)
		{
			wizyta[pomoc.sasiad] = true;
			for (unsigned int j = 0; j < lista_sasiadujaca[pomoc.sasiad].size(); j++)
			{
				Wierzcholek druga;
				druga.waga = lista_sasiadujaca[pomoc.sasiad][j].waga;
				druga.sasiad = lista_sasiadujaca[pomoc.sasiad][j].sasiad;
				if (wizyta[druga.sasiad] != true)
					stos.push(druga);

			}
			licznik++;
		}

	}
	delete[] wizyta;
	if (licznik == V)
	{
		cout << endl << "GRAF JEST SPOJNY! " << endl;
		return true;
	}
	else
	{
		cout << endl << "GRAF NIE JEST SPOJNY! " << endl;
		return false;
	}
	
}

void Graf::generuj_liste(int ilosc, int gestosc){
	V = ilosc;
	Wierzcholek pomoc;
	lista_sasiadujaca = new vector<Wierzcholek>[V];
	for (int i = 0; i < V; i++){
		for (int j = 0; j < i; j++)
		{
			int losowa = rand() % 100;
			if (losowa < gestosc)//(1)
			{
				int k = 1+ rand() % 1;
				pomoc.sasiad = j;
				pomoc.waga = k;
				lista_sasiadujaca[i].push_back(pomoc);
				if (i != j)
				{
					pomoc.sasiad = i;
					pomoc.waga = k;
					lista_sasiadujaca[j].push_back(pomoc);
				}

			}
		}
	}
	for (int i = 0; i <= 1; i++)
	{
		if (lista_sasiadujaca[i].empty())
		{
			pomoc.sasiad = 0;
			pomoc.waga = 0;
			lista_sasiadujaca[0].push_back(pomoc);
		}
	}

}



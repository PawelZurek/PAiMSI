#include "../inc/kolejka_tablica.hh"


	bool kolejka_tablica::isEmpty(){
		if ( rozmiar == 0)
		{
			return 1;
		}
		else return 0;
	}

	unsigned kolejka_tablica::size(){
		cout<<"Rozmiar to: "<<rozmiar<<endl;
		return rozmiar;
	}

	void kolejka_tablica::push(int element){
		if (rozmiar != 0)
		{
			danetmp = new int[rozmiar];
			for (int i = 0; i < rozmiar; i++)
				{
					danetmp[i] = dane[i];
				}
			delete [] dane;
			++rozmiar;
			dane = new int[rozmiar];
			dane[0] = element;
			int j = 1;
			for (int i = 0; i < (rozmiar-1); i++)
			{
				dane[j] = danetmp[i];
				j++;
			}
			j=0;
			delete [] danetmp;
		}else{
		++rozmiar;
		dane = new int[1];
		dane[0]=element;
		}	
	}

	void kolejka_tablica::pushx2(int element){
		++spr;
		if (rozmiar != 0)
		{ 
			if (rozmiar < spr)
			{
			danetmp = new int[rozmiar];
			for (int i = 0; i < rozmiar; i++)
				{
					danetmp[i] = dane[i];
				}
			delete [] dane;
			rozmiar=rozmiar*2;
			dane = new int[rozmiar];
			for (int i = 0; i < (spr-1); i++)
			{
				dane[i] = danetmp[i];
			}
			delete [] danetmp;
			dane[spr-1] = element;
			}
			else{
				dane[spr-1] = element;
			}
		}else{
		++rozmiar;
		dane = new int[1];
		dane[0]=element;
		}	
	}

	void kolejka_tablica::pop(){
		if (rozmiar != 0)
		{
			danetmp = new int[rozmiar];
			for (int i = 0; i < rozmiar; i++)
			{
				danetmp[i] = dane[i];
			}
			delete [] dane;
			--rozmiar;
			dane = new int[rozmiar];
			for (int i = 0; i < rozmiar; i++)
			{
				dane[i] = danetmp[i];
			}
			delete [] danetmp;
		}
		else cout<<" nie ma co usuwac, stos pusty !"<<endl;
	}
	void kolejka_tablica::pokaz_elementy(){
		if (rozmiar !=0)
		{
			cout<<"Elementy stosu to :\n";
			for (int i = (rozmiar-1); i >= 0; i--)
			{
				cout<<dane[i]<<endl;
			}
		}
		else cout<<"Stos PUSTY ! "<<endl;

	}

	void kolejka_tablica::wczytaj_dane(){
	int tmp = 0;
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
       		push(tmp);
    	}	
	}

	void kolejka_tablica::wczytaj_dane(string nazwa){
	int tmp = 0;
   	nazwa="dane/"+nazwa;
	ifstream liczby(nazwa.c_str());
	if (!liczby){
        cout << "\n***********Nie mozna otworzyc pliku !!**********\n";
        getchar();
    }
    else{
    		do{
       			liczby >> tmp;
       			push(tmp);      			
       		}while (!liczby.eof());
       		pop();
    	}	
	}
	void kolejka_tablica::wczytaj_danex2(string nazwa){
	int tmp = 0;
   	nazwa="dane/"+nazwa;
	ifstream liczby(nazwa.c_str());
	if (!liczby){
        cout << "\n***********Nie mozna otworzyc pliku !!**********\n";
        getchar();
    }
    else{
    		while (liczby>>tmp)
       		pushx2(tmp);
    	}	
	}

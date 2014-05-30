/*!
 *\file
 *\brief
 *
 *Plik zawiera funkcje z klasy graf
 *
 */
#include "../inc/graf.hh"

using namespace std;

graf::graf(int rozmiar)
{
	w.resize(rozmiar);
	for(unsigned int i = 0; i < w.size(); i++)
	{
		w[i].resize(rozmiar);
	}

	for(unsigned int i = 0; i < w.size(); i++)
	{
		for(unsigned int j = 0; j < w.size(); j++)
		{
			w[i][j].punkt.x = i;
			w[i][j].punkt.y = j;
		}
	}// ta wersja dla uzytkownika!!!!
	int startX = 0, stopX = 0;
	int startY = 0, stopY = 0;
	cout<<"Podaj gdzie sciana ma sie zaczac : "<<endl
		<<"Wspolrzedna x : ";
		cin>>startX;
	cout<<"Wspolrzedna y : ";
		cin>>startY;
	cout<<"Podaj gdzie sciana ma sie skonczyc : "<<endl
		<<"Wspolrzedna x : ";
		cin>>stopX;
	cout<<"Wspolrzedna y : ";
		cin>>stopY;
	Stworz_Sciane(startX,startY, stopX, stopY);
	cout<<"Podaj wspolrzedne punktu poczatkowego : "<<endl
		<<"Wspolrzedna x : ";
		cin>>startX;
	cout<<"Wspolrzedna y : ";
		cin>>startY;
	cout<<"Podaj wspolrzedne punktu koncowego: "<<endl
		<<"Wspolrzedna x : ";
		cin>>stopX;
	cout<<"Wspolrzedna y : ";
		cin>>stopY;
	Ustaw_punkty(startX,startY, stopX, stopY);
	cout<<endl;


	//Stworz_Sciane(1,1,7,7);do benchmarku
	//Ustaw_punkty(0,0,rozmiar-1,rozmiar-1);do benchmarku

}

void graf::Stworz_Sciane(int startX, int startY, int stopX, int stopY){
	Punkt start, meta;
	start.x = startX; start.y = startY ; meta.y = stopY; meta.x = stopX;

	for(int i = start.x; i <= meta.x; i++)
			w[i][startY].typ = sciana;
	for(int i = start.y; i <= meta.y; i++)
			w[stopX][i].typ = sciana;

}

void graf::Ustaw_punkty(int startX, int startY, int stopX, int stopY){
	poczatek.x = startX; poczatek.y = startY; koniec.x = stopX; koniec.y = stopY;

	w[poczatek.x][poczatek.y].typ = punkt;
	w[koniec.x][koniec.y].typ = punkt;
}

void graf::H(){
	for(unsigned int i = 0; i < w.size(); i++)
	{
		for(unsigned int j = 0; j < w.size(); j++)
		{
			w[i][j].h = fabs(w[i][j].punkt.x - koniec.x) + fabs(w[i][j].punkt.y - koniec.y);
		}
	}
}

void graf::G(){
	for(unsigned int i = 0; i < w.size(); i++)
	{
		for(unsigned int j = 0; j < w.size(); j++)
		{
			w[i][j].g = fabs(w[i][j].punkt.x - poczatek.x) + fabs(w[i][j].punkt.y - poczatek.y);
		}
	}
}

void graf::F(){
	for(unsigned int i = 0; i < w.size(); i++)
	{
		for(unsigned int j = 0; j < w.size(); j++)
		{
			w[i][j].f = w[i][j].h + w[i][j].g;
		}
	}
}

void graf::H(Punkt _w){
	w[_w.x][_w.y].h = fabs(w[_w.x][_w.y].punkt.x - koniec.x) + fabs(w[_w.x][_w.y].punkt.y - koniec.y);
}

void graf::F(Punkt _w){
	w[_w.x][_w.y].f = w[_w.x][_w.y].h + w[_w.x][_w.y].g;
}

void graf::Rozwiazanie(){
	Punkt p = koniec;
	while(p != w[poczatek.x][poczatek.y].rodzic)
	{
		w[p.x][p.y].typ = punkt;
		p = w[p.x][p.y].rodzic;
	}
}

void graf::A_star(){
    multimap<int, Wierzcholek> zamkniety, otwarty;
        
    w[poczatek.x][poczatek.y].g = 0;
    H(poczatek);
    F(poczatek);
    w[poczatek.x][poczatek.y].rodzic = poczatek;

    otwarty.insert(make_pair(w[poczatek.x][poczatek.y].f, w[poczatek.x][poczatek.y]));
        
    while (!otwarty.empty()) 
    {
        Wierzcholek p = otwarty.begin()->second;
        otwarty.erase(otwarty.begin());
        if (p.punkt.x == koniec.x && p.punkt.y == koniec.y) 
        {
            cout << " Punkt koncowy został znaleziony" << endl;
            break;
        }
        
        zamkniety.insert(make_pair(w[p.punkt.x][p.punkt.y].f, w[p.punkt.x][p.punkt.y]));
            
        for (int i = -1; i <= 1; ++i) 
        {
            for (int j = -1; j <= 1; ++j) 
            {
                int koszt;
				// zmiana kosztu szukania
                if (i && j)
                    koszt = 2;
                else
                    koszt = 1;
                    
                if (i && j)
                    continue;
                    
               	Punkt v;
                v.x = p.punkt.x + i;
                v.y = p.punkt.y + j;
                if (v.x < 0 || v.x >= w.size() || v.y < 0 || v.y >= w[v.x].size() || w[v.x][v.y].typ == sciana) 
                {
                	continue;
                }
                
                if (zamkniety.find(w[v.x][v.y].f) != zamkniety.end()) 
                {
                    continue;
                }
                
                if (otwarty.find(w[v.x][v.y].f) == otwarty.end()) 
                {
                    w[v.x][v.y].g = w[p.punkt.x][p.punkt.y].g + koszt;
                    H(v);
                    F(v);
                    w[v.x][v.y].rodzic = p.punkt;

                    otwarty.insert(make_pair(w[v.x][v.y].f, w[v.x][v.y]));
                }
                else 
                {
                    Wierzcholek x = otwarty.find(w[v.x][v.y].f)->second;
                    if (x.g < w[v.x][v.y].g) 
                    {
                        otwarty.erase(w[x.punkt.x][x.punkt.y].f);
                        otwarty.insert(make_pair(w[v.x][v.y].f, w[v.x][v.y]));
                    }
                }
            }
        }
    }
    Rozwiazanie();
}

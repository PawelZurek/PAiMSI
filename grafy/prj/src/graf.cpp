#include "../inc/graf.hh"

using namespace std;



graf::graf(int liczba_wierz){

  n= liczba_wierz;
  m=0;
  odwiedzony=0;
  tab = new int * [liczba_wierz];    // Tworzymy tablicę wskaźników
  wartosci = new string[liczba_wierz];
  wierzcholki = new int[liczba_wierz];

  for (int i = 0; i < liczba_wierz; i++)
    wierzcholki[i] = i+1; 

  for(int i = 0; i < n; i++)
    tab[i] = new int [liczba_wierz]; // Tworzymy wiersze

  wypelnij_zerami();

  odwiedzony = new bool[n];

  for(int i = 0; i < n; i++) odwiedzony[i] = false;
}

graf::~graf(){
  for(int i = 0; i < n; i++) 
    delete [] tab[i];
  delete [] tab;
  delete [] wartosci;
  if (m > 0)  
    delete [] wagi;
  delete [] wierzcholki;
  delete [] odwiedzony;
}
  
void graf::wypelnij_zerami(){
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++) tab[i][j] = 0;
}

void graf::ustaw_polaczenia(){
  cout<<"Podaj ile chcesz stworzyc krawedzi : ";
  cin>>m;
  wagi = new int[m];
  int v1=0,v2=0;  // Wierzchołek startowy i końcowy krawędzi
  int indeks = 0, indeks2 = 0;
  int jest = 0;

  
  for(int j = 1; j <= m; j++){
    cout<<"Polacz wierzcholek : ";
    cin>>v1;
    cout<<" z wierzcholkiem ( krawedz "<<j<<" ) : ";
    cin>>v2;
    for (int i = 0; i < n; i++){
      if (wierzcholki[i] == v1){
        indeks = i;
        jest++;
      }
      if (wierzcholki[i] == v2){
       indeks2 = i;
       jest++;
      }      
    }
    if (jest == 2){
      if ( ( (v1 >= wierzcholki[0] ) && (v1 <= wierzcholki[n-1]) ) && ( (v2 >= wierzcholki[0]) && (v2 <= wierzcholki[n-1]) ) ){
        tab[indeks][indeks2] = 1;      // Krawędź v1<->v2 obecna
      }
      else{
        cout<<"Zle wartosci ! wierzcholek musi byc wiekszy od 0 i nie wiekszy od "<<n<<" !"<<endl;
        j--;
      }
    }
    else
      cout<<"Nie ma ktoregos z wierzcholka !!!"<<endl;
    jest = 0; 
  }
}

void graf::dodaj_wartosci(){
  cout<<"\nPrzydzielanie wartosci do wierzcholkow : "<<endl;
  for (int i = 0; i < n; i++){
    cout<<"Podaj Wartosc dla wierzcholka "<<i+1<<" : ";
    cin>>wartosci[i];
  }
}

void graf::dodaj_wagi(){
  cout<<"\nPrzydzielanie wagi do krawedzi : "<<endl;
  for (int i = 0; i < m; i++){
  cout<<"Podaj Wartosc dla krawedzi "<<i+1<<" : ";
  cin>>wagi[i];
  }
}

void graf::wyswietl(){
  cout<<"Macierz polaczen : "<<endl;
  cout << "\n   ";
  for(int i = 0; i < n; i++) 
    cout << setw(3) << wierzcholki[i];
  cout << endl << endl;
  for(int i = 0; i < n; i++){
    cout << setw(3) << wierzcholki[i];
    for(int j = 0; j < n; j++) 
      cout << setw(3) << (int) tab[i][j];
    cout << endl;
  }
}

void graf::wyswietl_wartosci(){
  cout<<endl<<"wartosci wierzcholkow to : "<<endl;
  for (int i = 0; i < n; i++){
    cout<<"wierzcholek "<<wierzcholki[i]<<" : "<<wartosci[i]<<endl;
  }
}

void graf::wyswietl_wagi(){
  cout<<endl<<"wagi krawedzi to : "<<endl;
  for (int i = 0; i < m; i++){
    cout<<"krawedz "<<i+1<<" : "<<wagi[i]<<endl;
  }
}

void graf::wyswietl_wszystko(){
  //wyswietl_wartosci();
  //wyswietl_wagi();
  wyswietl();
}

bool graf::czy_sasiad(int v1,int v2){
  if (tab[v1][v2]==1){
    //cout<<"wierzcholek : "<<v1<<" jest sasiadem z wierzcholkiem : "<<v2<<endl;
    return 1;
    }
  else{
    //cout<<"wierzcholek : "<<v1<<" NIE jest sasiadem z wierzcholkiem : "<<v2<<endl;
    return 0;
  }
  cout<<"111111\n"<<endl;
}

void graf::sasiedztwo(){
  int w;
  cout<<"Podaj jakiego wierzcholka chcesz zbadac sasiedztwo : ";
  cin>>w;
  sasiedztwo(w);  
}

void graf::usuwanie_wierzcholka(){
  int w;
  bool jest= 0;
  cout<<"Podaj wierzcholek do usuniecia : ";
  cin>>w;

  for (int i = 0; i < n; i++){
    if (wierzcholki[i]==w)
      jest = 1;
  }
  if (jest == 1){
    usuwanie_wierzcholka(w);
  }
  else
    cout<<"Nie ma takiego wierzcholka !!!";
}

void graf::sasiedztwo(int v){
  int tmp=0;
  bool jest = 0;
  int indeks = 0;
  cout<<"Sasiedztwo wierzcholka "<<v<<" to :\n";

  for (int i = 0; i < n; i++){
      if (wierzcholki[i] == v){
        indeks = i;
        jest=1;
      } 
  }
  if (jest ==1){
    for (int i = 0; i < n; i++){
      if (( tab[i][indeks]==1 ) || ( tab[indeks][i]==1 )){
        cout<<"-> Wierzcholek : "<<wierzcholki[i]<<endl;
        tmp++;
      }
    }
    if (tmp==0)
      cout<<"Wierzcholek "<<v<<" nie ma sasiadow! :("<<endl;
  }
  else
    cout<<"Nie ma takiego wierzcholka!!!"<<endl;
}

void graf::dodaj_wierzcholek(){
  if (n >0){
    int **tmp; 
    tmp = new int * [n];    // Tworzymy tablicę wskaźników

    string *tmp_wart; 
    int *tmp_wierzcholki;
    tmp_wart = new string[n];
    tmp_wierzcholki =  new int[n];
  
    for(int i = 0; i < n; i++)
      tmp[i] = new int [n]; // Tworzymy wiersze

    for (int i = 0; i < n; i++){//kopiowanie wartosci
      tmp_wart[i] = wartosci[i];
      tmp_wierzcholki[i] = wierzcholki[i];
      for (int j = 0; j < n; j++)
        tmp[i][j] = tab[i][j];
    }
  
    for(int i = 0; i < n; i++)//usuwanie starych wartosci 
      delete [] tab[i];
    delete [] tab;
    delete [] wartosci;
    delete [] wierzcholki;

    n++;//Nowe wartosci
    tab = new int *[n];    // Tworzymy tablicę wskaźników
    wartosci = new string[n];
    wierzcholki = new int[n];
  
    for(int i = 0; i < n; i++)
      tab[i] = new int [n]; // Tworzymy wiersze

    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++) tab[i][j] = 0;

    for (int i = 0; i < n-1; i++){//kopiowanie wartosci
      wartosci[i] = tmp_wart[i];
      wierzcholki[i] = tmp_wierzcholki[i];
      for (int j = 0; j < n-1; j++)
        tab[i][j] = tmp[i][j];
    }
    wierzcholki[n-1]=wierzcholki[n-2]+1;
    for(int i = 0; i < n-1; i++)//usuwanie tymczasowych dancyh 
      delete [] tmp[i];
    delete [] tmp;
    delete [] tmp_wart;
    delete [] tmp_wierzcholki;

  }
}

void graf::usuwanie_wierzcholka(int v){
  if (n > 0){
    int * tmp_wierzcholki;
    tmp_wierzcholki =  new int[n];
    for (int i = 0; i < n; i++)
      tmp_wierzcholki[i] = wierzcholki[i];

    delete [] wierzcholki;
    int k = n;
    n--;
    wierzcholki =  new int[n];
    int j = 0;
    for (int i = 0; i < k; i++){
      if (tmp_wierzcholki[i] != v){
        wierzcholki[j] = tmp_wierzcholki[i];
        j++;
      }
    }

    int **tmp;
    tmp = new  int * [k];
     for(int i = 0; i < k; i++)
      tmp[i] = new int [k]; // Tworzymy wiersze
    
    for (int i = 0; i < k; i++)
      for (int j = 0; j < k; j++)
        tmp[i][j] = tab[i][j];

    for(int i = 0; i < k; i++)//usuwanie starych wartosci 
      delete [] tab[i];
    delete [] tab;
    int l=0;
    int p=0;
    tab = new int * [n];
    for(int i = 0; i < n; i++)
      tab[i] = new int [n]; // Tworzymy wiersze

    wypelnij_zerami();

    for (int i = 0; i < k; i++){
      if (tmp_wierzcholki[i] != v){
        for (int j = 0; j < k; j++){
          if (tmp_wierzcholki[j] != v){
          tab[p][l] = tmp[i][j];
          l++;
        }
        }
        p++;
        
      }
      l=0;
    }
    

    for(int i = 0; i < k; i++)//usuwanie tymczasowych dancyh 
      delete [] tmp[i];
    delete [] tmp;
    delete [] tmp_wierzcholki;

  }
  else
    cout<<"Brak wierzcholkow !!!!!!!!"<<endl;
}

void graf::dodawanie_krawedzi(int v1, int v2, int e){
  if (tab[v1][v2] == 0)
    tab[v1][v2] = e;
  else
    cout<<"te wierzcholki juz sa polaczone !!"<<endl;
}

void graf::dodawanie_krawedzi(){
  int v1=0, v2=0, e=0, jest = 0, indeks = 0, indeks2 =0;
  cout<<"Polacz wierzcholek : ";
  cin>>v1;
  cout<<" z wierzcholkiem : ";
  cin>>v2;
  cout<<"Polaczenie ma wage : ";
  cin>>e;

  for (int i = 0; i < n; i++){
      if (wierzcholki[i] == v1){
        indeks = i;
        jest++;
      }
      if (wierzcholki[i] == v2){
        indeks2 = i;
        jest++;
      }  
  }

  if (jest ==2)
    dodawanie_krawedzi(indeks,indeks2,e);
  else
    cout<<"Nie ma ktoregos z wierzcholka"<<endl;
}

void graf::usuwanie_krawedzi(int v1, int v2){
  if (tab[v1][v2] != 0)
    tab[v1][v2] = 0;
  else
    cout<<"Nie ma krawedzi miedzy tymi wierzcholkami !!"<<endl;
}

void graf::usuwanie_krawedzi(){
  int v1=0, v2=0, jest = 0, indeks2 = 0, indeks = 0;
  cout<<"Usun krawedz miedzy wierzcholkiem ";
  cin>>v1;
  cout<<" a wierzcholkiem : ";
  cin>>v2;

  for (int i = 0; i < n; i++){
      if (wierzcholki[i] == v1){
        indeks = i;
        jest++;
      }
      if (wierzcholki[i] == v2){
        indeks2 = i;
        jest++;
      }  
  }

  if (jest ==2)
    usuwanie_krawedzi(indeks,indeks2);
  else
    cout<<"Nie ma ktoregos z wierzcholka"<<endl;
  
}

void graf::ilosc_wierzcholkow(){
  cout<<" Aktualnie w grafie jest : "<<n<<" wierzcholkow."<<endl;
}

int graf::get_wierzcholki(){
  return n;
}

void graf::wyswietl_wierzcholki(){
  cout<<"Aktualne wierzcholki grafu to : "<<endl;
  for (int i = 0; i < n; i++)
    cout<<wierzcholki[i]<<endl;
}

void graf::dfs(int v){
  odwiedzony[v-1]=true;
  //cout<< setw(3) << v;

  for (int i = 0; i < n; i++)
    if ((tab[v-1][i] != 0) && (odwiedzony[i]==false))
      dfs(i+1);
}

void graf::dfs(){
  int v=0;
  usun_tab_odw();
  storz_tab_odw();

  cout<<"Podaj wierzcholek : ";
  cin>>v;
  dfs(v);
  cout<<endl;
}

void graf::bfs(int v){
  --v;
  elementk *q,*head,*tail;

  q = new elementk;        // W kolejce umieszczamy v
  q->nastepny = NULL;
  q->klucz = v;
  head = tail = q;


  odwiedzony[v] = true;      // Wierzchołek v oznaczamy jako odwiedzony

  while(head)
  {
    v = head->klucz;       // Odczytujemy v z kolejki
    q = head;             // Usuwamy z kolejki odczytane v
    head = head->nastepny;
    if(!head) tail = NULL;
    delete q;

    //cout << setw(3) << v+1;

    for(int i = 0; i < n; i++)
      if((tab[v][i] != 0) && !odwiedzony[i])
      {
        q = new elementk; // W kolejce umieszczamy nieodwiedzonych sąsiadów
        q->nastepny = NULL;
        q->klucz = i;
        if(!tail) head = q;
        else tail->nastepny = q;
        tail = q;
        odwiedzony[i] = true; // i oznaczamy ich jako odwiedzonych
      }
  }
}

void graf::bfs(){
  usun_tab_odw();
  storz_tab_odw();
  int v=0;
  
  cout<<"Podaj wierzcholek : ";
  cin>>v;
  bfs(v);
  cout<<endl;
}

void graf::usun_tab_odw(){
  delete [] odwiedzony;
}

void graf::storz_tab_odw(){
  odwiedzony = new bool[n];

  for(int i = 0; i < n; i++) odwiedzony[i] = false;
}


void graf::losuj_polaczenia(){
  
  int proc;
  cout<<"Podaj procentowo jakie chcesz zapelnienie: ";
  cin>>proc;
  m=(proc*n*n)/100;
  wagi = new int[m];
  int wartosc=0;
  int indeks = 0, indeks2 =0;

  for(int j = 0; j < m; j++){
    indeks = rand() % n;
    indeks2 = rand() % n;
      if (tab[indeks][indeks2] == 0){
        wartosc= 1;
        tab[indeks][indeks2] = wartosc;
        wagi[j] = wartosc;
      }
      else j--;
    }
}

void graf::losuj_polaczenia(int proc){

  m=(proc*n*n)/100;
  wagi = new int[m];
  int wartosc=0;
  int indeks = 0, indeks2 =0;

  for(int j = 0; j < m; j++){
    indeks = rand() % n;
    indeks2 = rand() % n;
      if (tab[indeks][indeks2] == 0){
        wartosc= 1;
        tab[indeks][indeks2] = wartosc;
        wagi[j] = wartosc;
      }
      else j--;
    }
}

void graf::usun_wszystko(){
  if (m>0)
    delete [] wagi;
  
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      tab[i][j] = 0;
}

void graf::a_star(){
  int v1=0, v2=0;

  cout<<"Podaj wierzcholek 1 : ";
  cin>>v1;
  cout<<"Podaj wierzcholek 2 : ";
  cin>>v2;

  a_star(v1,v2);

}

void graf::a_star(int start, int koniec){
  otwarte.dodaj_element(start);
  zamkniete.dodaj_element(start);
  do{
    punkty_odwiedzone.dodaj_element(start);
    wartosci[start-1]=oblicz_F_G_H(start);

    start=znajdz_najmniejsze_f();
    otwarte.usun(start);
    cout<<"start : "<<start<<endl;
    zamkniete.dodaj_element(start);
    for (int j = 0; j <  n; j++){
      if ((czy_sasiad(start-1,j)==1) && (zamkniete.znajdz(j+1) == 0 )){
        
        if (otwarte.znajdz(j+1)==0){        
          otwarte.dodaj_element(j+1);
          start=j+1;
          wartosci[j]=oblicz_F_G_H(j+1);
        }
        else{

          if (zdobadz_G(j+1) > zdobadz_G(start)){
              start=j+1;
          wartosci[j]=oblicz_F_G_H(j+1);
          }
        }
      }
    }
  }while(start != koniec);
  cout<<koniec<<endl;
  if (start == koniec){
    cout<<"Znaleziono polaczenie nastepujaca droga : "<<endl;
    punkty_odwiedzone.pokaz_elementy();
  }
  else
    cout<<"Nie Znaleziono polaczenia"<<endl;
}

string graf::oblicz_F_G_H(int indeks){

  int g=0,h=0,f=0;
  string tmp,tmp1,tmp2,fgh;
  g = oblicz_G();
  tmp = intToStr(g);
  h = oblicz_H(indeks);
  tmp1 = intToStr(h);
  f= g+h;
  tmp2= intToStr(f);
  fgh = tmp+"."+tmp1+","+tmp2;
  cout<<endl<<fgh<<endl;
  return fgh;
}

int graf::oblicz_H(int indeks){
  int suma=0;
  przejdz_do_nastepnego(indeks);
  for (int i = 0; i < m; i++)
  suma = suma + wagi[i];
  
  return suma;
}
int graf::przejdz_do_nastepnego(int indeks){
  int j = 0;
  for (j = 0; j < n; j++){
      if ((tab[indeks-1][j] == 1) && (odwiedzony[j]==0)){
        odwiedzony[j] = 1;
        dodaj_wagi(indeks, j, 5);
        break;
      } 
    }
    return  j;
}

int graf::oblicz_G(){
  int suma= 0, i =0 ; 
  int *tmp;
  if (punkty_odwiedzone.size() > 1){
    int rozmiar = punkty_odwiedzone.size();
    tmp  = new int[rozmiar];
    while(punkty_odwiedzone.isempty() == 0 ){
      tmp[i] = punkty_odwiedzone.top();
      punkty_odwiedzone.pop();
      i++;
    }
  for (int j = 0; j < rozmiar; j++){
    punkty_odwiedzone.dodaj_element(tmp[j]);
    suma = suma + (2*tmp[j]);
  }
  delete [] tmp;
  }
  
  return suma;
}

int graf::znajdz_najmniejsze_f(){

  
  int *tymczas;
  int *tmp;
  int rozmiar = punkty_odwiedzone.size();
  tymczas = new int[rozmiar];
  tmp =  new int[rozmiar];
  int i = 0, najmniejszy = 999, indeks = 0;
  while(punkty_odwiedzone.isempty() == 0 ){
    tymczas[i]=punkty_odwiedzone.usun();
    tmp[i] = zdobadz_F(tymczas[i]);
    i++;
  }
  for (int i = 0; i < rozmiar; i++){
    punkty_odwiedzone.dodaj_element(tymczas[i]);
     if( tmp[i] < najmniejszy ){
         najmniejszy = tmp[ i ];
         indeks = i;
       }
  }
  delete [] tymczas;
  delete [] tmp;
  return indeks+1;
}

int graf::zdobadz_G(int indeks){
  return znajdz_g(wartosci[indeks-1]);
}

int graf::zdobadz_F(int indeks){
  return znajdz_f(wartosci[indeks-1]);
}



int graf::znajdz_g(string tmp){
  int pos = tmp.find(".");

  string g = tmp.substr(0,pos);
  int g_gotowe  = strToInt(g);

  return  g_gotowe;
}

int graf::znajdz_f(string tmp){
  int pos = tmp.find(",");
  string f = tmp.substr(pos+1);
  int f_gotowe  = strToInt(f);

  return  f_gotowe;
} 



string intToStr(int n){
     string tmp;
     if(n < 0) {
      tmp = "-";
      n = -n;
     }
     if(n > 9)
      tmp += intToStr(n / 10);
     tmp += n % 10 + 48;
     return tmp;
}

int strToInt(string s){
     unsigned tmp = 0, i = 0;
     bool m = false;
     if(s[0] == '-') {
      m = true;
      i++;
     }
     for(; i < s.size(); i++)
      tmp = 10 * tmp + s[i] - 48;
     return m ? -tmp : tmp;   
}

void graf::dodaj_wagi( int v1, int v2 , int waga){
  tab[v1][v2] = waga;
  for (int i = 0; i < m; i++)
    if (wagi[i]==0){
      wagi[i] = waga;
      break;
    }

}
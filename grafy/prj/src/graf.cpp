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
        tab[indeks2][indeks] = 1;
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
        wartosc= 1+ rand() % 20;
        tab[indeks][indeks2] = wartosc;
        tab[indeks2][indeks] = wartosc;
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

#include "../inc/drzewo.hh"

using namespace std;
/*     
struct node{
  string key;
  string wart;
  struct node *lewy;
  struct node *prawy;
  }*korzen=NULL;
  */   
node *korzen=NULL;


void node::pushuj(node *&korzen,string x,string w){	
  if(korzen==NULL){
    korzen= new (struct node);
    korzen->lewy=NULL;
    korzen->prawy=NULL;
    korzen->key=x;
    korzen->wart = w;
    return;
    }
  else{
    if(x<(korzen->key))
    pushuj(korzen->lewy,x,w);
    else pushuj(korzen->prawy,x,w);
  }
} 

void node::showrek(node *korzen) //lewe poddrzewo, prawe,rekurencyjnie
{    
  if(korzen){
    showrek(korzen->lewy);
    cout<<"Element : "<<korzen->key<<" ma wartosc : "<<korzen->wart<<endl;
    showrek(korzen->prawy);
  }    
}
void node::wypelnij(string nazwa){
  string tmp1, tmp2;
    nazwa="dane/"+nazwa;
  ifstream liczby(nazwa.c_str());
  if (!liczby){
        cout << "\n***********Nie mozna otworzyc pliku !!**********\n";
    }
    else
      while (liczby>>tmp1){
        liczby>>tmp2;
          pushuj(korzen,tmp1,tmp2);  
    }
}

void node::UsunDrzewo (node *&wezel){  
  node *pom;    
  if (wezel != NULL){  
    UsunDrzewo (wezel -> lewy);  
    UsunDrzewo (wezel -> prawy);   
    pom=wezel;  
    wezel=NULL;  
    delete pom;    
  }  
} 

node*  node::ZnajdzWezel (node* wezel, string wartosc){  
// Funkcja zwraca wskaźnik do węzła zawierającego „wartosc”, jeśli taki węzeł znajduje się   
// w drzewie, w przeciwnym razie zwraca wartość NULL  
  if (wezel == NULL || wartosc == wezel->key)  
    return wezel;  
      
  if (wartosc < wezel->key)   
    return ZnajdzWezel (wezel->lewy, wartosc);  
  else  
    return ZnajdzWezel (wezel->prawy, wartosc);  
}  

void node::znajduj(){
  string a;
  cout<<"Podaj element do znalezienia : ";
  cin>>a;

  node *tmp = ZnajdzWezel(korzen,a);

  if (tmp == NULL)
  	cout<<"nie znaleziono :( "<<endl;
  else
    cout<<"Element o kluczu : "<<tmp->key<<" ma wartosc : "<<tmp->wart<<endl;
}



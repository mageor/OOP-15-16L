#include <iostream>
#include <cstring>
using namespace std;

class Vozac{
protected:
    char ime[100];
    int vozrast;
    int trki;
    bool veteran;
public:
    Vozac (){
    }
    
    Vozac (char *i, int v, int t, bool ve){
       strcpy(ime, i);
        vozrast = v;
        trki = t;
        veteran = ve;
    }
    
    ~Vozac(){
    }
    
    friend ostream &operator << (ostream& o, Vozac& v){
        o << v.ime << endl;
        o << v.vozrast << endl;
        o << v.trki << endl;
        if (v.veteran == true){
        o << "VETERAN" << endl;
        }
        return o;
    }
    
    bool operator == (Vozac &v){
    return zarabotuvacka() == v.zarabotuvacka();
    }
    
    virtual float zarabotuvacka () = 0;
    
    virtual float danok () = 0;
};

class Avtomobilist : public Vozac{
private:
    float cena;
public:
    Avtomobilist (char *i, int v, int t, bool ve, float c):Vozac(i,v,t,ve){
    cena = c;
    }
    
    ~Avtomobilist(){
    }
    
    float zarabotuvacka(){
    return cena / 5;
    }
    
    float danok(){
        int pom;
        if (trki > 10){
            return zarabotuvacka() * 0.15;
            //return pom + zarabotuvacka();
        }
        else 
            return zarabotuvacka() * 0.10;
        //return pom + zarabotuvacka();
    }
};

class Motociklist : public Vozac {
private:
    int mokjnost;
public:
    Motociklist(char *i, int v, int t, bool ve, int m):Vozac(i,v,t,ve){
    mokjnost = m;
    }
    
    ~Motociklist(){
    }
    
    float zarabotuvacka(){
    return mokjnost * 20;
    }
    
    float danok(){
        int pom;
        if (veteran == true){
        return zarabotuvacka() * 0.25;
            //return pom + zarabotuvacka();
        }
        else 
           return zarabotuvacka() * 0.20;
        //return pom + zarabotuvacka();
    }
};

int soIstaZarabotuvachka(Vozac **niza, int n, Vozac *v){
int broj = 0;
    for (int i=0; i<n; i++){
        if (*v== *niza[i]){
        broj++;
        }
    }
    return broj;
}

int main() {
	int n, x;
	cin >> n >> x;
	Vozac **v = new Vozac*[n];
	char ime[100];
	int vozrast;
	int trki;
	bool vet;
	for(int i = 0; i < n; ++i) {
		cin >> ime >> vozrast >> trki >> vet;
		if(i < x) {
			float cena_avto;
			cin >> cena_avto;
			v[i] = new Avtomobilist(ime, vozrast, trki, vet, cena_avto);
		} else {
			int mokjnost;
			cin >> mokjnost;
			v[i] = new Motociklist(ime, vozrast, trki, vet, mokjnost);
		}
	}
	cout << "=== DANOK ===" << endl;
	for(int i = 0; i < n; ++i) {
		cout << *v[i];
		cout << v[i]->danok() << endl;
	}
	cin >> ime >> vozrast >> trki >> vet;
	int mokjnost;
	cin >> mokjnost;
	Vozac *vx = new Motociklist(ime, vozrast, trki, vet, mokjnost);
	cout << "=== VOZAC X ===" << endl;
	cout << *vx;
	cout << "=== SO ISTA ZARABOTUVACKA KAKO VOZAC X ===" << endl;
	cout << soIstaZarabotuvachka(v, n, vx);
    for(int i = 0; i < n; ++i) {
        delete v[i];
    }
    delete [] v;
    delete vx;
	return 0;
}

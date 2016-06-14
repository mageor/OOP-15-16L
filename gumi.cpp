#include <iostream>
#include <cstring>
using namespace std;

class Guma {
private:
    char proizvoditel [100];
    int uslovi;
    float sirina;
    int naLager;
public:
    Guma(){}
    
    Guma (char *p, int uslovi, float sirina, int naLager){
    strcpy (proizvoditel, p);
        this -> uslovi = uslovi;
        this -> sirina = sirina;
        this -> naLager = naLager;
    }
    
   
    friend ostream &operator<<(ostream &out,Guma &g){
    out<<g.proizvoditel<<"\n";
    if(g.uslovi)
      out<<"letni"<<"\n";
    else
      out<<"zimski"<<"\n";
    out<<g.sirina<<"\n"<<g.naLager<<endl;
    return out;
    }
    bool operator == (Guma& p){
        if (!strcmp (proizvoditel, p.proizvoditel)&&uslovi==p.uslovi&&sirina == p.sirina){
        return true;
        }
        else return false;
    }
    
    Guma& operator += (int n){
    naLager += n;
        return *this;
    }
    
    int getLager(){
    return naLager;
    }
    
    int getUslovi(){
    return uslovi;
    }
};

class ProdavnicaZaGumi {
private:
    char ime [100];
    Guma *guma;
    int elementi;
public:
    ProdavnicaZaGumi(){}
    
    ProdavnicaZaGumi(const char *ime){
    strcpy (this -> ime, ime);
        guma = NULL;
        elementi = 0;
    }
    
    ProdavnicaZaGumi& operator += (Guma& g){
    bool nema = true;
        for (int i=0; i<elementi; i++)
            if (guma[i]==g){
        nema = false;
            guma[i]+=g.getLager();
        }
        
        if(nema){
        Guma *pom = new Guma[elementi+1];
            for (int i=0; i<elementi; i++)
                pom [i]=guma[i];
            delete [] guma;
            pom[elementi]=g;
            guma = pom;
            pom = NULL;
            elementi++;
        }
        return *this;
    }
    
    friend ostream& operator << (ostream& out, ProdavnicaZaGumi& p){
    out<<p.ime<<endl;
        for (int i=0; i<p.elementi; i++){
        out<<p.guma[i]<<endl;
        }
        return out;
    }
    
    int naLager(int uslovi){
    int lager=0;
        for (int i=0; i<elementi; i++){
        if (guma[i].getUslovi() == uslovi)
            lager+=guma[i].getLager();
        }
        return lager;
    }
};

int main() {
	char prodavnica[100];
	cin >> prodavnica;
	ProdavnicaZaGumi p(prodavnica);
	int n;
	cin >> n;
    for(int i = 0; i < n; ++i) {
		char proizvoditel[100];
		int uslovi;
		float shirina;
		int lager;
		cin >> proizvoditel >> uslovi >> shirina >> lager;
		Guma g(proizvoditel, uslovi, shirina, lager);
		p += g;
	}
	cout << "PECHATI PRODAVNICA" << endl;
	cout << p;
	int uslovi;
	cin >> uslovi;
    cout << "VKUPNO SO ULOVI: " << uslovi << endl;
	cout << p.naLager(uslovi) << endl;
	return 0;
}

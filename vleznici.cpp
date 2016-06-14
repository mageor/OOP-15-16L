#include <iostream>
#include <cstring>
using namespace std;

class Vleznica{
protected:
    char natprevar[50];
    float osCena;
public:
    Vleznica(char *n=NULL, float c=0.0){
    strcpy(natprevar, n);
    osCena = c;
    }
    
    char *getNatprevar(){
    return this->natprevar;
    }
    
    float getCena(){
    return this->osCena;
    }
    
    virtual float cena () = 0;
    
};

class VleznicaSedenje : public Vleznica {
private:
    int blok;
    int red;
public:
    VleznicaSedenje(char *n=NULL, float c=0.0, int b=0, int r=0)
        :Vleznica(n,c){
        blok = b;
        red = r;
        }
    float cena () {
        if (red<8){
        return osCena*0.4 + osCena;
        }
        else if (red>8&&red<15){
        return osCena*0.2+osCena;
        }
        else return osCena;
    }
};

class VleznicaStoenje : public Vleznica {
protected:
    char tribina;
public: 
    VleznicaStoenje(char *n=NULL, float c=0.0, const char t='s'):Vleznica(n,c){
        tribina = t;
        }
    
    float cena (){
        if (tribina == 'S'){
        return osCena*1.30;
        }
        else return osCena;
    }
};

void najmalaCena( Vleznica **vleznici, int n) { 
    float min;
    min = vleznici[0]->cena();
    int pom=0;//ni treba da go cuvame indexot i
    for(int i=0; i<n; i++) {
        if(vleznici[i]->cena() < min ) {
            min=vleznici[i]->cena();
            pom=i;
        }
    }
 
    cout<<vleznici[pom]->getNatprevar()<<endl; 
    cout<<min;
}


int main() {
	int n;
	cin >> n;
	Vleznica** vleznici = new Vleznica*[n];
	for(int i = 0; i < n; ++i) {	
		char ime[30];
		float osnovnaCena;
		cin >> ime >> osnovnaCena;
		if(i % 2) {
			int blok, red;
			cin >> blok >> red;
			vleznici[i] = new VleznicaSedenje(ime, osnovnaCena, blok, red);
		} else {
			char tribina;
			cin >> tribina;
			vleznici[i] = new VleznicaStoenje(ime, osnovnaCena, tribina);
		}
	}

	najmalaCena(vleznici, n);

	for(int i = 0; i < n; ++i) {
		delete vleznici[i];
	}
	delete [] vleznici;
	return 0;
}

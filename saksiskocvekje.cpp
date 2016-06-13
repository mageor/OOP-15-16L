#include <iostream>
#include <cstring>
using namespace std;

class SaksiskoCveke {
protected:
    char ime[30];
    int cena;
    char familija[30];
public:
    SaksiskoCveke(const char *ime=" ", int cena=0, const char *familija=" "){
        strcpy (this -> ime, ime);
        this -> cena = cena;
        strcpy (this -> familija, familija);
    }
    
    virtual int presmetajCena () = 0;
    
    virtual ~SaksiskoCveke(){
    }
    
    bool operator == (SaksiskoCveke& s){
    return strcmp (familija, s.familija);
    }
    
    char *getIme(){
    return ime;
    }
    
    char *getFamilija(){
    return familija;
    }
    
    int getCena(){
    return cena;
    }
};

class BezCvet : public SaksiskoCveke {
private:
    int staro;
public: 
    BezCvet (const char *ime=" ", int cena=0, const char *familija=" ", int staro = 0)
        :SaksiskoCveke (ime, cena, familija){
        this -> staro = staro;
        }
    
    int presmetajCena(){
        if (staro < 10){
        return cena + 20;
        }
        else if (staro > 10&&staro < 35){
        return cena + 10;
        }
        return cena;
    }
    
    ~BezCvet(){
    }
};

class SoCvet : public SaksiskoCveke {
private:
    int cvetovi;
public:
    SoCvet (const char *ime=" ", int cena=0, const char *familija=" ", int cvetovi =0)
        :SaksiskoCveke(ime, cena, familija){
        this -> cvetovi = cvetovi;
        }
    
    int presmetajCena(){
    return cena + cvetovi;
    }
    
    ~SoCvet(){
    }
};

void pecatiMaxCena(SaksiskoCveke **s, int elementi, SaksiskoCveke& c){
int maks = 0, indeks;
    for (int i = 0; i < elementi; i++){
        if (strcmp (s[i]->getFamilija(), c.getFamilija())==0){
            if (s[i]->getCena() > maks){
            maks = s[i]->getCena();
            indeks = i;
            }
        }
    }
    cout << s[indeks]->getIme() << " " << s[indeks]->getFamilija() << " " << s[indeks] -> presmetajCena() << endl;
}

int main() {

    char ime[10],familija[10];
    int tip,starost,broj,cena;
    int n;
    cin>>n;
    SaksiskoCveke **cvekinja;
    cvekinja=new SaksiskoCveke*[n];

    for (int i=0; i<n; i++) {

        cin>>tip>>ime>>cena>>familija;
        if (tip==1) {
            cin>>starost;
            cvekinja[i]=new BezCvet(ime,cena,familija,starost);

        } else {
            cin>>broj;
            cvekinja[i]=new SoCvet(ime,cena,familija,broj);
        }


    }

    BezCvet nov("opuntia",90,"cactus",10);
    pecatiMaxCena(cvekinja,n,nov);

    for (int i=0; i<n; i++) delete cvekinja[i];
    delete [] cvekinja;
    return 0;
}

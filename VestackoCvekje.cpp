#include<iostream>
#include<cstring>
using namespace std;

class VestackoCveke{
protected:
    char ime[50];
    int osCena;
    char boja[50];
    
public:
    VestackoCveke(){
    }
    
    VestackoCveke(char *i, int c, char *b){
        strcpy(ime, i);
        osCena = c;
        strcpy (boja, b);
    }
    
    ~VestackoCveke(){
    }
    
    virtual float vratiCena()=0;
    
    char *getBoja(){
    return boja;
    }
    
    char *getIme(){
    return ime;
    }
};

class SoSaksija : public VestackoCveke {
private:
    float masa;
public:
    SoSaksija(char *i, int c, char *b, float m) : VestackoCveke(i,c,b){
    masa = m;
    }
    
    ~SoSaksija(){
    }
    
    float vratiCena(){
    float pom;
        pom = (masa/100)*30;
        return osCena + pom;
    }
};

class BezSaksija : public VestackoCveke {
private:
    bool cvetovi;
public:
    BezSaksija (char *i, int c, char *b, bool cv) : VestackoCveke (i,c,b){
cvetovi = cv;
    }
    
    ~BezSaksija(){
    }
    
    float vratiCena(){
    if (cvetovi == true)
        return osCena + 50;
    else return osCena;
    }
};

void pecatiMinCena(VestackoCveke **niza, int n, VestackoCveke& v){

int indeks;
    for (int i=0; i<n; i++){
        float min=niza[0]->vratiCena();
        if (strcmp (niza[i]->getBoja(), v.getBoja())!=0){
            if (niza[i]->vratiCena() < min){
            indeks = i;
            }
        }
    }
    cout<<niza[indeks]->getIme() << " " << niza[indeks]->getBoja() << " " << niza[indeks]->vratiCena()<<endl;
}

int main(){

char ime[20],boja[10];
int tip,cena;
float masa;
bool cvet;
int n;
cin>>n;
VestackoCveke  **cvekinja;
cvekinja=new VestackoCveke *[n];

for (int i=0;i<n;i++){

    cin>>tip>>ime>>cena>>boja;
    if (tip==1) {
        cin>>masa;
        cvekinja[i]=new SoSaksija(ime,cena,boja,masa);

    }
    else {
        cin>>cvet;
        cvekinja[i]=new BezSaksija(ime,cena,boja,cvet);
    }


}

SoSaksija novo("ljubicici",45,"crvena",10.5);
pecatiMinCena(cvekinja,n,novo);

for (int i=0;i<n;i++) delete cvekinja[i];
delete [] cvekinja;
return 0;
}

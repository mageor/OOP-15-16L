#include<iostream>
#include<cstring>
using namespace std;

class Clen {

    private:
    char ime[50];
    char prezime [50];
    int stepen;
    
    public:
    Clen (){
    }
    
    Clen (char *ime, char *prezime, int stepen){
    strcpy(this->ime,ime);
        strcpy(this->prezime,prezime);
        this->stepen=stepen;
    }
    
    Clen& operator ++ (){
    stepen++;
        return *this;
    }
    
    Clen& operator ++(int){
    stepen++;
        return *this;
    }
    
    friend ostream& operator << (ostream &o, Clen &c){
    o<<c.ime<<" "<<c.prezime<<", "<<c.stepen;
        return o;
    }
    
    bool operator != (Clen& c){
    return stepen != c.stepen;
    }
    
    int getStepen(){
    return stepen;
    }
    
    ~Clen(){
    }
    
};

class Klub {
private:
    char ime[100];
    Clen *clenovi;
    int broj;
    
    public:
    Klub (){
    }
    
    Klub (const char *ime="", Clen *clenovi=NULL, int broj=0){
    strcpy(this->ime,ime);
        this->clenovi=new Clen [broj];
        this->broj=broj;
        for (int i=0; i<broj; i++){
        this -> clenovi[i]=clenovi[i];
        }
    }
    
    Klub (const Klub& k){
    strcpy (this->ime,k.ime);
        this->clenovi= new Clen[k.broj];
        this->broj=k.broj;
        for (int i=0; i<broj; i++){
        this->clenovi[i]=k.clenovi[i];
        }
    }
    ~Klub (){
    delete[]clenovi;
    }
    
    Klub& operator = (const Klub& k){
        if (this != &k){
        strcpy (this->ime, k.ime);
            delete [] clenovi;
            clenovi = new Clen [k.broj];
            this->broj=k.broj;
            for (int i=0; i<broj; i++){
            this -> clenovi[i]=k.clenovi[i];
            }
        }
        return *this;
    }
    
    Klub& operator += (const Clen& c){
    Clen *tmp=new Clen [broj+1];
        for (int i=0; i<broj;i++){
        tmp[i]=clenovi[i];
        }
        tmp[broj]=c;
        broj++;
        delete[]clenovi;
        clenovi=tmp;
        return *this;
    }
    
    friend ostream &operator << (ostream& o, Klub& k){
    o<<k.ime<<endl;
        for (int i=0;i<k.broj;i++){
        o<<k.clenovi[i]<<endl;
        }
        return o;
    }
    
   Klub novKlub(Clen &c){
    Klub newKlub(ime);
    for(int i=0;i<broj;i++){
        if(!(clenovi[i]!=c)){
            newKlub+=clenovi[i]++;
           
        }
    }
    return newKlub;
}
    
};

int main()
{
    Clen clen;
    int n, stepen;
    char ime[30], prezime[30];
	cin >> ime >> n;
    Klub k1(ime); 
    for(int i = 0; i < n; i++){
    	cin >> ime >> prezime >> stepen;
        Clen c(ime, prezime, stepen);
        k1 += c;
        clen = c; 
    }  
    Klub k2 = k1.novKlub(clen);
    cout << k2;
	return 0;
}

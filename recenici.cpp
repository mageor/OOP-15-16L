#include <iostream>
#include <cstring>
using namespace std;

// vashiot kod ovde

class Zbor{
 
private:
    char *znaci;
    int size;
public:
    Zbor(const char *znaci="NEDEFINIRAN"){
 
         this->znaci = new char[strlen(znaci) + 1];
       
        strcpy(this->znaci, znaci);
    }
   
    ~Zbor(){delete [] znaci;}
    char *getZbor(){
        return znaci;
    }
    Zbor(const Zbor &z){
        znaci = new char[strlen(z.znaci) + 1];
        strcpy(this->znaci, z.znaci);
    }
    Zbor& operator =(const Zbor &z){
        if(this != &z)
        {
            delete [] znaci;
            znaci = new char[strlen(z.znaci) + 1];
            strcpy(this->znaci, z.znaci);
        }
        return *this;
    }
};
 
class Rechenica{
   
private:
    Zbor *zborovi;
    int brZborovi;
    int size;
public:
    Rechenica (int size){
        this->size = size;
        zborovi = new Zbor[size];
        brZborovi = 0;
    }
    ~Rechenica () { delete []  zborovi; }
    Rechenica () {
        this->size = 10;
        zborovi = new Zbor[size];
        brZborovi = 0;
    }
    Rechenica (Rechenica &r){
        this->size = r.size;
        zborovi = new Zbor[r.size];
        for(int i=0;i<r.brZborovi;i++)
            this->zborovi[i] = r.zborovi[i];
        brZborovi = r.brZborovi;
    }
    void dodadi(Zbor z){
       
        if(brZborovi < size){
            zborovi[brZborovi] = z;
            brZborovi ++ ;
        }
        else{
           
            Zbor *tmp = new Zbor[size + 10];
            for(int i=0;i<brZborovi;i++){
                tmp[i] = zborovi[i];
            }
            tmp[brZborovi] = z;
            brZborovi++;
            size = size + 10;
            delete  [] zborovi;
            zborovi = tmp;
           
        }
       
    }
    Rechenica& operator = (Rechenica &r){
        if(this != &r){
        this->size = r.size;
        zborovi = new Zbor[r.size];
        for(int i=0;i<r.brZborovi;i++)
            this->zborovi[i] = r.zborovi[i];
        brZborovi = r.brZborovi;
        }
        return *this;
    }
    void pecati(){
       
        for (int i=0; i<brZborovi; i++) {
            cout<<zborovi[i].getZbor()<<" " ;
        }
        cout << endl;
       
    }
    void zameni(int i, int j){
       
        Zbor pom (zborovi[i]);
        zborovi[i] = zborovi[j];
        zborovi[j] = pom;
    }
   
};

int main() {
    int n;
    cin >> n;
    cin.get();
    cout << "CONSTRUCTOR" << endl;
    Rechenica r;
    cout << "DODADI ZBOR" << endl;
    for (int i = 0; i < n; ++i) {
        char z[100];
        cin.getline(z, 100);
        Zbor zbor(z);
        r.dodadi(zbor);
    }
    cout << "PECATI RECHENICA" << endl;
    r.pecati();
    cout << "COPY" << endl;
    Rechenica x = r;
    cout << "ZAMENI" << endl;
    x.zameni(n / 2, n / 3);
    x.pecati();
    cout << "ORIGINAL" << endl;
    r.pecati();
    return 0;
}

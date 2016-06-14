#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

class Nedviznost{
protected:
    char adresa[100];
    char grad[100];
    float kvadratura;
public:
    Nedviznost(){}
    Nedviznost(char *adresa,char *grad,float kvadratura){
        strcpy(this->adresa,adresa);
        strcpy(this->grad,grad);
        this->kvadratura=kvadratura;
    }
 
    Nedviznost(Nedviznost &n){
        strcpy(adresa,n.adresa);
        strcpy(grad,n.grad);
        kvadratura=n.kvadratura;
    }
 
    friend ostream& operator <<(ostream &out,Nedviznost &r){
        out <<"Adresa: " << r.adresa<<endl;
        out <<"Grad: "<< r.grad<<endl;
        out <<r.kvadratura<<" kvadrati"<<endl;
        out <<"Cena: "<<r.totalcena()<<endl;
        return out;
    }
 
    bool operator < (Nedviznost &n){
        return totalcena() > n.totalcena();
    }
    virtual float totalcena()=0;
};
 
class Kukja:public Nedviznost{
private:
    int brkat;
    float kvkat;
    bool poveke;
public:
    Kukja(char* adresa,char *grad,float kvadratura,int brkat,float kvkat,bool poveke):Nedviznost(adresa,grad,kvadratura){
        this->brkat=brkat;
        this->kvkat=kvkat;
        this->poveke=poveke;
    }
    float totalcena(){
        float potkrov=0;
        if(poveke==true)
            float potkrov=kvkat*450;
        return (brkat*(kvkat*700))+((kvadratura - kvkat)*200)+potkrov;
    }
};
 
class Zgrada:public Nedviznost{
private:
    float kvstan;
    int brstanovi;
public:
    Zgrada(char *adresa,char *grad,float kvadratura,int brstanovi,float kvstan):Nedviznost(adresa,grad,kvadratura){
        this->kvstan=kvstan;
        this->brstanovi=brstanovi;
    }
    float totalcena(){
                return ((kvstan*800)*brstanovi)+(brstanovi*500);
    }
};
 
class Stovariste:public Nedviznost{
private:
    float kvs;
    bool kancelarija;
public:
    Stovariste(char *adresa,char *grad,float kvadratura,float kvs,bool kancelarija):Nedviznost(adresa,grad,kvadratura){
        this->kvs=kvs;
        this->kancelarija=kancelarija;
    }
    float totalcena(){
        float plus=1.00;
        if(kancelarija==true){
                plus = 1.10;
        }
        return kvs*250+(kvadratura-kvs)*100;
    }
};
 
Nedviznost &najskap_imot(Nedviznost **ned, int n){
    Nedviznost *max = ned[0];
    for(int i = 1; i < n; i++)
    if (ned[i] > max)
        max = ned[i];
        return *max;
}
int main() {
    int n; // Broj na nedviznosti

    int tip_nedviznost; // Tip na nedviznost (1-kukja, 2-zgrada, 3-stovariste)

    cin >> n;

    Nedviznost **ned = new Nedviznost*[n];
    char adresa[100];
    char grad[30] ;
    float kvadratura;
    for(int i = 0; i < n; ++i) {
        cin >> tip_nedviznost>> adresa >> grad >> kvadratura;
        if(tip_nedviznost==1) {
            int br_kat;
            float kvadrat_kat;
            bool potkrovje;
            cin >> br_kat >> kvadrat_kat >> potkrovje;
            ned[i] = new Kukja(adresa, grad, kvadratura, br_kat, kvadrat_kat, potkrovje);
        }
        else if(tip_nedviznost == 2) {
            int br_stanovi;
            float kvadrat_na_stan;
            cin >> br_stanovi >> kvadrat_na_stan;

            ned[i] = new Zgrada(adresa, grad, kvadratura, br_stanovi, kvadrat_na_stan);
        }
        else if(tip_nedviznost == 3){
            float kvadrati_pokrien_del;
            bool kancelarija;
            cin >>kvadrati_pokrien_del >> kancelarija;

            ned[i]= new Stovariste(adresa, grad, kvadratura, kvadrati_pokrien_del,kancelarija);
        }
    }

    cout<<"== IMOTI =="<<endl;
    for (int i=0; i<n; i++){
    	cout<<*(ned[i])<<endl;
    }

    cout << "=== NAJSKAP IMOT ===" << endl;
    cout << najskap_imot(ned, n);

    return 0;
}

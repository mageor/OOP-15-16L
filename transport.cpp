#include <iostream>
#include <cstring>
using namespace std;

class Transport{
public:
    char destinacija[40];
    int cena;
    int rastojanie;
public:
    Transport (char *des=NULL, int c=0, int r=0){
    strcpy(destinacija, des);
    cena=c;
    rastojanie=r;
    }
    
    char *getDestinacija(){
    return destinacija;
    }
    
    int getCena(){
    return cena;
    }
    
    int getRastojanie(){
    return rastojanie;
    }
    
    ~Transport(){
    }
    
    virtual int cenaTransport () = 0;
    
    bool operator < (Transport& t){
    return rastojanie < t.rastojanie;
    }
};

class AvtomobilTransport : public Transport {
private:
    bool sofer;
public:
    AvtomobilTransport (char *des=NULL, int c=0, int r=0, bool s=true) : Transport(des, c, r){
    sofer=s;
    }
    
    int cenaTransport(){
        if (sofer == true){
        return getCena() * 1.20;
        }
        else return getCena();
    }
};

class KombeTransport : public Transport {
private:
    int lugje;
public:
    KombeTransport (char *des=NULL, int c=0, int r=0, int l=0) : Transport (des, c, r){
    lugje = l;
    }
    
    int cenaTransport () {
    return (getCena()-(lugje * 200));
    }
};

void pecatiPoloshiPonudi (Transport **ponudi, int n, Transport &t){
Transport *temp[100];
    Transport *tp[100];
    int k=0;
    for (int i=0; i<n; i++){
        if (t.cenaTransport() < ponudi[i] -> cenaTransport()){
        temp[k] = ponudi[i];
            k++;
        }
    }
    
    for (int i=0; i<k; i++){
        for (int j=0; j<i; j++){
            if (*temp[j+1] < *temp[j]){
            tp[j] = temp[j];
                temp[j] = temp[j+1];
                temp[j+1] = tp[j];
            }
        } 
    }
    for (int i=0; i<k; i++){
    cout<<temp[i]->getDestinacija()<<' '<<temp[i]->getRastojanie()<<' '<<temp[i]->cenaTransport()<<endl;
    }
}

int main(){

char destinacija[20];
int tip,cena,rastojanie,lugje;
bool shofer;
int n;
cin>>n;
Transport  **ponudi;
ponudi=new Transport *[n];

for (int i=0;i<n;i++){

    cin>>tip>>destinacija>>cena>>rastojanie;
    if (tip==1) {
        cin>>shofer;
        ponudi[i]=new AvtomobilTransport(destinacija,cena,rastojanie,shofer);

    }
    else {
        cin>>lugje;
        ponudi[i]=new KombeTransport(destinacija,cena,rastojanie,lugje);
    }


}

AvtomobilTransport nov("Ohrid",2000,600,false);
pecatiPoloshiPonudi(ponudi,n,nov);

for (int i=0;i<n;i++) delete ponudi[i];
delete [] ponudi;
return 0;
}

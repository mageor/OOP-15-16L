#include<iostream>
#include<string.h>
using namespace std;

//ова е место за вашиот код

//ова е место за вашиот код
class Zichara{
        char *mesto;
        int cenaDnevna;
    public:
    Zichara(char *mesto="",int c=0){
        this->mesto=new char[strlen(mesto)+1];
        cenaDnevna=c;
    }
    ~Zichara(){
        delete[]mesto;
    }
    Zichara(const Zichara &z){
        mesto=new char[strlen(z.mesto)+1];
        strcpy(mesto,z.mesto);
        cenaDnevna=z.cenaDnevna;
    }
    Zichara& operator=(Zichara &z){
        if(this!=&z){
                delete[]mesto;
            mesto=new char[strlen(z.mesto)+1];
            mesto=z.mesto;
            cenaDnevna=z.cenaDnevna;
        }
        return *this;
    }
    int getCenaDnevna(){
        return cenaDnevna;
    }
};
class PlaninarskiDom{
        static char ime[15];
        int cenaSezona[2];
        char klasa;
        bool zicara;
        Zichara *z;
        public:
    PlaninarskiDom(){
        static const char *ime="";
        int *cenaSezona=0;
        bool zicara=false;
        Zichara *z=0;
    }
    PlaninarskiDom(const char *i,int *c,char k){
        strcpy(ime,i);
        for(int i=0;i<2;i++){
                cenaSezona[i]=c[i];
        }
        klasa=k;      
    }
    ~PlaninarskiDom(){}
    PlaninarskiDom(const PlaninarskiDom &p){
        strcpy(ime,p.ime);
        for(int i=0;i<2;i++){
                cenaSezona[i]=p.cenaSezona[i];
        }
        klasa=p.klasa;
        zicara=p.zicara;
        z=p.z;
    }
    PlaninarskiDom &operator=(const PlaninarskiDom &p){
        if(this!=&p){
                strcpy(ime,p.ime);
            for(int i=0;i<2;i++){
                cenaSezona[i]=p.cenaSezona[i];
        }
        klasa=p.klasa;
        zicara=p.zicara;
        z=p.z;
        }
        return *this;
    }
    PlaninarskiDom &operator--(){
        if(klasa<'D'){
                klasa++;
                return *this;
        }
        return *this;
    }
    friend ostream &operator<<(ostream &o,PlaninarskiDom &p){
        if(p.zicara)
            o<<p.ime<<" klasa:"<<p.klasa<<" so Zichara"<<endl;
        else
            o<<p.ime<<" klasa:"<<p.klasa<<endl;
        return o;
    }
    bool operator<=(char c){
        if(klasa>=c)
            return true;
        return false;
    }
    void setZichara(Zichara z){
        this->z=&z;
        zicara=true;
        klasa++;
    }
    void presmetajDnevenPrestoj(int den,int mesec,int &cena){
        try{
                if(!(den>=1&&den<=31)||!(mesec>=1&&mesec<=12))
                throw 1;
                    if(mesec>=4&&mesec<=8){
                        if(zicara)
                            cena=cenaSezona[0]+z->getCenaDnevna();
                        else
                            cena=cenaSezona[0];
                   
                    }
                    else{
                        if(zicara)
                            cena=cenaSezona[1]+z->getCenaDnevna();
                        else
                            cena=cenaSezona[1];
                        }
        }
        catch(int){
                throw;
        }
    }
};
char PlaninarskiDom::ime[15]="";
int main(){

   PlaninarskiDom p; //креирање на нов објект од класата планинарски дом

   //во следниот дел се вчитуваат информации за планинарскиот дом
   char imePlaninarskiDom[15],mestoZichara[30],klasa;
   int ceni[12];
   int dnevnakartaZichara;
   bool daliZichara;
   cin>>imePlaninarskiDom;
   for (int i=0;i<2;i++) cin>>ceni[i];
   cin>>klasa;
   cin>>daliZichara;

   //во следниот дел се внесуваат информации и за жичарата ако постои
   if (daliZichara) {
      cin>>mestoZichara>>dnevnakartaZichara;
      PlaninarskiDom pom(imePlaninarskiDom,ceni,klasa);
      Zichara r(mestoZichara,dnevnakartaZichara);
      pom.setZichara(r);
      p=pom;
   }
   else{
      PlaninarskiDom *pok=new PlaninarskiDom(imePlaninarskiDom,ceni,klasa);
      p=*pok;
   }

   //се намалува класата на планинарскиот дом за 2
   --p;
   --p;

   int cena;
   int den,mesec;
   cin>>den>>mesec;
   try{
   p.presmetajDnevenPrestoj(den,mesec,cena); //тука се користи функцијата presmetajDnevenPrestoj
   cout<<"Informacii za PlaninarskiDomot:"<<endl;
   cout<<p;
   if (p<='D') 
       cout<<"Planinarskiot dom za koj se vneseni informaciite ima klasa poniska ili ista so D\n";
       
   cout<<"Cenata za "<<den<<"."<<mesec<<" e "<<cena; //се печати цената за дадениот ден и месец
   }
   catch (int){
      cout<<"Mesecot ili denot e greshno vnesen!";
   }
}

#include <iostream>
#include <cstring>
 
using namespace std;
 
//Vasiot kod tuka
class Pica{
private:
    char ime[15];
    int cena;
    char *sostojki;
    int popust;
public:
    Pica(){}
    Pica(char *ime,int cena,char *sostojki,int popust){
   this->sostojki=new char[strlen(sostojki)+1];
    strcpy(this->ime,ime);
    this->cena=cena;
         strcpy(this->sostojki,sostojki);
       
        this->popust=popust;
        
    }
    Pica(const Pica &p){
    sostojki=new char[strlen(p.sostojki)+1];
    strcpy(ime,p.ime);
    cena=p.cena;
         strcpy(sostojki,p.sostojki);
      popust=p.popust;
        
    }
    Pica& operator= (const Pica &p) 
{
if(this!=&p)
{
delete[] sostojki;
strcpy(ime,p.ime);
cena=p.cena;
sostojki=new char [strlen(p.sostojki)+1];
strcpy(sostojki,p.sostojki);
popust=p.popust;
}
return *this;
}
    ~Pica(){
    delete[] sostojki;}

    
    void pecati(){
    cout<<ime<<" - "<<sostojki<<", "<<cena<<" "<<cena-cena*popust/100<<endl;
    }
    
    bool istiSe(Pica p){
    if(strcmp(sostojki,p.sostojki)==0)
        return true;
        else return false;
    }
    int vratipopust(){
    return popust;
   }
    char* vratisostojki(){
    return sostojki;
    }
};
    
class Picerija {
private:
    char ime[15];
    Pica *pica;
    int broj;
    public:
    Picerija(){}
    Picerija(char *ime){
        broj=0;
    pica=new Pica[0];
   strcpy(this->ime,ime);
    }
    Picerija(const Picerija &p){
        broj=p.broj;
    pica=new Pica[p.broj];
   strcpy(ime,p.ime);
        for(int i=0;i<p.broj;i++){
        pica[i]=p.pica[i];
        }
    }
   void dodadi(Pica p){
        for(int i=0;i<broj;i++){
            if(strcmp(p.vratisostojki(),pica[i].vratisostojki())==0){
                
                return;
            }
        }
       
       
         Pica *tmp=new Pica[broj+1];  
        for(int i=0;i<broj;i++){
         tmp[i]=pica[i];
        }
        delete[] pica;
         tmp[broj]=p;
        broj++;
        pica=tmp;
   }
    
    void piciNaPromocija(){for(int i=0;i<broj;i++){
        if(pica[i].vratipopust()>0&&pica[i].vratipopust()<100){
        pica[i].pecati();
        
        }}
    
    }

    void setIme(char *ime){
    strcpy(this->ime,ime);
    }
    char *getIme(){
    return ime;
    }
    ~Picerija(){
    delete [] pica;
    }
};

int main () {

    int n;
    char ime[15];
    cin >> ime;
    cin >> n;

    Picerija p1(ime);
    for(int i = 0; i < n; i++){
        char imp[100];
        cin.get();
        cin.getline(imp,100);
        int cena;
        cin >> cena;
        char sostojki[100];
        cin.get();
        cin.getline(sostojki,100);
        int popust;
        cin >> popust;
        Pica p(imp,cena,sostojki,popust);
        p1.dodadi(p);
    }

    Picerija p2 = p1;
    cin >> ime;
    p2.setIme(ime);
    char imp[100];
    cin.get();
    cin.getline(imp,100);
    int cena;
    cin >> cena;
    char sostojki[100];
    cin.get();
    cin.getline(sostojki,100);
    int popust;
    cin >> popust;
    Pica p(imp,cena,sostojki,popust);
    p2.dodadi(p);

    cout<<p1.getIme()<<endl;
    cout<<"Pici na promocija:"<<endl;
    p1.piciNaPromocija();

    cout<<p2.getIme()<<endl;
    cout<<"Pici na promocija:"<<endl;
    p2.piciNaPromocija();

	return 0;
}

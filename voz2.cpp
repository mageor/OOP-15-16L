#include<iostream>
#include<cstring>
using namespace std;

class Patnik{
 
public:
    char ime[100];
    int klasavagon;
    bool velosiped;
   
 
    Patnik (){}
   
    Patnik (char *ime, int klasavagon, bool velosiped){
    strcpy (this ->ime,ime);
        this->klasavagon=klasavagon;
        this ->velosiped=velosiped;
        }
    Patnik (const Patnik &p){
     strcpy (this ->ime,p.ime);
        this->klasavagon=p.klasavagon;
        this ->velosiped=p.velosiped;
   
   
    }
     Patnik & operator=(const Patnik &p){
         if (this!=&p){
         strcpy (this ->ime,p.ime);
        this->klasavagon=p.klasavagon;
        this ->velosiped=p.velosiped;
         }
    return *this;
    }
    friend ostream & operator <<(ostream &out,const Patnik &p){
    return out<<p.ime<<"\n"<<p.klasavagon<<"\n"<<p.velosiped<<endl;
    return out ;
    }
    ~Patnik (){}
};
 
class Voz{
 
private:
    char destinacija[100];
    Patnik *patnik;
    int brElementi;
    int dzVelosipedi;
 
public:
 
        Voz(char *destinacija="" , int dzVelosipedi =0,Patnik *patnik=0 , int brElementi=0 ){
        strcpy(this->destinacija,destinacija);
        this->brElementi=brElementi;
        this->dzVelosipedi=dzVelosipedi;
 
        this->patnik = new Patnik[brElementi];
       for(int i = 0 ; i < brElementi ; i++){
           this->patnik[i]=patnik[i];
       }
        }
 
        Voz & operator = (const Voz &vz ){
     if(this!=&vz){
            delete [] patnik;
        strcpy(this->destinacija,vz.destinacija);
        this->brElementi=vz.brElementi;
        this->dzVelosipedi=vz.dzVelosipedi;
 
 
            for(int i = 0 ; i < brElementi ; i++){
                this->patnik[i]=vz.patnik[i];
            }
            this->patnik = new Patnik[brElementi];
        }
        return *this;
        }
 
        Voz &operator +=(Patnik pt){
 
        Patnik *tmp = new Patnik[brElementi+1];
 
            if((dzVelosipedi<=0&&!(pt.velosiped)) || dzVelosipedi!=0 ){
                  for(int i = 0 ; i < brElementi ; i++)
                        tmp[i]=patnik[i];
               
            tmp[brElementi++] = pt;
            delete[]patnik;
            patnik=tmp;
            return *this;
           
             }
 
        return *this;
    }
   
 
        friend ostream & operator <<(ostream &out , Voz &voz){
        out<<voz.destinacija<<"\n";
        for(int i = 0 ; i < voz.brElementi ; i++){
            out<<voz.patnik[i]<<endl;
        }
 
        return out;
        }
 
 void patniciNemaMesto()
    {
        int brPrva=0;  
        int brVtora=0;  
        int kvota=0;    
 
        for(int i=0 ; i< brElementi;i++){
            if(patnik[i].klasavagon==1&&patnik[i].velosiped){
                kvota++;
            }
        }
        if(kvota>=dzVelosipedi){
            brPrva=kvota-dzVelosipedi;
            kvota=dzVelosipedi;
        }
 
        for(int i =0; i< brElementi;i++){
            if(patnik[i].klasavagon==2&&patnik[i].velosiped){
                kvota++;
            }
        }
        if(kvota>=dzVelosipedi)
            brVtora=kvota-dzVelosipedi;
 
        cout << "Brojot na patnici od 1-va klasa koi ostanale bez mesto e: "<<brPrva<<endl;
        cout << "Brojot na patnici od 2-ra klasa koi ostanale bez mesto e: "<<brVtora;
    }
   
};
int main()
{
	Patnik p;
	char ime[100], destinacija[100];
	int n;
	bool velosiped;
	int klasa;
	int maxv;
	cin >> destinacija >> maxv;
	cin >> n;
	Voz v(destinacija, maxv);
	//cout<<v<<endl;
	for (int i = 0; i < n; i++){
		cin >> ime >> klasa >> velosiped;
		Patnik p(ime, klasa, velosiped);
		//cout<<p<<endl;
		v += p;
	}
	cout << v;
	v.patniciNemaMesto();

	return 0;
}

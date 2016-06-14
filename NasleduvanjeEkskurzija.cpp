#include<iostream>
#include<cstring>
using namespace std;

class Ekskurzija {
private:
    char ime[50];
    int prevoz;
    int mesec;
    int vreme;
    double cenaDen;
    int patnici;
public:
    void copy(const Ekskurzija &e){
    strcpy (ime, e.ime);
        prevoz = e.prevoz;
        mesec = e.mesec;
        vreme = e.vreme;
        cenaDen = e.cenaDen;
        patnici = e.patnici;
    }
    
    Ekskurzija (const char *i=" ",int p=0, int m=0, int v=0, double c=0, int pa=0){
    strcpy (ime, i);
        prevoz = p;
        mesec = m;
        vreme = v;
        cenaDen = c;
        patnici = pa;
    }
    
    ~Ekskurzija(){
    }
 
    int getPrevoz(){
    return prevoz;
    }
    
    int getMesec(){
    return mesec;
    }
    
    double getCena(){
    return cenaDen;
    }
    
    int getPatnici(){
    return patnici;
    }
    
    int getVreme(){
    return vreme;
    }
    
    Ekskurzija& operator = (Ekskurzija& e){
        if (this != &e){
        copy(e);
        }
        return *this;
    }
    
    Ekskurzija (const Ekskurzija& e){
    copy(e);
    }
};


class TuristichkaAgencija {
protected:
    char ime[50];
    Ekskurzija eks[5];
    int broj;
public:
    TuristichkaAgencija(){
        strcpy(ime, " ");
        broj =0;
    }
    
    TuristichkaAgencija(const char *i, Ekskurzija e[], int b){
        strcpy (ime, i);
        broj = b;
        for (int i=0; i<broj; i++){
        eks[i] = e[i];
        }
    }
    
    virtual double vkupnaDobivka () = 0;
    virtual ~TuristichkaAgencija(){}
};

class TradicionalnaTuristichkaAgencija : public TuristichkaAgencija{
public:
    TradicionalnaTuristichkaAgencija() : TuristichkaAgencija(){}
    TradicionalnaTuristichkaAgencija(const char *i, Ekskurzija e[], int b):
    TuristichkaAgencija(i,e,b){}
    
    double vkupnaDobivka(){
    double c=0;
        for (int i=0; i<broj; i++){
            if (eks[i].getMesec() > 5&&eks[i].getMesec() < 9){
            c += eks[i].getVreme() * eks[i].getCena() * eks[i].getPatnici() + 30 * 1.8;
            }
            else c += eks[i].getVreme() * eks[i].getCena() * eks[i].getPatnici() + 30 * 1.3;
        }
        return c;
    }
};

class OnlineTuristichkaAgencija : public TuristichkaAgencija{
public:
    OnlineTuristichkaAgencija() : TuristichkaAgencija(){}
    OnlineTuristichkaAgencija(const char *i, Ekskurzija e[], int b):
    TuristichkaAgencija(i,e,b){}
    
   double vkupnaDobivka() {
        double k=0;
        for(int i=0; i<broj; i++) {
            if(eks[i].getMesec()<6||eks[i].getMesec()>8) {
                if(eks[i].getPrevoz())
                    k+=(eks[i].getVreme() * eks[i].getPatnici() * eks[i].getCena() + 20*2.2);
                else
                    k+=(eks[i].getVreme() * eks[i].getPatnici() * eks[i].getCena() + 20*1.8);
            } else {
                k+=(eks[i].getVreme() * eks[i].getPatnici() * eks[i].getCena() + 20*2.5);
            }
        }
        return k;
    }
};


int main ()
{
    
    	char agency[50];
    	double freq;
    	int numOnlineE, numTradE;
    	Ekskurzija online[5];
    	Ekskurzija traditional[5];
    	cin >> numOnlineE >> numTradE;
    	for(int i = 0; i < numOnlineE; i++){
    		char name[50];
            int vehicle, month, duration, price, tourists;
        	cin >> name >> vehicle >> month >> duration >> price >> tourists;
       		Ekskurzija e(name, vehicle, month, duration, price, tourists);
       		online[i] = e;      
    	}
    	cin >> agency;
		OnlineTuristichkaAgencija onlineAgency(agency, online, numOnlineE);
		for(int i = 0; i < numTradE; i++){
    		char name[50];
        	int vehicle, month, duration, price, tourists;
        	cin >> name >> vehicle >> month >> duration >> price >> tourists;
       		Ekskurzija e(name, vehicle, month, duration, price, tourists);
       		traditional[i] = e;
    	}
    	cin >> agency;
		TradicionalnaTuristichkaAgencija traditionalAgency(agency, traditional, numTradE);
		cout << onlineAgency.vkupnaDobivka() << endl;
    	cout << traditionalAgency.vkupnaDobivka() << endl;
    
    return 0;
}

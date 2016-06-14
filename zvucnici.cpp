#include <iostream>
#include <cstring>
using namespace std;


// vashiot kod ovde

// zabraneto e menuvanje na main funkcijata

class Speaker {
public:
    float moknost;
    char model[100];
    bool daliImaPojacalo;
    float osnovnaCena;
    static int DDV;
 
    Speaker() {}
    Speaker(float m, char *model, bool pojacalo, float c) {
        moknost=m;
        strcpy(this->model,model);
        daliImaPojacalo=pojacalo;
        osnovnaCena=c;
    }
    Speaker(const Speaker &s) {
        moknost=s.moknost;
        strcpy(model,s.model);
        daliImaPojacalo=s.daliImaPojacalo;
        osnovnaCena=s.osnovnaCena;
    }
    void setModel(char *model) {
        strcpy(this->model,model);
    }
    char *getModel() {
        return model;
    }
 
 
    friend ostream &operator <<(ostream &o, Speaker &s) {
        o<<s.model;
        if(s.daliImaPojacalo)
            o<< " ima pojachalo ";
        else o<< " nema pojachalo ";
 
        o<<s.presmetajCena();
        return o;
 
    }
    virtual float presmetajCena()=0;
    bool operator >(Speaker &s1) {
        if(presmetajCena()>s1.presmetajCena())
            return true;
        else return false;
 
    }
 
    static int getDDV() {
        return DDV;
    }
 
 
    static void smeniDDV(int ddv) {
        DDV=ddv;
    }
 
    static void vkupnoDDV(Speaker** s, int n) {
        float VkupnaCena=0;
        float ddv=0;
        for(int i=0; i<n; i++)
 
            VkupnaCena += s[i]->presmetajCena();
        for(int d=0; d<n; d++)
            ddv += s[d]->presmetajCena()*s[d]->getDDV()/100.0;
 
        cout<<"Vkupna cena: "<<VkupnaCena<<endl;
        cout<<"Vkupno DDV: "<<ddv<<endl;
    }
    virtual ~Speaker() {}
};
int Speaker::DDV=18;
 
class TowerSpeaker: public Speaker {
public:
    bool fullSemi;
 
 
    TowerSpeaker(float m, char *model, bool pojacalo, float c,bool f):Speaker(m,model,pojacalo,c) {
        this->fullSemi=f;
 
 
    }
 
 
    float presmetajCena() {
        float cena = osnovnaCena;
 
        if (daliImaPojacalo)
            cena += osnovnaCena * 0.10;
 
        if (fullSemi)
            cena += osnovnaCena * 0.05;
 
        return cena;
    }
 
 
};
class MonitorSpeaker: public Speaker {
public:
    bool studioDruga;
 
 
 
    MonitorSpeaker(float m, char *model, bool pojacalo, float c,bool studioDruga):Speaker(m,model,pojacalo,c) {
        this->studioDruga=studioDruga;
    }
    float presmetajCena() {
        float cena = osnovnaCena;
 
        if (daliImaPojacalo)
            cena += osnovnaCena * 0.10;
 
        if (studioDruga)
            cena += osnovnaCena * 0.15;
 
        return cena;
    }
 
 
 
};
 
 
 
 
void lowestPrice(Speaker **s,int n) {
    int min=9999;
    int index;
    int i;
    for(i=0; i<n; i++) {
        if(s[i]->presmetajCena()< min) {
            min = s[i]->presmetajCena();
            index=i;
        }
    }
 
 
    cout<< s[index]->model <<" nema pojachalo "<<min<< endl;
 
}

int main() {
    int testCase;
    cin >> testCase;
    float power;
    char model[100];
    bool amp;
    float price;
    bool fullSemi;
    if(testCase == 1) {
        cout << "===== TESTING CONSTRUCTORS ======" << endl;
        cin >> power;
        cin >> model;
        cin >> amp;
        cin >> price;
        cin >> fullSemi;
        TowerSpeaker ts(power, model, amp, price, fullSemi);
        cout << ts << endl;
        cin >> power;
        cin >> model;
        cin >> amp;
        cin >> price;
        cin >> fullSemi;
        MonitorSpeaker ms(power, model, amp, price, fullSemi);
        cout << ms << endl;
        
    } else if(testCase == 2) {
        cout << "===== TESTING LOWEST PRICE ======" << endl;
        int n;
        cin >> n;
        Speaker** speakers = new Speaker*[n];
        for(int i = 0; i < n; ++i) {
        	cin >> power;
        	cin >> model;
        	cin >> amp;
        	cin >> price;
        	cin >> fullSemi;
            if(i % 2 == 1)
        		speakers[i] = new TowerSpeaker(power, model, amp, price, fullSemi);
            else 
                speakers[i] = new MonitorSpeaker(power, model, amp, price, fullSemi);
        }
        
        lowestPrice(speakers, n);
        for(int i = 0; i < n; ++i) {
            delete speakers[i];
        }
        delete [] speakers;
    } else if(testCase == 3) {
        cout << "===== TESTING DDV STATIC ======" << endl;
        int n;
        cin >> n;
        Speaker** speakers = new Speaker*[n];
        for(int i = 0; i < n; ++i) {
        	cin >> power;
        	cin >> model;
        	cin >> amp;
        	cin >> price;
        	cin >> fullSemi;
            if(i % 2 == 1)
        		speakers[i] = new TowerSpeaker(power, model, amp, price, fullSemi);
            else 
                speakers[i] = new MonitorSpeaker(power, model, amp, price, fullSemi);
        }
        Speaker::vkupnoDDV(speakers, n);
        int ddv;
        cin >> ddv;
        Speaker::smeniDDV(ddv);
        Speaker::vkupnoDDV(speakers, n);
        for(int i = 0; i < n; ++i) {
            delete speakers[i];
        }
        delete [] speakers;
    }
    
}

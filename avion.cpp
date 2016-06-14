#include<iostream>
#include<cstring>
using namespace std;

class Patnik{
 
    private:
        bool klasa;
        char Ime[100];
        int tezina;
    public:
    Patnik(){};
    Patnik(char *ime,int tezina,bool klasa)
    {
        strcpy(Ime,ime);
        this->klasa=klasa;
        this->tezina= tezina;
    }
    friend ostream& operator<<(ostream& o,Patnik& x)
    {
      o <<x.Ime <<endl;
              o <<x.klasa<<endl;
 
      o <<x.tezina<<endl;
        return o;
    };
    Patnik (Patnik& x)
    {
        strcpy(this->Ime,x.Ime);
        this->klasa=x.klasa;
        this->tezina= x.tezina;
       
    }
    int get_tezina(){return tezina;}
       
    bool get_klasa(){return klasa;}
};
 
class Avion{
 
    private:
    char destinacija[100];
    int brojelementi=0;
    int mmp;
    int mmpglavno;
    Patnik *p = new Patnik[brojelementi];
       
    public:
    Avion(char *dest,int ma,int mb){strcpy(destinacija,dest);mmp=mb;mmpglavno=ma;}
   
    Avion &operator+=(Patnik& aa)
    {
        Patnik z= aa;
        if(z.get_tezina() <= mmp)
            p[brojelementi++] = z;
        return *this;
    }
    int presmetajVkupnaTezina()
    {
        int i,vkupnatezina=0,brojpatnicci=0;
        for(i=0;i<brojelementi;i++)
        {  
            if(p[i].get_klasa() == true)
            {
                if(vkupnatezina+ p[i].get_tezina() <= mmpglavno)
                vkupnatezina += p[i].get_tezina();
                 else
                {
                    brojpatnicci++;
                }
            }
        }
        for(i=0;i<brojelementi;i++)
        {
            if(p[i].get_klasa() ==false)
            {
                if(vkupnatezina+ p[i].get_tezina() <= mmpglavno)
                vkupnatezina += p[i].get_tezina();
                 else
                {
                    brojpatnicci++;
                }
            }
        }
        return brojpatnicci;
    }
 
   friend ostream& operator<<(ostream& o, Avion& x)
    {
      o <<x.destinacija<<endl;  
      int i;
       for(i=0;i<x.brojelementi;i++)
       {
           o << x.p[i]<< endl;
       }  
     
        return o;
    }
};

int main()
{
    Patnik p;
    char ime[100], destinacija[100];
    int n;
    bool klasa;
    int bagaz;
    int ma, mb;
	cin >> destinacija >> ma >> mb;
    cin >> n;
    Avion a(destinacija, ma, mb);
    //cout<<a<<endl;
    for(int i = 0; i < n; i++){
    	cin >> ime >> bagaz >> klasa;
        Patnik p(ime, bagaz, klasa);
        //cout<<p<<endl;
        a += p;
    }
    cout << a;
    cout << "Brojot na patnici cii bagaz ostanuva e: " << a.presmetajVkupnaTezina() <<endl;
    
	return 0;
}

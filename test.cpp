#include <iostream>
#include <cstring>
#include <stdlib.h>
using namespace std;

//Vasiot kod tuka

class Test
{
private:
    char *imePrezime;
    int index;
    int points[3];
 
public:
    Test(const char *imePrezime = "", int index = 0, int points[3] = NULL)
    {
        this->imePrezime = new char[strlen(imePrezime) + 1];
        strcpy(this->imePrezime, imePrezime);
 
        this->index = index;
 
        if(points!=NULL)
        {
            for(int i=0;i<3;i++)
                this->points[i] = points[i];
        }
    }
 
    Test(const Test &t)
    {
        this->imePrezime = new char[strlen(t.imePrezime) + 1];
        strcpy(this->imePrezime, t.imePrezime);
 
        this->index = t.index;
 
        for(int i=0;i<3;i++)
            this->points[i] = t.points[i];
    }
 
    void pecati()
    {
        cout << this->imePrezime << " ";
        cout << this->index << " ";
 
        for(int i=0;i<2;i++)
        {
            cout << this->points[i] << " ";
        }
 
        cout << this->points[2] << endl;
    }
 
    Test& operator=(const Test &t)
    {
        if(this!=&t)
        {
            delete [] this->imePrezime;
            this->imePrezime = new char[strlen(t.imePrezime) + 1];
            strcpy(this->imePrezime, t.imePrezime);
 
            this->index = t.index;
 
            for(int i=0;i<3;i++)
                this->points[i] = t.points[i];
        }
 
        return *this;
    }
 
    bool polozen()
    {
        if(this->points[0] < 5)
            return false;
 
        if(this->points[1] + this->points[2] < 50)
            return false;
 
        return true;
    }
 
    ~Test()
    {
        delete [] this->imePrezime;
    }
};
 
class PrvKolokvium
{
private:
    char datum[15];
    Test *testovi;
    int n;
 
public:
    PrvKolokvium(const char datum[15] = "", Test *testovi = NULL, int n = 0)
    {
        strcpy(this->datum, datum);
 
        this->testovi = new Test[n];
 
        for(int i=0;i<n;i++)
        {
            this->testovi[i] = testovi[i];
        }
 
        this->n = n;
    }
 
    PrvKolokvium(const PrvKolokvium &p)
    {
        strcpy(this->datum, p.datum);
 
        this->testovi = new Test[p.n];
 
        for(int i=0;i<p.n;i++)
        {
            this->testovi[i] = p.testovi[i];
        }
 
        this->n = p.n;
    }
 
    void setDatum(char datum[15])
    {
        strcpy(this->datum, datum);
    }
 
    char *getDatum(){return this->datum;}
 
    void dodadi(Test t)
    {
        Test *tmp = new Test[n+1];
 
        for(int i=0;i<n;i++)
        {
            tmp[i] = testovi[i];
        }
 
        delete []testovi;
        testovi = tmp;
        testovi[n] = t;
        n++;
    }
 
    void polozeniStudenti()
    {
        for(int i=0;i<this->n;i++)
        {
            if(this->testovi[i].polozen())
            {
                testovi[i].pecati();
            }
        }
    }
 
    ~PrvKolokvium()
    {
        delete [] this->testovi;
    }
};

int main () {

    int n;
    char dat[10];
    cin >> dat;
    cin >> n;
    PrvKolokvium pk1 (dat);
    for(int i = 0; i < n; i++){
        char imp[100];
        cin.get();
        cin.getline(imp,100);
        int ind;
        cin >> ind;
        int poeni[3];
        for(int j = 0; j < 3; j++)
            cin >> poeni[j];
        Test t(imp,ind,poeni);
        pk1.dodadi(t);

    }

    PrvKolokvium pk2 = pk1;
	cin >> dat;
    pk2.setDatum(dat);
    
    char ip[50];
    cin.get();
    cin. getline(ip,50);
    int ind;
    cin >> ind;
    int poeni[3];
    for(int j = 0; j < 3; j++)
    	cin >> poeni[j];
    Test t(ip,ind,poeni);
    pk2.dodadi(t);
	
    cout<<pk1.getDatum()<<endl;
    cout<<"Polozeni studenti:"<<endl;
    pk1.polozeniStudenti();
    cout<<pk2.getDatum()<<endl;
    cout<<"Polozeni studenti:"<<endl;
    pk2.polozeniStudenti();

	return 0;
}

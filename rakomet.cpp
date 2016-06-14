#include <iostream>
#include <cstring>
using namespace std;

class TimRakomet{
    protected:
 
    char ime[30];
    float prosek;
 
    public:
    TimRakomet(char *i=" ", float p=0)
    {
        strcpy(ime,i);
        prosek=p;
    }
    ~TimRakomet(){}
 
    virtual float dostignuvanje()=0;
 
    char *getIme()
    {
        return ime;
    }
 
};
 
class Klub:public TimRakomet{
    private:
 
    int tituli;
 
    public:
 
    Klub(char *i=" ", float p=0, int t=0):TimRakomet(i,p)
    {
        tituli=t;
    }
    float dostignuvanje()
    {
        float vk;
        vk=(prosek*5)+(tituli*50);
        return vk;
 
    }
    ~Klub(){}
 
};
class Reprezentacija:public TimRakomet{
    private:
 
    int rank[2];
 
    public:
 
    Reprezentacija(char *i=" ", float p=0, int *r=0):TimRakomet(i,p)
    {
        for(int j=0;j<3;j++)
        {
            rank[j]=r[j];
 
        }
 
    }
    float dostignuvanje()
    {
        float vk;
        int bodovi=0;
 
        for(int i=0;i<3;i++)
        {
            if(rank[i]==1)
            {
                bodovi+=60;
 
            }
            else if(rank[i]==2)
            {
                bodovi+=40;
            }
            else if(rank[i]==3)
            {
                bodovi+=20;
            }
 
        }
        vk=(prosek*5)+(float)bodovi;
        return vk;
    }
    ~Reprezentacija(){}
 
};
 
void najdobar(TimRakomet **tr, int n)
{
    int max=0;
    for(int i=0;i<n;i++)
    {
        if(tr[i]->dostignuvanje()>tr[max]->dostignuvanje())
        {
            max=i;
        }
    }
    cout<<tr[max]->getIme()<<endl;
    cout<<tr[max]->dostignuvanje()<<endl;
 
}

int main() {
	int n;
	cin >> n;
	TimRakomet** timovi = new TimRakomet*[n];
	for(int i = 0; i < n; ++i) {
		char ime[30];
		float prosekGolovi;
		cin >> ime >> prosekGolovi;
		if(i % 2) {
			int tituli;
			cin >> tituli;
			timovi[i] = new Klub(ime, prosekGolovi, tituli);
		} else {
			int rank[] = {0, 0, 0};
			cin >> rank[0] >> rank[1] >> rank[2];
			timovi[i] = new Reprezentacija(ime, prosekGolovi, rank);
		}
	}

	najdobar(timovi, n);

	for(int i = 0; i < n; ++i) {
		delete timovi[i];
	}
	delete [] timovi;
	return 0;
}

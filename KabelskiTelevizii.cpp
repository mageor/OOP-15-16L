#include <iostream>
#include <cstring>
using namespace std;

class TV {
private:
    char ime[100];
    bool vid;
    int kategorija;
    float rejting;
public:
    TV() {};
    TV(char *i,char v,int k,float r) {
        strcpy(ime,i);
        vid=v;
        kategorija=k;
        rejting=r;
    };
    char *get_ime() {
        return ime;
    };
    float get_rejting() {
        return rejting;
    };
 
    friend ostream &operator<<(ostream &out,TV &t) {
        out<<t.ime<<"\n";
        if (t.vid)
            out<<"D"<<"\n";
        else
            out<<"A"<<"\n";
        out<<t.kategorija<<"\n"<<t.rejting<<endl;
        return out;
    }
 
    bool operator==(TV &t) {
        if (rejting == t.rejting&&!(strcmp(ime,t.ime)) )
            return true;
        else
            return false;
    }
 
    TV &operator++() {
        rejting+=0.5;
        return *this;
    };
};
 
class KabelskiOperator {
private:
    char ime[100];
    TV *tv;
    int broj;
public:
    KabelskiOperator(char *i) {
        strcpy(ime,i);
        broj=0;
        tv=NULL;
    }
 
    KabelskiOperator &operator+=(TV &t) {
        if (t.get_rejting()> 5) {
            TV *pom=new TV[broj+1];
            for(int i=0; i<broj; i++)
                pom[i]=tv[i];
            delete[] tv;
            pom[broj]=t;
            tv=pom;
            pom=NULL;
            broj++;
        }
 
        return *this;
    }
 
    friend ostream &operator<<(ostream &out,KabelskiOperator &ko) {
        out<<ko.ime<<endl;
        for(int i=0; i<ko.broj; i++)
            out<<ko.tv[i]<<endl;
 
        return out;
    };
 
    void zgolemi(TV &t) {
        for(int i=0; i<broj; i++)
            if (tv[i]==t)
                ++tv[i];
 
    };
 
 
 
};

int main() {
	int n, x;
	cin >> n >> x;
	char name[100];
	cin >> name;
	KabelskiOperator ko(name);
	TV t;
	for(int i = 0; i < n; ++i) {
		char name[100];
		bool digital;
		int category;
		float rating;
		cin >> name >> digital >> category >> rating;
		TV tv(name, digital, category, rating);
		ko += tv;
		if(i == x) {
			t = tv;
		}
	}
	cout << ko;
	cout << "=== ZGOLEMI ===" << endl;
    cout << t;
	ko.zgolemi(t);
	cout << ko;
	return 0;
}

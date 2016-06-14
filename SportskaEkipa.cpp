#include<iostream>
#include<string.h>
using namespace std;

typedef struct Igrac {
char ime [20];
char prezime [20];
int dres;
int godini;
char zemja [30];
}Igrac;

typedef struct Tim {
char imeTim[30];
    char drzava[20];
    Igrac igraci [20];
    int broj;
}Tim;

void pomaliStranskiIgraci(Tim *t, int n, int god){
    int i,j,maxI,zbir,max=0;
    for (i=0;i<n;i++){
        zbir=0;
       
   
        for ( j=0;j<t[i].broj;j++)
        {
            if (strcmp(t[i].drzava,t[i].igraci[j].zemja)!=0&&t[i].igraci[j].godini<god)
           
                zbir++;
        }
            if(zbir>max){
                max=zbir;
            maxI=i;
             
            }
           
         }
   
        cout<<t[maxI].imeTim<<" "<<t[maxI].drzava<<" "<<max<<endl;
}

int main()
{
    int n;
	cin>>n;
    Tim a[n];
	for (int i = 0; i < n; i++){
        cin>>a[i].imeTim;
        //vnesi ime
        cin>>a[i].drzava;
        //vnesi drzava
        cin>>a[i].broj;
        //vnesi broj na igraci
        for (int j=0;j<a[i].broj;j++){
       
        //za sekoj igrac vnesi:
            cin>>a[i].igraci[j].ime;
            //vnesi ime
            cin>>a[i].igraci[j].prezime;
            //vnesi prezime
            cin>>a[i].igraci[j].dres;
            //vnesi broj na dres
            cin>>a[i].igraci[j].godini;
            //vnesi godini
            cin>>a[i].igraci[j].zemja;
              //vnesi zemja od kaj doagja
        }
    }
   
    
    int god;
    cin>>god;
    pomaliStranskiIgraci(a, n, god);
    //povik na funkcijata pomaliStranskiIgraci
   
    return 0;
}

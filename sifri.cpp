#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

class Prasanje{
private:
    char kod[100];
    int sifra;
public:
    Prasanje(const char *kod=" ", int sifra = 0){
    strcpy (this -> kod, kod);
    this -> sifra = sifra;
    }

    ~Prasanje(){
    }

    char *getKod(){
    return kod;
    }

    int getSifra(){
    return sifra;
    }

    friend ostream &operator << (ostream &o, Prasanje &p){
    o << p.kod << "-> ";
    return o;
    }
};

int main (){
int sifraa, tocni=0, gresni=0;

Prasanje p_1("ki 1 ", 1);
cout << p_1;
cin >> sifraa;
if (sifraa == p_1.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_1.getSifra(); gresni++;}

Prasanje p_2("ki 2 ", 2);
cout << p_2;
cin >> sifraa;
if (sifraa == p_2.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_2.getSifra() << endl; gresni++;}

Prasanje p_3("ki x ", 0);
cout << p_3;
cin >> sifraa;
if (sifraa == p_3.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_3.getSifra() << endl; gresni++;}

Prasanje p_4("ds 1x ", 10);
cout << p_4;
cin >> sifraa;
if (sifraa == p_4.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_4.getSifra() << endl; gresni++;}

Prasanje p_5("ds 12 ", 11);
cout << p_5;
cin >> sifraa;
if (sifraa == p_5.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_5.getSifra() << endl; gresni++;}

Prasanje p_6("ds X2 ", 12);
cout << p_6;
cin >> sifraa;
if (sifraa == p_6.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_6.getSifra() << endl; gresni++;}

Prasanje p_7("dspp 1x ", 954);
cout << p_7;
cin >> sifraa;
if (sifraa == p_7.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_7.getSifra() << endl; gresni++;}

Prasanje p_8("dspp 12 ", 955);
cout << p_8;
cin >> sifraa;
if (sifraa == p_8.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_8.getSifra() << endl; gresni++;}

Prasanje p_9("dspp X2 ", 956);
cout << p_9;
cin >> sifraa;
if (sifraa == p_9.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_9.getSifra() << endl; gresni++;}

Prasanje p_10("1pp 1 ", 19);
cout << p_10;
cin >> sifraa;
if (sifraa == p_10.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_10.getSifra() << endl; gresni++;}

Prasanje p_11("1pp x ", 20);
cout << p_11;
cin >> sifraa;
if (sifraa == p_11.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_11.getSifra() << endl; gresni++;}

Prasanje p_12("1pp 2 ", 21);
cout << p_12;
cin >> sifraa;
if (sifraa == p_12.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_12.getSifra() << endl; gresni++;}

Prasanje p_13("2dp 1 ", 79);
cout << p_13;
cin >> sifraa;
if (sifraa == p_13.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_13.getSifra() << endl; gresni++;}

Prasanje p_14("2dp x ", 80);
cout << p_14;
cin >> sifraa;
if (sifraa == p_14.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_14.getSifra() << endl; gresni++;}

Prasanje p_15("2dp 2 ", 81);
cout << p_15;
cin >> sifraa;
if (sifraa == p_15.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_15.getSifra() << endl; gresni++;}

Prasanje p_16("pk 1-1 ", 7);
cout << p_16;
cin >> sifraa;
if (sifraa == p_16.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_16.getSifra() << endl; gresni++;}

Prasanje p_16x("pk x-1 ", 8);
cout << p_16x;
cin >> sifraa;
if (sifraa == p_16x.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_16x.getSifra() << endl; gresni++;}

Prasanje p_17("pk 2-2 ", 9);
cout << p_17;
cin >> sifraa;
if (sifraa == p_17.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_17.getSifra() << endl; gresni++;}

Prasanje p_18("pk 1-x ", 22);
cout << p_18;
cin >> sifraa;
if (sifraa == p_18.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_18.getSifra() << endl; gresni++;}

Prasanje p_18x("pk 1-2 ", 23);
cout << p_18x;
cin >> sifraa;
if (sifraa == p_18x.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_18x.getSifra() << endl; gresni++;}

Prasanje p_19("pk x-x ", 24);
cout << p_19;
cin >> sifraa;
if (sifraa == p_19.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_19.getSifra() << endl; gresni++;}

Prasanje p_20("pk x-2 ", 25);
cout << p_20;
cin >> sifraa;
if (sifraa == p_20.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_20.getSifra() << endl; gresni++;}

Prasanje p_21("pk 2-1 ", 26);
cout << p_21;
cin >> sifraa;
if (sifraa == p_21.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_21.getSifra() << endl; gresni++;}

Prasanje p_22("pk 2-x ", 27);
cout << p_22;
cin >> sifraa;
if (sifraa == p_22.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_22.getSifra() << endl; gresni++;}

Prasanje p_23("w 1 ", 95);
cout << p_23;
cin >> sifraa;
if (sifraa == p_23.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_23.getSifra() << endl; gresni++;}

Prasanje p_24("w 2 ", 96);
cout << p_24;
cin >> sifraa;
if (sifraa == p_24.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_24.getSifra() << endl; gresni++;}

Prasanje p_25("1w 1 ", 581);
cout << p_25;
cin >> sifraa;
if (sifraa == p_25.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_25.getSifra() << endl; gresni++;}

Prasanje p_26("1w 2 ", 582);
cout << p_26;
cin >> sifraa;
if (sifraa == p_26.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_26.getSifra() << endl; gresni++;}

Prasanje p_26x("SP 1 ", 754);
cout << p_26x;
cin >> sifraa;
if (sifraa == p_26x.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_26x.getSifra() << endl; gresni++;}

Prasanje p_27("SP 2 ", 755);
cout << p_27;
cin >> sifraa;
if (sifraa == p_27.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_27.getSifra() << endl; gresni++;}

Prasanje p_28("HP 1 ", 756);
cout << p_28;
cin >> sifraa;
if (sifraa == p_28.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_28.getSifra() << endl; gresni++;}

Prasanje p_29("HP 2 ", 757);
cout << p_29;
cin >> sifraa;
if (sifraa == p_29.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_29.getSifra() << endl; gresni++;}

Prasanje p_30("vg 1 (1>2) ", 55);
cout << p_30;
cin >> sifraa;
if (sifraa == p_30.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_30.getSifra() << endl; gresni++;}

Prasanje p_31("vg x (1=2) ", 57);
cout << p_31;
cin >> sifraa;
if (sifraa == p_31.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_31.getSifra() << endl; gresni++;}

Prasanje p_32("vg 2 (2>1) ", 56);
cout << p_32;
cin >> sifraa;
if (sifraa == p_32.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_32.getSifra() << endl; gresni++;}

Prasanje p_33("3+ ", 3);
cout << p_33;
cin >> sifraa;
if (sifraa == p_33.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_33.getSifra() << endl; gresni++;}

Prasanje p_34("4+ ", 4);
cout << p_34;
cin >> sifraa;
if (sifraa == p_34.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_34.getSifra() << endl; gresni++;}

Prasanje p_35("0-2 g ", 5);
cout << p_35;
cin >> sifraa;
if (sifraa == p_35.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_35.getSifra() << endl; gresni++;}

Prasanje p_36("2-3 g ", 6);
cout << p_36;
cin >> sifraa;
if (sifraa == p_36.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_36.getSifra() << endl; gresni++;}

Prasanje p_37x("0-1 g ", 13);
cout << p_37x;
cin >> sifraa;
if (sifraa == p_37x.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_37x.getSifra() << endl; gresni++;}

Prasanje p_37("4-6 g ", 14);
cout << p_37;
cin >> sifraa;
if (sifraa == p_37.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_37.getSifra() << endl; gresni++;}

Prasanje p_38("5+ g ", 15);
cout << p_38;
cin >> sifraa;
if (sifraa == p_38.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_38.getSifra() << endl; gresni++;}

Prasanje p_39("7+ g ", 16);
cout << p_39;
cin >> sifraa;
if (sifraa == p_39.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_39.getSifra() << endl; gresni++;}

Prasanje p_40("0-3 g ", 45);
cout << p_40;
cin >> sifraa;
if (sifraa == p_40.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_40.getSifra() << endl; gresni++;}

Prasanje p_41("2+ g ", 383);
cout << p_41;
cin >> sifraa;
if (sifraa == p_41.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_41.getSifra() << endl; gresni++;}

Prasanje p_42("2-4 g ", 384);
cout << p_42;
cin >> sifraa;
if (sifraa == p_42.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_42.getSifra() << endl; gresni++;}

Prasanje p_43("3-4 g ", 385);
cout << p_43;
cin >> sifraa;
if (sifraa == p_43.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_43.getSifra() << endl; gresni++;}

Prasanje p_44("1-3 g ", 527);
cout << p_44;
cin >> sifraa;
if (sifraa == p_44.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_44.getSifra() << endl; gresni++;}

Prasanje p_45("2-5 g ", 528);
cout << p_45;
cin >> sifraa;
if (sifraa == p_45.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_45.getSifra() << endl; gresni++;}

Prasanje p_46("3-5 g ", 529);
cout << p_46;
cin >> sifraa;
if (sifraa == p_46.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_46.getSifra() << endl; gresni++;}

Prasanje p_47("1-2 g ", 612);
cout << p_47;
cin >> sifraa;
if (sifraa == p_47.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_47.getSifra() << endl; gresni++;}

Prasanje p_48("4-5 g ", 613);
cout << p_48;
cin >> sifraa;
if (sifraa == p_48.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_48.getSifra() << endl; gresni++;}

Prasanje p_49("1ug 1+ g ", 33);
cout << p_49;
cin >> sifraa;
if (sifraa == p_49.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_49.getSifra() << endl; gresni++;}

Prasanje p_50("1ug 2+ g ", 34);
cout << p_50;
cin >> sifraa;
if (sifraa == p_50.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_50.getSifra() << endl; gresni++;}

Prasanje p_51("1ug 3+ g ", 35);
cout << p_51;
cin >> sifraa;
if (sifraa == p_51.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_51.getSifra() << endl; gresni++;}

Prasanje p_52("1ug 2-3 g ", 38);
cout << p_52;
cin >> sifraa;
if (sifraa == p_52.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_52.getSifra() << endl; gresni++;}

Prasanje p_53("2ug 1+ g ", 39);
cout << p_53;
cin >> sifraa;
if (sifraa == p_53.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_53.getSifra() << endl; gresni++;}

Prasanje p_54("2ug 2+ g ", 40);
cout << p_54;
cin >> sifraa;
if (sifraa == p_54.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_54.getSifra() << endl; gresni++;}

Prasanje p_55("2ug 3+ g ", 41);
cout << p_55;
cin >> sifraa;
if (sifraa == p_55.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_55.getSifra() << endl; gresni++;}

Prasanje p_56("2ug 2-3 g ", 44);
cout << p_56;
cin >> sifraa;
if (sifraa == p_56.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_56.getSifra() << endl; gresni++;}

Prasanje p_57("tm 1 1+ ", 519);
cout << p_57;
cin >> sifraa;
if (sifraa == p_57.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_57.getSifra() << endl; gresni++;}

Prasanje p_58("tm 1 2+ ", 520);
cout << p_58;
cin >> sifraa;
if (sifraa == p_58.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_58.getSifra() << endl; gresni++;}

Prasanje p_59("tm 1 3+ ", 758);
cout << p_59;
cin >> sifraa;
if (sifraa == p_59.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_59.getSifra() << endl; gresni++;}

Prasanje p_60("tm 1 12GG ", 597);
cout << p_60;
cin >> sifraa;
if (sifraa == p_60.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_60.getSifra() << endl; gresni++;}

Prasanje p_61("tm 1 12NG ", 598);
cout << p_61;
cin >> sifraa;
if (sifraa == p_61.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_61.getSifra() << endl; gresni++;}

Prasanje p_62("tm 1 2+ & GG ", 614);
cout << p_62;
cin >> sifraa;
if (sifraa == p_62.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_62.getSifra() << endl; gresni++;}

Prasanje p_63("1tm1 1+ ", 511);
cout << p_63;
cin >> sifraa;
if (sifraa == p_63.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_63.getSifra() << endl; gresni++;}

Prasanje p_64("1tm1 2+ ", 512);
cout << p_64;
cin >> sifraa;
if (sifraa == p_64.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_64.getSifra() << endl; gresni++;}

Prasanje p_65("1tm1 0 ", 513);
cout << p_65;
cin >> sifraa;
if (sifraa == p_65.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_65.getSifra() << endl; gresni++;}

Prasanje p_66("2tm1 1+ ", 575);
cout << p_66;
cin >> sifraa;
if (sifraa == p_66.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_66.getSifra() << endl; gresni++;}

Prasanje p_67("2tm1 2+ ", 576);
cout << p_67;
cin >> sifraa;
if (sifraa == p_67.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_67.getSifra() << endl; gresni++;}

Prasanje p_68("2tm1 0 ", 577);
cout << p_68;
cin >> sifraa;
if (sifraa == p_68.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_68.getSifra() << endl; gresni++;}

Prasanje p_69("2tm1 0 ", 577);
cout << p_69;
cin >> sifraa;
if (sifraa == p_69.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_69.getSifra() << endl; gresni++;}

Prasanje p_70("tm2 1+ ", 523);
cout << p_70;
cin >> sifraa;
if (sifraa == p_70.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_70.getSifra() << endl; gresni++;}

Prasanje p_71("tm2 2+ ", 524);
cout << p_71;
cin >> sifraa;
if (sifraa == p_71.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_71.getSifra() << endl; gresni++;}

Prasanje p_72("tm2 3+ ", 759);
cout << p_72;
cin >> sifraa;
if (sifraa == p_72.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_72.getSifra() << endl; gresni++;}

Prasanje p_73("tm2 12GG ", 599);
cout << p_73;
cin >> sifraa;
if (sifraa == p_73.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_73.getSifra() << endl; gresni++;}

Prasanje p_74("tm2 12NG ", 600);
cout << p_74;
cin >> sifraa;
if (sifraa == p_74.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_74.getSifra() << endl; gresni++;}

Prasanje p_74x("tm2 2+ & GG ", 615);
cout << p_74x;
cin >> sifraa;
if (sifraa == p_74x.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_74x.getSifra() << endl; gresni++;}

Prasanje p_75("1tm2 1+ ", 514);
cout << p_75;
cin >> sifraa;
if (sifraa == p_75.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_75.getSifra() << endl; gresni++;}

Prasanje p_76("1tm2 2+ ", 515);
cout << p_76;
cin >> sifraa;
if (sifraa == p_76.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_76.getSifra() << endl; gresni++;}

Prasanje p_77("1tm2 0 ", 516);
cout << p_77;
cin >> sifraa;
if (sifraa == p_77.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_77.getSifra() << endl; gresni++;}

Prasanje p_78("2tm2 1+ ", 578);
cout << p_78;
cin >> sifraa;
if (sifraa == p_78.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_78.getSifra() << endl; gresni++;}

Prasanje p_79("2tm2 2+ ", 579);
cout << p_79;
cin >> sifraa;
if (sifraa == p_79.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_79.getSifra() << endl; gresni++;}

Prasanje p_80("2tm2 0 ", 580);
cout << p_80;
cin >> sifraa;
if (sifraa == p_80.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_80.getSifra() << endl; gresni++;}

Prasanje p_80x("2tm2 0 ", 580);
cout << p_80x;
cin >> sifraa;
if (sifraa == p_80x.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_80x.getSifra() << endl; gresni++;}

Prasanje p("GG ", 517);
cout << p;
cin >> sifraa;
if (sifraa == p.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p.getSifra() << endl; gresni++;}

Prasanje p_81("tm1 2+ & tm2 2+ ", 760);
cout << p_81;
cin >> sifraa;
if (sifraa == p_81.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_81.getSifra() << endl; gresni++;}

Prasanje p_82("tgg NG ", 518);
cout << p_82;
cin >> sifraa;
if (sifraa == p_82.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_82.getSifra() << endl; gresni++;}

Prasanje p_83("tgg GG 3+ ", 574);
cout << p_83;
cin >> sifraa;
if (sifraa == p_83.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_83.getSifra() << endl; gresni++;}

Prasanje p_84("tgg 1GG ", 601);
cout << p_84;
cin >> sifraa;
if (sifraa == p_84.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_84.getSifra() << endl; gresni++;}

Prasanje p_85("tgg 2GG ", 602);
cout << p_85;
cin >> sifraa;
if (sifraa == p_85.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_85.getSifra() << endl; gresni++;}

Prasanje p_86("1GG & 2GG ", 616);
cout << p_86;
cin >> sifraa;
if (sifraa == p_86.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_86.getSifra() << endl; gresni++;}

Prasanje p_87("pr 1-1 ", 555);
cout << p_87;
cin >> sifraa;
if (sifraa == p_87.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_87.getSifra() << endl; gresni++;}

Prasanje p_88("pr 1-x ", 556);
cout << p_88;
cin >> sifraa;
if (sifraa == p_88.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_88.getSifra() << endl; gresni++;}

Prasanje p_89("pr 1-2 ", 557);
cout << p_89;
cin >> sifraa;
if (sifraa == p_89.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_89.getSifra() << endl; gresni++;}

Prasanje p_90("pr 2-1 ", 558);
cout << p_90;
cin >> sifraa;
if (sifraa == p_90.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_90.getSifra() << endl; gresni++;}

Prasanje p_91("pr 2-x ", 559);
cout << p_91;
cin >> sifraa;
if (sifraa == p_91.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_91.getSifra() << endl; gresni++;}

Prasanje p_92("pr 2-2 ", 560);
cout << p_92;
cin >> sifraa;
if (sifraa == p_92.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_92.getSifra() << endl; gresni++;}

Prasanje p_93("kmb 1 & 3+ ", 561);
cout << p_93;
cin >> sifraa;
if (sifraa == p_93.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_93.getSifra() << endl; gresni++;}

Prasanje p_94("kmb 2 & 3+ ", 562);
cout << p_94;
cin >> sifraa;
if (sifraa == p_94.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_94.getSifra() << endl; gresni++;}

Prasanje p_95("kmb 1 & 2+ Ip ", 563);
cout << p_95;
cin >> sifraa;
if (sifraa == p_95.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_95.getSifra() << endl; gresni++;}

Prasanje p_96("kmb 2 & 2+ Ip ", 564);
cout << p_96;
cin >> sifraa;
if (sifraa == p_96.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_96.getSifra() << endl; gresni++;}

Prasanje p_97("kmb 1-1 & 3+ ", 565);
cout << p_97;
cin >> sifraa;
if (sifraa == p_97.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_97.getSifra() << endl; gresni++;}

Prasanje p_98("kmb 1-1 & 2+ Ip ", 566);
cout << p_98;
cin >> sifraa;
if (sifraa == p_98.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_98.getSifra() << endl; gresni++;}

Prasanje p_99("kmb 1 & 2-3 ", 567);
cout << p_99;
cin >> sifraa;
if (sifraa == p_99.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_99.getSifra() << endl; gresni++;}

Prasanje p_100("kmb 2 & 2-3 ", 568);
cout << p_100;
cin >> sifraa;
if (sifraa == p_100.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_100.getSifra() << endl; gresni++;}

Prasanje p_101("kmb GG & 2+ Ip ", 569);
cout << p_101;
cin >> sifraa;
if (sifraa == p_101.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_101.getSifra() << endl; gresni++;}

Prasanje p_102("kmb 1 & 2+ ", 570);
cout << p_102;
cin >> sifraa;
if (sifraa == p_102.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_102.getSifra() << endl; gresni++;}

Prasanje p_103("kmb 2 & 2+ ", 571);
cout << p_103;
cin >> sifraa;
if (sifraa == p_103.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_103.getSifra() << endl; gresni++;}

Prasanje p_104("kmb 1 & 4+ ", 572);
cout << p_104;
cin >> sifraa;
if (sifraa == p_104.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_104.getSifra() << endl; gresni++;}

Prasanje p_105("kmb 2 & 4+ ", 573);
cout << p_105;
cin >> sifraa;
if (sifraa == p_105.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_105.getSifra() << endl; gresni++;}

Prasanje p_106("kmb 1+I & 1+II ", 619);
cout << p_106;
cin >> sifraa;
if (sifraa == p_106.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_106.getSifra() << endl; gresni++;}

Prasanje p_107("kmb 1+I & 2+II ", 604);
cout << p_107;
cin >> sifraa;
if (sifraa == p_107.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_107.getSifra() << endl; gresni++;}

Prasanje p_108("kmb 2-2 & 3+ ", 611);
cout << p_108;
cin >> sifraa;
if (sifraa == p_108.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_108.getSifra() << endl; gresni++;}

Prasanje p_109("kmb 1 & GG ", 692);
cout << p_109;
cin >> sifraa;
if (sifraa == p_109.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_109.getSifra() << endl; gresni++;}

Prasanje p_110("kmb 2 & GG ", 693);
cout << p_110;
cin >> sifraa;
if (sifraa == p_110.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_110.getSifra() << endl; gresni++;}

Prasanje p_111("kmb 2-2 & 2+ pp ", 695);
cout << p_111;
cin >> sifraa;
if (sifraa == p_111.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_111.getSifra() << endl; gresni++;}

Prasanje p_112("sns ki1 V pp1 ", 607);
cout << p_112;
cin >> sifraa;
if (sifraa == p_112.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_112.getSifra() << endl; gresni++;}

Prasanje p_113("sns kiX V ppX ", 608);
cout << p_113;
cin >> sifraa;
if (sifraa == p_113.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_113.getSifra() << endl; gresni++;}

Prasanje p_114("sns ki2 V pp2 ", 609);
cout << p_114;
cin >> sifraa;
if (sifraa == p_114.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_114.getSifra() << endl; gresni++;}

Prasanje p_115("sns ki1 V pp3+ ", 610);
cout << p_115;
cin >> sifraa;
if (sifraa == p_115.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_115.getSifra() << endl; gresni++;}

Prasanje p_116("dp 11 ", 605);
cout << p_116;
cin >> sifraa;
if (sifraa == p_116.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_116.getSifra() << endl; gresni++;}

Prasanje p_117("dp 22 ", 606);
cout << p_117;
cin >> sifraa;
if (sifraa == p_117.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_117.getSifra() << endl; gresni++;}

Prasanje p_118("pdg 1 ", 891);
cout << p_118;
cin >> sifraa;
if (sifraa == p_118.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_118.getSifra() << endl; gresni++;}

Prasanje p_119("pdg X ", 890);
cout << p_119;
cin >> sifraa;
if (sifraa == p_119.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_119.getSifra() << endl; gresni++;}

Prasanje p_120("pdg 2 ", 892);
cout << p_120;
cin >> sifraa;
if (sifraa == p_120.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_120.getSifra() << endl; gresni++;}

Prasanje p_121("pdg Ip 1 ", 585);
cout << p_121;
cin >> sifraa;
if (sifraa == p_121.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_121.getSifra() << endl; gresni++;}

Prasanje p_122("pdg Ip X ", 586);
cout << p_122;
cin >> sifraa;
if (sifraa == p_122.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_122.getSifra() << endl; gresni++;}

Prasanje p_123("pdg Ip 2 ", 587);
cout << p_123;
cin >> sifraa;
if (sifraa == p_123.getSifra()){
    cout << "Tocno" << endl; tocni++;}
else {cout <<"Greska, " << p_123.getSifra() << endl; gresni++;}

cout << "Tocni: " << tocni << "\n" << "Gresni: " << gresni << endl;
system ("pause");
return 0;
}

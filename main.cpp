#include <iostream>
#include <time.h>
#include <bits/stdc++.h>
#include <fstream>
#include <cstring>
#include <map>

using namespace std;
ifstream ffin("cuvinte.in");
ofstream ffout("cuvinte.out");
//ofstream gout("C:\\Users\\maria\\Desktop\\ASC DUS-INTORS\\fisiere\\ceva.txt");///ceva e unde pun cuvantul incercat
//ifstream gin("C:\\Users\\maria\\Desktop\\ASC DUS-INTORS\\fisiere\\ceva2.txt");///ceva2 e unde pun rezultatu
fstream ggout;
fstream ggin;


int alimita=11453;
int alimita2=11453;
char acuv[12000][6];///matricea cu cuvinte
char acuv2[12000][6];///copie pentru incercari matricea cu cuvinte
char asolutie[6];///nu stiu dc e aici
int aapar[300];///vector pt litere si aparitii, daca o sa fie nevoie
char acuvant_entropic[6];///cuvantul cel mai entropic per stage
double aentropie_max=0;///entropia maxima per stage
double apos_lit[30][6];///posibilitatea [litera]/[pozitie]
char acopie_cuv[12000][6];
char anterior[6]="";
unordered_map<string,int>pl;
double pos_lit_tot[30];
unordered_map<char,int>folosit;
double mediaJOC=0;
int pasi=0;
int nr=0;



double aentropie(double aposibilitate)///functie de calculat entropia pentru posibilitate
{
    return aposibilitate*log2(1/aposibilitate);
}

void abag()///bag cuvintele in matrice
{
    char acuvant[6];
    for(int i=0; i<=11453; ++i)
    {
        ffin>>acuvant;
        strcpy(acuv[i],acuvant);
        strcpy(acuv2[i],acuvant);
    }
}



void abaga_pos()///functia de pus posibilitatile in matrice
{
    for(int j=0; j<=25; ++j)
    {
        for(int k=0; k<=4; ++k)
        {
            //cout<<char(j+'A')<<" ";
            double acazf=0;
            for(int i=0; i<=alimita; ++i)
            {
                if(acuv[i][k]==j+'A')
                    acazf++;
            }
           // cout<<cazf<<" ";
            apos_lit[j][k]=acazf/(alimita+1);
        }
       // cout<<'\n';
    }
}
void baga_pos_2()
{

    for(int j=0;j<=25;++j)
    {double caz_2=0;
        for(int i=0;i<=alimita;++i)
        {
            if(acuv[i][0]==j+'A' || acuv[i][1]==j+'A' || acuv[i][2]==j+'A' || acuv[i][3]==j+'A' || acuv[i][4]==j+'A')
                caz_2++;
        }
        pos_lit_tot[j]=caz_2/(alimita+1);
    }
}


void agaseste_entropie()///functia de gasit cel mai bun cuvant entropic per stage
{aentropie_max=0;
 if(alimita){


    for(int i=0;i<=alimita2;++i)
    {
        double aentrop=0;
        for(int j=0;j<=4;++j)
        {
            aentrop+=aentropie(apos_lit[acuv2[i][j]-'A'][j]);
        }
        if(aentrop>aentropie_max)
        {
            aentropie_max=aentrop;
            strcpy(acuvant_entropic,acuv2[i]);
        }
    }
 }
 else
 {
     strcpy(acuvant_entropic,acuv[0]);
 }
    ffout<<acuvant_entropic<<'\n'<<'\n';

}

void gaseste_super()
{
   double entropie_supermax=0;
 if(alimita){

strcpy(acuvant_entropic,acuv[0]);
    for(int i=0;i<=alimita2;++i)
    {
        for(int j=0;j<=25;++j)
            folosit[j+'A']=0;
        double entrop=0;
        for(int j=0;j<=4;++j)
        {
            if(folosit[acuv2[i][j]]==0)
            entrop+=aentropie(pos_lit_tot[acuv2[i][j]-'A']);
        folosit[acuv2[i][j]]=1;
        }
        if(entrop>entropie_supermax)
        {
            entropie_supermax=entrop;
            strcpy(acuvant_entropic,acuv2[i]);
        }
    }
 }
 else
 {
     strcpy(acuvant_entropic,acuv[0]);
 }
    //cout<<entropie_supermax<<" "<<cuvant_entropic<<'\n'<<'\n';
}


void ataieposibilitati(char aincercatu[],char arezultatu[])
{
int arezul[12000]={0};/// rezul[i] e 1 cand tre sa sterg cuvantul i din lista
for(int i=0;i<=4;++i)
{
    if(arezultatu[i]=='C')///daca e litera buna
    for(int j=0;j<=alimita;++j)
    {
    if(acuv[j][i]!=aincercatu[i])
            arezul[j]=1;
    }

    if(arezultatu[i]=='G')///daca e litera gresita
    for(int j=0;j<=alimita;++j)
    {
        for(int k=0;k<=4;++k)
        if(acuv[j][k]==aincercatu[i])
        arezul[j]=1;
    }

    if(arezultatu[i]=='A')///daca e aprox buna
    for(int j=0;j<=alimita;++j)
    {
        if(acuv[j][i]==aincercatu[i])
        arezul[j]=1;
        int acnt=0;
        for(int k=0;k<=4;++k)
            if(acuv[j][k]==aincercatu[i])
            acnt++;
        if(acnt==0)
            arezul[j]=1;
    }
}
int agresit=0;
for(int i=0;i<=alimita;++i)///stergere efectiva (cum naiba se facea fara vector aditional???)
{
if(!arezul[i])
    strcpy(acopie_cuv[agresit++],acuv[i]);
}
alimita=agresit-1;
for(int i=0;i<=alimita;++i)
strcpy(acuv[i],acopie_cuv[i]);

/*for(int i=0;i<=alimita;++i)
    cout<<acuv[i]<<'\n';///afisare la cuvinte ramase

    cout<<'\n'<<'\n';*/
}

///DE FACUT CAND E CCACC SAU CAZURI CU A CAND DEJA EXISTA LITERA!!!
int main()
{ char arezultat[6]="";
    ggout.open("ceva.txt", std::ios_base::out);///scot trunc daca nu mere si citesc toate liniile    ggout<<acuvant_entropic<<'\n';
    ggout.close();
    ggout.open("ceva2.txt", std::ios_base::out);///scot trunc daca nu mere si citesc toate liniile    ggout<<acuvant_entropic<<'\n';
    ggout.close();
int pas=0;
    abag();
pl[""]++;
    baga_pos_2();
    gaseste_super();
    int anumarascrieri=0;
    while(arezultat!="CCCCC"){///==   ->   !=
    strcpy(anterior,arezultat);
    gaseste_super();///gaseste cuvantul bun
    ggout.open("ceva.txt", std::ios_base::out);///scot trunc daca nu mere si citesc toate liniile
    ggout<<acuvant_entropic<<'\n';
    cout<<acuvant_entropic<<'\n';
    ggout.close();
    while(strcmp(arezultat,anterior)==0){
    ggin.open("ceva2.txt", std::ios_base::in);
    ggin>>arezultat;
    ggin.close();
    }
    pas++;
    if(arezultat[0]=='C' && arezultat[1]=='C' && arezultat[2]=='C' && arezultat[3]=='C' && arezultat[4]=='C')
    break;
    ataieposibilitati(acuvant_entropic,arezultat);
    baga_pos_2();
    
    }
    cout<<"L-ai ghicit din "<<pas<<" incercari!!!";
///face 2 pasi si nu mai mere tre sa vad cu citirea aia belita

    return 0;
}


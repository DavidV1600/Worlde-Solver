#include <iostream>
#include <time.h>
#include <bits/stdc++.h>
#include <fstream>
#include <cstring>

using namespace std;
ifstream fin("cuvinte.in");
//ofstream file("filename.txt"); // Without append

ofstream fout("cuvinte.out");
//ifstream gin("C:\\Users\\maria\\Desktop\\ASC DUS-INTORS\\fisiere\\ceva.txt");///ceva e unde pun cuvantul incercat
//ofstream gout("C:\\Users\\maria\\Desktop\\ASC DUS-INTORS\\fisiere\\ceva2.txt");///ceva2 e unde pun rezultatu
fstream gin;
fstream gout;

int limita=11453;
int limita2=11453;
char cuv[12000][6];///matricea cu cuvinte
char cuv2[12000][6];///copie pentru incercari matricea cu cuvinte
char solutie[6];///nu stiu dc e aici
int apar[300];///vector pt litere si aparitii, daca o sa fie nevoie
char cuvant_entropic[6];///cuvantul cel mai entropic per stage
double entropie_max=0;///entropia maxima per stage
double pos_lit[30][6];///posibilitatea [litera]/[pozitie]
char copie_cuv[12000][6];
char ant[6];
unordered_map<string,int>pls;///mapa de cuvinte folosite

double entropie(double posibilitate)///functie de calculat entropia pentru posibilitate
{
    return posibilitate*log2(1/posibilitate);
}

void bag()///bag cuvintele in matrice
{
    char cuvant[6];
    for(int i=0; i<=11453; ++i)
    {
        fin>>cuvant;
        strcpy(cuv[i],cuvant);
        strcpy(cuv2[i],cuvant);
    }
}

void genereaza_cuv()///functie de generat un cuvant random
{
    int susta=rand()%limita+1;
    // cout<<susta<<'\n';
    strcpy(solutie,cuv[susta]);
    //  cout<<solutie<<'\n';
    for(int i=0; i<=4; ++i)
        apar[solutie[i]]++;
    /*for(int i=0;i<=30;++i)
        if(apar[i])
        cout<<apar[i]<<" ";*/

}

void joc()///functia de jucat ca persoana
{
pls[""]++;  ///aici tre sa vad daca bag mapa de cuvinte folosite la WHILE
  cout<<"Toate literele din cuvant trebuie sa fie MARI!!!\n";
    cout<<"Cuvantul contine exact 5 litere!!!\n";
    cout<<"G - Litera nu exista in cuvant\n";
    cout<<"C - Litera este plasata corect in cuvant\n";
    cout<<"A - Litera exista in cuvant, dar nu pe aceea pozitie\n";
    char incerc[6];
    int pasi=0;
    char ant[6];
    int ok=1;
    while(ok)
    {
        char afisaj[6];
        
        cout<<"Incearca cuvant:";
        int ebun=0;
        //cin>>incerc (daca doresc sa joace omul trebuie inlocuita linia cu urmatoare cu aceasta)(adica,  strcpy(ant,incerc);  ->  cin>>incerc;    )
        strcpy(ant,incerc);
        while(ebun==0){
       
        while(strcmp(ant,incerc)==0){
        gin.open("ceva.txt", std::ios_base::in); 
        gin>>incerc;
        gin.close();
    }
    
    pls[incerc]++;
    if(pls[incerc]==1)
    pasi++;
    
        for(int i=0;i<=limita;++i)
        {
            if (strcmp(incerc,cuv[i])==0)
                ebun=1;
        }
        if(!ebun)
        {
            cout<<"Cuvantul scris este invalid, mai incercati\n";
        }
        }
        cout<<'\n';
///sa fac cazul cand o litera apare de mai multe ori???
        for(int i=0; i<=4; ++i)
        {
            if(incerc[i]==solutie[i])
                afisaj[i]='C';
            else if(apar[incerc[i]])
                afisaj[i]='A';
            else
                afisaj[i]='G';
        }
    gout.open("ceva2.txt", std::ios_base::out);///scot/bag trunc daca nu mere si citesc toate liniile
    gout<<afisaj<<pasi<<'\n';
    cout<<afisaj<<'\n';
    gout.close();

        if (strcmp(afisaj,"CCCCC")==0)
        {
            cout<<"\n Felicitari ati ghicit cuvantul din "<<pasi<<" incercari!"<<'\n';
            break;
        }
    }
}


void posib()
{
    for(int i=0; i<=25; ++i)
    {
        cout<<char(i+'A')<<" ";
        for(int j=0; j<=4; ++j)
            cout<<pos_lit[i][j]<<" ";
        cout<<'\n';
    }
}


///DE FACUT CAND E CCACC SAU CAZURI CU A CAND DEJA EXISTA LITERA!!!
int main()
{
    //srand(clock());

    srand(time(NULL));

    bag();

//test();
    genereaza_cuv();
    joc();
///face doi pasi si nu mai mere tre sa vad cu citirea aia belita
    return 0;
}


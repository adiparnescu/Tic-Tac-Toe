#include <iostream>
#include <string>

using namespace std;
string jucatorx,jucatoro;
class XO
{
    int a[4][4];
public:
    void setCamp(int x,int y,int z) { if(this->a[x][y]==0) this->a[x][y]=z; else cout<<"Exista deja un caracter pe aceasta pozitie\n";}
    void afisare();
    void citire(char);
    int verificare();
    XO();
};
XO::XO()
{
    for(int i=1;i<=3;i++)
     {
         for(int j=1;j<=3;j++)
            a[i][j]=0;
     }
}
void XO:: afisare()
{
     int i;
     cout<<endl;
     for(i=1;i<=3;i++)
     {
         for(int j=1;j<=3;j++)
     {
         cout<<"|";
         if(this->a[i][j]==1) cout<<"X";
         else if(this->a[i][j]==2) cout<<"O";
         else if(this->a[i][j]==0)  cout<<"_";
     }

     cout<<"|"<<endl;
     }

}
void XO::citire(char c)
{
    int a,b;
    cin>>a>>b;
    if(c=='X' || c=='x') this->setCamp(a,b,1);
    if(c=='O' || c=='o') this->setCamp(a,b,2);
}
int XO::verificare()
{
    int verif=0,i,k=0;
    for(i=1;i<=3;i++)
    {
        if(a[i][1]==a[i][2] && a[i][2]==a[i][3]) return a[i][1];
        if(a[1][i]==a[2][i] && a[2][i]==a[3][i]) return a[1][i];
    }
    if(a[1][1]==a[2][2] && a[2][2]==a[3][3]) return a[1][1];
    if(a[1][3]==a[2][2] && a[2][2]==a[3][1]) { return a[1][3]; cout<<a[1][3]<<"="<<a[2][2]<<"="<<a[3][1];}
     for(int i=1;i<=3;i++)
     {
         for(int j=1;j<=3;j++)
            if(a[i][j]) k++;
     }
     if(k==9) return 9;
     return 0;
}

void Start_joc(XO *ob)
{
    int turn=1;
    while(ob->verificare()==0)
    {
        if(turn>0){
            cout<<"Introduceti pozitiile pentru caracterul X ";
            ob->citire('X');
        }
        else{
            cout<<"Introduceti pozitiile pentru caracterul O ";
            ob->citire('O');
        }

        ob->afisare();
        turn=turn*(-1);

    }
        if(ob->verificare()==1) {cout<<"\nCastigatorul este jucatorul "<<jucatorx; return;}

         if(ob->verificare()==2)  {cout<<"\nCastigatorul este jucatorul "<<jucatoro; return;}
         if(ob->verificare()==9) {cout<<"\nJocul s-a terminat la egalitate intre "<<jucatorx<<" si "<<jucatoro; return;}

}
void afisare_tabla()
{
    cout<<"Tabla de joc are coordonatele urmatoare\n";
    cout<<"  ";
    for(int i=1;i<=3;i++) cout<<i<<" ";
    cout<<endl;
    for(int i=1;i<=3;i++)
    {
        cout<<i<<"|";
        for(int j=1;j<=3;j++)
        {
            cout<<"_|";
        }
        cout<<i;
        cout<<endl;

    }
    cout<<"  ";
    for(int i=1;i<=3;i++) cout<<i<<" ";
    cout<<endl;
}
int main()
{
    XO *ob;
    ob=new XO();
    cout<<"MENIU\n";
    cout<<"Introduceti numele jucatorului care va juca cu X ";
    getline(cin,jucatorx);
    cout<<"\nIntroduceti numele jucatorului care va juca cu O ";
    getline(cin,jucatoro);

    afisare_tabla();
    cout<<"\nComenzi de adaugare:\nIntroduceti numarul liniei si numarul coloanei pentru caracterul precizat.\n";
    Start_joc(ob);
    return 0;
}

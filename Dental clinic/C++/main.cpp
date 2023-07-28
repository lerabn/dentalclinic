#include <iostream>
#include <fstream>
using namespace std;

ifstream f("Teren.in");
int m,n,i,j, c1, c2 , ob;
float a[100][100];
void Citirea(){
   f>>n;
   f>>m;
   for(i=1;i<=n;i++)
       for(j=1;j<=m;j++)
           f>>a[i][j];
           f.close();
   }

void Afisare(){
cout<<"\n Matricea este:\n";
for(i=1;i<=n;i++)
{for(j=1;j<=m;j++)
cout<<a[i][j]<<" ";
cout<<"\n";}
}

   void Interschimbarecoloana(){
       int aux;
       cout<<"\n Numerele coloanelor care doriti sa le interschimbati";
cout<<"\n c1: ";cin>>c1;
cout<<"\n c2: ";cin>>c2;
for(i=1;i<=n;i++)
{aux=a[i][c1];
a[i][c1]=a[i][c2];
a[i][c2]=aux;}
cout<<"\n Noua matrice este:\n";
for(i=1;i<=n;i++)
{for(j=1;j<=m;j++)
cout<<a[i][j]<<" ";
cout<<"\n";}
   }

   void Stergerea(){
   int x,y;
  cout<<endl<<"Linia de sters:";
cin>>x;
for (i=x;i<n;i++)
    for(j=1;j<=n;j++)
        a[i][j]=a[i+1][j];
for(i=1;i<n;i++)
   {
   for(j=1;j<=n;j++)
       cout<<a[i][j]<<" ";
   cout<<endl;
   }
cout<<endl<<"Coloana de sters:";
cin>>y;
for(i=1;i<n;i++)
    for(j=y;j<n;j++)
         a[i][j]=a[i][j+1];
for(i=1;i<n;i++)
   {
   for(j=1;j<n;j++)
        cout<<a[i][j]<<" ";
   cout<<endl;
   }

   }
   void determinare(){
   int c,maxx,lmax;
    maxx=0;lmax=0;
   for(i=1;i<n;i++)
    { c=0;
   for(j=1;j<=n;j++)
   if (a[i][j]==1)c++;
   if(c>maxx){
        maxx=c;
   lmax=i;
   }
   }
   cout<<"Lina cu numarul maxim de zone minate: "<<lmax;
   }
   void Media(){
    int nr,s=0,k=0;
    for(i=1;i<=n;i++)
    {

        for(j=1;j<=m;j++)
            if (i%2==1)
            {
                s=s+a[i][j];
                if (a[i][j]==1) k++;
            }


   }
   cout<<"Media: "<<s/k;
   }

   void Creare(){
       ofstream g("Mine.txt");
   for( i=1;i<=n;i++)
       {for( j=1;j<=m;j++)
           if (a[i][j]==1)
        g<<a[i][j]<<" "<<endl;
  g.close();
    cout<<"\nFisierul a fost creat cu succes!\n";
}
   }



   void Obecte(int i, int j ){
   a[i][j]=0;
   if (a[i+1][j]==1)
   Obecte(i+1,j);
   if(a[i-1][j]==1)
    Obecte(i-1,j);
   if (a[i][j+1]==1)
    Obecte(i,j+1);
   if (a[i][j-1]==1)
    Obecte(i,j-1);
   }
   void afis(int i, int j ){
       int ob=0;
   for( i=1;i<=n;i++)
       for( j=1;j<=m;j++)
   if(a[i][j]==1)
   {
       ob++;
       Obecte(i,j);
   }
   cout<<"Numarul de obecte :"<<ob;
   }

int main(){
int ch;
    do {
        cout<<"\n Alegeti una dintre optiunile de mai jos:\n";
        cout<<"1: Interschimbarea in planul terenului prima cu ultima coloana \n";
        cout<<"2: Stergerea unui rand / coloana \n";
        cout<<"3: Determinarea numarul liniei cu un numar maxim de zone minate \n";
        cout<<"4: Deterimanrea medie numerilor de zone minate de pe zone impare ale terenului\n";
        cout<<"5: Lista numerilor de ordine ale coloanelor in ordine descendenta a numarului total de mine plasate pe coloanele respective \n";
        cout<<"6: Crearea fisierului Mine.txt  \n";
        cout<<"7: Determinare numarul de obiecte din matricea binara \n";
        cout<<"8: Traseu \n";
        cout<<" Introduceti numarul optiunei alese: ";
        cin>>ch;
switch (ch)
        {
            case 1:{Citirea();Interschimbarecoloana();break ;}
            case 2:{Citirea();Stergerea();break ;}
            case 3:{Citirea();determinare();break ;}
            case 4:{Citirea();Media();break ;}
            case 6:{Citirea();Creare();break ;}
            case 7:{Citirea();afis(i, j );break ;}
        }
    }
    while (ch!=0);


return 0;}

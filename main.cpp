#include <iostream>
#include <cstring>
using namespace std;

int verificremiza(char b[5][5])
{
    int i,j,ok=1;
    for(i=1;i<=3;i++)
        for(j=1;j<=3;j++)
            if(b[i][j]==' ')
                ok=0;
    return ok;
}
int verfdiagsec(char b[5][5])
{
    int ok=1,i;
    for(i=1;i<=2;i++)
        if(b[i][3-i+1]!=b[i+1][3-i] or (b[i][3-i+1]==b[i+1][3-i] and b[i][3-i+1]==' '))
            ok=0;
    if(ok==1)
        return ok;
 return ok;
}
int verfdiagp(char b[5][5])
{   int ok=1,i;
    for(i=1;i<=2;i++)
        if(b[i][i]!=b[i+1][i+1] or (b[i][i]==b[i+1][i+1] and b[i][i]==' '))
            ok=0;
    if(ok==1)
        return ok;
 return ok;
}
int verfcoloane(char b[5][5])
{    int i,j,ok=1;
     char v;
     for(j=1;j<=3;j++)
    {
        ok=1;

        for(i=1;i<=3;i++)
        {
            v=b[1][j];
            if(b[i][j]!=v or (b[i][j]==v and b[i][j]==' '))
                ok=0;
        }
        if(ok==1)
            return ok;
    }
 return ok;
}
int verflinii(char b[5][5])
{
    int ok=1,i,j;
 for(i=1;i<=3;i++)
   { ok=1;
       for(j=1;j<=2;j++)
            if(b[i][j]!=b[i][j+1] or (b[i][j]==b[i][j+1] and b[i][j]==' '))
                ok=0;
    if(ok==1)
        return ok;
   }
  return ok;
}
void afis(char a[5][5])
{
    int i,j;
        for(i=0;i<=3;i++)
    {
        for(j=0;j<=3;j++)
            cout<<a[i][j]<<' ';
        cout<<endl;
    }
}

int AI(char a[5][5],int juc,int x,int y)
{
    int i,j,ok,ok2=0;

 for(i=1;i<=3;i++) // verifica daca castiga pe linie
   {
    if(a[i][1]==a[i][2] and a[i][3]==' ' and a[i][1]=='O')
            {
                a[i][3]='O';
                return 1;
            }
     else
        if(a[i][2]==a[i][3] and a[i][1]==' ' and a[i][2]=='O')
            {
                a[i][1]='O';
                return 1;
            }
     else
        if(a[i][1]==a[i][3] and a[i][2]==' ' and a[i][1]=='O')
            {
                a[i][2]='O';
                return 1;
            }
   }
 for(j=1;j<=3;j++) //verifica daca castiga pe coloana
   {
    if(a[1][j]==a[2][j] and a[3][j]==' ' and a[1][j]=='O')
            {
                a[3][j]='O';
                return 1;
            }
     else
        if(a[2][j]==a[3][j] and a[1][j]==' ' and a[2][j]=='O')
            {
                a[1][j]='O';
                return 1;
            }
     else
        if(a[1][j]==a[3][j] and a[2][j]==' ' and a[1][j]=='O')
            {
                a[2][j]='O';
                return 1;
            }
   }

 if(a[1][1]==a[2][2] and a[3][3]==' ' and a[1][1]=='O')  //verifica daca castiga pe diag principala
        {
            a[3][3]='O';
            return 1;
        }
 else
  if(a[2][2]==a[3][3] and a[1][1]==' ' and a[2][2]=='O')
       {
           a[1][1]='O';
           return 1;
       }
  else
   if(a[1][1]==a[3][3] and a[2][2]==' ' and a[1][1]=='O')
        {
            a[2][2]='O';
            return 1;
        }

 if(a[1][3]==a[2][2] and a[3][1]==' ' and a[1][3]=='O')  //verifica daca castiga pe diag secundara
        {
            a[3][1]='O';
            return 1;
        }
 else
  if(a[2][2]==a[3][1] and a[1][3]==' ' and a[2][2]=='O')
        {
            a[1][3]='O';
            return 1;
        }
  else
   if(a[1][3]==a[3][1] and a[2][2]==' ' and a[1][3]=='O')
        {
            a[2][2]='O';
            return 1;
        }

 for(i=1;i<=3;i++) //verifica daca poate bloca jucatorul pe linie
   {
    if(a[i][1]==a[i][2] and a[i][3]==' ' and a[i][1]=='X')
            {
                a[i][3]='O';
                return 1;
            }
     else
        if(a[i][2]==a[i][3] and a[i][1]==' ' and a[i][2]=='X')
            {
                a[i][1]='O';
                return 1;
            }
     else
        if(a[i][1]==a[i][3] and a[i][2]==' ' and a[i][1]=='X')
            {
                a[i][2]='O';
                return 1;
            }
   }
 for(j=1;j<=3;j++) //verifica daca poate bloca jucatorul pe coloana
   {
    if(a[1][j]==a[2][j] and a[3][j]==' ' and a[1][j]=='X')
            {
                a[3][j]='O';
                return 1;
            }
     else
        if(a[2][j]==a[3][j] and a[1][j]==' ' and a[2][j]=='X')
            {
                a[1][j]='O';
                return 1;
            }
     else
        if(a[1][j]==a[3][j] and a[2][j]==' ' and a[1][j]=='X')
            {
                a[2][j]='O';
                return 1;
            }
   }
 if(a[1][1]==a[2][2] and a[3][3]==' ' and a[1][1]=='X')  //verifica daca poate bloca jucatorul pe diag principala
        {
            a[3][3]='O';
            return 1;
        }
 else
  if(a[2][2]==a[3][3] and a[1][1]==' ' and a[2][2]=='X')
        {
            a[1][1]='O';
            return 1;
        }
  else
   if(a[1][1]==a[3][3] and a[2][2]==' ' and a[1][1]=='X')
        {
            a[2][2]='O';
            return 1;
        }

 if(a[1][3]==a[2][2] and a[3][1]==' ' and a[1][3]=='X')  //verifica daca poate bloca jucatorul pe diag secundara
        {
            a[3][1]='O';
            return 1;
        }
 else
  if(a[2][2]==a[3][1] and a[1][3]==' ' and a[2][2]=='X')
        {
            a[1][3]='O';
            return 1;
        }
  else
   if(a[1][3]==a[3][1] and a[2][2]==' ' and a[1][3]=='X')
        {
            a[2][2]='O';
            return 1;
        }
 if(x!=y and ((x==1 and y==3)) or (x==3 and y==1) and ok2==0) //daca jucatorul a pus pe un colt prima data si pune pe mijloc
    {
    if(a[2][2]==' ')
        {
        a[2][2]='O';
        ok2=1;
        return 1;
        }
    }
 else
  if(x==y or (x==1 or x==3) and ok2==0)
     {
        if(a[2][2]==' ')
            {
            a[2][2]='O';
            return 1;
            ok2=1;
            }
     }

 if((a[1][1]=='X' and a[1][1]==a[3][3] and a[2][2]=='O') or (a[3][1]=='X' and a[3][1]==a[1][3] and a[2][2]=='O')) //verifica daca jucatorul poate face o furca si pune astfel incat sa nu il lase sa castige
    for(i=1;i<=3;i++)
      if(i%2==1)
        {
            if((a[i][2]==' ') and (a[3][2]==' '))
            {
                if(i==1)
                 a[i][2]='O';
                else
                 a[3][2]='O';
            return 1;
            }
        }
      else
        if(a[i][1]==' ' and a[i][3]==' ')
            {
               if(i==1)
                a[i][1]='O';
               else
                a[i][3]='O';
            return 1;
            }
 //creare furca
 if(a[1][1]==' ')
    {
    a[1][1]='O';
    return 1;
    }
 else
 if(a[3][3]==' ')
    {
    a[3][3]='O';
    return 1;
    }
 else
 if(a[1][3]==' ')
    {
    a[1][3]='O';
    return 1;
    }
 else
 if(a[3][1]==' ')
    {
    a[3][1]='O';
    return 1;
    }

 if(a[2][2]==' ') //verifica centrul
    {
        a[2][2]='O';
        return 1;
    }
 if(x!=y and ((x==1 and y==3)) or (x==3 and y==1)) //daca jucatorul a pus pe un colt,pune pe cel opus
    {
    if(a[y][x]==' ')
        {
        a[y][x]='O';
        return 1;
        }
    }
 else
  if(x==y and (x==1 or x==3))
     {
        if((x==1) and a[3][3]==' ')
            {
            a[3][3]='O';
            return 1;
            }
        else
         if(x==3 and a[1][1]==' ')
            {
            a[1][1]='O';
            return 1;
            }
     }

 if(a[1][1]==' ')//verificam daca vreun colt este liber si punem pe el
    {
       a[1][1]='O';
       return 1;
    }
 else
  if(a[1][3]==' ')
    {
       a[1][3]='O';
       return 1;
    }
  else
   if(a[3][1]==' ')
    {
       a[3][1]='O';
       return 1;
    }
   else
     if(a[3][3]==' ')
    {
       a[3][3]='O';
       return 1;
    }
 for(i=1;i<=3;i++) //daca nicio conditie de mai sus nu s-a indeplinit,cautam orice loc liber
    for(j=1;j<=3;j++)
        if(a[i][j]==' ')
            {
            a[i][j]='O';
            return 1;
            }
}

int main()
{
   char a[5][5],oprit;
   int i,j,ok=1,juc=1,rund=1,x,y,scor1=0,scor2=0,rem=0,onAI=0;
   a[0][0]=' ';
   a[0][1]='1';
   a[0][2]='2';
   a[0][3]='3';
   a[1][0]='1';
   a[2][0]='2';
   a[3][0]='3';
   for(i=1;i<=3;i++)
    for(j=1;j<=3;j++)
        a[i][j]=' ';
    cout<<"Jucator 1: X"<<endl<<"Jucator 2: 0"<<endl;
    cout<<"Scor: "<<scor1<<'-'<<scor2<<endl;
    cout<<"Vrei sa joci contra Gigel? ATENTIE!GIGEL ESTE CAMPION PE SATE LA X SI O!!! Scrie 1 sau 0!";
    cin>>onAI;
    cout<<"Incepe jucatorul 1"<<endl;
    while(ok)
    {
        cout<<"Runda "<<rund<<endl;
    afis(a);
     if(juc==1)
     {
        cin>>x>>y;
        while(x>4 or x<0 or y>4 or y<0 or a[x][y]!=' ' or x==0 or y==0)
        {
            cout<<endl<<"Ai introdus gresit! Incearca din nou:"<<endl;
            cin>>x>>y;
        }
        a[x][y]='X';
        if(verificremiza(a) and (verflinii(a)==0) and (verfcoloane(a)==0) and (verfdiagp(a)==0) and (verfdiagsec(a)==0))

            {
            cout<<"Remiza!"<<endl;
            ok=0;
            rem=1;
            scor1--;
            }
            else
                rem=0;
        if(rem==0)
        {
        if(verflinii(a))
            {
            cout<<"Jucatorul 1 a castigat!"<<endl;
            ok=0;
            }
        if(verfcoloane(a))
            {
            cout<<"Jucatorul 1 a castigat!"<<endl;
            ok=0;
            }
        if(verfdiagp(a))
            {
            cout<<"Jucatorul 1 a castigat!"<<endl;
            ok=0;
            }
        if(verfdiagsec(a))
            {
            cout<<"Jucatorul 1 a castigat!"<<endl;
            ok=0;
            }
        }
        if(ok==0)
           {
            afis(a);
            scor1++;
           }
        juc=2;
     }
    else
     if(onAI==1)
     {
        if(AI(a,juc,x,y))
        {
            if(verificremiza(a) and (verflinii(a)==0) and (verfcoloane(a)==0) and (verfdiagp(a)==0) and (verfdiagsec(a)==0))
                {
                cout<<"Remiza!"<<endl;
                ok=0;
                rem=1;
                scor2--;
                }
            else
                rem=0;
            if(rem==0)
            {
             if(verflinii(a))
                {
                cout<<"Gigel a castigat!"<<endl;
                ok=0;
                }
             if(verfcoloane(a))
                {
                cout<<"Gigel a castigat!"<<endl;
                ok=0;
                }
             if(verfdiagp(a))
                {
                cout<<"Gigel a castigat!"<<endl;
                ok=0;
                }
             if(verfdiagsec(a))
                {
                cout<<"Gigel a castigat!"<<endl;
                ok=0;
                }
            }
        if(ok==0)
           {
            afis(a);
            scor2++;
           }
        }
        juc=1;
     }
     else
     {
        cin>>x>>y;
        while(x>4 or x<0 or y>4 or y<0 or a[x][y]!=' ' or x==0 or y==0)
        {
            cout<<endl<<"Ai introdus gresit! Incearca din nou:"<<endl;
            cin>>x>>y;
        }
        a[x][y]='O';
        if(verificremiza(a) and (verflinii(a)==0) and (verfcoloane(a)==0) and (verfdiagp(a)==0) and (verfdiagsec(a)==0))
            {
            cout<<"Remiza!"<<endl;
            ok=0;
            rem=1;
            scor2--;
            }
            else
                rem=0;
        if(rem==0)
        {
        if(verflinii(a))
            {
            cout<<"Jucatorul 2 a castigat!"<<endl;
            ok=0;
            }
        if(verfcoloane(a))
            {
            cout<<"Jucatorul 2 a castigat!"<<endl;
            ok=0;
            }
        if(verfdiagp(a))
            {
            cout<<"Jucatorul 2 a castigat!"<<endl;
            ok=0;
            }
        if(verfdiagsec(a))
            {
            cout<<"Jucatorul 2 a castigat!"<<endl;
            ok=0;
            }

        }
        if(ok==0)
           {
            afis(a);
            scor2++;
           }
        juc=1;
     }
        if(ok==0)
        {
            cout<<endl<<"Apasati tasta Y si apoi enter pentru a continua sau apasati tasta N apoi tasta enter pentru a opri jocul"<<endl;
            cin>>oprit;
            if(oprit=='y' or oprit=='y')
            {
                ok=1;
                rund++;
            for(i=1;i<=3;i++)
                for(j=1;j<=3;j++)
                    a[i][j]=' ';
            }
            else
             ok=0;
        if(rund%2==0 and (oprit=='y' or oprit=='Y'))
           {
            juc=2;
            cout<<endl<<"Scor: "<<scor1<<'-'<<scor2<<endl;
            cout<<endl<<"Incepe jucatorul 2"<<endl;
            }
        else
        if(oprit=='y' or oprit=='y')
            {
            juc=1;
            cout<<"Scor: "<<scor1<<'-'<<scor2<<endl;
            cout<<endl<<"Incepe jucatorul 1"<<endl;
            }
        }
    cout<<endl;
    }
    return 0;
}

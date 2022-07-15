#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iomanip>
using namespace std;
int f[12],date[400];
double k;
long long i,n,m,d,tem,bi,sum;
int main()
{
    f[1]=0;
    f[2]=31;
    f[3]=60;
    f[4]=91;
    f[5]=121;
    f[6]=152;
    f[7]=182;
    f[8]=213;
    f[9]=244;
    f[10]=274;
    f[11]=305;
    f[12]=335;
    cin>>n;
    for (i=1;i<=n;i++)
    {
        cin>>m>>d;
        tem=f[m];
        tem+=d;
        date[tem]=1;
    }
    for (i=1;i<=366;i++)
    {
        if (date[i]==1)
        {
            sum=0;
        } else sum++;
        if (sum>bi) bi=sum;
    }
    k=bi*24*60*60*1.0/366;
    cout<<fixed<<setprecision(0)<<k;
} 
#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#define R register
#define MAXN 1000010 
typedef long long ll;
using namespace std;
ll n,k,m;
ll p[MAXN];
ll f[MAXN],ff[MAXN],ans[MAXN];
int main()
{
	scanf("%lld%lld%lld",&n,&k,&m);
	for(ll i=1;i<=n;i++)
	{
		scanf("%lld",&p[i]);
	}
	f[1]=k+1;
	ll l=1,r=k+1;
	for(ll i=2;i<=n;i++)//滑窗维护左右端点
	{
		while(r+1<=n&&p[i]-p[l]>p[r+1]-p[i]) l++,r++;
		if(p[i]-p[l]>=p[r]-p[i]) f[i]=l;
		else f[i]=r;
	}
	for(ll i=1;i<=n;i++) ans[i]=i;//初始跳0次
	while(m)//倍增
	{
		if(m&1) for(ll i=1;i<=n;i++) ans[i]=f[ans[i]];//更新答案
		m>>=1;
		memcpy(ff,f,sizeof(ff));
		for(ll i=1;i<=n;i++) f[i]=ff[ff[i]];//更新下一个跳到的点
	}
	for(ll i=1;i<=n;i++) printf("%lld ",ans[i]);
	return 0;//撒由那拉
}


#include<iostream>
#include<algorithm>
#include<stdio.h>
long long x,y,ix,iy,p,q,t;
bool ok2(long long k){
    return k*q-y>=k*p-x and k*p-x>=0;//见分析部分
  }
void solve(){
      long long l=1,r=0x7fffffff;//r取足够大即可
      while(l<r){
            long long mid=l+(r-l)/2;//取中间值（二分思路）
            if(ok2(mid)) r=mid;    //mid大于等于k最小值
            else l=mid+1;          //mid小于等于k最小值
        }
      printf("%lld\n",l==0x7fffffff?-1:l*q-y);//l*q-y=y';
  } 
  int main(){
      scanf("%lld",&t);//显然
      while(t--){//显然
            scanf("%lld%lld%lld%lld",&x,&y,&p,&q);//显然
            solve();//显然
        }
      return 0;
  } 


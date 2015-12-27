//
//  BulbMath.cpp
//  BitsContests
//
//  Created by Shikhar  on 27/09/15.
//  Copyright (c) 2015 Shikhar . All rights reserved.
//

#include <stdio.h>
#include <cstdio>
#include <cmath>
#define MOD 1000000007
using namespace std;
typedef long long ll;
void fastscan(int &x)
{
    bool neg=false;
    register int c;
    x =0;
    c=getchar();
    if(c=='-')
    {
        neg = true;
        c=getchar();
    }
    for(;(c>47 && c<58);c=getchar())
        x = (x<<1) + (x<<3) +c -48;
    if(neg)
        x *=-1;
}
/*ll expoent(int a,int b){
 ll result = 1;
 
 for (ll multiplier = a; b != 0; multiplier = ((multiplier%MOD)*(multiplier%MOD))%MOD, b /= 2) {
 if (b % 2 == 1) {
 result =(result%MOD* multiplier%MOD)%MOD;
 }
 }
 return result;
 }*/

int main(){
    int q;
    fastscan(q);
    while (q--) {
        int n,c;
        fastscan(n);
        fastscan(c);
        ll exp=pow(c,n);
        //cout<<exp<<endl;
        ll ans=((exp-1)/(((c-1)%MOD*(c-1)%MOD)%MOD))-((exp%MOD*(n-1)%MOD)/(c-1));
        printf("%lld\n",-ans);
    }
    
    
    return 0;
}
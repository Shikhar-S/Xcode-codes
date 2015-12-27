//
//  Comp3.cpp
//  Team
//
//  Created by Shikhar  on 20/09/15.
//  Copyright (c) 2015 Shikhar . All rights reserved.
//

#include <iostream>

#include <cmath>
#include <cstring>
#include <climits>
typedef long long ll;
using namespace std;
int t;
ll *a;
ll *b;
ll *phi;
int main(){
    
    cin>>t;
    a=new ll[t];
    b=new ll[t];
    ll max=LLONG_MIN,min=LLONG_MAX;
    for (int i=0; i<t; i++) {
        ll l,r;
        cin>>l>>r;
        a[i]=l;
        b[i]=r;
        max=r>max?r:max;
        min=l<min?l:min;
        
    }
    phi=new ll[max-min+1];
    ll c=min;
    for (ll i=0; i<(max-min+1); i++) {
        phi[i]=c;
        c++;
    }
    ll lim=(ll)sqrt(max)+1;
    bool primes[lim];
    memset(primes, true, sizeof(primes));
    
    primes[0]=false;
    primes[1]=false;
    for (ll i=2; i<lim; i++) {
        if (primes[i]) {
            for (ll j=i*2; j<lim; j+=i) {
                primes[j]=false;
            }
        }
        
    }
    
    for (ll i=2; i<lim; i++) {
        if (primes[i]) {
            for (ll j=(min/i)*i>min?((min/i)*i-min):(((min/i+1)*i)-min); j<(max-min+1); j+=i) {
                phi[j]=(phi[j]*i)/(i-1);
            }
        }
    }
    
    
    
    for (int i=0; i<t; i++)
    {
        ll c=0;
        
        ll l=a[i];
        ll r=b[i];
        
        for(ll i=l;i<=r;i++){
            
            if (i%phi[i-min]==0) {
                c++;
            }
        }
        cout<<(c)<<endl;
    }
}


//
//  main.cpp
//  SpojTeam
//
//  Created by Shikhar  on 09/09/15.
//  Copyright (c) 2015 Shikhar . All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
int main() {
    ll a,b,n;
    cin>>a>>b>>n;
    ll arr[b-a+1];
    memset(arr,0,sizeof(arr));
    for (ll i=1; i*i<=b; i++) {
        for (ll j=(a/i)*i; j<=b; j+=i) {
            if(j-a+1>=0)  arr[j-a+1]+=2;
            //if(j-a==1) cout<<i<<" ";
        }
    }
    ll c=0;
    for (ll i=0; i<b-a+1; i++) {
        //cout<<arr[i]<<" ";
        if(arr[i]==n)c++;
    }
    cout<<c<<endl;
    return 0;
}
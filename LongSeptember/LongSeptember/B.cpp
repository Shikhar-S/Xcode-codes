//
//  B.cpp
//  LongSeptember
//
//  Created by Shikhar  on 04/09/15.
//  Copyright (c) 2015 Shikhar . All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;
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
int main()
{
    int t;
    fastscan(t);
    while (t--) {
        int n,m;
        fastscan(n);
        fastscan(m);
        int arr[m];
        int ma=INT_MIN;
        for (int i=0; i<m; i++) {
            fastscan(arr[i]);
            ma=max(arr[i],ma);
        }
        int freq[ma+1];
        memset(freq, 0, sizeof(freq));
        for (int i=0; i<m; i++) {
            freq[arr[i]]++;
        }
        int ans=0;
        int c=m-1;
        for (int i=0; i<ma+1 && c>0; i++) {
            while(freq[i]-- && c>0){
                
                c-=i;
                
                ans+=i;
                if(c<0){
                    ans=ans+c;
                }
                else
                    c--;
            }
            
            
        }
        cout<<ans<<endl;
    }
}

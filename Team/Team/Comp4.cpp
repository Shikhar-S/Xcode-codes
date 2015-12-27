//  Comp4.cpp
//  Team
//
//  Created by Shikhar  on 21/09/15.
//  Copyright (c) 2015 Shikhar . All rights reserved.
#include <iostream>
#include <utility>
#include <climits>
#include <algorithm>
#include <cstring>
using namespace std;
bool comp(const pair<int, int> &a,const pair<int, int> &b){
    return a.second>b.second;
    
    
}
typedef long long ll;
int n;
ll *d;
ll *q;
pair<int, int> *p;
int main(){
    int t;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        p=new pair<int, int>[n];
        
        for (int i=0; i<n; i++) {
            int a;
            cin>>a;
            p[i].first=a;
            
        }
        for (int i=0; i<n; i++) {
            int a;
            cin>>a;
            p[i].second=a;
        }
        sort(p, p+n, comp);
        d=new ll[n+1];
        q=new ll[n+1];
        
        for (int i=0; i<=n; i++) {
            d[i]=0;
            q[i]=0;
        }
        q[1]=p[0].first;
        
        
        for (int i=1; i<=n; i++) {
            
            for (int j=1; j<=i; j++) {
                if (j==1) {
                    q[1]=max(d[1],(ll)p[i-1].first);
                    continue;
                    
                }
                q[j]=max(d[j-1]+p[i-1].first+(j-1)*p[i-1].second,d[j]);
            }
            
            for (int i=0; i<=n; i++) {
                d[i]=q[i];
            }
        }
        /*for(int i=1;i<=n;i++){
         for (int j=1; j<=i; j++) {
         cout<<dp[i][j]<<" ";
         }*/
        for (int i=1; i<=n; i++) {
            cout<<q[i]<<" ";
        }
        cout<<endl;
    }
}
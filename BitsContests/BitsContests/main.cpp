//
//  main.cpp
//  BitsContests
//
//  Created by Shikhar  on 27/09/15.
//  Copyright (c) 2015 Shikhar . All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> v[1000001];
void dfs(int x,int bitmask[]){
    
    unsigned long int n=v[x].size();
    for (int i=0; i<n; i++) {
        if (bitmask[v[x].at(i)]==0) {
            dfs(v[x].at(i),bitmask);
        }
        
    }
    bitmask[x]=1;
}


int main(){
    int t;
    cin>>t;
    while (t--) {
        int n,m;
        cin>>n>>m;
        
        for (int i=0; i<m; i++) {
            int a,b;
            cin>>a>>b;
            v[a].push_back(b);
        }
        int c=0;
        int bitmask[n+1];
        for (int i=0; i<=n; i++) {
            bitmask[i]=0;
        }
        for (int i=1; i<=n; i++) {
            if (bitmask[i]==0) {
                dfs(i,bitmask);
                c++;
            }
        }
        cout<<c<<endl;
    }
}
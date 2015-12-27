//
//  110E.cpp
//  Team
//
//  Created by Shikhar  on 16/09/15.
//  Copyright (c) 2015 Shikhar . All rights reserved.
//

#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
int checkLuck(int x){
    while (x>0) {
        if(x%10==4  || x%10==7)
            x/=10;
        else
            return 1;
    }
    return 0;
}
ll bfs(int x,vector<int> v[],bool visited[]){
    ll c=0;
    queue<int> q;
    q.push(x);
    while (!q.empty()) {
        int temp=q.front();
        visited[temp]=true;
        c++;
        q.pop();
        unsigned long int m=v[temp].size();
        for (int i=0; i<m; i++) {
            if(!visited[v[temp].at(i)])
                q.push(v[temp].at(i));
        }
        
    }
    return c;
}
ll fact(ll x){
    if(x==1)return 1;
    return x*fact(x-1);
}
int main(){
    int n;
    cin>>n;
    bool visited[n+1];
    memset(visited, false, sizeof(visited));
    vector<int> v[n+1];
    for (int i=0; i<n-1; i++) {
        int a,b,c;
        if(checkLuck(c))
        {
            v[a].push_back(b);
            v[b].push_back(a);
            
        }
    }
    vector<ll> comp;
    for (int i=1; i<=n; i++) {
        if (!visited[i]) {
            ll x=(bfs(i, v, visited));
            cout<<i<<" "<<x<<" ";
            comp.push_back(x);
        }
    }
    unsigned long int m=comp.size();
    ll ans=0;
    for (int i=0; i<m; i++) {
        //cout<<comp[i]<<" ";
        ans+=(comp[i]*fact(n-comp[i]));
    }
    cout<<ans<<endl;
    
}

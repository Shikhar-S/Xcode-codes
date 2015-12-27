//
//  474B.cpp
//  Team
//
//  Created by Shikhar  on 01/09/15.
//  Copyright (c) 2015 Shikhar . All rights reserved.
//

#include <iostream>
#include <cstring>
#include <set>
#include <climits>
using namespace std;
int main()
{
    int m,n;
    cin>>n>>m;
    set<int> v[n+1];
    for (int i=0; i<m; i++) {
        int x,y;
        cin>>x>>y;
        v[x].insert(y);
        v[y].insert(x);
    }
    int ans=INT_MAX;
    for (int i=1; i<=n; i++) {
        int k=v[i].size();
        int c=k;
        for (set<int>::iterator si=v[i].begin(); si!=v[i].end; si++) {
            
            for (set<int>::iterator ti=v[(*si)].begin(); ti!=v[(*si)].end(); ti++) {
                int temp=c+v[*si].size();
                if (v[(*ti)].find(i) != v[(*ti)].end()) {
                    temp+=v[*ti].size();
                }
                c=min(temp,c);

            }
            
            
        }
        ans=min(c,ans);
    }
    cout<<ans<<endl;
    
    
}

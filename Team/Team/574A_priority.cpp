//
//  574A_priority.cpp
//  Team
//
//  Created by Shikhar  on 06/09/15.
//  Copyright (c) 2015 Shikhar . All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;
    priority_queue<int> q;
    for (int i=1; i<n; i++) {
        int x;
        cin>>x;
        q.push(x);
    }
    int ans=0;
    while (m<=q.top()) {
        int x=q.top();
        q.pop();
        m++;
        x--;
        ans++;
        q.push(x);
        
    }
    cout<<ans;
}

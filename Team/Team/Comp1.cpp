//
//  Comp1.cpp
//  Team
//
//  Created by Shikhar  on 20/09/15.
//  Copyright (c) 2015 Shikhar . All rights reserved.
//

#include <iostream>
#include <cstring>
#include <climits>
using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--) {
        int n,k;
        cin>>n>>k;
        string s[n];
        bool out[n];
        memset(out, false, sizeof(out));
        for (int i=0; i<n; i++) {
            cin>>s[i];
        }
        for (int i=0; i<k; i++) {
            int x;
            cin>>x;
            for (int i=0; i<x; i++) {
                string temp;
                cin>>temp;
                for(int j=0;j<n;j++)
                    if(temp.compare(s[j])==0){
                        out[j]=true;
                    }
            }
            
        }
        for (int i=0; i<n; i++) {
            if(out[i])
                cout<<"YES"<<" ";
            else
                cout<<"NO"<<" ";
        }
        cout<<endl;
    }
}

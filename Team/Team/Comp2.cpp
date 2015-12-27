//
//  Comp2.cpp
//  Team
//
//  Created by Shikhar  on 20/09/15.
//  Copyright (c) 2015 Shikhar . All rights reserved.
//

#include <iostream>
#include <climits>
#include <cstring>
using namespace std;
int srch(int a[],int x,int k){
    int pos=-1;
    int l=0,r=k-1;
    while (l<=r) {
        int mid=l+(r-l)/2;
        if(a[mid]>x){
            pos=mid;
            r=mid-1;
        }
        else if(a[mid]<=x){
            l=mid+1;
        }
        
        
        
    }
    
    return pos;
}
int main(){
    int t;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        
        int top[n];
        memset(top,INT_MAX,sizeof(top));
        int y;cin>>y;
        top[0]=y;
        int k=1;
        for (int i=0; i<n-1; i++) {
            int x;
            cin>>x;
            int pos=(x>=top[k-1])?-1:srch(top,x,k);
            if(pos==-1)
            {
                top[k]=x;
                k++;
                
            }
            else
                top[pos]=x;
        }
        
        cout<<k<<" ";
        for (int i=0; i<k; i++) {
            cout<<top[i]<<" ";
        }
        cout<<endl;
    }
}

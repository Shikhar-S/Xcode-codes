//
//  CFA.cpp
//  Team
//
//  Created by Shikhar  on 22/09/15.
//  Copyright (c) 2015 Shikhar . All rights reserved.
//

#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    int m=INT_MIN;
    for (int i=0; i<n; i++) {
        cin>>arr[i];
    }
    for (int i=0; i<n;) {
        int start=i,j;
        int c=1;
        for(j=start+1;j<n;j++){
            
            if(arr[j]>=arr[j-1])
            {
                c++;
            }
            else{
                i=j;
                break;
            }
            
        }
        m=max(c,m);
        c=0;
        if(j>=n)break;
        
    }
    cout<<m;
}

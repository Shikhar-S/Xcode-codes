//
//  574Ctry2.cpp
//  Team
//
//  Created by Shikhar  on 31/08/15.
//  Copyright (c) 2015 Shikhar . All rights reserved.
//

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    int temp=-1;
    for (int i=0; i<n; i++) {
        cin>>arr[i];
        while (arr[i]%2==0 && arr[i]>0) {
            arr[i]/=2;
        }
        while (arr[i]%3==0 && arr[i]>0) {
            arr[i]/=3;
        }
        

    }
    int flag=1;
    temp=arr[0];
    for (int i=1; i<n; i++) {
        if(arr[i]!=temp){
            flag=0;break;
        }
    }
    
    
    if(flag)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}

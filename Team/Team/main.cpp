//
//  474C.cpp
//  CodeForcesTeamProblems
//
//  Created by Shikhar  on 30/08/15.
//
//

#include <iostream>
#include <cstring>
#include <climits>
typedef long long ll;
using namespace std;
int man(){
    int n;
    cin>>n;
    int arr[n];
    for (int i=0; i<n; i++) {
        cin>>arr[i];
    }
    int c=0;
    int sub[n];
    memset(sub,0,sizeof(sub));
    int l=0,r=n-1;
    int flag=1;
    while (l<=r && flag) {
        flag=0;
        for (int i=l+1; i<r; i++) {
        
            if (arr[i]>0) {
                int x=min(arr[i-1],arr[i+1]);
                
                if(x>=arr[i])sub[i]=1;
                else
                    sub[i]=(arr[i]-x);
                
                
                
            }
            
        }
        for (int i=l+1; i<r; i++) {
            //cout<<sub[i]<<" ";
            if (arr[i]>0) {
                
                arr[i]-=sub[i];
                flag+=arr[i];
            }
            
        }
        //cout<<endl;
        arr[l]=0;
        arr[r]=0;
        /*for (int x=0; x<n; x++) {
            cout<<arr[x]<<" ";
        }
        cout<<'\n';*/
        l++;r--;
        c++;
    }
    
    cout<<c<<endl;
    return 0;
}

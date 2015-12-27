//
//  WildCard.cpp
//  CookOff August
//
//  Created by Shikhar  on 23/08/15.
//
//

#include <iostream>
#include <cstring>
using namespace std;
int main(){
    int t;
    cin>>t;
    for (int i=0; i<t; ++i) {
        string a,b;
        cin>>a>>b;
        int flag=0;
        int n=a.size();
        for (int j=0; j<n; j++) {
            if (a[j]==b[j] || a[j]=='?' || b[j]=='?') {
                continue;
            }
            else{
                flag=1;
                break;
            }
            
        }
        if (flag==1) {
            cout<<"No"<<endl;
        }
        else
            cout<<"Yes"<<endl;
        
    }
}

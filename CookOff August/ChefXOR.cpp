//
//  ChefXOR.cpp
//  CookOff August
//
//  Created by Shikhar  on 24/08/15.
//
//

#include <iostream>
using namespace std;
typedef long long ll;
int main()
{
    int t;
    cin>>t;
    while (t--) {
        ll n;
        cin>>n;
        if(n%2==0){
            cout<<-1<<endl;
        }
        else{
            ll c=1;
            int flag=0;
            for (ll i=1; i<=n; i=i*2+1) {
                if (i==n) {
                    flag=1;
                    break;
                }
                
            }
            if (flag==1) {
                cout<<n/2<<endl;
                
            }
            else
                cout<<-1<<endl;
            
        }
    }
}

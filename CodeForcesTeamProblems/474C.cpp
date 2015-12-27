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
int main(){
    int n;
    cin>>n;
    int m=INT_MIN;
    int arr[n];
    for (int i=0; i<n; i++) {
        cin>>arr[i];
        m=min(m,arr[i]);
    }
    int primes[m];
    memset(primes,1,sizeof(primes));
    primes[0]=0;
    primes[1]=0;
    for (int i=2; i<m; i++) {
        if (primes[i]) {
            for (int j=i ; j<m; j=j+i ) {
                primes[j]=0;
            }
        }
        
    }
    
    int flag=1;
    for (int i=5; i<m && flag==1; i++) {
        if (primes[i]) {
            cout<<i<<" ";
            bool divided=true;
            while (divided) {
                divided=false;
                for (int j=0; j<n; j++) {
                    if(arr[0]%i==0){divided=true;}
                    if (divided^(arr[j]%i==0)) {
                        flag=0;
                        break;
                        
                    }
                    
                    if(divided)arr[j]/=i;
                    
                }
                
            }
            
            
        }
    }
    
    
    if(flag)
        cout<<"NO"<<endl;
    else
        cout<<"YES"<<endl;
}

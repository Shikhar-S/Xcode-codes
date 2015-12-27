//
//  main.cpp
//  WeekOfCode
//
//  Created by Shikhar  on 03/09/15.
//  Copyright (c) 2015 Shikhar . All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;
int calculate(int m,int y,int c){
    //cout<<m<<" "<<y<<" "<<c;
    int ans=(int)(13+int(floor(2.6*m-0.2))+y+(y/4)+(c/4)-2*c);
    while (ans<0) {
        ans+=7;
    }
    ans%=7;
        //cout<<ans<<" ";
    return ans;
}
int main(){
    int t;
    cin>>t;
    while (t--) {
        int d1,m1,y1;
        int d2,m2,y2;
        int ans=0;
        cin>>d1>>m1>>y1>>d2>>m2>>y2;
        int tempm2=(m2-2)<=0?(m2+11):m2-2;
        int tempm1=(m1-2)<=0?(m1+11):m1-2;
        for (int i=y1; i<=y2; i++) {
            
            for (int j=(i==y1)?tempm1:1; j<=(i==y2?tempm2:12); j++) {
                if((d1>13 && i==y1) || (d2<13 && i==y2))continue;
                int y,c,k;
                if(j==11 || j==12){
                    
                    y=(i-1)%100;
                    c=(i-1)/100;
                    
                }
                else
                {
                    c=i/100;
                    y=i%100;
                }
                k=calculate(j, y, c);
                if(k==5){
                    ans++;
                //    cout<<13<<"-"<<j<<"-"<<i<<endl;
                }
            }
        }
        cout<<ans<<endl;
    }
}
//
//  main.c
//  CSF222
//
//  Created by Shikhar  on 26/09/15.
//  Copyright (c) 2015 Shikhar . All rights reserved.
//
#include <stdio.h>
unsigned long long int toDecimal(int a[]){
    unsigned long long int ans=0;
    unsigned long long int e=1;
    int i;
    for (i=31; i>=0; i--) {
        ans=ans+a[i]*e;
        e=e*2;
    }
    return ans;
}

void toBinary(unsigned long long int x,int arr[]){
    int i=31;
    for (; i>=0 && x>0; i--) {
        arr[i]=x%2;
        x/=2;
    }
}

int main(){
    int A[32];
    int B[32];
    int i;
    
    int t;
    scanf("%d ",&t);
    while (t--) {
        unsigned long long int n,m;
        scanf("%llu%llu",&n,&m);
        for (i=0; i<32; i++) {
            A[i]=0;
            B[i]=0;
        }
        toBinary(n,A);
        toBinary(m,B);
        /*for (i=0; i<32; i++) {
         printf("%d ",B[i]);
         }
         printf("\n");*/
        int p[32],k[32],l[32],q[32];
        int j;
        
        for (j=0; j<32; j++) {
            k[j]=0;
            l[j]=0;
            p[j]=0;
            q[j]=0;
        }
        
        int an=0;
        for (i=0; i<32; i++) {
            if(A[i] || B[i])
                k[i]=1;
            if (A[i] && B[i]) {
                l[i]=1;
            }
            
            if (!B[i]) {
                p[i]=1;
            }
            if (A[i] && !(B[i])) {
                q[i]=1;
            }
            if (A[i]) {
                an++;
            }
            
        }
        
        printf("%llu\n",toDecimal(k));
        printf("%llu\n",toDecimal(l));
        printf("%llu\n",toDecimal(p));
        printf("%llu\n",toDecimal(q));
        printf("%d\n",an);
        
    }
    return 0;
}
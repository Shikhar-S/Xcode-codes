//
//  Gsoln.c
//  CSF222
//
//  Created by Shikhar  on 26/09/15.
//  Copyright (c) 2015 Shikhar . All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
int main(){
    int n,m;
    scanf("%d %d",&m,&n);
    int i;
    int a[n+1];
    for (i=0; i<=n; i++) {
        a[i]=0;
    }
    int flag=0;
    
    for (i=0; i<m; i++) {
        int x;
        scanf("%d",&x);
        if(x>n || x<1)flag=1;
        else if (a[x]==1) {
                flag=1;
            }
        else
            a[x]=1;
    }
    if (n<m) {
        flag=1;
    }
    
    if(flag==1)
        printf("INVALID\n");
    else
        printf("VALID\n");
    return 0;
}
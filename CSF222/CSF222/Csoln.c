//
//  Csoln.c
//  CSF222
//
//  Created by Shikhar  on 26/09/15.
//  Copyright (c) 2015 Shikhar . All rights reserved.
//

#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int a[n][n];
    int i,j;
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            scanf("%d",&a[i][j]);
        }
    }
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            if(a[i][j])
                a[j][i]=1;
            if (i==j) {
                a[i][j]=1;
            }
        }
    }
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }

    
    return 0;
}
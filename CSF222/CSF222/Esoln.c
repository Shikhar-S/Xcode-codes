//
//  Esoln.c
//  CSF222
//
//  Created by Shikhar  on 27/09/15.
//  Copyright (c) 2015 Shikhar . All rights reserved.
//

#include <stdio.h>
int n;
int srch(int arr[],int p,int x){
    int i;
    for (i=0; i<p;i++) {
        if(arr[i]==x)return i;
    }
    return -1;
}
int checkFor(int x,int arr[][n],int count,int query[],int k){
    int pos=srch(query, k, x);
    if (pos!=-1) {
        count++;
    }
    int i;
    if (count>1) {
        return count;
    }
    for (i=0; i<n; i++) {
        if (arr[x][i]) {
            int number=checkFor(i, arr, count, query, k);
            
            if (number>1) {
                return number;
            }
        }
    }
    return count;
}
int main(){
    int m,q,i,j;
    scanf("%d %d %d",&n,&m,&q);
    int arr[n][n];
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            arr[i][j]=0;
        }
    }
    for (i=0; i<m; i++) {
        int a,b;
        scanf("%d %d",&a,&b);
        a--;b--;
        arr[a][b]=1;
    }
    while (q--) {
        int x;
        scanf("%d ",&x);
        int query[x];
        for (i=0; i<x; i++) {
            query[i]=0;
        }
        for (i=0; i<x; i++) {
            scanf("%d ",&query[i]);
            query[i]--;
        }
        for (i=0; i<x; i++) {
            for (j=0; j<x-i-1; j++) {
                if (query[j]>query[j+1]) {
                    int t=query[j];
                    query[j]=query[j+1];
                    query[j+1]=t;
                }
            }
        }
        for (i=0; i<x; i++) {
            int flag=checkFor(query[i], arr, 0, query, x);
            if (flag==1) {
                printf("%d ",query[i]+1);
            }
        }
        printf("\n");
    }
    return 0;
}
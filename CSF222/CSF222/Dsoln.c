//
//  Dsoln.c
//  CSF222
//
//  Created by Shikhar  on 27/09/15.
//  Copyright (c) 2015 Shikhar . All rights reserved.
//

#include <stdio.h>
int n,counter;

void topoSort(int x,int arr[][n],int ans[],int bitmask[]){
    int i;
    for (i=n-1; i>=0; i--) {
        if (arr[x][i]==1) {
            //printf("%d\n",i);
            topoSort(i, arr,ans,bitmask);
        }
    }
    if (bitmask[x]==0) {
        ans[counter]=x;
        bitmask[x]=1;
        counter++;
    }
    
}
int main(){
    int m;
    scanf("%d %d",&n,&m);
    int arr[n][n];
    int i,j;
    int bitmask[n];
    for (i=0; i<n; i++) {
        bitmask[i]=0;
    }
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            arr[i][j]=0;
        }
    }
    for (i=0; i<m; i++) {
        int x,y;
        scanf("%d %d",&x,&y);
        x--;y--;
        arr[x][y]=1;
        
    }
    int ans[n];
    for (i=0; i<n; i++) {
        ans[i]=-1;
    }
    counter=0;
    
    for (i=n-1; i>=0; i--) {
        
        if (bitmask[i]==0) {
            topoSort(i, arr,ans,bitmask);

        }
    }
    
    
    for (i=n-1; i>=0; i--) {
        printf("%d ",ans[i]+1);
    }
    printf("\n");
    return 0;
}
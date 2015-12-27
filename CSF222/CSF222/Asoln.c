//
//  Asoln.c
//  CSF222
//
//  Created by Shikhar  on 26/09/15.
//  Copyright (c) 2015 Shikhar . All rights reserved.
//

#include <stdio.h>
int n;
int check(int arr[][n-1]){
    int i,j,flag=0;
    for (i=0; i<n-1; i++) {
        for (j=0; j<n-1; j++) {
            if (arr[i][j]!=arr[j][i]) {
                flag=1;
                return flag;
            }
            if (i==j && arr[i][j]==0) {
                flag=1;
                return flag;
            }
            
        }
    }
    return flag;
}
int main(){
    int m;
    scanf("%d %d",&n,&m);
    int arr[n][n];
    int i,j;
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            arr[i][j]=0;
        }
    }
    
    for (i=0; i<m; i++) {
        int a,b;
        scanf("%d %d",&a,&b);
        arr[a-1][b-1]=1;
    }
    
    int k;
    int ans=0;
    for (k=0; k<n; k++) {
        int a[n-1][n-1];
        int r=0,c=0;
        for (i=0; i<n; i++) {
            for (j=0; j<n; j++) {
                if (i==k || j==k) {
                    continue;
                }
                else{
                    a[r][c]=arr[i][j];
                    c++;
                    if (c>n-2) {
                        c=0;
                        r++;
                    }
                }
            }
        }
        int flag=check(a);
        
        if(flag==0)ans++;
        
    }
    printf("%d\n",ans);
    return 0;
}
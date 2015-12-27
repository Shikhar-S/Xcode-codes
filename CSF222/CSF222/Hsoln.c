//
//  Hsoln.c
//  CSF222
//
//  Created by Shikhar  on 27/09/15.
//  Copyright (c) 2015 Shikhar . All rights reserved.
//

#include <stdio.h>
int findParent(int arr[],int x){
    if (arr[x]==-1) {
        return x;
    }
    else
    {
        return findParent(arr,arr[x]);
    }
    
}
void Union(int arr[],int x,int y){
    int a,b;
    a=findParent(arr,x);
    b=findParent(arr,y);
    if(a!=b)
        arr[a]=b;
}
int main(){
    
    int m,n,i,x,y;
    char a,b;
    scanf("%d %d",&m,&n);
    int arr[m];
    for (i=0; i<m; i++) {
        arr[i]=-1;
    }
    for (i=0; i<n; i++) {
        scanf(" %c %c",&a,&b);
        x=(int)a-65;
        y=(int)b-65;
        if(x==y)continue;
        
        Union(arr,x,y);
    }
    int ans=0;
    for (i=0; i<m; i++) {
        if (arr[i]==-1) {
            ans++;
        }
    }
    printf("%d",ans);
    return 0;
}
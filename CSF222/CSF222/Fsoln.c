//
//  Fsoln.c
//  CSF222
//
//  Created by Shikhar  on 26/09/15.
//  Copyright (c) 2015 Shikhar . All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *arr;
    int i;
    arr=(int*)malloc(101*sizeof(int));
    for (i=0; i<100; i++) {
        int a,b;
        scanf("%d %d",&a,&b);
        arr[b]=a;
    }
    int t;
    scanf("%d",&t);
    while (t--) {
        int a;
        scanf("%d",&a);
        printf("%d\n",arr[a]);
    }
    return 0;
}
//
//  TopologicalSort.cpp
//  Arsenal
//
//  Created by Shikhar  on 27/09/15.
//  Copyright (c) 2015 Shikhar . All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int n;
vector<int> ans;

void toSort(int x,int **arr){
    
    for (int i=0; i<n; i++) {
        if (arr[x][i]==1) {
            arr[x][i]=0;
            ans.push_back(i);
        }
    }
    
}
int main(){
    int m;
    int **arr;
    cin>>n>>m;
    arr=new int*[n];
    for (int i=0; i<n; i++) {
        arr[i]=new int[n];
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            arr[i][j]=0;
        }
    }
    
    for (int i=0; i<m; i++) {
        int a,b;
        cin>>a>>b;
        arr[a][b]=1;
    }
    
    int i,j;
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            if (arr[j][i]==1) {
                break;
            }
        }
        if (j==n) {
            toSort(i,arr);
        }
    }
    return 0;
}

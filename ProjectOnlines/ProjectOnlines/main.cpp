//
//  main.cpp
//  ProjectOnlines
//
//  Created by Shikhar  on 06/09/15.
//  Copyright (c) 2015 Shikhar . All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
#include <queue>
#include <set>
using namespace std;

class Graph
{
    
    int V;
    vector<int> *adj;
    vector<pair<int,int> > *cost;
public:
    Graph(int V);
    void BFS(int start);
    void DFS();
    void DFSUtil(int x,bool visited[]);
    void MST(int start);
    void addEdge(int x,int y,int cst=0);
    void display(int x);
    //void addVertex(int x);
    
};

Graph::Graph(int x){
    V=x;
    adj=new vector<int>[V];
    cost=new vector<pair<int,int> >[V];
}

void Graph::display(int x){
    
}

void Graph::addEdge(int x, int y,int cst){
    adj[x].push_back(y);
    cost[x].push_back(make_pair(y,cst));
    cost[y].push_back(make_pair(x, cst));
}

void Graph::DFSUtil(int x, bool visited[]){
    visited[x]=true;
    display(x);
    unsigned long n=adj[x].size();
    for (int i=0; i<n; i++) {
        DFSUtil(adj[x].at(i), visited);
    }
}

void Graph::DFS(){
    bool visited[V+1];
    memset(visited, false, sizeof(visited));
    for (int i=1; i<=V; i++) {
        if (!visited[i]) {
            DFSUtil(i, visited);
        }
    }
    
}

void Graph::BFS(int start){
    bool visited[V+1];
    memset(visited, false, sizeof(visited));
    queue<int> q;
    q.push(start);
    visited[start]=true;
    
    while (!q.empty()) {
        int temp=q.front();
        display(temp);
        q.pop();
       unsigned long n=adj[temp].size();
        for (int i=0; i<n; i++) {
            if (!visited[adj[temp].at(i)]) {
                q.push(adj[temp].at(i));
            }
        }
    }
    
}

struct great{
    bool operator()(const pair<int, int> &a,const pair<int, int> &b){
        return a.second>b.second;
    }
};


void Graph::MST(int start){
    bool visited[V+1];
    memset(visited, false, sizeof(visited));
    priority_queue<pair<int,int>,vector<pair<int, int> >,great> pq;
    set<int> mst;
    pq.push(make_pair(start, 0));
    while (!pq.empty()) {
        pair<int, int> temp=pq.top();
        mst.insert(temp.first);
        pq.pop();
        visited[temp.first]=true;
        unsigned long n=adj[temp.first].size();
        for (int i=0; i<n; i++) {
            int x=adj[temp.first].at(i);
            if(!visited[x]){
                pq.push(cost[x].at(i));
                
                
            }
                
        }
    }
    
}


int main()
{
    
    return 0;
}

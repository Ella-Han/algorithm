//
//  main.cpp
//  baekjoon
//
//  Created by 한아름 on 24/10/2019.
//  Copyright © 2019 Ella-Han. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, S;

vector<int> adjList[1001];
bool isVisited[1001] = {false,};
queue<int> que;

void dfs(int V) {
    
    if (isVisited[V]) { return; }
    isVisited[V] = true;
    printf("%d ", V);
    
    for (int i=0; i<adjList[V].size(); i++) {
        int next = adjList[V][i];
        dfs(next);
    }
}

void bfs(int V) {
    fill_n(isVisited, 1001, false);
    
    que.push(V);
    
    while (!que.empty()) {
        int cur = que.front();
        que.pop();
        
        if (isVisited[cur]) { continue; }
        isVisited[cur] = true;
        
        printf("%d ", cur);
        
        for (int i=0; i<adjList[cur].size(); i++) {
            que.push(adjList[cur][i]);
        }
    }
}

int main() {
    scanf("%d %d %d", &N, &M, &S);
    
    for (int i=0; i<M; i++) {
        int s, e;
        scanf("%d %d", &s, &e);
        adjList[s].push_back(e);
        adjList[e].push_back(s);
    }
    
    // sort
    for (int i=0; i<1001; i++) {
        sort(adjList[i].begin(), adjList[i].end());
    }
    
    dfs(S);
    printf("\n");
    bfs(S);
    
    return 0;
}

//
//  baekjoon_1504.cpp
//  baekjoon
//
//  Created by 한아름 on 2021/04/15.
//  Copyright © 2021 Ella-Han. All rights reserved.
//
#if 1
#include <stdio.h>
#include <vector>
#include <queue>
#include <limits.h>

#define MAX_COUNT   801

using namespace std;

struct Edge {
    int to, cost;
    Edge(int _to, int _cost) {
        to = _to;
        cost = _cost;
    }
};

int N, E, V1, V2;
vector<Edge> adjList[MAX_COUNT];
priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

long long distFromS[MAX_COUNT];
long long distFromV1[MAX_COUNT];
long long distFromV2[MAX_COUNT];

bool operator > (Edge e1, Edge e2) {
    return e1.cost > e2.cost;
}

void dijkstra(int start, long long dist[MAX_COUNT]) {
    fill_n(dist, MAX_COUNT, INT_MAX);
    
    dist[start] = 0;
    pq.push(Edge(start, 0));
    
    while (!pq.empty()) {
        Edge cur = pq.top();
        pq.pop();
        
        for (int i=0; i<adjList[cur.to].size(); i++) {
            Edge next = adjList[cur.to][i];
            
            if (dist[next.to] > dist[cur.to] + next.cost) {
                dist[next.to] = dist[cur.to] + next.cost;
                pq.push(next);
            }
        }
    }
}

int main() {
    scanf("%d %d", &N, &E);
    
    for (int i=1; i<=E; i++) {
        int from, to, cost;
        scanf("%d %d %d", &from, &to, &cost);
        adjList[from].push_back(Edge(to, cost));
        adjList[to].push_back(Edge(from, cost));
    }
    
    scanf("%d %d", &V1, &V2);
    
    dijkstra(1, distFromS);
    dijkstra(V1, distFromV1);
    dijkstra(V2, distFromV2);
    
    long long ans1 = distFromS[V1] + distFromV1[V2] + distFromV2[N];
    long long ans2 = distFromS[V2] + distFromV2[V1] + distFromV1[N];
    long long answer = min(ans1, ans2);
    
    if ( answer < 0 || answer >= INT_MAX) {
        printf("%d\n", -1);
    } else {
        printf("%lld\n", answer);
    }
    
    return 0;
}

#endif

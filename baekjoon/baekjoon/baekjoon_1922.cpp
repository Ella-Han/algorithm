//
//  baekjoon_1922.cpp
//  baekjoon
//
//  Created by 한아름 on 24/10/2019.
//  Copyright © 2019 Ella-Han. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
int N, M;

struct Edge {
    int s, e, cost;
};

bool compare(Edge edge1, Edge edge2) {
    return edge1.cost < edge2.cost;
}

vector<Edge> edgeList;

struct DisjointSet { // union & find
    
    vector<int> parent;
    
    DisjointSet(int V) {
        parent.resize(V+1);
        
        for (int i=0; i<=V; i++) {
            parent[i] = i;
        }
    }
    
    int find(int V) {
        if (parent[V] == V) { return V; } // root
        else return parent[V] = find(parent[V]);
    }
    
    bool merge(int S, int E) {
        int parent_of_S = find(S);
        int parent_of_E = find(E);
        
        if (parent_of_S == parent_of_E) { return false; } // cycle
        
        parent[parent_of_S] = parent_of_E;
        return true;
    }
};

int main() {
    scanf("%d", &N);
    scanf("%d", &M);
    
    for (int i=0; i<M; i++) {
        Edge edge;
        scanf("%d %d %d", &edge.s, &edge.e, &edge.cost);
        edgeList.push_back(edge);
    }

    // sort
    sort(edgeList.begin(), edgeList.end(), compare);

    // kruskal algorithm
    // After sorting the costs in ascending order
    // we check the cycles with union & find to get the minimum spanning tree.
    
    int answer = 0;
    DisjointSet disjointSet = DisjointSet(N);
    
    for (int i=0; i<edgeList.size(); i++) {
        bool isMerged = disjointSet.merge(edgeList[i].s, edgeList[i].e);
        
        if (isMerged) {
            answer += edgeList[i].cost;
        }
    }
    
    printf("%d", answer);
    
    return 0;
}

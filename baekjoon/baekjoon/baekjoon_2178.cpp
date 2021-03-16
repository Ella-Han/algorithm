#if 0
//
//  baekjoon_2178.cpp
//  baekjoon
//
//  Created by 한아름 on 2020/10/27.
//  Copyright © 2020 Ella-Han. All rights reserved.
//

#include <stdio.h>
#include <queue>

using namespace std;

struct Edge {
    int x, y, cost;
    
    Edge(int _x, int _y, int _cost) {
        x = _x;
        y = _y;
        cost = _cost;
    }
};

int N, M;
int map[101][101] = {0, }; // 미로 행렬
int isVisited[101][101] = {false, };
queue<Edge> que;

int posX[4] = {-1, 0, 1, 0}; // 왼쪽, 위, 오른쪽, 아래
int posY[4] = {0, 1, 0, -1}; // 왼쪽, 위, 오른쪽, 아래

bool isInside(int x, int y) {
    return (x >= 1) && (x <= N) && (y >= 1) && (y <= M);
}

int bfs(int X, int Y) {
    que.push(Edge(X, Y, map[X][Y])); // 시작 위치 push
    
    while (!que.empty()) {
        Edge cur = que.front();
        que.pop();
        
        if (isVisited[cur.x][cur.y]) { continue; }
        isVisited[cur.x][cur.y] = true;
        
        if (cur.x == N && cur.y == M) { return cur.cost; } // 종료조건
        
        for (int i=0; i<4; i++) { // 왼쪽, 위, 오른쪽, 아래로 갈 수 있는지 조사
            int nextX = cur.x + posX[i];
            int nextY = cur.y + posY[i];
            
            if (isInside(nextX, nextY) == false) { continue; } // map 영역을 벗어나면 pass
            if (map[nextX][nextY] == 0) { continue; } // 이동 불가하면 pass
            que.push(Edge(nextX, nextY, cur.cost + 1)); // 이동 가능한 칸 정보(Edge)를 que에 넣는다
        }
    }
    
    return 0;
}

int main() {
    
    scanf("%d %d", &N, &M);
    
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) {
            scanf("%1d", &map[i][j]);
        }
    }
    
    int length = bfs(1, 1);
    printf("%d", length);
    
    return 0;
}
#endif

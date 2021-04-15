#if 0
//
//  baekjoon_2357_최솟값과 최댓값.cpp
//  baekjoon
//
//  Created by 한아름 on 2021/03/19.
//  Copyright © 2021 Ella-Han. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

int N, M, TN;
vector<int> minTree, maxTree;
int MAX_VAL = 0, MIN_VAL = 1000000001;

void update(int i, int data) {
    int idx = i + TN - 1;
    minTree[idx] = data;
    maxTree[idx] = data;
    
    for (int i=idx/2; i>=1; i/=2) {
        minTree[i] = min(minTree[i*2], minTree[i*2+1]);
        maxTree[i] = max(maxTree[i*2], maxTree[i*2+1]);
    }
}

void find(int a, int b) {
    int s = a + TN - 1;
    int e = b + TN - 1;
    
    while (s <= e) {
        if (s % 2 == 1) {
            MIN_VAL = min(MIN_VAL, minTree[s]);
            MAX_VAL = max(MAX_VAL, maxTree[s]);
            s++;
        }
        
        if (e % 2 == 0) {
            MIN_VAL = min(MIN_VAL, minTree[e]);
            MAX_VAL = max(MAX_VAL, maxTree[e]);
            e--;
        }
        
        s /= 2;
        e /= 2;
    }
}

int main() {
    scanf("%d %d", &N, &M);
    
    // get TN
    for (TN=1; TN<N; TN*=2);
    minTree.resize(TN*2);
    maxTree.resize(TN*2);
    
    fill_n(minTree.begin(), TN*2, 1000000001);
    fill_n(maxTree.begin(), TN*2, 0);
    
    for (int i=1; i<=N; i++) {
        int num;
        scanf("%d", &num);
        update(i, num);
    }
    
    
    for (int m=1; m<=M; m++) {
        MAX_VAL = 0;
        MIN_VAL = 1000000001;
        
        int a, b;
        scanf("%d %d", &a, &b);
        find(a, b);
        printf("%d %d\n", MIN_VAL, MAX_VAL);
    }
    
    return 0;
}
#endif

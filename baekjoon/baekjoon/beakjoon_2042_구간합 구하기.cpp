#if 0
//
//  beakjoon_2042_구간합 구하기.cpp
//  baekjoon
//
//  Created by 한아름 on 2021/01/18.
//  Copyright © 2021 Ella-Han. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

int N, M, K, TN;
vector<long long> tree;

void update(int i, long long data) {
    int w = i + TN - 1;
    tree[w] = data;
    
    for (int i = w/2; i>=1; i/=2) {
        tree[i] = tree[i*2] + tree[i*2+1];
    }
}

long long sum(long long s, long long e) {
    s = s + TN - 1;
    e = e + TN - 1;
    long long sum = 0;
    
    while (s <= e) {
        if (s%2 == 1) {
            sum += tree[s++];
        }
        
        if (e%2 == 0) {
            sum += tree[e--];
        }
        s /= 2;
        e /= 2;
    }
    
    return sum;
}

int main() {
    scanf("%d %d %d", &N, &M, &K);
    
    for (TN=1; TN<=N; TN*=2);
    tree.resize(TN*2);
    
    for (int i=1; i<=N; i++) {
        int num;
        scanf("%d", &num);
        update(i, num);
    }
    
    vector<long long> answers;
    
    for (int i=1; i<=M+K; i++) {
        long long a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        
        if (a == 1) {
            update(b, c);
        } else if (a == 2) {
            answers.push_back(sum(b, c));
        }
    }
    
    for (int i=0; i<answers.size(); i++) {
        printf("%lld\n", answers[i]);
    }
    
    return 0;
}
#endif

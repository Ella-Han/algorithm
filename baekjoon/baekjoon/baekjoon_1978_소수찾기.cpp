#if 0
//
//  baekjoon_1978_소수찾기.cpp
//  baekjoon
//
//  Created by 한아름 on 2021/01/18.
//  Copyright © 2021 Ella-Han. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include <algorithm>

#define MAX     1000

using namespace std;

bool isPrime[MAX+1];

void initPrimes() {
    fill_n(isPrime, MAX+1, true);
    isPrime[0] = isPrime[1] = false;
    
    for (int i=2; i<=sqrt(MAX); i++) {
        if (isPrime[i] == false) { continue; }
        for (int j=i+i; j<=MAX; j+=i) {
            isPrime[j] = false;
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);
    initPrimes();
    
    int primeCnt = 0;
    for (int i=1; i<=N; i++) {
        int num;
        scanf("%d", &num);
        if (isPrime[num]) {
            primeCnt++;
        }
    }
    
    printf("%d\n", primeCnt);
    
    return 0;
}
#endif

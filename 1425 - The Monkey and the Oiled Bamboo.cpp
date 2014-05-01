//Md. Khairullah Gaurab
//SUST, CSE
//20th Batch
//gaurab.cse.sust@gmail.com

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <numeric>
#include <utility>

#define sf scanf
#define pf printf

using namespace std;

template <class T> inline T fastin() {
    register char c = 0;
    register T a = 0;
    while (c < '0' || c > '9') c = getchar();
    while ('0' <= c && c <= '9') a = a * 10 + c - '0', c = getchar();
    return a;
}
int main(int argc, const char *argv[]) {
    int i, j, test, N, prev, cur, K;
    test = fastin<int>();
    for(i=1; i<=test; i++) {
        N = fastin<int>();
        K = -1;
        prev = 0;
        for(j=0; j<N; j++) {
            cur = fastin<int>();
            if((cur-prev)>K) K = (cur-prev);
            else if((cur-prev)==K) K += 1;
            prev = cur;
        }
        pf("Case %d: %d\n",i,K);
    }
    return 0;
}

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

int main(int argc, const char *argv[]) {
    int test, N, inf;
    char ch[105];
    sf("%d",&test);
    for(int i=1; i<=test; i++) {
        sf("%d",&N);
        inf = 0;
        for(int j=1; j<=N; j++) {
            sf(" %c",&ch[j]);
        }
        for(int j=1; j<=N;) {
            if(ch[j]=='#') j++;
            else {
                j+=3;
                inf++;
            }
        }
        pf("Case %d: %d\n",i,inf);
    }
    return 0;
}

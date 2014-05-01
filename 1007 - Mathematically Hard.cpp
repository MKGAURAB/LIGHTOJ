//Md. Khairullah Gaurab
//SUST, CSE
//20th Batch
//gaurab.cse.sust@gmail.com
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define sf scanf
#define pf printf

typedef unsigned long long int lli;

const int M = 5000001;

lli phi[5000001];

void Phi() {
    int i, p;
    for(i=1; i<M; i++) phi[i] = i;
    for(p=2; p<M; p++) {
        if(phi[p]==p) {
            for(i=p; i<M; i+=p) {
                phi[i] -= (phi[i]/p);
            }
        }
    }
    for(i=2; i<M; i++) {
        phi[i] *= phi[i];
        phi[i] += phi[i-1];
    }
}

int main(int argc, const char *argv[]) {
    int test, l, r, i, j;
    sf("%d",&test);
    Phi();
    for(i=1; i<=test; i++) {
        sf("%d %d",&l, &r);
        pf("Case %d: %llu\n",i,(phi[r]-phi[l-1]));
    }
    return 0;
}

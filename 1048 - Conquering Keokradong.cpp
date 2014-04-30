//Md. Khairullah Gaurab
//SUST, CSE
//20th Batch
//gaurab.cse.sust@gmail.com
#include <stdio.h>

#define sf scanf
#define pf printf


int arr[1001];

int OK(int amount, int SZ, int cam) {
    int cnt, tmp, i;
    cnt = tmp = i = 0;
    cnt++;
    while(i<SZ) {
        if(tmp+arr[i]<=amount) {
            tmp += arr[i];
        } else {
            tmp = 0;
            tmp += arr[i];
            cnt++;
        }
        i++;
    }
    if(cnt==cam) return 1;
    if(cnt<=cam) return 1;
    return 0;

}
int main() {
    int test, N, K, low, high, res, mid, i, j, pcnt;
    sf("%d",&test);
    for(i=1; i<=test; i++) {
        sf("%d %d",&N, &K);
        low = (-1*1e9);
        high = 0;
        for(j=0; j<N+1; j++) {
            sf("%d",&arr[j]);
            if(arr[j]>low) low = arr[j];
            high += arr[j];
        }
        res = high;
        while(low<=high) {
            mid = ((low+high)>>1);
            if(OK(mid,N+1,K+1)) {
                if(mid<res) res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        pf("Case %d: %d\n",i,res);
        pcnt = 0;
        high = 0;
        for(j=0; j<(N+1); j++) {
            if(high+arr[j]>res || (N-j+1)==(K-pcnt)) {
                pf("%d\n",high);
                pcnt++;
                high = arr[j];
            } else {
                high += arr[j];
            }
        }
        pf("%d\n",high);

    }
    return 0;
}

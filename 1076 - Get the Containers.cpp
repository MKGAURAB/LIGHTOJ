#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <cstdlib>
#include <map>
#include <utility>
#include <numeric>
#include <string>

#define sf scanf
#define pf printf

using namespace std;
const int SZ = 1005;

int data[SZ];
bool OK(int amount, int SZ, int vess)
{
    int cnt, tmp, i;
    cnt = tmp = i = 0;
    cnt++;
    while(i<SZ)
    {
        if(data[i]+tmp<=amount)
        {
            tmp += data[i];
        }
        else{
            cnt++;
            tmp = 0;
            tmp += data[i];
        }
        i++;
    }
    if(cnt==vess) return true;
    else if(cnt<vess) return true;
    return false;
}
int main(int argc, const char *argv[])
{
    int test, N, M, low, high, mid, res;
    sf("%d",&test);
    for(int i=1; i<=test; i++)
    {
        sf("%d %d",&N, &M);
        low = (-1*1e6);
        high = 0;
        for(int j=0; j<N; j++)
        {
            sf("%d",&data[j]);
            if(data[j]>low) low = data[j];
            high += data[j];
        }
        res = high;
        while(low<=high)
        {
            mid = (low+high)/2;
            if(OK(mid, N, M))
            {
                if(mid<res) res = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        pf("Case %d: %d\n",i,res);
    }
	return 0;
}

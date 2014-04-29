//Md. Khairullah Gaurab
//CSE, SUST
//20th Batch
//gaurab.cse.sust@gmail.com
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

int main(int argc, const char *argv[]) {
    int test, len, half, all9, mid, i;
    char str[100005];
    sf("%d",&test);
    for(int cas=1; cas<=test; cas++) {
        sf("%s",str);
        len = strlen(str);
        all9 = 1;
        half = (len>>1);
        for(i=0; i<len; i++) {
            if(str[i]!='9') all9 = 0;
        }
        if(all9) {
            str[0] = '1';
            for(i=1; i<len; i++) str[i] = '0';
            str[i+1] = str[i];
            str[i] = '1';
        } else {
            for(i=0; i<half; i++) {
                if(str[i]<str[len-i-1]) all9 = -1;
                else if(str[i]>str[len-i-1]) all9 = 1;
                str[len-i-1] = str[i];
            }
            if(len&1) mid = half;
            else mid = half - 1;
            if(all9==-1 or !all9) {
                i = 0;
                while(str[mid-i]=='9') {
                    str[mid-i] = '0';
                    str[len-1-mid+i] = '0';
                    i++;
                }
                str[mid-i]++;
                str[len-1-mid+i] = str[mid-i];
            }
        }
        pf("Case %d: %s\n",cas,str);
    }
    return 0;
}

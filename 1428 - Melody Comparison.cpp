//Md. Khairullah Gaurab
//CSE, SUST  20th
//gaurab.cse.sust@gmail.com

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <cstring>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <algorithm>


#define sf scanf
#define pf printf
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define all(a) (a.begin(),a.end())
#define REP(i,a,b) for(int i=a; i<=b; ++i)
#define REPR(i,a,b) for(int i=b; i>=a; --i)
#define mp(a,b) make_pair(a,b)
#define fs first
#define sc second
#define unq(vec) stable_sort(vec.begin(),vec.end());\
				 vec.resize(distance(vec.begin(),unique(vec.begin(),vec.end())));

using namespace std;

const int inf = 2000000000;
const int SZ = 50000;

typedef long long Long;
typedef double dd;

int plen, slen;
string pat, hay;
int inp[SZ+7], GOT[SZ+7];
struct SA
{
	const static int maxn = 150005;

	int n, m;
	int sa[maxn];       //, sa[i] = j, i from 1 to n, j from 0 to n-1
	int rank[maxn];     //, rank[i] = j, i from 0 to n-1, j from 1 to n
	int hei[maxn];      //hei[i] = LCP(suffix(sa[i-1], sa[i])
	int wa[maxn], wb[maxn], wv[maxn], wt[maxn];

	int cmp(int *r, int a, int b, int l)
	{
		return r[a]==r[b] && r[a+l]==r[b+l];
	}

	//r[], from 0 to n-1
	void build_sa(int *r, int n, int m)
	{
		r[n] = 0;
		this -> n = n;
		++ n;

		int i, j, p, *t, *x = wa, *y = wb;
		for(i = 0; i < m; i++) wt[i] = 0;
		for(i = 0; i < n; i++) wt[x[i]=r[i]]++;
		for(i = 1; i < m; i++) wt[i] += wt[i-1];
		for(i = n-1; i >= 0; i--) sa[--wt[x[i]]] = i;

		for(j=1, p=1; p < n; j*=2, m=p)
		{
			for(p=0, i=n-j; i<n; i++) y[p++] = i;
			for(i = 0; i < n; i++) if(sa[i] >= j) y[p++] = sa[i] - j;

			for(i = 0; i < n; i++) wv[i] = x[y[i]];
			for(i = 0; i < m; i++) wt[i] = 0;
			for(i = 0; i < n; i++) wt[wv[i]]++;
			for(i = 1; i < m; i++) wt[i] += wt[i-1];
			for(i = n-1; i >= 0; i--) sa[--wt[wv[i]]] = y[i];

			for(t=x,x=y,y=t, p=1, x[sa[0]]=0, i=1; i < n; i++)
				x[sa[i]] = cmp(y, sa[i-1], sa[i], j) ? p-1 : p++;
		}
		return;
	}

	void calhei(int *r)
	{
		int i, j, k = 0;
		for(i = 1; i <= n; i++) rank[sa[i]] = i;
		for(i = 0; i < n; hei[rank[i++]] = k)
			for(k?k--:0, j=sa[rank[i]-1]; r[i+k] == r[j+k]; k++);
		return;
	}
} OBJ;
void computeLPSArray(int *LPS)
{
	int i, len;
	LPS[0] = len = 0;
	i = 1;
	while(i<plen)
	{
		if(pat[i]==pat[len])
		{
			len++;
			LPS[i] = len;
			i++;
		}
		else{
			if(len!=0)
			{
				len = LPS[len-1];
			}
			else{
				LPS[i] = 0;
				i++;
			}
		}
	}
}
void KMP()
{
	int i, j, k, l;
	slen = hay.length();
	int *LPS = (int *)malloc(sizeof(int)*plen);
	computeLPSArray(LPS);
	i=j=k=l=0;
	while(i<slen)
	{
		if(hay[i]==pat[j])
		{
			i++;
			j++;
		}
		if(j==plen)
		{
			REP(k,l,i-plen)
				{
					GOT[k] = i- 2;
				}
			l = i = i - plen + 1;
			j = 0;
		}
		else if(hay[i]!=pat[j])
		{
			if(j!=0) j = LPS[j-1];
			else i++;
		}
	}
	REP(i,l,slen-1)
	{
		GOT[i] = slen - 1;
	}
	free(LPS);
}

int main(int argc, const char **argv)
{
	int test;
	sf("%d",&test);
	REP(i,1,test)
	{
		cin>>hay>>pat;
		slen = hay.length();
		plen = pat.length();
		REP(j,0,slen-1) inp[j] = hay[j];
		KMP();
		OBJ.build_sa(inp,slen,123);
		OBJ.calhei(inp);
		Long ans = 0;
		REP(j,1,slen)
		{
			int tmp = GOT[OBJ.sa[j]] - OBJ.sa[j] + 1;
			if(tmp>OBJ.hei[j]) ans += tmp - OBJ.hei[j];
		}
		pf("Case %d: %lld\n",i,ans);
	}
	return 0;
}




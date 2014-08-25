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
const int SZ = 150005;

typedef long long Long;
typedef double dd;

class data {
public:
	data();
	int abdb;
	int val;
};
data::data(void) {
	abdb = 0;
	val = 0;
}
data tree[4 * SZ + 7];

void insert(int root, int st, int ed, int pos, int stat, int val) {
	if (st == ed) {
		tree[root].abdb = stat;
		tree[root].val = val;
		return;
	}
	int left = (root << 1);
	int right = left + 1;
	int mid = ((st + ed) >> 1);
	if (pos <= mid)
		insert(left, st, mid, pos, stat, val);
	else
		insert(right, mid + 1, ed, pos, stat, val);
	tree[root].abdb = tree[left].abdb + tree[right].abdb;
}

data query(int root, int st, int ed, int pos) {
	if (st == ed) {
		data ret;
		ret.abdb = st;
		ret.val = tree[root].val;
		return ret;
	}
	int left = (root << 1);
	int right = left + 1;
	int mid = ((st + ed) >> 1);
	if (tree[left].abdb >= pos)
		return query(left, st, mid, pos);
	else
		return query(right, mid + 1, ed, pos - tree[left].abdb);
}

int main(int argc, const char **argv) {
	int test, N, Q, tmp;
	char c;
	sf("%d", &test);
	REP(i,1,test)
	{
		sf("%d %d", &N, &Q);
		REP(j,1,N)
		{
			sf("%d", &tmp);
			insert(1, 1, SZ, j, 1, tmp);
		}
		N++;
		pf("Case %d:\n", i);
		REP(j,1,Q)
		{
			sf(" %c %d", &c, &tmp);
			if (c == 'a') {
				insert(1, 1, SZ, N, 1, tmp);
				N++;
			} else {
				if (tmp > tree[1].abdb)
					pf("none\n");
				else {
					data ans = query(1, 1, SZ, tmp);
					insert(1, 1, SZ, ans.abdb, 0, ans.val);
					pf("%d\n", ans.val);
				}
			}
		}
		mem(tree, 0);
	}
	return 0;
}


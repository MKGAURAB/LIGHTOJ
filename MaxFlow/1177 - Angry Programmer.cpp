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

// Implementation of min cost max flow algorithm using adjacency
// matrix (Edmonds and Karp 1972).  This implementation keeps track of
// forward and reverse edges separately (so you can set cap[i][j] !=
// cap[j][i]).  For a regular max flow, set all edge costs to 0.
//
// Running time, O(|V|^2) cost per augmentation
//     max flow:           O(|V|^3) augmentations
//     min cost max flow:  O(|V|^4 * MAX_EDGE_COST) augmentations
//
// INPUT:
//     - graph, constructed using AddEdge()
//     - source
//     - sink
//
// OUTPUT:
//     - (maximum flow value, minimum cost value)
//     - To obtain the actual flow, look at positive values only.
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long L;
typedef vector<L> VL;
typedef vector<VL> VVL;
typedef pair<int, int> PII;
typedef vector<PII> VPII;

const L INF = numeric_limits<L>::max() / 4;

struct MinCostMaxFlow {
	int N;
	VVL cap, flow, cost;
	VI found;
	VL dist, pi, width;
	VPII dad;

	MinCostMaxFlow(int N) :
			N(N), cap(N, VL(N)), flow(N, VL(N)), cost(N, VL(N)), found(N), dist(
					N), pi(N), width(N), dad(N) {
	}

	void AddEdge(int from, int to, L cap, L cost) {
		this->cap[from][to] = cap;
		this->cost[from][to] = cost;
	}

	void Relax(int s, int k, L cap, L cost, int dir) {
		L val = dist[s] + pi[s] - pi[k] + cost;
		if (cap && val < dist[k]) {
			dist[k] = val;
			dad[k] = make_pair(s, dir);
			width[k] = min(cap, width[s]);
		}
	}

	L Dijkstra(int s, int t) {
		fill(found.begin(), found.end(), false);
		fill(dist.begin(), dist.end(), INF);
		fill(width.begin(), width.end(), 0);
		dist[s] = 0;
		width[s] = INF;

		while (s != -1) {
			int best = -1;
			found[s] = true;
			for (int k = 0; k < N; k++) {
				if (found[k])
					continue;
				Relax(s, k, cap[s][k] - flow[s][k], cost[s][k], 1);
				Relax(s, k, flow[k][s], -cost[k][s], -1);
				if (best == -1 || dist[k] < dist[best])
					best = k;
			}
			s = best;
		}

		for (int k = 0; k < N; k++)
			pi[k] = min(pi[k] + dist[k], INF);
		return width[t];
	}

	pair<L, L> GetMaxFlow(int s, int t) {
		L totflow = 0, totcost = 0;
		while (L amt = Dijkstra(s, t)) {
			totflow += amt;
			for (int x = t; x != s; x = dad[x].first) {
				if (dad[x].second == 1) {
					flow[dad[x].first][x] += amt;
					totcost += amt * cost[dad[x].first][x];
				} else {
					flow[x][dad[x].first] -= amt;
					totcost -= amt * cost[x][dad[x].first];
				}
			}
		}
		return make_pair(totflow, totcost);
	}
};

int main(int argc, const char **argv) {
	int test, u, v, N, M, cap, src, snk;
	sf("%d", &test);
	REP(i,1,test)
	{
		sf("%d %d", &N, &M);
		src = 1;
		snk = 2 * N;
		MinCostMaxFlow OBJ(snk + 1);
		OBJ.AddEdge(1, N + 1, INF, 0);
		OBJ.AddEdge(N + 1, 1, 0, 0);
		OBJ.AddEdge(N, N + N, INF, 0);
		OBJ.AddEdge(N + N, N, 0, 0);
		REP(j,2,N-1)
		{
			sf("%d", &cap);
			OBJ.AddEdge(j, j + N, cap, 0);
			OBJ.AddEdge(j + N, j, 0, 0);
		}
		REP(j,1,M)
		{
			sf("%d %d %d", &u, &v, &cap);
			OBJ.AddEdge(u + N, v, cap, 0);
			OBJ.AddEdge(v, u + N, 0, 0);
			OBJ.AddEdge(v + N, u, cap, 0);
			OBJ.AddEdge(u, v + N, 0, 0);

		}
		pair<L, L> pp = OBJ.GetMaxFlow(src, snk);
		pf("Case %d: %lld\n", i, pp.fs);
	}
	return 0;
}

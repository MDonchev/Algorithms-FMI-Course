#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;


struct State {
  int to, len;
  bool operator<(const State &other) const { return len > other.len; }
};

int N, M, K;
vector<vector<State>> graph;
int dist[10010];
bool used[10010];

void dijkstra(int start) {
  priority_queue<State> pq;

  pq.push(State{start, 0});
  dist[start] = 0;

  while (!pq.empty()) {
    int v = pq.top().to;
    pq.pop();
    if (used[v]) {
      continue;
    }
    used[v] = true;
    for (const State &s : graph[v]) {
      if (!used[s.to] && dist[v] + s.len < dist[s.to]) {
        dist[s.to] = dist[v] + s.len;
        pq.push(State{s.to, dist[s.to]});
      }
    }
  }
}

void cheating() {
	scanf("%d %d %d", &N, &M, &K);
	graph.resize(N+1);
	int from, to;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &from, &to);
		graph[from].push_back(State{ to, 0 });
		graph[to].push_back(State{ from, 0 });
	}
	for (int i = 0; i < K; i++) {
		scanf("%d %d", &from, &to);
		graph[from].push_back(State{ to, 1 });
		graph[to].push_back(State{ from, 1 });
	}
	memset(dist, 63, sizeof(dist));
	dijkstra(0);
	printf("%d\n", used[N - 1] ? dist[N - 1] : -1);
}

int main() {
  cheating();
  return 0;
}

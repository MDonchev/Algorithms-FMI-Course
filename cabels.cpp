#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

const int MAXN = 1001;

struct Edge
{
    int from, to, price;
    Edge( int f, int t, int p ) : from(f), to(t), price(p) {}
    bool operator<( const Edge& e ) const
    {
        return price > e.price;
    }
};

struct State
{
    int to, price;
    State( int t, int p ) : to(t), price(p) {}
};

int N, M;
vector <State> v[MAXN];
vector <Edge> edges;
void input()
{
    scanf("%d %d", &N, &M);
    int from, to, price;
    for( int i = 0; i < M; i++ )
    {
        scanf("%d %d %d", &from, &to, &price);
        v[from-1].push_back(State(to-1, price));
        v[to-1].push_back(State(from-1, price));
    }
}

bool used[MAXN];
void prim()
{
    priority_queue <Edge> pq;
    int start_vertex = 0;
    for( int i = 0; i < v[start_vertex].size(); i++ )
    {
        pq.push(Edge(start_vertex, v[start_vertex][i].to, v[start_vertex][i].price));
    }

    used[start_vertex] = 1;

    int sum = -1;
    while( !pq.empty() )
    {
        int from = pq.top().from;
        int to = pq.top().to;
        int price = pq.top().price;
        pq.pop();

        if( used[to] )
            continue;

        used[to] = 1;
        sum = price;

        for( int i = 0; i < v[to].size(); i++ )
        {
            int next = v[to][i].to;
            int priceToNext = v[to][i].price;
            if( !used[next] )
            {
                pq.push(Edge(to, next, priceToNext));
            }
        }
    }

    printf("%d\n", sum);
}

int main()
{

    input();
    prim();

    return 0;
}


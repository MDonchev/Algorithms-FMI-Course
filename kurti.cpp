#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 1000;

struct Edge
{
    int from, to, price;
    Edge( int f, int t, int p ) : from(f), to(t), price(p) {}
    bool operator<( const Edge& e ) const
    {
        return price < e.price;
    }
};

int N, M;
vector <Edge> edges;
int parent[MAXN], rankk[MAXN];

void input()
{
    scanf("%d %d", &N, &M);
    int from, to, price;
    for( int i = 0; i < M; i++ )
    {
        scanf("%d %d %d", &from, &to, &price);
        edges.push_back(Edge(from-1, to-1, price));
    }

    for( int i = 0; i < N; i++ )
        parent[i] = i;

    for( int i = 0; i < N; i++ )
        rankk[i] = 1;
}

int findParent( int node )
{
    if( parent[node] == node )
    {
        return node;
    }

    return parent[node] = findParent(parent[node]); /// path compression
}

void unionTrees( int p1, int p2 )
{
    /// parent[p1] = p2; // you can use that instead of union-by-rank

    /// union-by-rank
    if( rankk[p1] == rankk[p2] )
    {
        parent[p1] = p2;
        rankk[p2]++;
    }
    else if( rankk[p1] < rankk[p2] )
    {
        parent[p1] = p2;
    }
    else
    {
        parent[p2] = p1;
    }
}

void kruskal()
{
    sort(edges.begin(), edges.end());
    int br = 0;
    int i = 0;
    int sum = -1;
    while ( br < N-1 )
    {
        int p1 = findParent(edges[i].from);
        int p2 = findParent(edges[i].to);
        if( p1 != p2 )
        {
            br++;
            unionTrees(p1, p2);
            sum = edges[i].price;
        }
        i++;
    }

    printf("%d\n", sum);
}


int main()
{
    input();
    kruskal();

    return 0;
}

#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

struct Vertex
{
    int row;
    int col;
    int level;
    Vertex(int r,int c,int l) : row(r), col(c), level(l) {}
};

int n,m;
int startX,startY,endX,endY, endX2, endY2;
int graph[1001][1001];
bool vis[1001][1001];

int bfs(int row, int col, int rowEnd, int colEnd)
{
    memset(vis,0,sizeof(vis));

    queue<Vertex> q;
    q.push(Vertex(row,col,0));

    int ans = 0;

    while(!q.empty())
    {
        Vertex vertex = q.front();
        q.pop();

        if(vertex.row == rowEnd && vertex.col == colEnd)
            return vertex.level;

        if (vis[vertex.row][vertex.col]) continue;

        vis[vertex.row][vertex.col] = 1;

        if (vertex.row - 2 >= 0 && vertex.row - 2 < n && vertex.col - 1 >= 0 && vertex.col - 1 < m && !vis[vertex.row - 2][vertex.col - 1])
            q.push(Vertex(vertex.row - 2, vertex.col - 1, vertex.level + 1));
        if (vertex.row - 2 >= 0 && vertex.row - 2 < n && vertex.col + 1 >= 0 && vertex.col + 1 < m && !vis[vertex.row - 2][vertex.col + 1])
            q.push(Vertex(vertex.row - 2, vertex.col + 1, vertex.level + 1));
        if (vertex.row - 1 >= 0 && vertex.row - 1 < n && vertex.col - 2 >= 0 && vertex.col - 2 < m && !vis[vertex.row - 1][vertex.col - 2])
            q.push(Vertex(vertex.row - 1, vertex.col - 2, vertex.level + 1));
        if (vertex.row - 1 >= 0 && vertex.row - 1 < n && vertex.col + 2 >= 0 && vertex.col + 2 < m && !vis[vertex.row - 1][vertex.col + 2])
            q.push(Vertex(vertex.row - 1, vertex.col + 2, vertex.level + 1));
        if (vertex.row + 1 >= 0 && vertex.row + 1 < n && vertex.col - 2 >= 0 && vertex.col - 2 < m && !vis[vertex.row + 1][vertex.col - 2])
            q.push(Vertex(vertex.row + 1, vertex.col - 2, vertex.level + 1));
        if (vertex.row + 1 >= 0 && vertex.row + 1 < n && vertex.col + 2 >= 0 && vertex.col + 2 < m && !vis[vertex.row + 1][vertex.col + 2])
            q.push(Vertex(vertex.row + 1, vertex.col + 2, vertex.level + 1));
        if (vertex.row + 2 >= 0 && vertex.row + 2 < n && vertex.col - 1 >= 0 && vertex.col - 1 < m && !vis[vertex.row + 2][vertex.col - 1])
            q.push(Vertex(vertex.row + 2, vertex.col - 1, vertex.level + 1));
        if (vertex.row + 2 >= 0 && vertex.row + 2 < n && vertex.col + 1 >= 0 && vertex.col + 1 < m && !vis[vertex.row + 2][vertex.col + 1])
            q.push(Vertex(vertex.row + 2, vertex.col + 1, vertex.level + 1));
    }
}
int main()
{
    scanf("%d %d", &n, &m);
    scanf("%d %d",&startX,&startY);
    scanf("%d %d",&endX,&endY);
    scanf("%d %d",&endX2,&endY2);


    int bfs1 = bfs(startX,startY,endX,endY);
    int bfs2 = bfs(startX,startY,endX2,endY2);

    int res = min(bfs1,bfs2);
    if(bfs1 > bfs2) res+=bfs(endX2,endY2,endX,endY);
    else res+=bfs(endX,endY,endX2,endY2);

    printf("%d\n",res);



    return 0;
}

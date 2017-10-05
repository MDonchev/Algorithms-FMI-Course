#include <iostream>
#include <vector>
#include <cstdio>

int n,m;
bool used[500];
int conected = 0;
std::vector<int> a[500];

void in()
{
    scanf("%d %d",&n,&m);
    for (int i=0; i<m; i++)
    {
        int v1,v2;
        scanf("%d %d", &v1,&v2);
        a[v1 - 1].push_back(v2-1);
        a[v2 - 1].push_back(v1-1);
    }
}
void dfs(int i)
{
    used[i] = true;
    for (std::vector<int>::iterator it = a[i].begin() ; it != a[i].end(); ++it)
    {
        if (used[*it] == false)
        {
            used[*it] = true;
            dfs(*it);
        }
    }
}
void solve()
{
    for (int i=0; i<n; i++)
    {
        if (used[i] == false)
        {
            used[i] = true;
            conected += 1;
            dfs(i);
        }
    }
    printf("%d\n", conected);
}
int main ()
{
    in();
    solve();
    return 0;
}

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstdio>
int n;
int a[10001];

void putThisElement(int i)
{ while (i > 0 && a[i] < a[i - 1])
  { std::swap(a[i], a[i - 1]);
    i--;
  }
}
double med = 0;
void solve()
{
    std::cout<<std::fixed;
    scanf("%d", &n);
    for(int i=0;i<n-1;i++)
    {
        scanf("%d",&a[i]);
        putThisElement(i);
        med = 0;
        if (i % 2 == 0)
        {
            med = (double)a[i/2];
            std::cout<<std::setprecision(1)<<med<<" ";
        }
        else
        {
            med = (double)(a[i/2] + a[i/2 + 1])/2;
            std::cout<<std::setprecision(1)<<med<<" ";
        }
    }
    scanf("%d",&a[n-1]);
    putThisElement(n-1);
    med = 0;
    if ((n-1) % 2 == 0)
    {
        med = (double)a[(n-1)/2];
        std::cout<<std::setprecision(1)<<med<<std::endl;
    }
    else
    {
        med = (double)(a[(n-1)/2] + a[(n-1)/2 + 1])/2;
        std::cout<<std::setprecision(1)<<med<<std::endl;
    }
}
int main()
{
    solve();
    return 0;
}

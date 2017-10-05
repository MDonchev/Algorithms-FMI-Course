#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct Date
{
    int year;
    int month;
    int day;
    int place;
    bool operator<= (const Date& other) const
    {
        if (year == other.year)
        {
            if (month == other.month)
            {
                return day <= other.day;
            }
            return month<=other.month;
        }
        return year<=other.year;
    }
};
Date a[100];
Date a1[50],a2[50];
char c;
int n;
void in()
{
    scanf("%d\n",&n);
    for (int i=0;i<n;i++)
    {
        scanf("%d%c%d%c%d", &a[i].day, &c , &a[i].month, &c , &a[i].year);
        a[i].place = i+1;
    }
}
void mergeSortedParts(int l, int m, int r)
{ for (int i = l; i < m; i++)
    a1[i - l] = a[i];

  for (int i = m; i < r; i++)
    a2[i - m] = a[i];

  int ind1 = 0, ind2 = 0;
  for (int i = l; i < r; i++)
  { if (ind1 >= m - l && ind2 < r - m)
      a[i] = a2[ind2++];

    else if (ind2 >= r - m && ind1 < m - l)
      a[i] = a1[ind1++];

    else
    { if (a1[ind1] <= a2[ind2])
        a[i] = a1[ind1++];

      else a[i] = a2[ind2++];
    }
  }
}

void mergeSort(int l, int r)
{ if (r - l <= 1)
    return;

  mergeSort(l, l + (r - l) / 2);
  mergeSort(l + (r - l) / 2, r);
  mergeSortedParts(l, l + (r - l) / 2, r);
}

void out()
{
    for (int i=0;i<n;i++)
    {
        printf("%d\n", a[i].place);
    }
}


int main ()
{
    in();
    mergeSort(0,n);
    out();
    return 0;
}
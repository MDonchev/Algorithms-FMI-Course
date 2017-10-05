#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstring>
struct Agent
{
        char name[1000000];
        int buffer[53] = {0};
        bool operator<(const Agent& other) const
        {
            for(int i=0; i<53; i++)
            {
                if(buffer[i]>other.buffer[i]) return true;
                else if(buffer[i]<other.buffer[i]) return false;
            }
            return false;
        }
        void fullBuffer()
        {
            int len = strlen(name);
            for (int it = 0; it <= len; it++)
            {
                if ('A' <= name[it] && name[it] <= 'Z') buffer[name[it]-'A']++;
                else if (name[it] == '_') buffer[26]++;
                else buffer[name[it]-'a'+27]++;
            }
        }
};
int n;
int main ()
{
    scanf("%d",&n);
    std::vector<Agent> v(n);
    std::sort(v.begin(),v.end());
    for(int i=0;i<n;i++)
    {
        printf("%s\n",v[i].name);
    }

    return 0;
}

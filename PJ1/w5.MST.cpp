#include <bits/stdc++.h>
using namespace std;
const int N=100010;

int p[N];
vector<pair<int,pair<int,int>>> e;

int find(int x)
{
    if(x!=p[x]) p[x]=find(p[x]);
    return p[x];
}

void kruskal(int n,int m)
{
    sort(e.begin(),e.end());
    for(int i=1;i<=n;i++) p[i]=i;
    int cnt=0,ans=0;
    for(int i=0;i<m;i++)
    {
        int u=e[i].second.first,v=e[i].second.second,w=e[i].first;
        int t1=find(u),t2=find(v);
        if(t1!=t2)
        {
            p[t1]=t2;
            ans+=w;
            cnt++;
        }
        if(cnt==n-1) break;
    }
    cout<<ans<<endl;
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        e.push_back({w,{u,v}});
    }
    kruskal(n,m);
    return 0;
}

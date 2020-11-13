#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 200005
#define pb push_back
int i,j,n,m,k,s,t;
int f[maxn],c[maxn],cha[maxn];
ll kq=0;
struct ii
{
    int v,id;
};
vector <ii> a[maxn];
void nhap()
{
    freopen("maxflow.inp","r",stdin);
    freopen("maxflow.out","w",stdout);
    scanf("%d %d %d %d",&n,&m,&s,&t);
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        scanf("%d %d %d",&x,&y,&z);
        a[x].pb({y,i}); f[i]=0; c[i]=z;
        a[y].pb({x,i+m}); f[i+m]=0; c[i+m]=0;
    }
}
int check()
{
    queue <ll> st;
    for(int i=1;i<=n;i++) cha[i]=0;
    st.push(s); cha[s]=s;
    while(!st.empty())
    {
        int u=st.front(); st.pop();
        for(int i=0;i<a[u].size();i++)
        {
            int v=a[u][i].v; int id=a[u][i].id;
            if(cha[v]==0 && c[id]>f[id])
            {
                cha[v]=u;
                st.push(v);
                if(v==t) return 1;
            }
        }
    }
    return 0;
}
void solve()
{
    stack <int> st;
    int v=t; int minn=1e9;
    while(v!=s)
    {
        int u=cha[v];
        for(int i=0;i<a[u].size();i++)
        {
            int id=a[u][i].id;
            if(v==a[u][i].v && c[id]>f[id])
            {
                st.push(id); minn=min(minn,c[id]-f[id]);
                break;
            }
        }
        v=cha[v];
    }
    while(!st.empty())
    {
        int id=st.top(); st.pop();
        f[id]+=minn;
        if(id>m) f[id-m]-=minn;
        else f[id+m]-=minn;
    }
    kq+=minn;
}
void xuli()
{
    while (check()==1) solve();
    cout<<kq;
}
int main()
{
    nhap();
    xuli();
}

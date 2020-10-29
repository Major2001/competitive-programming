//  ||  || |____|  //
//  ||  ||   ||   // 
//  \\__//   ||  // 
#include<bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#include <bitset>
#define mp make_pair
#define F first
#define S second
#define vll vector <ll>
#define mll map <ll,ll>
#define pb push_back
#define pf push_front
#define popf pop_front
#define popb pop_back
#define M 1000000007
#define INT_BITS 32
#define SIZE_INT sizeof(int) * 8
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define test ll t;cin>>(t);while(t--)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

#define f(a, b) for (ll i = a; i < b; i++)
#define fr(a, b) for (ll j = a; j >= b; j--)
#define fi(a, b) for (ll j = a; j < b; j++)
#define fii(a, b) for (ll k = a; k < b; k++)
#define forab(i,a,b,c) for(ll (i) = a ; (i) <= (b) ; (i)+=(c))

using namespace std;
void start()
{
    fast;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

/***********************************************************************************************************/
vll adj[100001];
ll vis[100001]={0};
ll c=0;

ll dfs(ll x)
{
    vis[x]=1;
    c++;
    f(0,adj[x].size())
    {
        if(vis[adj[x][i]]==0)
            dfs(adj[x][i]);
    }
    return c;
}
int main()
{
    start();
    test
    {
        ll n,m; cin>>n>>m;
        f(1,n+1)
        {    
            vis[i]=0;
            adj[i].clear();
        }
        f(0,m)
        {
            ll x,y; cin>>x>>y;
            adj[x].pb(y);
            adj[y].pb(x);
        }
        ll ans1=0,ans2=1;
        f(1,n+1)
        {
            if(vis[i]==0)
            {
                ans1++;
                c=0;
                ans2=(ans2*dfs(i))%M;
            }
        }
        cout<<ans1<<" "<<ans2<<"\n";
    }
    return 0;
}
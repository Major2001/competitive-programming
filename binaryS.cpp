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
#define ub upper_bound
#define lb lower_bound
#define popf pop_front
#define popb pop_back
#define M 1000000007
#define M1 998244353
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
ll check(ll x,ll y)
{
    cout<<"? "<<x<<" "<<y<<endl;
    fflush(stdout);
    string s; cin>>s;
    if(s[0]=='Y')
    	return 1;
    return 0;
}
ll solve1(ll h)
{
	ll l=0;
	ll ans=-1,c;
	while(l<=h)
	{
		ll m = (l+h)/2;
		ans=check(0,m);
		if(ans==1)
		{
		    l=m+1;
		    c=m;
		}
		else
			h=m-1;
	}
	return c;
}
ll solve2(ll h)
{
	ll l=0;
	ll ans=-1,c;
	while(l<=h)
	{
		ll m = (l+h)/2;
		ans = check(m,0);
		if(ans==1)
		{
		    l=m+1;
		    c=m;
		}
		else
			h=m-1;
	}	
	return c;
}
ll solve3(ll h,ll k)
{
	ll l=k/2;
	ll ans=-1,c;
	while(l<=h)
	{
		ll m = (l+h)/2;
		ans=check(m,k);
		if(ans==1)
		{
		    l=m+1;
		    c=m;
		}
		else
			h=m-1;
	}
	return c;
}
int main()
{
	start();
    ll x = 1000, y = 1000;
    ll x1,x2,x3;
    x1 = solve1(y);
    x2 = solve2(x);
    x2*=2;
    ll k = x1-x2;
    x3 = solve3(x,x2);
    ll ans= (x2*x2+x3*k); 
    cout<<"! "<<ans<<endl;
    fflush(stdout);
    return 0;
}
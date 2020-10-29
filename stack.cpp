// ||  || |____| //
// ||  ||   ||  // 
// \\__//   || // 
#include<bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#include <bitset>
#define mp make_pair
#define vll vector <ll>
#define pb push_back
#define M 1000000007
#define INT_BITS 32
#define SIZE_INT sizeof(int) * 8
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define test ll t;read(t);while(t--)

#define f(a, b) for (ll i = a; i < b; i++)
#define fr(a, b) for (ll j = a; j >= b; j--)
#define fi(a, b) for (ll j = a; j < b; j++)
#define fii(a, b) for (ll k = a; k < b; k++)
#define forab(i,a,b,c) for(ll (i) = a ; (i) <= (b) ; (i)+=(c))

using namespace std;
template <typename T>
void read(T &x){
    cin >> x;
}

template <typename T , typename T0>
void read(T &x,T0 &y){
    cin >> x >> y;
}
 
template <typename T , typename T0 , typename T1>
void read(T &x,T0 &y,T1 &z){
    cin >> x >> y >> z;
}

template <typename T , typename T0 , typename T1 , typename T2>
void read(T &x,T0 &y,T1 &z,T2 &w){
    cin >> x >> y >> z >> w;
}

template <typename T>
void write1(T &x){
    cout << x << " ";
}

template <typename T>
void write(T &x){
    cout << x << "\n";
}
 
template <typename T , typename T0>
void write(T &x,T0 &y){
    cout << x << " " << y << "\n";
}
 
template <typename T , typename T0 , typename T1>
void write(T &x,T0 &y,T1 &z){
    cout << x << " " << y << " " << z << "\n";
}
 
template <typename T , typename T0 , typename T1 , typename T2>
void write(T &x,T0 &y,T1 &z,T2 &w){
    cout << x << " " << y << " " << z << " " << w << "\n";
}

//GCD of 2 numbers START
int gcd(int a, int b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b); 
}


//LCM of two numbers STARTS
ll lcm(ll a, ll b){
    return a / __gcd(a, b) * b;
}

//Check Prime STARTS
int isPrime(ll n) 
{  
    if((n%2==0 && n!=2) || n==1)
    return 0;
    for (ll i=3;i*i<=n;i+=2) 
        {
            if (n%i==0) 
            return 0; 
        }
    return 1; 
}

//BINARY SEARCH STARTS
int BS(int a[], int l, int r, int find) 
{ 
   if (l<=r) 
   { 
      int mid=(l + r)/2; 
      if (a[mid]==find)   
         return mid ; 
      if (a[mid]>find)
         return BS(a,l,mid-1,find);            
      if (a[mid]<find)
         return BS(a,mid+1,r,find); 
   } 
   return -1; 
} 


//POWER function STARTS
ll power(ll x, ll y) 
{ 
    ll temp; 
    if( y == 0) 
        return 1; 
    temp = power(x, y/2); 
    if (y%2 == 0) 
        return temp*temp; 
    else
        return x*temp*temp; 
}

//BINARY TO DECIMAL STARTS
int binaryToDecimal(ll n) 
{ 
    ll num = n, dec_value = 0,base = 1; 
    ll temp = num; 
    while (temp) { 
        int last_digit = temp % 10; 
        temp = temp / 10; 
  
        dec_value += last_digit * base; 
  
        base = base * 2; 
    } 
    return dec_value; 
}


//Count set Bits function STARTS
ll countSetBits(ll n) {
    if (n == 0) 
        return 0; 
    else
        return 1 + countSetBits(n & (n - 1)); 
}

//START CODE
int main()
{
    fast;
    ll n; cin>>n;
    ll depth=0,posdepth=0,length=0,poslength=0;
    stack<int> s;
    ll size,top;
    f(1,n+1)
	{
		ll a; cin>>a;
		if(a==1)
		{
			s.push(i);
			size=s.size();
			if(size>depth)
			{
				depth=size;
				posdepth=i;
			}
		}
		// 1 2 1 1 2 2 1 2 1 1  2  1  2  2  1  1  2  1  2  2
		// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
		
		// 1 1 2 1 2 2
		// 1 2 3 4 5 6
		else if(a==2)
		{
			top=s.top();
			s.pop();
			if(s.empty())
			{
				size=i-top+1;
				if(size>length)
				{
					length=size;
					poslength=top;
				}
			}
		}
	}
	write(depth,posdepth,length,poslength);
    return 0;
}
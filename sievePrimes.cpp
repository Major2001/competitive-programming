// ||  || |____| //
// ||  ||   ||  // 
// \\__//   || // 
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#define ordered_set tree<ll, null_type,greater_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>
typedef long long int ll;
typedef long double ld;
#include <bitset>
#define mp make_pair
#define F first
#define S second
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
using namespace __gnu_pbds;
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
int IsPrime(ll n) 
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


//SIEVE
int sieve(ll N) {
        bool isPrime[N+1];
        for(ll i = 0; i <= N;++i) {
            isPrime[i] = true;
        }
        isPrime[0] = false;
        isPrime[1] = false;
        for(ll i = 2; i * i <= N; ++i) {
             if(isPrime[i] == true) {                    //Mark all the multiples of i as composite numbers
                 for(int j = i * i; j <= N ;j += i)
                     isPrime[j] = false;
            }
        }
    //Count
        /*ll c=0;
        for (int p=2; p<=N; p++) 
        {
            if (isPrime[p]) 
            c++;
        }
        return  c;*/
    //print
        /*for (int p=2; p<=N; p++) 
        {
            if (isPrime[p]) 
          cout << p << " "; 
        }
        return 0;
        */
    }
    
    
// nCr CAL in O(k) STARTS
int nCr(ll n, ll r)  
{  
    ll res = 1;  
    if ( r > n - r )  
        r = n-r;  
    for (ll i = 0; i < r; ++i)  
    {  
        res *= (n - i);  //general term (n-x)/(1+x)
        res /= (i + 1);  
    }  
    return res;  
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

//BINARY EXPO
ll binaryExponentiation(ll x,ll n)
{
    if(n==0)
        return 1;
    else if(n%2 == 0)        //n is even
        return binaryExponentiation(x*x,n/2);
    else                             //n is odd
        return x*binaryExponentiation(x*x,(n-1)/2);
}

//MODULAR EXPO
ll modularExponentiation(ll x,ll n,ll Mod)
{
    if(n==0)
        return 1;
    else if(n%2 == 0)        //n is even
        return modularExponentiation((x*x)%Mod,n/2,Mod);
    else                             //n is odd
        return (x*modularExponentiation((x*x)%Mod,(n-1)/2,Mod))%Mod;

}

//FERMAS LITTLE THEORM 
ll Ferma(ll A,ll Mod)
{               // works only if  M is prime or else go for Euclid.
    return modularExponentiation(A,Mod-2,Mod);
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
    ll primefac[100001]={0};
        for(ll i=2;i<100001;i++)
        {
            if(primefac[i]==0)
            {
                for(ll j=i;j<100001;j+=i)
                    primefac[j]++;       
            }
        }
    test
    {
        ll a,b,k; read(a,b,k);
        ll c=0;
        for(int i=a;i<=b;i++)
        {
            if(primefac[i]==k)
            c++;
        }
        write(c);
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array
#define forn(i,n) for(int i=0;i<(int)n;++i)
const int mxn=1e7+1;
const int mod=1e9+7;
vector<ll>primes;

ll modexp(ll a,ll b)
{
    a=a%mod;
    if(!a) return 0;
    ll ans=1;
    while(b)
    {
        if(b&1) ans=(ans*a)%mod;
        a=(a*a)%mod;
        b/=2;
    }
    return ans%mod;
}

void seive()
{
    vector<int>p(mxn,0);
    for(ll i=2;i<=mxn;++i)
    {
        if(i*i>mxn) break;
        if(!p[i])
        {
            for(ll j=i*i;j<=mxn;j+=i)
                p[j]=1;
        }
    }
    for(int i=2;i<=mxn;++i) if(!p[i])primes.push_back(i);

}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    seive();
    int n;cin>>n;
    int arr[n];
    ll ans=1;
    for(int i=0;i<n;++i){
        ll x;cin>>x;
        ans=(ans*modexp(primes[i],x))%mod;
    }
    ll res=1;
    for(ll i=1;i<=ans;++i) if(!(ans%i)) res=(res*i)%mod;
    map<int,int>mp;
    while(res&1^1) mp[2]++,res/=2;
    for(int i=3;i*i<=res;i+=2)
    {
        while(!(res%i)) mp[i]++,res/=i;
    } 
    if(res>2) mp[res]++;
    ans=1;
    for(auto x:mp)
        ans=(ans*(x.second+1))%mod;
    cout<<ans;

}
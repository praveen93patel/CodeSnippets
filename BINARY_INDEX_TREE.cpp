#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

typedef long long ll;

#define MAXN 100005

ll tree[MAXN], A[MAXN], B[MAXN];
ll N;

ll read(ll idx)
{
    ll sum=0;
    while(idx>0)
    {
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

void update(ll idx, ll val)
{
    while(idx<=N)
    {
        tree[idx] += val;
        idx += (idx & -idx);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin>>N;
    for(int i=0; i<N; ++i)
    {
        cin>>A[i];
        B[i] = A[i];
    }
    sort(B, B+N);
    for(int i=0; i<N; ++i)
        A[i] = (int)(lower_bound(B, B+N, A[i]) - B) + 1;

    //Example: Inversion count <O(NlogN)>

    ll inv_count = 0;
    for(int i=N-1; i>=0; --i)
    {
        ll x = read(A[i]-1);
        inv_count += x;
        update(A[i], 1);
    }
    cout<<inv_count<<endl;
    return 0;
}

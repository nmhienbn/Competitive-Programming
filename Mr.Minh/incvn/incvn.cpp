#include <bits/stdc++.h>
#define fi(i,a,b) for(int i=a; i<=b; i++)
#define fid(i,a,b) for(int i=a; i>=b; i--)
#define fir first
#define se second
#define bit(i,j) ((i>>j)&1)
#define bit2(i) (1<<(i-1))
#define ll long long
#define pii pair<int,int>
#define pb push_back
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

#define maxn 10005
#define maxm 100006
#define mod 5000000
#define Seraphine "incvn"

using namespace std;

int n, k, a[maxn], bit[maxm][55];

void update(int x, int k, int val){
    while (x <= 1e5+1){
        bit[x][k] += val;
        bit[x][k] %= mod;
        x += x & -x;
    }
}

int get(int x, int k){
    int ans = 0;
    while (x > 0){
        ans += bit[x][k];
        ans %= mod;
        x -= x & -x;
    }
    return ans;
}

int main(){
    faster
    freopen(Seraphine".inp","r",stdin);
    freopen(Seraphine".out","w",stdout);
    cin >> n >> k;
    fi(i, 1, n){
        cin >> a[i];
        a[i]++;
    }
    fi(i, 1, n){
        update(a[i], 1, 1);
        fi(j, 2, min(i, k)){
            int l = get(a[i] - 1, j-1);
            update(a[i], j, l);
        }
    }
    cout << get(1e5+2, k);
}

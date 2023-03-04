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

#define maxn 100005
#define maxm 1000006
#define MOD 1000003
#define base 31
#define Seraphine "dtksub"

using namespace std;

int n, k;
string s;
ll h[maxn], t[maxn];
int cnt[MOD];

ll get_hash(int l, int r){
    return (h[r] - h[l-1]*t[r-l+1] + 1ll*MOD*MOD) % MOD;
}

bool check(int g){
    memset(cnt, 0, sizeof(cnt));
    fi(i, 1, n-g+1){
        cnt[get_hash(i, i+g-1)]++;
        if (cnt[get_hash(i, i+g-1)] >= k) return 1;
    }
    return 0;
}

int main(){
    faster
    freopen(Seraphine".inp","r",stdin);
    freopen(Seraphine".out","w",stdout);
    cin >> n >> k;
    cin >> s;
    s = ' ' + s;
    t[0] = 1;
    fi(i, 1, n){
        h[i] = (h[i-1]*base + s[i]) % MOD;
        t[i] = t[i-1]*base % MOD;
    }
    int d = 0, c = n;
    while (d <= c){
        int g = (d + c) >> 1;
        if (check(g)) d = g+1;
        else c = g-1;
    }
    cout << c;
}

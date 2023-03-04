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
#define MOD
#define Seraphine "nkseq"

using namespace std;

int n, a[maxn], res;
ll s[maxn*2], mins[maxn*2];

int main(){
    faster
    freopen(Seraphine".inp","r",stdin);
    freopen(Seraphine".out","w",stdout);
    cin >> n;
    fi(i, 1, n) cin >> a[i];
    fi(i, 1, n*2){
        s[i] = s[i-1] + a[(i-1)%n + 1];
    }
    mins[n*2] = s[n*2];
    fid(i, n*2 - 1, 1){
        mins[i] = min(mins[i+1], s[i]);
    }
    fi(i, 1, n){
        if (s[i-1] < mins[i]) res++;
    }
    cout << res;
}

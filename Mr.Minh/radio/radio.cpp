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
#define Seraphine "radio"

using namespace std;

int n, t[maxn], Ll[maxn], Lr[maxn], Rl[maxn], Rr[maxn];
ll res[maxn];

void sub1(){
    fi(i, 2, n) res[i] = 1e18;
    fi(i, 1, n){
        fi(j, Rl[i], Rr[i]){
            if (Ll[j] <= i && i <= Lr[j]){
                res[j] = min(res[j], res[i] + t[i] + j-i + t[j]);
            }
        }
    }
    fi(i, 2, n) cout << res[i] << ' ';
}



int main(){
    faster
    freopen(Seraphine".inp","r",stdin);
    freopen(Seraphine".out","w",stdout);
    cin >> n;
    fi(i, 1, n){
        cin >> t[i] >> Ll[i] >> Lr[i] >> Rl[i] >> Rr[i];
    }
    if (n <= 5000){
        sub1();
    }
}

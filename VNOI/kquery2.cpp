#include <bits/stdc++.h>
#define in ({int x=0;int c=getchar(),n=0;for(;!isdigit(c);c=getchar()) n=(c=='-');for(;isdigit(c);c=getchar()) x=x*10+c-'0';n?-x:x;})
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "kquery2"
const int maxn = 3e4 + 5, maxm = 174, maxa = 1e4;
using namespace std;

int n, a[maxn], SB, block;
int q;
int bit[maxm + 5][maxa + 5];

int inB(int x){
    return x / SB + (x % SB > 0);
}

void update(int x, int y, int add){
    while (x <= block){
        int i = y;
        while (i <= maxa){
            bit[x][i] += add;
            i += i & -i;
        }
        x += x & -x;
    }
}

int get(int x, int y){
    if (y == maxa) return x * SB;
    int ans = 0;
    while (x > 0){
        int i = y;
        while (i > 0){
            ans += bit[x][i];
            i -= i & -i;
        }
        x -= x & -x;
    }
    return ans;
}

int query(int i, int u, int j, int v){
    if (i > j || u > v) return 0;
    return get(j, v) - get(j, u - 1) - get(i - 1, v) + get(i - 1, u - 1);
}

int main(){
    ios_base::sync_with_stdio(0);
    //cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    n = in;
    SB = sqrt(n);
    block = inB(n);
    fi(i, 1, n){
        a[i] = in;
        update(inB(i), a[i], 1);
    }
    q = in;
    while (q--){
        bool typ;
        typ = in;
        if (!typ){
            int i = in, v = in;
            update(inB(i), a[i], -1);
            update(inB(i), v, 1);
            a[i] = v;
        }
        else {
            int l = in, r = in, k = in, ans = 0;
            int L = inB(l), R = inB(r);
            if (L == R){
                fi(i, l, r) ans += (a[i] > k);
                cout << ans << '\n';
                continue;
            }
            ans = query(L + 1, k + 1, R - 1, maxa);
            fi(i, l, L * SB) ans += a[i] > k;
            fi(i, (R - 1) * SB + 1, r) ans += a[i] > k;
            cout << ans << '\n';
        }
    }
}

#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "snum"
const int maxn = 1500;

using namespace std;

int s[maxn], l, r, L[maxn], a[25], c, b[25];
ll resl, resr, res;

bool instack[maxn];
int dfs(int u){
    instack[u] = 1;
    int v = s[u];
    if (L[v] != -1){
        instack[u] = 0;
        return L[u] = L[v];
    }
    if (instack[v]){
        instack[u] = 0;
        return L[u] = 0;
    }
    return L[u] = dfs(v);
}

void prepare(){
    fi(i, 1, 1458){
        s[i] = s[i/10] + (i%10) * (i%10);
    }
    fi(i, 1, 1458){
        L[i] = -1;
    }
    L[1] = 1;
    fi(i, 2, 1458){
        if (L[i] == -1){
            dfs(i);
        }
    }
}

ll f[maxn];

void process(int t){
    int sum = 0;
    fi(i, 0, 1458) f[i] = 0;
    fi(i, 1, t){
        sum += b[i]*b[i];
    }
    f[sum] = 1;
    fi(i, t+1, c){
        fid(j, 1458, 1){
            fi(k, 1, 9){
                if (j >= k*k){
                    f[j] += f[j-k*k];
                }
            }
        }
    }
    fi(i, 1, 1458) if (L[i]) res += f[i];
}

void backtrack(int i){
    fi(j, 0, a[i]){
        b[i] = j;
        if (b[i] < a[i] || i == c){
            process(i);
        }
        else {
            backtrack(i+1);
        }
    }
}

void calc(int n){
    res = 0;
    if (n == 0) return;
    if (n == 1e18) n--, res++;
    c = min(log10(n) + 1, double(18));
    fid(i, c, 1){
        a[i] = n%10;
        n /= 10;
    }
    backtrack(1);
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    prepare();
    cin >> l >> r;
    calc(r);
    resr = res;
    calc(l-1);
    resl = res;
    cout << resr - resl;
}

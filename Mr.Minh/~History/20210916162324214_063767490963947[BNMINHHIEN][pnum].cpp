#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "pnum"
const int maxn = 200;

using namespace std;

int p[maxn], t, c;
ll res;
void Erathosenes(){
    int n = 162, m = 13;
    fi(i, 1, n) p[i] = i;
    fi(i, 2, m) if (p[i] == i){
        for (int j = i*i; j <= n; j += i){
            p[j] = i;
        }
    }
    p[0] = p[1] = -1;
}

int a[20], b[20];
ll L[maxn];
bool flag = 1;

void xuli(int t){
    fi(i, 0, 162) L[i] = 0;
    int sum = 0;
    fi(i, 1, t) sum += b[i];
    L[sum] = 1;
    fi(i, t+1, c){
        fid(j, 162, 1){
            fi(k, 1, 9){
                L[j] += L[j - k];
            }
        }
    }
    fi(i, 1, 162) if (p[i] == i && L[i]) res += L[i];
}

void ql(int i){
    fi(j, 0, a[i]){
        b[i] = j;
        if (b[i] < a[i] || i == c){
            xuli(i);
        }
        else ql(i+1);
    }
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    Erathosenes();
    cin >> t;
    while (t--){
        res = 0;
        ll n;
        cin >> n;
        if (n == 1000000000000000000) n--;
        c = log10(n) + 1;
        fi(i, 0, 19) a[i] = b[i] = 0;
        fid(i, c, 1){
            a[i] = n%10;
            n /= 10;
        }
        ql(1);
        cout << res << '\n';
    }
    /*fi(i, 1, 1e6){
        s[i] = s[i/10] + i%10;
        if (p[s[i]] == s[i]) res++;
    }
    cout << res;*/
}

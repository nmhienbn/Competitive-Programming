#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "mass1"
const int maxn = 1e6 + 6;
using namespace std;

int n, a[maxn], nex[maxn], las[maxn], peak[maxn];
string s;

int solve(){
    a[0] = 0;
    fi(i, 1, n){
        a[i] = a[i - 1] + (s[i - 1] == '1' ? 1 : -1);
    }
    int amin = *min_element(a + 1, a + n + 1);
    fi(i, 0, n) a[i] -= amin;
    fi(i, 0, n) las[i] = -1;
    fid(i, n, 0){
        nex[i] = las[a[i]];
        las[a[i]] = i;
    }
    fi(i, 0, n) peak[i] = i;
    int tpeak = n, res = 0;
    fid(i, n - 1, 0){
        if (s[i] == '1'){
            if (~nex[i] && a[peak[nex[i]]] >= a[tpeak])
                tpeak = peak[nex[i]];
            peak[i] = tpeak;
            res = max(res, tpeak - i);
        }
        else tpeak = i;
    }

//    int pmin = n;
//    fi(i, 0, n - 1){
//        p[i + 1] = p[i] + (s[i] == '1' ? 1 : -1);
//        pmin = min(pmin, p[i]);
//    }
//    fi(i, 0, n) p[i] = p[i] - pmin, cout << p[i] << ' '; cout << endl;
//    fill(las, las + n + 1, -1);
//    for(int i = n; i >= 0; i--) {
//        nex[i] = las[p[i]];
//        las[p[i]] = i;
//        cout << nex[i] << ' ';
//    }
//    cout << endl;
//    int res = 0, tpeak = n;
//    iota(peak, peak + n + 1, 0);
//    for(int i = n - 1; i >= 0; i--){
//        if(s[i] == '1') {
//            if(nex[i] != -1 && p[peak[nex[i]]] >= p[tpeak])
//                tpeak = peak[nex[i]];
//            peak[i] = tpeak;
//            res = max(res, tpeak - i);
//        }
//        else
//            tpeak = i;
//        cout << peak[i] << ' ';
//    }
//    cout << endl;
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    while (true){
        cin >> n;
        if (!n) break;
        cin >> s;
        cout << solve() << '\n';
    }
}

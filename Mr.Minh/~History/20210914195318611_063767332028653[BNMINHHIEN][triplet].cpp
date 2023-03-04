#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "triplet"
const int maxn = 0;

using namespace std;

int a, A, b, B, c, C, res;

int main(){
    faster
    freopen(Seraphine".in", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> a >> A >> b >> B >> c >> C;
    int uu = sqrt(C);
    fi(i, a, min(A, uu)){
        int bb = max((c-1)/i + 1, b), BB = min(C/i, B);
        if (bb <= BB) res += BB - bb + 1;
    }
    fi(i, b, min(B, uu)){
        int aa = max((c-1)/i + 1, a), AA = min(C/i, A);
        if (aa <= AA) res += AA - aa + 1;
    }
    if (uu*uu == C) res--;
    cout << res;
}

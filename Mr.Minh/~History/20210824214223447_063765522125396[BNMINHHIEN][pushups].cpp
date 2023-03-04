#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "pushups"
const int maxn = 5005;

using namespace std;

int L[maxn], T[maxn], a[15], m, n;

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> m;
    fi(i, 1, n) L[i] = -1;
    fi(i, 1, m){
        cin >> a[i];
    }
    fi(i, 0, n){
        if (L[i] != -1) fi(j, 1, m){
            if (L[i] + a[j] > L[i + (T[i]+1) * a[j]]){
                L[i + (T[i]+1) * a[j]] = L[i] + a[j];
                T[i + (T[i]+1) * a[j]] = T[i] + 1;
            }
        }
    }
    cout << L[n];
}

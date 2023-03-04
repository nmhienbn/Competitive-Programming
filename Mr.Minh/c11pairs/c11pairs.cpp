#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "c11pairs"
const int maxn = 5e5+5;

using namespace std;

int n, st[maxn], top;
ll res;
map<int, int> cnt;

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n;
    while (n--){
        int x;
        cin >> x;
        while (st[top] < x && top > 0){
            cnt[st[top]]--;
            top--;
            res++;
        }
        if (top > 0){
            res += (x == st[top] ? cnt[x] + (top > cnt[x]) : 1);
        }
        st[++top] = x;
        cnt[x]++;
    }
    cout << res;
}

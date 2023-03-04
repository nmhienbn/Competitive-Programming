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
#define Seraphine "digit0"

using namespace std;

int n, cnt[26];

int vp(int n, int p){
    int ans = 0;
    while (n > 0){
        ans += n/p;
        n /= p;
    }
    return ans;
}

int p2, p5;

int main(){
    faster
    freopen(Seraphine".inp","r",stdin);
    freopen(Seraphine".out","w",stdout);
    string s;
    cin >> s;
    n = s.size();
    for (auto c : s){
        cnt[c - 'a']++;
    }
    p2 = vp(n, 2);
    p5 = vp(n, 5);
    fi(i, 0, 25){
        p2 -= vp(cnt[i], 2);
        p5 -= vp(cnt[i], 5);
    }
    cout << min(p2, p5);
}

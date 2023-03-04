#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia ""

using namespace std;

string s1, s2;
bool kt[200];
int n, m;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
//    freopen(Irelia".inp", "r", stdin);
//    freopen(Irelia".out", "w", stdout);
    getline(cin, s1);
    getline(cin, s2);
    n = s1.size();
    m = s2.size();
    s1 += '.';
    s2 += '.';
    int i = 0, j = 0;
    while (i < n){
        int cnt1 = 1, cnt2 = 1;
        while (s1[i] == s1[i + 1]) i++, cnt1++;
        while (s2[j] == s2[j + 1]) j++, cnt2++;
        if (cnt2 == cnt1 * 2) kt[s1[i]] = 1;
        i++;
        j++;
    }
    fi(i, 1, 150) if (kt[i]) cout << char(i);
}

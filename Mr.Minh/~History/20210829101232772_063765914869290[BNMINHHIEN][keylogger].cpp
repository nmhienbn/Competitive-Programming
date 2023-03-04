#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "keylogger"
const int maxn = 1e6+5;

using namespace std;

char c;
list<char> a;

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    auto x = a.begin();
    while (cin >> c){
        //cout << a.size() << ' ' << c << '\n';
        //cout << *x;
        if (c == '<'){
            if (x != a.begin()) x--;
        }
        else if (c == '>'){
            if (x != a.end()) x++;
        }
        else if (c == '-'){
            if (x != a.begin()){
                x--;
                x = a.erase(x);
            }
            //cout << *x;
            //cout << (x == a.begin());
        }
        else {
            //cout << (x == a.begin());
            a.insert(x, c);
        }

    }
    //cout << a.size();
    for (auto t : a) cout << t;
}

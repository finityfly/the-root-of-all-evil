typedef long long ll;

class Solution {
public:
    ll countCommas(ll n) {
        ll res = 0, thres = 1000;
        while (n >= thres) {
            res += (n - thres + 1);
            thres *= 1000;
        }
        return res;
    }
};
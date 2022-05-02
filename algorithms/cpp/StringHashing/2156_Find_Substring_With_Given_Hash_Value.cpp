class Solution {
public:
    int64_t bigPow(int64_t a, int64_t n, int64_t m) {
        a %= m;
        int64_t ret = 1;
        while (n) {
            if (n & 1) ret = (ret * a) % m;
            a = (a * a) % m;
            n >>= 1;
        }
        return ret;
    }
    
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        int n = (int)s.length();
        reverse(s.begin(), s.end());
        int64_t powK1 = bigPow(power, k-1, modulo);
        
        int64_t hash = 0;
        for (int i = 0; i < k; i++) 
            hash = ((hash * power) + (s[i]-'a'+1)) % modulo;
        
        int startIndex = -1;
        for (int i = 0; i <= n-k; i++) {
            //printf("%d %lld\n", i, hash);
            
            if (hash == hashValue) startIndex = i;
            
            if (i < n-k) {
                hash = (((hash - (s[i]-'a'+1)*powK1) % modulo) * power) % modulo;
                hash = (hash + (s[i+k]-'a'+1)) % modulo;
                if (hash < 0) hash += modulo;
            }
        }
        string ret = s.substr(startIndex, k);
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

/**

01234567
leetcode
edocteel

8-2 = 6

hash(s, p, m) = (val(s[0]) * p0 + val(s[1]) * p1 + ... + val(s[k-1]) * pk-1) mod m.

Using the mentioned hash formula you can't apply rolling hash. To apply rolling hash you have to calculate hash by below method - 

m * p^5 + a * p^4 + h * p^3 + b * p^2 + u * p^1 + b * p^0

So if you reverse the string, then you can calculate rolling hash.


(hash - val[i]) / p * val[i+k] * p^(k-1)

**/


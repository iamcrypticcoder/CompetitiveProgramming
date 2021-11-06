1. Basic Sieve
2. Optimized Sieve
3. Bitwise Sieve
4. Primality Check
5. Prime Factorization
6. Number of Divisors
7. Number of Divisors from 1 to N
8. Sum of Divisors of N
9. Sum of Divisors from 1 to N
10. Euler Totient Function of N
11. Euler Totient Function from 1 to N





### 1. Basic Sieve:

```cpp
const int MAX_PRIME = 1e7;
vector<bool> flag;
vector<int> primes;

// Time Complexity: O(n log log n)
void sieveBasic() {
    flag = vector<bool>(MAX_PRIME+7, false);
    flag[0] = flag[1] = true;       // Not prime
    int i = 2;
    while (i * i <= MAX_PRIME) {
        for (int j = i*i; j <= MAX_PRIME; j += i)
            flag[j] = true;
        while(flag[++i]);
    }
    primes.push_back(2);
    for (i = 3; i <= MAX_PRIME; i += 2)
        if (!flag[i]) primes.push_back(i);
}
```





### 2. Optimized Sieve:

```cpp
const int MAX_PRIME = 1e7;
vector<bool> flag;
vector<int> primes;

// Time Complexity: O(n log log n)
void sieveOptimized() {
    flag = vector<bool>(MAX_PRIME+7, false);
    flag[0] = flag[1] = true;       // Not prime
    for (int i = 3; i*i <= MAX_PRIME; i += 2) {
        if (!flag[i]) {
            for (int j = i*i; j <= MAX_PRIME; j += 2*i)
                flag[j] = true;
        }
    }
    primes.push_back(2);
    for (int i = 3; i <= MAX_PRIME; i += 2) {
        if (!flag[i]) primes.push_back(i);
    }
}
```



### 3. Bitwise Sieve:

```cpp
typedef long long LL;
typedef unsigned long long ULL;

const int MAX_PRIME = 1e7;
ULL bitFlag[MAX_PRIME / 64 + 7];
vector<int> primes;

void sieveBitwise()
{
    for (int i = 3; i*i <= MAX_PRIME; i += 2) {
        if ((bitFlag[i/64] & (1LL << (i%64))) == 0) {
            for (ULL j = i*i; j <= MAX_PRIME; j += 2*i) {
                bitFlag[(j/64)] |= (1L << (j%64));
            }
        }
    }
    primes.push_back(2);
    for (ULL i = 3; i <= MAX_PRIME; i += 2)
        if ((bitFlag[i/64] & (1L << (i%64))) == 0) primes.push_back(i);
}
```





### 4. Primality Check:

```cpp
// Time Complexity: O(sqrt n)
bool isPrime(long long n) {
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    if(n <= MAX_PRIME) return (!flag[n]);
    int root = sqrt(n);
    for(int i = 0; primes[i] <= root; i++)
        if(n % primes[i] == 0) return false;
    return true;
}
```



### 5. Prime Factorization:

```cpp
// Time Complexity: O(sqrt n)
vector<long long> factorize(long long n) {
    if (n < 2) return {n};
    vector<long long> ret;
    int root = sqrt((double)n);
    for(int i=0; primes[i] <= root; i++) {
        if (n % primes[i] != 0) continue;
        while(n % primes[i] == 0) {
            n /= primes[i];
            ret.push_back(primes[i]);
        }
        if (n == 1 || isPrime(n)) break;
    }
    if(n > 1) ret.push_back(n);
    return ret;
}

// Time Complexity: O(sqrt n)
// Return prime factorization as p1^a1 * p2*a2 * p3^a3 ... pn*an
vector<pair<int, int>> factorizeAsPower(long long n) {
    if (n < 2) return {{n, 1}};
    vector<pair<int, int>> ret;
    int root = sqrt((double)n);
    for(int i = 0; primes[i] <= root; i++) {
        if (n % primes[i] != 0) continue;
        int power = 0;
        while(!(n % primes[i])) { n /= primes[i]; power++; }
        ret.push_back({primes[i], power});
        if (n == 1 || isPrime(n)) break;
    }
    if(n > 1) ret.push_back({n, 1});
    return ret;
}
```



### 6. Number of Divisors:

```cpp
// Time complexity: O(sqrt n)
int countDivisors(long long n) {
    if(n == 0) return 0;
    int ret = 1;
    int root = sqrt((double)n);
    for(int i = 0; primes[i] <= root; i++) {
        if (n % primes[i] != 0) continue;
        int power = 0;
        while(!(n % primes[i])) { n /= primes[i]; power++; }
        ret *= (power + 1);
        if (n == 1 || isPrime(n)) break;
    }
    if(n > 1) ret *= 2;
    return ret;
}
```



### 7. Number of Divisors from 1 to N:

```cpp
const int MAX = 1e7;
unsigned int bigPrime[MAX + 7];
unsigned long long tau[MAX + 7];

// Time complexity: O(n log log n)
void preCalTau() {
    memset(bigPrime, 0, sizeof(bigPrime));
    int root = (int)sqrt(MAX);
    for (int i = 2; i <= MAX; ++i) {
        if (bigPrime[i] == 0) {
            bigPrime[i] = i;
            if (i > root) continue;
            for (int j = i*i; j <= MAX; j += i)
                bigPrime[j] = i;
        }
    }
    tau[0] = 0, tau[1] = 1;
    for (int i = 2; i <= MAX; ++i) {
        int p = bigPrime[i];
        int power = 0;
        int tmp = i;
        while (tmp % p == 0) { power++; tmp /= p; }
        tau[i] = (power + 1) * tau[tmp];
    }
}
```



### 8. Sum of Divisors of N:

```cpp
// Time complexity: O(sqrt n)
long long sumDivisors(long long n) {
    if(n == 0) return 0;
    long long ret = 1;
    int root = (int)sqrt((double)n);
    for(int i = 0; primes[i] <= root; i++) {
        if (n % primes[i] != 0) continue;
        int pi = primes[i];
        LL tmp = pi;
        while(n % pi == 0) { n /= pi; tmp *= pi; }
        ret *= (tmp - 1) / (pi - 1);
        if (n == 1 || isPrime(n)) break;
    }
    if(n > 1) ret *= (n*n - 1) / (n - 1);
    return ret;
}
```



### 9. Sum of Divisors from 1 to N:

```cpp
const int MAX = 1e7;
unsigned int bigPrime[MAX + 7];
unsigned long long sigma[MAX + 7];

// Time complexity: O(n log log n)
void preCalSigma() {
    memset(bigPrime, 0, sizeof(bigPrime));
    int root = (int)sqrt(MAX);
    for (int i = 2; i <= MAX; ++i) {
        if (bigPrime[i] == 0) {
            bigPrime[i] = i;
            if (i > root) continue;
            for (int j = i*i; j <= MAX; j += i)
                bigPrime[j] = i;
        }
    }
    sigma[0] = 0, sigma[1] = 1;
    for (int i = 2; i <= MAX; ++i) {
        int p = bigPrime[i];
        int pa = p;
        int tmp = i;
        while (tmp % p == 0) { pa *= p; tmp /= p; }
        sigma[i] = (pa - 1) / (p - 1) * sigma[tmp];
    }
}
```



### 10. Euler Totient Function of N

```cpp
// Time complexity: O(sqrt n)
long long eulerPhi(long long n) {
    long long ret = n;
    int root = (int)sqrt((double)n);
    for(int i=0; primes[i] <= root; i++) {
        if (n % primes[i] != 0) continue;
        int pi = primes[i];
        while(n % pi == 0) n /= pi;
        ret -= (ret / pi);
        if (n == 1 || isPrime(n)) break;
    }
    if(n > 1) ret -= (ret / n);
    return ret;
}
```



### 11. Euler Totient Function from 1 to N:

```cpp
const int MAX = 1e7;
long long phi[MAX + 7] = { 0 };

// Time complexity: O(n log log n)
void preCalPhi() {
    phi[1] = 1;
    for (int i = 2; i <= MAX; i++) {
        if (phi[i] == 0) {
            phi[i] = i-1;
            for (int j = 2*i; j <= MAX; j += i) {
                if (phi[j] == 0) phi[j] = j;
                phi[j] -= phi[j] / i;
            }
        }
    }
}
```

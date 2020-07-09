## BASIC OPERATIONS:

1. ALL_BITS
2. NEG_BITS
3. TEST_BIT
4. ON_BIT
5. OFF_BIT
6. TOGGLE_BIT
7. IS_POWER_TWO
8. OFF_LOWEST_SET_BIT
9. LOWEST_SET_BIT_POSITION
10. DIVIDE_BY_POWER_TWO
11. BIT COUNT IN RANGE
12. HAMMING DISTANCE

#### ALL_BITS: 
Getting an integer with all bits set. Following expression will provide us an integer of 31 bits where all bits set.

```java
public static final int ALL_BITS = (1 << 31) - 1;
```

#### NEG_BITS:
Given an integer N, generate a new integer where all bits are toggled.

```java
public static int NEG_BITS(int N) {
    return N ^ ALL_BITS;
}
```

#### TEST_BIT: 
Given an integer N, check is i'th bit set or not.

```java
public static boolean TEST_BIT(int n, int i) {
    return (n & (1 << i)) != 0;
}
```

#### ON_BIT: 
Given an integer N and a bit position, turn on the bit at that position.

```java
public static int ON_BIT(int n, int i) {
    return n | (1 << i);
}
```

#### OFF_BIT:
Given an integer N and a bit position, turn off the bit at that position.

```java
public static int OFF_BIT(int n, int i) {
    return n & NEG_BITS(1 << i);
}
```

#### TOGGLE_BIT:
Given an integer N and a bit position, toogle the bit at that position.

```java
public static int TOGGLE_BIT(int n, int i) {
    return n ^ (1 << 31);
}
```

#### IS_POWER_TWO:
Given an integer N, check is it power of 2.

```java
public static boolean IS_POWER_TWO(int n) {
    return (n & (n - 1)) == 0;
}
```

#### OFF_LOWEST_SET_BIT:
Given an integer N, check is it power of 2.

```java
public static int OFF_LOWEST_SET_BIT(int n) {
    return n & (n - 1);
}
```

#### LOWEST_SET_BIT_POSITION:
Given an integer N, turn off lowest set bit.

```java
public static int LOWEST_SET_BIT_POSITION(int n) {
    return n ^ (n & (n - 1));
}
```

#### DIVIDE_BY_POWER_TWO:
Given an integer N and P where N needs to be divided by P and P is an integer which is power of 2, then we can perform the division using bitwise operation.

```java
public static int DIVIDE_BY_POWER_TWO(int n, int p) {
    return n & (p - 1);
}
```

#### BIT COUNT IN RANGE:
Given an integer N and two values l and r, count set bits from rightmost l'th bit to rightmost r'th bit.

```java
public static int bitCountRange(int N, int l, int r) {
    int mask = ((1 << (r+1)) - 1) ^ ((1 << l) - 1);
    return Integer.bitCount(N & mask);
}
```

#### HAMMING DISTANCE:
Given two integer X and Y, hamming distance is the number of positions at which the corresponding bits are different.

```java
public static int hammingDistance(int x, int y) {
    return Integer.bitCount(x ^ y);
}
```

## BASIC PROBLEMS:

1. Printing Subsets
2. Unique Integer Search
3. Unique Integer Search General
4. Counting Set Bits from 0 to N
5. XOR of integers from 0 to N
6. Minimum AND Value Pair in an Array
7. Maximum AND Value Pair in an Array
8. Minimum OR Value Pair in an Array
9. Maximum OR Value Pair in an Array
10. Minimum XOR Value Pair in an Array
11. Maximum XOR Value Pair in an Array


### 1. Printing Subsets: 
Given a set of integers print all subsets. Example:

```
Input: A = [1, 2, 3]
Output:
[]
[1]
[2]
[3]
[1, 2]
[1, 3]
[2, 3]
[1, 2, 3]
```

**Solution:**

Represent each elements by each bits of an integer. So array `[1, 2, 3]` requires only 3 bits. 
Maximum number with 3 bits = 7 (111). 
Then each integer from 0 to 7 represents a subsets.

You can also generate all subsets of a given subset. For example consider `10110` is a given subset. All subset will be:

```
00000
00010
00100
00110
10000
10010
10100
10110
```

Java Code:

```java
public static void printSubsets(int n) {
    int x = n;
    while (true) {
        System.out.println(Integer.toBinaryString(x));
        if (x == 0) break;
        x = (x - 1) & n;
    }
}
```

### 2. Unique Integer Search: 
Given an array where all integers will appear twice except one integer. Find that unique integer. Example:

```
Input: A = [3, 4, 8, 2, 3, 8, 4]
Output: 2
Input: A = [3, 4, 3, 4, 10]
Output: 10
```

**Solution:**

Hint: XOR operation. XOR operation gives output 0 when bits are similar, 1 otherwise. So if we XOR all integers of the array, result for similar integers will be 0 since their bit representation is similar. Here is an example:

```
Integers  - Result = 0000
--------------------------
3  = 0011 - 0011 
4  = 0100 - 0111
3  = 0011 - 0100
4  = 0100 - 0000
10 = 1010 - 1010
--------------------------
```


### 3. Unique Integer Search General:

Given an array where all integers will appear K (odd value only) times except one integer. Find that unique integer. Example:

```
Input: K = 3, A = [5, 5, 5, 10, 7, 7, 7]
Output: 10
```

**Solution:**

Hint: Counting set bits at each bit position.
This time XOR won't help since value of K will be odd. XOR doesn't vanish all bits which are similar three times. So need another approach. Following explanation is for K = 3. Since similar number has similar bit representation, for a particular bit position total bit count will be multiple of K=3 unless that unique integer has bit at that bit position.

```
Integers
--------------------------
5        = 0 1 0 1
5        = 0 1 0 1
5        = 0 1 0 1
10       = 1 0 1 0
7        = 0 1 1 1
7        = 0 1 1 1
7        = 0 1 1 1
--------------------------
Count    = 1 6 4 6
Count%3  = 1 0 1 0 = 10
```

### 4. Counting Set Bits from 0 to N:
Given an integer N, count all set bits of each integer starting from 0 up to N. Example:

```
Input: N = 6
Output: 9
Integers - Bit Count
---------------------
0 = 000  - 0
1 = 001  - 1
2 = 010  - 1
3 = 011  - 2
4 = 100  - 1
5 = 101  - 2
6 = 110  - 2
---------------------
Total set bit count: 9
```

**Solution:**

Hint: Pattern Searching
The solution comes from a pattern of binary representation of integers. For some special type of integers we can answer the question by a mathematical formula. To find out that formula lets write down binary representations of integers up to 15.

```
Integers
------------------------------------------------------------------
 0 = 0000
 1 = 0001
 2 = 0010
 3 = 0011
 4 = 0100
 5 = 0101
 6 = 0110
 7 = 0111
 8 = 1000
 9 = 1001
10 = 1010
11 = 1011
12 = 1100
13 = 1101
14 = 1110
15 = 1111

The pattern is for those integers which can be represented by (2^x -1). Example: 1, 3, 7, 15... For this integers set bit count will be half of total bit count. 
At 0th bit position bits are flipping one after one.
At 1th bit position bits are flipping after 2 bits.
At 2th bit position bits are flipping after 4 bits.

Consider integer N = 7.

0 0 0
0 0 1
0 1 0
0 1 1
1 0 0
1 0 1
1 1 0
1 1 1
------------------------------------------------------------------
Number of bits per integer, b = 3
Total bit count = 2^b * b = 8 * 3 = 24
Set bit count   = Half of total bit count 
                = (2^b * b) / 2 = b * 2^(b-1)
                
So, formula will be = b * 2^(b-1) = 3 * 2^2 = 12

Now consider N = 13
1. Count bits up to 7 using the formula
2. Count bits of leftmost bit from 8 to 13
3. Count bits again for (13 - 8) = 5 and into original result.
```

Java Code:

```java
public static int leftmostBit(int n) {
    int ret = 0;
    while(n > 1) {
        n = n >> 1;
        ret++;
    }
    return ret;
}

public static int bitCount(int n) {
    int b = leftmostBit(n);
    if (((1 << (b+1)) - 1) == n) return (b+1) * (1 << b);

    int ret = 0;
    while(n > 1) {
        b = leftmostBit(n);
        ret += (b * (1 << (b-1)));
        n = n - (1 << b);
        ret += (n + 1);
    }
    return n == 0 ? ret : ret + 1;
}
```

### 5. XOR of Integers from 0 to N

Given an integer `N`, compute XOR value of integers from `0` to `N`. Example:

```
Input: N = 5
Output: 1

000
001
010
011
100
101
----
001 = 1
```

**Solution:**

Hint: Pattern Searching Find out answers up to N = 8 manually.

```
N  -- Ans
------------
0  -- 0 <- Notice this
1  -- 1
2  -- 3
3  -- 0
4  -- 4 <- Notice this
5  -- 1
6  -- 7
7  -- 0
8  -- 8 <- Notice this

IF N % 4 == 0, result = N
IF N % 4 == 1, result = 1
IF N % 4 == 2, result = N+1
IF N % 4 == 3, result = 0
```

### 6. Minimum AND Value Pair in an Array

Given an array of integers find minimum AND value pair.

**Hint:** Trie


### 7. Maximum AND Value Pair in an Array

Given an array of integers find maximum AND value pair. Example:

```
Input: A = [10, 4, 5, 11]
Output: 10
Integers
------------------
10 = 1010
 4 = 0100
 5 = 0101
11 = 1011
------------------
Manually find the pair = (1010 & 1011) = 1010
```

**Solution:**

```
Hint: Traverse bits from left to right with a pattern
A = [10, 4, 5, 11]

Start from most significant bit. 
For bit position 3:
pattern = 1000
1010 & 1000 = 1000 <- (A[i] & pattern == pattern)
0100 & 1000 = 0000
0101 & 1000 = 0000
1011 & 1000 = 1000 <- (A[i] & pattern == pattern)
---------------------------------------------------
count = 2
since (count >= 2) bit at position 3 will remain 1.
It means there are at least 2 integers exist in the array with set bit at position 3. So we will take this bit.

For bit position 2:
pattern = 1100
1010 & 1100 = 1000
0100 & 1100 = 0100
0101 & 1100 = 0100
1011 & 1100 = 1000
---------------------------------------------------
count = 0
since (count < 2) bit at position 2 will remain be changed to 0.

For bit position 1:
pattern = 1010
1010 & 1010 = 1010 <- (A[i] & pattern == pattern)
0100 & 1010 = 0000
0101 & 1010 = 0000
1011 & 1010 = 1010 <- (A[i] & pattern == pattern)
---------------------------------------------------
count = 2
since (count >= 2) bit at position 1 will remain 1.

For bit position 0:
pattern = 1011
1010 & 1011 = 1010
0100 & 1011 = 0000
0101 & 1011 = 0001
1011 & 1011 = 1011 <- (A[i] & pattern == pattern)
---------------------------------------------------
count = 1
since (count < 2) bit at position 1 will be changed to 0.

Finally, pattern = 1010
pattern the is the result.

Complexity: For each bit position (consider 31 bit integer) we traverse all integer once. So complexity will be O(31 * n) = O(n)
```

Java Code:

```java
public static int maxAndPair(int nums[]) {
    int pattern = 0;
    for (int i = 31; i >= 0; i--) {
        pattern = ON_BIT(pattern, i);
        int count = 0;
        for (int j = 0; j < nums.length; j++) {
            if ((nums[j] & pattern) == pattern) count++;
        }
        if (count < 2) pattern = OFF_BIT(pattern, i);
    }
    return pattern;
}
```

### 8. Minimum OR Value Pair in an Array:

**Solution:** Find minimum and second minimum. Their OR value is the result.


### 9. Maximum OR Value Pair in an Array:

**Solution:** Find maximum and second maximum. Their OR value is the result.


### 8. Minimum XOR Value Pair in an Array:

Given an array of integers find minimum XOR value pair.

**Hint:** Trie


### 9. Maximum XOR Value Pair in an Array:

Given an array of integers find maximum XOR value pair. Example:

```
Input: A = [3, 10, 5, 25, 2, 8]
Output: 28 = 5 ^ 25
```

**Solution:**

```
Hint 1: Traverse bits from left to right, Masking, Set or HashMap
Hint 2: Use Trie

Lets write down binary representations:

Integers
---------------------
 3 = 00011
10 = 01010
 5 = 00101
25 = 11001
 2 = 00010
 8 = 01000
---------------------

First of all we must know below property of XOR:
If a ^ b = c then a = b ^ c and a ^ c = b

Suppose at bit position 4, we want set bit = 10000. 
It's only possible when there is a pair with different bit at position 4.
To check we have to traverse all integers and do check like following:
DesiredResult = 10000
If for any A[i], 
DesiredResult ^ A[i] = X which is also available in array.
Then we can confirm set bit at position 4.
** But how to know X is available in array. Answer if Set or HashMap

We have to repeat this process until bit position 0. While doing process for bit position 4 other bits in position 3 to 0 will create problem. 
So before doing this process we have to modify each integer using a mask.
For position 4, mask = 10000
For position 3, mask = 11000
...
For position 0, mask = 11111

====================================================================

Lets simulate the algorithm:
Mask   = 00000
Result = 00000

For position 4,
Mask = 10000

Integers    Mask      Modified Integer
--------------------------------------
 3 = 00011 & 10000 =  00000
10 = 01010 & 10000 =  00000
 5 = 00101 & 10000 =  00000
25 = 11001 & 10000 =  10000
 2 = 00010 & 10000 =  00000
 8 = 01000 & 10000 =  00000
--------------------------------------
DesiredResult = Result | (1 << 4) = 10000
DesiredResult ^ 00000 = 10000 <- which is available in array. stop!
Result = 10000

For position 3,
Mask = 11000
Integers    Mask      Modified Integer
--------------------------------------
 3 = 00011 & 11000 =  00000
10 = 01010 & 11000 =  01000
 5 = 00101 & 11000 =  00000
25 = 11001 & 11000 =  11000
 2 = 00010 & 11000 =  00000
 8 = 01000 & 11000 =  01000
--------------------------------------
DesiredResult = Result | (1 << 3) = 11000
DesiredResult ^ 00000 = 11000 <- which is available in array. stop!
Result = DesiredResult = 11000

For position 2,
Mask = 11100
Integers    Mask      Modified Integer
--------------------------------------
 3 = 00011 & 11100 =  00000
10 = 01010 & 11100 =  01000
 5 = 00101 & 11100 =  00100
25 = 11001 & 11100 =  11000
 2 = 00010 & 11100 =  00000
 8 = 01000 & 11100 =  01000
--------------------------------------
DesiredResult = Result | (1 << 2) = 11100
DesiredResult ^ 00000 = 11100
DesiredResult ^ 01000 = 10100
DesiredResult ^ 00100 = 11000 <- which is available in array. stop!
Result = DesiredResult = 11100 

For position 1,
Mask = 11110
Integers    Mask      Modified Integer
--------------------------------------
 3 = 00011 & 11110 =  00010
10 = 01010 & 11110 =  01010
 5 = 00101 & 11110 =  00100
25 = 11001 & 11110 =  11000
 2 = 00010 & 11110 =  00010
 8 = 01000 & 11110 =  01000
--------------------------------------
DesiredResult = Result | (1 << 1) = 11110
DesiredResult ^ 00010 = 11100
DesiredResult ^ 01010 = 10100
DesiredResult ^ 00100 = 11010
DesiredResult ^ 00010 = 11100
DesiredResult ^ 00100 = 11010
This time Result isn't updated

For position 0,
Mask = 11111
Integers    Mask      Modified Integer
--------------------------------------
 3 = 00011 & 11111 =  00011
10 = 01010 & 11111 =  01010
 5 = 00101 & 11111 =  00101
25 = 11001 & 11111 =  11001
 2 = 00010 & 11111 =  00010
 8 = 01000 & 11111 =  01000
--------------------------------------
DesiredResult = Result | (1 << 0) = 11101
DesiredResult ^ 00011 = 11110
DesiredResult ^ 01010 = 10110
DesiredResult ^ 00101 = 11000
DesiredResult ^ 11001 = 00100
DesiredResult ^ 00010 = 11111
DesiredResult ^ 01000 = 10101
This time Result isn't updated
Finally, Result = 11100 = 28
```

Java Code:

```
public static int maxXORPair(int nums[]) {
    int result = 0, mask = 0;
    for (int i = 31; i > 0; i--) {
        mask |= (1 << i);
        int desiredResult = result | (1 << i);
        Set<Integer> set = new HashSet<>();
        for (int j = 0; j < nums.length; j++) {
            int num = nums[j] & mask;
            if (set.contains(desiredResult ^ num)) {
                result = desiredResult;
                break;
            }
            set.add(num);
        }
    }
    return result;
}
```

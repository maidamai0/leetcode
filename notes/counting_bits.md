# Counting bits

Count the number of `1`s of a binary integer.

## Basics

``` binary
10  1010
9   1001
8   1000
7   0111
6   0110
5   0101
4   0100
3   0011
2   0010
1   0001
0   0000
```

``` binary
10&9    1000->8
9&8     1000->8
8&7     0000->0
7&6     0110->6
6&5     0100->4
5&4     0100->4
4&3     0000->0
3&2     0010->2
2&1     0000->0
1&0     0000->0
```

Operation `n&(n-1)` removes exactly one `1` from `n`, so you can get:

```math
f(n) = f(n&(n-1)) +1
```

## Implementation in cpp

```cpp
int count_bits(const int num){
    vector<int> sum(num+1,0);
    for(int i=1; i<=num; ++i){
        sum[i] = sum[i&(i-1)]+1;
    }
}
```

## Reference

1. [Brian Kernighan’s Algorithm](https://medium.com/@sanchit3b/brian-kernighans-algorithm-9e0ca5989148)

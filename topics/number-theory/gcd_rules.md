# GCD and LCM Rules

## GCD (Greatest Common Divisor)

1. **Definition**: The GCD of two integers `a` and `b` is the largest positive integer that divides both `a` and `b` without leaving a remainder.

2. **Properties**:

   - `gcd(a, b) = gcd(b, a)`
   - `gcd(a, 0) = |a|` (for any integer `a`)
   - `gcd(a, b) = gcd(a, b - a)`
   - `gcd(a, b) ≤ min(|a|, |b|)`
   - If `d = gcd(a, b)`, then `d` can be expressed as a linear combination of `a` and `b`: `d = ax + by` for some integers `x` and `y` (Bezout's identity).
   - The Euclidean algorithm can be used to find the GCD efficiently: `gcd(a, b) = gcd(b, a % b)`

3. **GCD of Multiple Numbers**:
   - `gcd(a, b, c) = gcd(gcd(a, b), c)`

## LCM (Least Common Multiple)

1. **Definition**: The LCM of two integers `a` and `b` is the smallest positive integer that is divisible by both `a` and `b`.

2. **Properties**:

   - `lcm(a, b) = lcm(b, a)`
   - `lcm(a, b) ≥ max(|a|, |b|)`
   - `lcm(a, b) = |a * b| / gcd(a, b)`
   - If `d = gcd(a, b)`, then `lcm(a, b) = a * b / d`

3. **LCM of Multiple Numbers**:
   - `lcm(a, b, c) = lcm(lcm(a, b), c)`

## Combined Rules and Relationships

1. **Product of GCD and LCM**:

   - For any two integers `a` and `b`: `gcd(a, b) * lcm(a, b) = |a * b|`

2. **Distributive Property**:

   - `gcd(lcm(a, b), c) = lcm(gcd(a, c), gcd(b, c))`
   - `lcm(gcd(a, b), c) = gcd(lcm(a, c), lcm(b, c))`

3. **Associative Property**:

   - `gcd(a, gcd(b, c)) = gcd(gcd(a, b), c)`
   - `lcm(a, lcm(b, c)) = lcm(lcm(a, b), c)`

4. **Identity and Zero**:
   - `gcd(a, 1) = 1`
   - `lcm(a, 1) = |a|`
   - `lcm(a, 0) = 0`
   - `gcd(a, 0) = |a|`

## Practical Computation

### Euclidean Algorithm for GCD

```cpp
int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}
```

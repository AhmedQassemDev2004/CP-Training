# Prime Numbers: Rules and Properties

## Definition

- A **prime number** is a positive integer greater than 1 that has no positive integer divisors other than 1 and itself.

## Basic Properties

1. **Uniqueness**:

   - Prime numbers are unique in that they are only divisible by 1 and themselves.

2. **First Prime**:

   - The smallest prime number is 2. It is the only even prime number.

3. **Odd Primes**:

   - All prime numbers greater than 2 are odd.

4. **Prime Factors**:
   - Every positive integer greater than 1 can be uniquely factored into prime numbers. This is known as the **Fundamental Theorem of Arithmetic**.

## Primality Testing

1. **Trial Division**:

   - To test if a number \( n \) is prime, check for divisibility from 2 up to \( \sqrt{n} \). If \( n \) is not divisible by any of these numbers, then \( n \) is prime.

2. **Efficient Checking**:
   - For larger numbers, more efficient primality tests, such as the **Sieve of Eratosthenes** or probabilistic tests like the **Miller-Rabin test**, can be used.

## Mathematical Properties

1. **GCD and LCM**:

   - For any integer \( a \) and a prime \( p \), \( \text{gcd}(a, p) \) is either 1 (if \( p \) does not divide \( a \)) or \( p \) (if \( p \) divides \( a \)).
   - The **Least Common Multiple (LCM)** of a prime \( p \) and any integer \( a \) is \( p \times a \) if \( p \) divides \( a \), otherwise it is \( p \times a \).

2. **Prime Power**:
   - If \( p \) is a prime number and \( k \) is a positive integer, then \( p^k \) is a power of a prime.

## Prime Number Theorems

1. **Distribution**:

   - The **Prime Number Theorem** approximates the distribution of prime numbers. It states that the number of primes less than \( n \) is approximately \( \frac{n}{\log n} \).

2. **Twin Primes**:

   - Twin primes are pairs of primes that differ by 2 (e.g., (11, 13), (17, 19)).

3. **Goldbach's Conjecture**:
   - Every even integer greater than 2 can be expressed as the sum of two primes.

## Special Prime Sequences

1. **Mersenne Primes**:

   - Primes of the form \( 2^p - 1 \), where \( p \) is also a prime number.

2. **Fermat Primes**:

   - Primes of the form \( 2^{2^n} + 1 \).

3. **Palindromic Primes**:
   - Primes that are the same when read forwards or backwards.

## Common Prime Numbers

Here are some small prime numbers for reference:
2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97

## Applications

1. **Cryptography**:

   - Primes are fundamental in modern cryptographic algorithms, such as RSA, due to their properties in number theory.

2. **Hashing**:

   - Primes are used in hash functions to reduce collisions and improve efficiency.

3. **Random Number Generation**:
   - Certain algorithms use primes to generate random sequences or ensure uniform distribution.

## Conclusion

Prime numbers are essential in mathematics and various applications. Understanding their properties and applications is crucial for both theoretical and practical purposes.

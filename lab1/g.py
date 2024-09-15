def sieve_of_eratosthenes(limit):
    sieve = [True] * (limit + 1)
    sieve[0] = sieve[1] = False  # 0 and 1 are not primes

    for i in range(2, int(limit ** 0.5) + 1):
        if sieve[i]:
            for j in range(i * i, limit + 1, i):
                sieve[j] = False

    primes = [i for i in range(2, limit + 1) if sieve[i]]
    return primes

def find_superprime(n):
    prime_limit = 10000  # Increased limit to generate enough primes
    primes = sieve_of_eratosthenes(prime_limit)
    
    # Get the prime numbers whose indices are also prime
    superprimes = [primes[i - 1] for i in sieve_of_eratosthenes(len(primes))]
    
    # Return the nth superprime (1-based index)
    return superprimes[n - 1]

# Input
n = int(input())

# Output the nth superprime
print(find_superprime(n))
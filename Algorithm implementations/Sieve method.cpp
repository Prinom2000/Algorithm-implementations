#include <iostream>

void sieveOfEratosthenes(int n) {
    // Create a boolean array "prime[0..n]" and initialize all entries it as true.
    // A value in prime[i] will finally be false if i is not a prime, else true.
    bool prime[n+1];
    for(int i = 0; i <= n; i++)
        prime[i] = true;

    for (int p = 2; p * p <= n; p++) {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true) {
            // Update all multiples of p
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    // Print all prime numbers
    std::cout << "Prime numbers up to " << n << " are:" << std::endl;
    for (int p = 2; p <= n; p++)
        if (prime[p])
            std::cout << p << " ";
}

int main() {
    int n = 10; // Example: Finding primes up to 30
    sieveOfEratosthenes(n);
    return 0;
}


from math import sqrt
from shared.primenumbers import sieve

def sumofprimes(maxPrime):
	primes = sieve(maxPrime)
	sum = 0
	# 1 is not prime
	for num in primes:
			sum += num

	return sum


if __name__ == '__main__':
	#7919 is the 1000th prime
	print sumofprimes(7919)

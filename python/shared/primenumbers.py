def sieve(maxPrime):
	from math import sqrt
	isPrime = [True]*(maxPrime+1)
	for i in range(2, int(sqrt(maxPrime))+1):
		if isPrime[i]:
			for j in range(i*i, maxPrime+1, i):
				isPrime[j] = False

	return [i for i in range(2,len(isPrime)) if isPrime[i]]


if __name__ == '__main__':
	print sieve(100)
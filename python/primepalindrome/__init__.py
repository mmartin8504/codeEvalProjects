from shared.primenumbers import sieve

if __name__ == '__main__':
	primes = sieve(1000)
	for num in sorted(primes,None,None,True):
		if str(num) == str(num)[::-1]:
			print num
			break




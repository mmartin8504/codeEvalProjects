def fib_recursive(n):
	if (n<0):
		return 0
	elif (n==1 or n==0):
		return 1
	else:
		return fib_recursive(n-1) + fib_recursive(n-2)

def fib_iter(n):
	ret=0
	prev1=1
	prev2=1
	if (n==1 or n==2):
		return 1
	else:
		for i in range(3, n+1):
			ret = prev1 + prev2
			prev1 = prev2
			prev2 = ret
	return ret

if __name__ == '__main__':
	import sys
	test_cases = open(sys.argv[1], 'r')
	for test in test_cases:
		print fib_iter(int(test.strip()))
	test_cases.close()

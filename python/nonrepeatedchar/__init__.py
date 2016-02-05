from collections import OrderedDict

if __name__ == '__main__':
	import sys
	test_cases = open(sys.argv[1], 'r')
	for test in test_cases:
		stripStr = test.strip()
		dict = OrderedDict()
		for c in stripStr:
			if c in dict:
				dict[c] += 1
			else:
				dict[c] = 1

		for k,v in dict.iteritems():
			if v==1:
				print k
				break

	test_cases.close()

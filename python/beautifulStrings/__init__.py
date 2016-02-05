from collections import defaultdict

if __name__ == '__main__':
	import sys
	test_cases = open(sys.argv[1], 'r')
	for test in test_cases:
		stripped = test.strip()
		d = defaultdict(int)
		for c in stripped.upper():
			if c.isalpha():
				d[c] += 1
		counts = d.values()
		score = 0
		multiplier = 26
		for i in sorted(counts, reverse=True):
			score += i*multiplier
			multiplier -= 1

		print score
	test_cases.close()

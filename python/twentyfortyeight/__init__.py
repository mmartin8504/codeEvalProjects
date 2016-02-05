from collections import deque

def slide_right(rows):
	result = []
	for row in rows:
		resultRow = deque([])
		size = len(row)
		temp = []
		while len(row) > 0:
			if len(temp)==0:
				first = row.pop()
			else:
				first = temp.pop()
			while len(row)>0 and first == 0:
				first = row.pop()
			if len(row)>0:
				next = row.pop()
				while next==0 and len(row)>0:
					next = row.pop()
				if first == next:
					resultRow.appendleft(next*2)
				else:
					resultRow.appendleft(first)
					temp.append(next)
			else:
				resultRow.appendleft(first)
		resultRow.extendleft(temp)
		while len(resultRow) < size:
			resultRow.appendleft(0)
		result.append(resultRow)
	return result

def slide_left(rows):
	reversedRows = [list(reversed(row)) for row in rows]
	slidRows = slide_right(reversedRows)
	return [list(reversed(row)) for row in slidRows]

def slide_up(rows):
	zippedRows = [list(i) for i in zip(*rows)]
	slidRows = slide_left(zippedRows)
	return [list(i) for i in zip(*slidRows)]

def slide_down(rows):
	zippedRows = [list(i) for i in zip(*rows)]
	slidRows = slide_right(zippedRows)
	return [list(i) for i in zip(*slidRows)]

def parse(line):
	splitSemi = line.strip().split(';')
	direction = splitSemi[0]
	splitRows = splitSemi[2].strip().split('|')
	rows = [[int(i) for i in row.split(' ')] for row in splitRows]
	return (direction, rows)

def printresult(rows):
	strToPrint = ''
	for row in rows:
		for i in row:
			strToPrint += str(i) + ' '
		strToPrint = strToPrint.strip() + '|'
	print strToPrint.strip('|')

if __name__ == '__main__':
	import sys
	test_cases = open(sys.argv[1], 'r')
	for test in test_cases:
		(direction, rows) = parse(test)
		result = []
		if direction == 'UP':
			result = slide_up(rows)
		elif direction == 'DOWN':
			result = slide_down(rows)
		elif direction == 'RIGHT':
			result = slide_right(rows)
		elif direction == 'LEFT':
			result = slide_left(rows)

		printresult(result)
	test_cases.close()
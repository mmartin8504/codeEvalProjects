import unittest
from ddt import data, ddt, unpack
from twentyfortyeight import slide_right

@ddt
class foo(unittest.TestCase):
	@data(
		([[4,0,2,0]], [0,0,4,2]),
		([[0,2,0,2]], [0,0,0,4]),
		([[2,2,2,2]], [0,0,4,4]),
		([[0,0,0,8]], [0,0,0,8]),
		([[8,0,0,8]], [0,0,0,16]),
		([[8,0,0,0]], [0,0,0,8]),
		([[4,0,2,4]], [0,4,2,4]),
		([[2,4,2,2]], [0,2,4,4]),
		([[8,8,2,0]], [0,0,16,2]),
		([[2,0,2,0]], [0,0,0,4])
	)
	@unpack
	def test_slide_right(self, row, expected):
		self.assertEqual(expected, list(slide_right(row)[0]))

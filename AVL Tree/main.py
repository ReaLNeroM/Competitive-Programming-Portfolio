class Node():
	def __init__(self, key):
		self.key = key
		self.parent = None
		self.left = None
		self.right = None
		self.height = None
class AVL():
	def __init__(self):
		self.root = None
	def insert_tree(self, key):
		if self.root is None:
			self.root = Node(key)
		
	def find(self, key):


T = AVL()
seq = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12]
for i in seq:
	T.insert(i)
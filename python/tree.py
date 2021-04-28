#!usr/bin/python

class Tree:

	def __init__(self):
		self.node = None
		self.left = None
		self.right = None

	def insert(self, x):
		if self.node == None:
			self.node = x
		elif x >= self.node:
			if self.right is None:
				self.right = Tree()
				self.right.node = x
			else: 
				self.right.insert(x)
		elif x < self.node:
			if self.left is None:
				self.left = Tree()
				self.left.node = x
			else:
				self.left.insert(x)

tree = Tree()
tree.insert(5)
tree.insert(8)
tree.insert(4)
tree.insert(2)

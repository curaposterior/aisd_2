
class Node:
    def __init__(self, val, left=None, right=None):
        self.left = left
        self.right = right
        self.val = val

class BST:
    def __init__(self, val, left=None, right=None):
        self.root = Node(left, right, val)

    def addNode(self):
        return None

    def inOrder(self):
        return None

    def postOrder(self):
        return None

    def preOrder(self):
        return None

    def printBT(self):
        return None

    def search(self, key):
        if self.root is None or key == self.root.val:
            return self.root
        
        if self.root.val < key:
            return self.search(self.root.right, key)
        
        return self.search(self.left, key)

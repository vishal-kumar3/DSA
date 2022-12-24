# Linked Lists :-
# Sequence of data are connected via links.
# Each data contains a connection to another data
# 2 -> 3 -> 8 -> 5

# Singly Linked lists


class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class SLinkedList:
    def __init__(self):
        self.head = None

    # Print elements of Linked list Using 'Recursion'
    def listPrintFunc(self):
        node = self.head

        def Function(node):
            if node is not None:
                return node.data, Function(node.next)

        print(Function(node))

    # Print elements of Linked list Using 'Loop'
    def listPrintLoop(self):
        node = self.head
        while node is not None:
            print(node.data, end=', ')
            node = node.next
        print('None')

    # insert at end node via list of node == nodes
    def insertAtLast(self, data):
        node = self.head
        while True:
            # Node ka end part find kro
            if node.next is None:
                # milne pe None ko data se replace kro
                for element in data:
                    node.next = Node(element)
                    node = node.next
                return node

            else:
                # nhi mila to node me aage badho
                node = node.next

    # insert at beginning

    def insertAtStart(self, data):
        # data into a New Node
        NewNode = Node(data)
        # NewNode ko Existing Node se link kiye
        NewNode.next = self.head
        # yaha NewNode ko head bana rhe h
        self.head = NewNode

    def insertInBetween(self, data):
        middleNode = Node(data)
        node = self.head
        elements = 0

        # Elements Kitna h vo pta chalega
        while True:
            if node.next is None:
                break
            else:
                elements += 1
                node = node.next

        # finding the middle part
        node = self.head
        for _ in range((elements)//2):
            node = node.next

        # Inserting the NewNode to middle of Linked list
        # And NewNode ke baad jo ayega usko bhi add kr diye
        middleNode.next, node.next = node.next, middleNode

    def removeNode(self, target):
        node = self.head

        # Agar first element hi target ho
        if node is not None:
            if node.data == target:
                # head change kiye
                self.head = node.next
                # first node ka next None kr diye
                node = None
                return

        # Jb first ke baad ho
        while node is not None:
            if node.data == target:
                break

            prev = node
            node = node.next
        
        if node is None:
            return
        
        prev.next = node.next
        node = None



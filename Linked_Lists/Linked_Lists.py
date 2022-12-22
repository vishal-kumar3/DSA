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

    # Find Linked List's Head
    def listHead(self):
        node = self.head
        while True:
            if node.next == None:
                print(node.data)
                break
            else:
                node = node.next

    # Print elements of Linked list Using 'Recursion'
    def listPrintFunc(self):
        node = self.head
        def Function(node):
            if node != None:
                return node.data, Function(node.next)
                
        print(Function(node))
    
    # Print elements of Linked list Using 'Loop'
    def listPrintLoop(self):
        node = self.head
        while node != None:
            print(node.data, end=', ')
            node = node.next
        print('None')

    # insert at end node via list of node == nodes
    def insertAtLast(self, data):
        node = self.head
        while True:
            # Node ka end part find kro
            if node.next == None:
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
            if node.next == None:
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


    def remove(self, target):
        node = self.head

        if node is not None:
            if node.data == target:
                self.head = node.next
                node = None
                return
        
        while node is not None:
            if node.data == target:
                break
            
            node = node.next


list1 = SLinkedList()
list1.head = Node("Mon")

e2 = Node('Tue')
e3 = Node('Wed')
e4 = Node('Thur')
e4 = Node('Fri')
e5 = Node('Sat')
e6 = Node('Sun')

list1.head.next = e2

e2.next = e3
e3.next = e4
e4.next = e5
e5.next = e6

list2 = SLinkedList()
list2.head = Node('10')

l2 = Node('5')
l3 = Node('1')

list2.head.next = l2

l2.next = l3


# print('List1')
# list1.listPrintLoop()
# list1.insertAtLast([1, 2])
# list1.listPrintLoop()

# print('InBetween')
# list1.insertInBetween(10)
# list1.listPrintLoop()

# print('List2')
# list2.listPrintLoop()
# list2.insertAtStart('holla')
# list2.listPrintLoop()

llist = SLinkedList()
llist.insertAtStart("Thu")
llist.insertAtStart("Wed")
llist.insertAtStart("Tue")
llist.insertAtStart("Mon")
llist.RemoveNode("Mon")
llist.listPrintLoop()
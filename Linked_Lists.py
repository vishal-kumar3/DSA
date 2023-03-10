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

    # To find the length of linked list
    def size(self):
        node = self.head
        size = 0
        while node is not None:
            size+=1
            node = node.next
        return size
    

    def sum(self):
        node = self.head
        sum = 0
        while node is not None:
            sum = sum + node.data
            node = node.next
        return sum

    
    def maxNum(self):
        node = self.head
        max_num = []
        while node is not None:
            max_num.append(node.data)
            node = node.next
        return max(max_num)

    # insert at end node via list of node == nodes
    def insertAtLast(self, data):
        node = self.head
        while node is not None:
            if node.next is None:
                node.next = Node(data)
                return
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

        # When Head value is the Target
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
            # if not equal to target
            # saving the previous value of node in prev variable
            # node.next se pehle save kiya that's why previous value save hua
            prev = node
            # changing node to next node
            node = node.next
        
        # if target value is last element
        # since saved previous value in prev
        if node is None:
            return

        # for middile term or last term both will execute this code
        # this code is responsible for deletion of element
        # changed the next term
        prev.next = node.next
        # changed deletion term to node
        node = None

    # Normal Searching
    def search(self, target):
        node = self.head
        index = 0
        while node is not None:
            if node.data == target:
                return index
            node = node.next
            index+=1
        return -1


list1 = SLinkedList()
l1 = Node(0)
list1.head = l1
for x in range(1,7):
    list1.insertAtLast(x)

list1.listPrintLoop()
list1.removeNode(6)
list1.listPrintLoop()

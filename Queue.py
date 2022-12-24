


class Queue:

    def __init__(self):
        self.queue = []
    

    def add(self, data):
        if data not in self.queue:
            self.queue.append(data)
            return True
        return False


    def remove(self):
        if len(self.queue) > 0 :
            self.queue.pop(0)
            return True
        print('No Element in Queue')
    

    def size(self):
        return len(self.queue)


    def peek(self):
        if len(self.queue) > 0:
            return self.queue[0], self.queue[-1]
        print('No Element in Queue')


TheQueue = Queue()
TheQueue.add("Mon")
TheQueue.add("Tue")
TheQueue.add("Wed")
print(TheQueue.size())
print(TheQueue.peek())
TheQueue.remove()
print(TheQueue.peek())


class Node:

    def __init__(self, next, value):
        self.next = next
        self.value = value


class SinglyLinkedList:
    # ends with NULL next

    def __init__(self):
        self.head = None

    # get length
    def __len__(self):
        l = 0
        curr = self.head
        while curr != None:
            curr = curr.next
            l += 1
        return l

    def __getitem__(self, idx):
        if not (0 <= idx < len(self)):
            raise IndexError

        nodes_left = idx
        curr = self.head
        while nodes_left > 0:
            curr = curr.next
            nodes_left -= 1

        return curr

    # insert @
    def insert(self, value, idx):

        if idx == 0:
            new_node = Node(self.head, value)
            self.head = new_node
            return

        length = len(self)
        prev_node = self[length - 1]
        if idx == length:
            prev_node.next = Node(None, value)
            return

        next_node = self[length]
        prev_node.next = Node(next_node, value)

    # add at front

    def insertFront(self, value):
        self.insert(value, 0)

    # add at back
    def insertEnd(self, value):
        self.insert(value, len(self))

    # remove @
    def remove(self, idx):
        if not (0 <= idx < len(self)):
            raise IndexError

        node = self[idx]

        if idx == 0:
            self.head = node.next
        else:
            prev_node = self[idx - 1]
            prev_node = node.next

    # remove from from
    def removeFront(self):
        self.remove(0)

    # remove from back
    def removeBack(self):
        self.remove(len(self) - 1)

    # check cycles
    def hasCycles(self):
        if len(self) == 0:
            return False

        one_skip = self.head
        two_skip = self.head

        while one_skip is not None and two_skip is not None:
            one_skip = one_skip.next
            if two_skip.next is not None and two_skip.next.next is not None:
                two_skip = two_skip.next.next
            else:
                break

            if one_skip == two_skip:
                return True

        return False

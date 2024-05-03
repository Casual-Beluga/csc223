from binarytree import Node

frequency = [4,5,2,3,4,5,6,7,8,9]
characters = ["a","b","c","d","e"]
nodes = []
temp_tree = 0
main_tree = 0
#create base binary trees

i=0
# creates the nodes - works
while i < len(frequency):
    nodes.append(Node(frequency[i]))
    i+=1

#function to create temporary binary tree
def create_temp_tree():
    global temp_tree
    temp_tree = Node(nodes[0].value + nodes[1].value)
    temp_tree.left = nodes.pop(0)
    temp_tree.right = nodes.pop(0)
    print(temp_tree)


#insert temp_tree into the list of nodes based on the number
def insert_tree():
    j=0
    global temp_tree
    while j < len(nodes):
        if (temp_tree.value < nodes[j].value):
            nodes.insert((j), temp_tree)
            break
        j+=1
    nodes.insert(j, temp_tree)


# main loop
while len(nodes) > 1:
    #create the first tree
    create_temp_tree()
    insert_tree()
    print(nodes)

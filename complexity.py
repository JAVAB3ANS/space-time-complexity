# Let's say that it takes 1 second per loop

# 1 second to execute 
array = [1] 
# 5 seconds to execute
# array = [1, 2, 3, 4, 5] 
# 10 seconds to execute
# array = [1, 2, 3, 4, 5 6, 7, 8, 9, 10] 
# 20 seconds to execute
# array = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 , 17, 18, 19, 20]

[1, 2, 3, 4, 5, 6, 7]
# One loop is one second

# We always want programs to be efficient as engineers.
# Use as little memory as possible and done quickly
# Time should be low and memory usage low as well
# Programmers don't explicitly state the amount of seconds or memory the program consumed
# But rather, we use Big-O notation to represent how long the algorithm takes

"""
Tasks 
- print every number in array
- count frequency of each number
- find an element in a sorted array
- sort an array
"""

# Linear complexity: as data goes up, so does time > direct proportionality

""" O(n):
[1] - 1 second
[1, 2] - 2 seconds
[1, 2, 3] - 3 seconds
[1, 2, 3, 4] - 4 seconds
[1, 2, 3, 4, 5] - 5 seconds
"""

""" O(n^2):
[1] - 1 second
[1, 2] - 2 seconds
[1, 2, 3] - 9 seconds
[1, 2, 3, 4] - 16 seconds
[1, 2, 3, 4, 5]  - 25 seconds
"""

# O(n) time complexity - where n is the number of elements in my array 
for i in range(len(array)):
    print("Number [O(n)]: ", array[i])

# O(n^2) time complexity
for i in range(len(array)):
    print("Number 1 [0(n^2)]")
    for j in range(len(array)):
        print("Number 2 [0(n^2)]", array[j])

"""
Here there's a O(n) in a nested for loop so it's O(n^2) when same array used but not always the case
"""

frequencies = [1, 2, 2, 3, 3, 4, 4, 4, 4, 4]

dictionary = {1 : 1, 2: 2, 3 :  1}

# O(n) time complexity
for i in range(len(array)):
    if array[i] in dictionary:
        dictionary[array[i]] += 1
    else:
        dictionary = 1

# O(n^2) time complexity
for i in range(len(array)):
    numCount = 1
    for j in range(len(array)):
        if array[i] == array[j] and i != j:
            numCount += 1

 
"""
This brings our time complexity down by using data
"""

# O(n) time complexity
for i in range(len (array)):
    if array[i] in dictionary:
        dictionary[array[i]] += 1
    else:
        dictionary[array[i]] = 1

    print("Frequency of", array[i], "[0(n)]:", numCount) 


# O(n^3) time complexity
for i in range(len(array)):
    for j in range(len(array)):
        for k in range(len(array)):
            print("Array[i] [0(n^3)]:", array[i])
            print("Array[j] [0(n^3)]:", array[j])
            print("Array[k] [0(n^3)]:", array[k])
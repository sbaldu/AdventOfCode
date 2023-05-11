import numpy as np

def get_range(assignment: str):
    domain = assignment.split('-')
    first = int(domain[0])
    second = int(domain[1])
    return (first, second)

def contains(range_1: tuple, range_2: tuple):
    # The first range is contained in the second
    if range_1[0] >= range_2[0] and range_1[1] <= range_2[1]:
        return True
    # The second range is contained in the first
    if range_1[0] <= range_2[0] and range_1[1] >= range_2[1]:
        return True
    return False

def overlap(range_1: tuple, range_2: tuple):
    list_range_1 = np.arange(range_1[0], range_1[1]+1)
    list_range_2 = np.arange(range_2[0], range_2[1]+1)

    len_1 = len(list_range_1)
    len_2 = len(list_range_2)
    if len_1 < len_2:
        for element in list_range_1:
            if element in list_range_2:
                return True
    else:
        for element in list_range_2:
            if element in list_range_1:
                return True
    return False


file = open('./input.txt', 'r')
contained_counter = 0
overlap_counter = 0
for line in file:
    assignments = line.split(',')
    range1 = get_range(assignments[0])
    range2 = get_range(assignments[1])
    if contains(range1, range2):
        contained_counter += 1
    if overlap(range1, range2):
        overlap_counter += 1

print("The number of ranges contained in another is:", contained_counter)
print("The number of ranges overlapping with another is:", overlap_counter)

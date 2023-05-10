import numpy as np

file = open("./calories.dat", "r")

calories = []
partial = []
for line in file:
    if line == '\n':
        calories.append(partial)
        partial = []
        continue
    partial.append(int(line))

max_calories = 0
for elf in calories:
    sum_i = sum(elf)
    if sum_i > max_calories:
        max_calories = sum_i
print("The maximum number of calories carried by a single elf is:", max_calories)

totals = []
for elf in calories:
    totals.append(sum(elf))

totals.sort()
total_top_three_elves = np.sum(totals[-3:])
print("The number of calories carried by the top three elves is:", total_top_three_elves)

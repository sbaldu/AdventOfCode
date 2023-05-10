# Part 1
file = open("./input.txt", "r")

def score(letter):
    letters = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
    if not(letter.isupper()):
        return letters.index(letter) + 1
    else:
        return letters.index(letter.lower()) + 27

backpacks = []
total = 0
for line in file:
    length = len(line) - 1
    backpacks.append(line[0:length])
    first_comp = line[0:length // 2]
    second_comp = line[length // 2:]

    duplicates = []
    for letter in first_comp:
        if letter in second_comp:
            duplicates.append(score(letter))
    duplicates = list(set(duplicates))
    total += sum(duplicates)
print("The first solution is:", total)

# Part 2
badges = []
new_total=0
groups = [j for j in range(len(backpacks)) if j % 3 == 0]
for group in groups:
    for letter in backpacks[group]:
        if (letter in backpacks[group+1]) and (letter in backpacks[group+2]):
            badges.append(score(letter))
            break         
new_total = sum(badges)
print("The second solution is:", new_total)

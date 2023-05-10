#
# rock = 1, paper = 2, scissor = 3

score () {
	if [ $1 == "X" ]  # Rock
	then
		return 1
	elif [ $1 == "Y" ]  # Paper 
	then
		return 2
	elif [ $1 == "Z" ]  # Scissor
	then
		return 3
	fi
}

# P-R = 1 + P = 10
# S-P = 2 + S = 10
# R-S = 3 + R = 10

opponent_score () {
	if [ $1 == "A" ]  # Rock
	then
		return 8
	elif [ $1 == "B" ]  # Paper 
	then
		return 7
	elif [ $1 == "C" ]  # Scissor
	then
		return 9
	fi
}

winner () {
	if [ $(($1 + $2)) == 10 ]
	then
		return 6
	elif [ $(($1 + $2)) == 9 ] || [ $(($1 + $2)) == 12 ]
	then
		return 3
	else 
		return 0
	fi
}

total=0
while read col1 col2 ; do
	score $col2
	myscore=$?
	opponent_score $col1
	opponent=$?
	total=$(($myscore + $total))
	winner $myscore $opponent
	total=$(($? + $total))
done < ./input.dat
echo $total

new_score () {
	if [ $1 == "A" ]  # Rock
	then
		return 1
	elif [ $1 == "B" ]  # Paper 
	then
		return 2
	elif [ $1 == "C" ]  # Scissor
	then
		return 3
	fi
}


# X = I lose 
# Y = I draw
# Z = I win

result () {
	if [ $1 == "X" ]  # Rock
	then
		return 0
	elif [ $1 == "Y" ]  # Paper 
	then
		return 3
	elif [ $1 == "Z" ]  # Scissor
	then
		return 6
	fi
}

my_choice () {
	if [ $2 == "X" ]
	then
		if [ $1 == "A" ]
		then
			return 3
		elif [ $1 == "B" ]
		then
			return 1
		elif [ $1 == "C" ]
		then
			return 2
		fi
	elif [ $2 == "Y" ]
	then
		new_score $1
		return $?
	elif [ $2 == "Z" ]
	then
		opponent_score $1
		opponent=$?
		myscore=$((10-$opponent))
		return $myscore
	fi
}

total=0
while read col1 col2 ; do
	result $col2
	score1=$?
	total=$(($score1 + $total))
	my_choice $col1 $col2
	total=$(($? + $total))
done < ./input.dat
echo $total

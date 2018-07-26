in_extension=".in"
out_extension=".out"
in_length=${#in_extension}

g++ -O2 src.cpp

for input in `find . -name "*${in_extension}"`; do
	input=${input:2:${#input}}
	answer=${input::-in_length}${out_extension}

	echo $input
	echo $answer
	time ./a.out < $input > response.temp

	if [ -f $answer ]; then
		diff $answer response.temp
	else
		echo ANSWER FILE NOT FOUND
	fi
done

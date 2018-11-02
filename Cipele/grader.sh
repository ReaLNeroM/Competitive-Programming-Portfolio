in_extension=".in"
out_extension=".out"
in_length=${#in_extension}

g++ -O2 src.cpp

for input in `find . -name "cipele.in.*"`; do
	input=${input:2:${#input}}
	answer="cipele.out.${input:10}"

	echo $input
	
	time ./a.out < $input > response.temp

	if [ -f $answer ]; then
		if [ "$(diff -w $answer response.temp)" != "" ]; then
			echo WA
		fi
	else
		echo ANSWER FILE NOT FOUND
	fi
done

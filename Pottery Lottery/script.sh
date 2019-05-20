for i in {1..100}; do
	python main.py > res.out
	python testing_tool.py < res.out > /dev/null 2> error.txt
	tail -2 error.txt | head -1
done
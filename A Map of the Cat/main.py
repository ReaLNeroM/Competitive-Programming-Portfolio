import sys

good = ["great!", "don\'t think so", "not bad", "cool", "don\'t touch me!"]
bad = ["no way", "go die in a hole", "are you serious?", "worse", "terrible"]
for i in range(10):
	print i
	sys.stdout.flush()

	s = raw_input()

	for j in good:
		if s == j:
			print "normal"
			sys.exit()
	for j in bad:
		if s == j:
			print "grumpy"
			sys.exit()

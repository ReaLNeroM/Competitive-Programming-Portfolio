import sys

n = input()
s = list(raw_input())

def say_no():
	print "No"
	sys.exit()

for i in range(0, len(s)):
	if s[i] == '1':
		if i != 0 and s[i - 1] == '1':
			say_no()
		elif i != len(s) - 1 and s[i + 1] == '1':
			say_no()
	elif s[i] == '0':
		if (i == 0 or s[i - 1] == '0') and (i == len(s) - 1 or s[i + 1] == '0'):
			say_no()

print "Yes"
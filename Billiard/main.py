y, x = 8, 6

py, px = 1, 1
diry, dirx = 1, 1

for i in range(50):
	if py == y and diry == 1:
		diry = -1
	if px == x and dirx == 1:
		dirx = -1
	if py == 0 and diry == -1:
		diry = 1
	if px == 0 and dirx == -1:
		dirx = 1;

	py += diry
	px += dirx

	print py, px

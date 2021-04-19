# https://open.kattis.com/contests/nadc21practice1/problems/europeantrip

from math import *
#distance between two points
d = lambda x,y: ((x[0]-y[0])**2+(x[1]-y[1])**2)**0.5

#given the points, returns the sides
s = lambda A,B,C : (d(B,C), d(C,A), d(A,B))

#given the sides, returns the angle
j = lambda a,b,c : acos((b*b+c*c-a*a)/(2*b*c))

#given the sides, returns secant of that angle
t = lambda a,b,c: 1/cos(j(a,b,c)-pi/6)

#given the sides and the Trilinear co-ordinates, returns the Cartesian co-ordinates
b = lambda A,B,C,p,q,r: [(p*A[i]+q*B[i]+r*C[i])/(p+q+r) for i in [0,1]]

#this one checks if any of the angle is >= 2π/3 returns that point else computes the point
f = lambda A,B,C: A if j(*s(A,B,C)) >= 2*pi/3 else B if j(*s(B,C,A)) >= 2*pi/3 else C if j(*s(C,A,B)) >= 2*pi/3 else b(A,B,C,d(B,C)*t(*s(A,B,C)),d(C,A)*t(*s(B,C,A)),d(A,B)*t(*s(C,A,B)))

ax, ay = map(int, input().split(' '))
bx, by = map(int, input().split(' '))
cx, cy = map(int, input().split(' '))

res = f([ax, ay], [bx, by], [cx, cy])
print(res[0], res[1])





import
	>>> from geometry import Poly


init
	>>> poly = Poly(((0,0),(4,0),(2,2)))

aabb
	>>> poly.AABB.p == (0,0)
	True
	>>> poly.AABB.w
	4
	>>> poly.AABB.h
	2

adjacent
	>>> poly1 = Poly(((0,0),(4,0),(2,2)))
	>>> poly2 = Poly(((0,0),(2,-2),(4,0)))
	>>> poly1.adjacent(poly2)
	True
	>>> poly3 = Poly(((0,1),(4,1),(2,2)))
	>>> poly1.adjacent(poly3)
	False


move
	>>> poly = Poly(((0,0),(4,0),(2,2)))
	>>> _ = poly.move((2,2)).round()
	>>> poly.points == [(2,2), (6,2), (4,4)]
	True

move_to
	>>> poly = Poly(((0,0),(4,0),(4,4),(0,4)))
	>>> _ = poly.move_to((0,0)).round()
	>>> poly.points == [(-2, -2), (2, -2), (2, 2), (-2, 2)]
	True
	

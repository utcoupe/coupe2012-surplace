
import
	>>> from geometry import AABB

init
	>>> box = AABB((0,0), 3, 4)

contain
	>>> (-1,2) in box
	False
	>>> (5,2) in box
	False
	>>> (2,-1) in box
	False
	>>> (2,5) in box
	False
	>>> (2,2) in box
	True
	>>> (0,0) in box
	True
	>>> (2,3) in box
	True
	>>> (3,4) in box
	False


aire
	>>> box.aire()
	12

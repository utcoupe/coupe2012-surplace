
import xml.dom.minidom

from .objects import *
from .define import *

def load_map(filename,engine):
	
	ofi = open(filename, 'r')
	document = ofi.read()
	ofi.close()
	
	dom = xml.dom.minidom.parseString(document)
	for cd in dom.getElementsByTagName("cd"):
		engine.add(Cd(engine,mm_to_px(int(cd.getAttribute("x")),int(cd.getAttribute("y"))),cd.getAttribute("color")))
		
	for wall in dom.getElementsByTagName("wall"):
		engine.add(Wall(engine,mm_to_px(int(wall.getAttribute("x1")),int(wall.getAttribute("y1"))),mm_to_px(int(wall.getAttribute("x2")),int(wall.getAttribute("y2")))))
	
	for totem in dom.getElementsByTagName("totem"):
		engine.add(Totem(engine,mm_to_px(int(totem.getAttribute("x")),int(totem.getAttribute("y")))))
	
	for tour in dom.getElementsByTagName("tour"):
		engine.add(Tour(engine))
		
	for lingo in dom.getElementsByTagName("lingo"):
		engine.add(Lingo(engine,mm_to_px(int(lingo.getAttribute("x")),int(lingo.getAttribute("y")))))

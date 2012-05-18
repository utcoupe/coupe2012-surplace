#!/usr/bin/python3
# -*- coding:utf-8 -*-


import sys
import os
FILE_DIR  = os.path.dirname(os.path.abspath(__file__))
sys.path.append(os.path.join(FILE_DIR,"..","..","..","lib"))

from py3irc.mypyirc.mypyircbot import MyPyIrcBot

import tkinter as tk
import threading


class Bot(MyPyIrcBot):
	def __init__(self,serverip, serverport):
		MyPyIrcBot.__init__(self, serverip, serverport, "commandbot", ["#coupeoff"])
		self.canal = "#test"
	def send(self, msg):
		super().send("#coupeoff", msg)

bot = Bot('localhost',6667)
t = threading.Thread(target=bot.start)
t.setDaemon(True)
t.start()

def keypress(event):
	if event.keysym == 'Escape':
		root.destroy()
	x = event.char
	if x=='z':
		bot.send(".pwm 100 100")
	elif x=='q':
		bot.send(".pwm 0 100")
	elif x=='d':
		bot.send(".pwm 100 0")
	elif x=='s':
		bot.send(".pwm 0 0")
	else:
		print( x)
root = tk.Tk()
print ("Press a key (Escape key to exit):")
root.bind_all('<Key>', keypress)
# don't show the tk window
#root.withdraw()
root.mainloop()

import pygame
from pygame.locals import *


axis=[0,0,0,0,0,0]
    
pygame.init()
joysticks = [pygame.joystick.Joystick(x) for x in range(pygame.joystick.get_count())]

while True:
    for event in pygame.event.get(): # get the events (update the joystick)
        if event.type == QUIT: # allow to click on the X button to close the window
            pygame.quit()
            exit()
        elif event.type == pygame.JOYBUTTONDOWN:
        	if event.button==0:
        		print("A")
        	if event.button==1:
        		print("B")
        	if event.button==2:
        		print("X")
        	if event.button==3:
        		print("Y")
        	if event.button==4:
        		print("l1")
        	if event.button==5:
        		print("r1")
        	if event.button==6:
        		print("select")
        	if event.button==7:
        		print("7")
        	if event.button==8:
        		print("8")
        	if event.button==9:
        		print("l3")
        	if event.button==10:
        		print("r3")
        	if event.button==11:
        		print("11")
        elif event.type == pygame.JOYAXISMOTION:
        	axis[event.axis]=round(event.value,2)
        	print(axis)
        	
        	
        		
        		
        	


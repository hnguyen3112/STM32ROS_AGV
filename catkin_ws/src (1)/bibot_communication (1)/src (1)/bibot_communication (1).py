#!/usr/bin/env python3
import time
import serial
import threading
import pygame
from pygame.locals import *
import rospy
import roslib
from std_msgs.msg import Int32
from geometry_msgs.msg import Twist

axis=[0,0,0,0,0,0]
pygame.init()
joysticks = [pygame.joystick.Joystick(x) for x in range(pygame.joystick.get_count())]

port=rospy.get_param('/port','/dev/ttyUSB0')
baudrate=int(rospy.get_param('/baudrate','115200'))

Ser=serial.Serial(port,baudrate,timeout=.1)
#Ser=serial.Serial(port='/dev/ttyUSB0',baudrate=115200,timeout=.1)
Ser.flush()

print("run communication")

data=[0,0,0,0,0]

def ps2():
	for event in pygame.event.get(): # get the events (update the joystick)
		if event.type == QUIT: # allow to click on the X button to close the window
			pygame.quit()
			exit()
		elif event.type == pygame.JOYBUTTONDOWN:
			if event.button==0:
				print("A")
				data_send="A035B035__"
				Ser.write(data_send.encode())
			if event.button==1:
				print("B")
				data_send="A035B135__"
				Ser.write(data_send.encode())
			if event.button==2:
				print("X")
				data_send="A135B035__"
				Ser.write(data_send.encode())
			if event.button==3:
				print("Y")
				data_send="A135B135__"
				Ser.write(data_send.encode())
			if event.button==4:
				print("l1")
				data_send="OOOOOOOO__"
				Ser.write(data_send.encode())
			if event.button==5:
				print("r1")
				data_send="FFFFFFFF__"
				Ser.write(data_send.encode())
			if event.button==6:
				print("select")
			if event.button==9:
				print("l3")
			if event.button==10:
				print("r3")
		elif event.type == pygame.JOYBUTTONUP:
				data_send="A000B000__"
				Ser.write(data_send.encode())
		elif event.type == pygame.JOYAXISMOTION:
			axis[event.axis]=round(event.value,2)
			#print(axis)

def callback(dt):
	#rospy.loginfo("sendto_bibot");
	send=[0,0,0,0,0,0,0,0,0,0]
	send[0]=round(dt.linear.x,3)
	send[1]=round(dt.angular.z,3)
	
	dx=send[0]
	dz=send[1]
	
	tdl=(dx+dz*0.25)
	tdr=(dx-dz*0.25)
	
	send[2]=tdl
	send[3]=tdr
	
	for i in range(500):
		if abs(tdl)>=0.5 or abs(tdr)>=0.5:
			break
		else:
			tdl=tdl*1.2
			tdr=tdr*1.2
	
	send[4]=round(tdl,3)
	send[5]=round(tdr,3)
	
	tdl=tdl*50
	tdr=tdr*50
	
	send[6]=round(tdl,3)
	send[7]=round(tdr,3)
	
	if tdl >=90:
		tdl=90
	if tdl <= -90:
		tdl=-90
	if tdr >=90:
		tdr=90
	if tdr <= -90:
		tdr=-90
	
	send[8]=int(tdl)
	send[9]=int(tdr)
	

	data_send="A"
	if tdl>=0:
		data_send+="1"
	else: 
		data_send+="0"
		
	if abs(tdl)<10:
		data_send+= "0"+ str(abs(int(tdl)))
	else:
		data_send+=str(abs(int(tdl)))
		
	data_send+="B"
	if tdr>=0:
		data_send+="1"
	else:
		data_send+="0"
		
	if abs(tdr)<10:
		data_send+= "0"+ str(abs(int(tdr)))
	else:
		data_send+=str(abs(int(tdr)))
	data_send+="__"
	
	#print(send)
	#print(data_send)
	Ser.write(data_send.encode())

def get_data():
	global	data
	data_serial= Ser.readline()
	dt=data_serial.split()
	
	if len(data_serial)>0 and len(dt)>4:
		data=dt[0:5]
		print(data)
	

def pub_sub():
	global	data
	
	rospy.init_node("bibot")#,anonymous=True)
	rospy.Subscriber("cmd_vel",Twist,callback)
	pub1=rospy.Publisher("lwheel",Int32,queue_size=10)
	pub2=rospy.Publisher("rwheel",Int32,queue_size=10)

	rate=rospy.Rate(10)
	
	while not rospy.is_shutdown():
	
		ps2()
		
		data=[0,0,0,0,0]
		get_data()
		if data[0]!=0 and data[1]!=0:
			pub1.publish(int(float(data[0])))
			pub2.publish(int(float(data[1])))
		rate.sleep()
		

if __name__ =='__main__':
	try:
		pub_sub();
	except rospy.ROSInterruptException:
		pass


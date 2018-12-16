#!/usr/bin/python

import serial 
import MySQLdb
import sys

#establish connection to MySQL.
dbConn = MySQLdb.connect("localhost","user","password","bdd") or die ("could not connect to database")
#open a cursor to the database
cursor = dbConn.cursor()

device = '/dev/ttyUSB0'
baudrate = 9600




def getSerialData():
 try:
  print "Connection sur:",device
  arduino = serial.Serial(device, baudrate) 
 except: 
  print "Connection impossible sur:",device    
 try:
     print "Recuperation des donnees:"
     next(arduino)
     data = arduino.readline()  #read the data from the arduino
     pieces = data.split("\t")  #split the data by the tab
     print "Data: %s" % data
     print "Piece 1: %s" % pieces[0]
     print "Piece 2: %s" % pieces[1]
     print "Piece 3: %s" % pieces[2]
     print "Piece 4: %s" % pieces[3]
     print "Piece 5: %s" % pieces[4]
     print "Piece 6: %s" % pieces[5]
     print "Piece 7: %s" % pieces[6]
     #Here we are going to insert the data into the Database
     try:
       print "Trying insertion..."
       cursor.execute("INSERT INTO table (temperature,tempmin,tempmax,humidity,temperaturep,humidityp,pressure) VALUES (%s,%s,%s,%s,%s,%s,%s)", (pieces[0],pieces[1],pieces[2],pieces[3],pieces[4],pieces[5],pieces[6]))
       dbConn.commit() #commit the insert
       
     except MySQLdb.IntegrityError:
      print "failed to insert data"
     finally:
      print "closing cursor"
      
      del pieces[:]
 except:
  print "Impossible de recuperer les donnees!!!"
  sys.exit(1)


val = 0
while val == 0 :
 getSerialData()

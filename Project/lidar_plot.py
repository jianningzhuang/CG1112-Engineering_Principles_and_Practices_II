import matplotlib.pyplot as plt
import csv

x = []
y = []

with open('lidar_reading.dat','r') as csvfile:
    plots = csv.reader(csvfile, delimiter=',')
    for row in plots:
        print(row[0])



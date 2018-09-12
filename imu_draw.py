# coding:utf-8
import numpy as np
from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt

import Connect_Start_Arduino     #自作のスクリプト
import commands
ArdName={"GY-521":None}
ArdName=Connect_Start_Arduino.UsbStart(ArdName)

def plot_data():
    ArdName["GY-521"].write("#ok#")
    data = commands.getoutput("cat %s" %ArdName["GY-521"].port).split("\n")
    print(len(data),data)
    if len(data)==6:
        X1, Y1, Z1 = float(data[0]), float(data[1]), float(data[2])
        X2, Y2, Z2 = float(data[3]), float(data[4]), float(data[5])
        ax.cla()
        ax.quiver(0, 0, 0, X1, Y1, Z1, pivot="tail", color="black")
        ax.quiver(0, 0, 0, X2, Y2, Z2, pivot="tail", color="red")
        ax.set_xlim(-10000, 10000)
        ax.set_ylim(-10000, 10000)
        ax.set_zlim(-10000, 10000)
        ax.set_xlabel("x")
        ax.set_ylabel("y")
        ax.set_zlabel("z")    

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
plot_data()
while True:
    plot_data()
    plt.pause(.1)

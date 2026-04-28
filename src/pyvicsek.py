#%%

import numpy as np
import matplotlib.pyplot as plt
import glob
import natsort
from matplotlib.animation import FuncAnimation, PillowWriter

def read_config(filename, skip=2):
	"""Reading an vicsek configuration from a file handle"""
	with open(filename) as file_handle:
		#skip the first two lines
		for i in range(skip):
			next(file_handle)

		data = np.loadtxt(file_handle)
		conf = {}

		conf["id"] = data[:,0]
		conf["x"] = data[:,1]
		conf["y"] = data[:,2]
		conf["theta"] = data[:,3]
		conf["vx"] = np.cos(conf["theta"])
		conf["vy"] = np.sin(conf["theta"])
		return conf

def plot(conf,ax):
	qv = ax.quiver(conf["x"], conf["y"], conf["vx"], conf["vy"], conf["theta"], scale=1, scale_units = "xy", cmap = "hsv")
	return qv

#files stored in folder
files = natsort.natsorted(glob.glob("frame*"))

#plot
fig, ax = plt.subplots()

qv = plot(read_config(files[0]),ax)
#plot(read_config("init.conf"), ax) # for image file
#plt.savefig("vicsek_img.png")

plt.axis("equal")
plt.axis("off")

def animate(i):
#	print(i)
	conf = read_config(files[i])
	pos = np.array(list(zip(conf["x"], conf["y"])))
#	print(pos)
	qv.set_offsets(pos)
	qv.set_UVC(conf["vx"], conf["vy"], conf["theta"])
	return qv

anim = FuncAnimation(fig, animate, range(len(files)))
anim.save("vicsek_gif.gif", writer=PillowWriter(fps=20))

plt.show()


# %%

from threading import Thread
import time

def timer(name, delay, repeat):
	print name + ": has started"
	while repeat:
		time.sleep(delay)
		print name + ": " + time.ctime(time.time())
		repeat -= 1
	print name + ": has completed"

def main():
	t1 = Thread(target=timer, args=("Thread1", 1, 5))
	t2 = Thread(target=timer, args=("Thread2", 2, 5))

	t1.start()
	t2.start()

	print "Main has completed"

if __name__ == "__main__":
	main()
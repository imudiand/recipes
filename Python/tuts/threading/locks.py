from threading import Thread, Lock
import time

t_lock = Lock()

def timer(name, delay, repeat):
	"""
		Consider this function as critical region Consider
		which needs a lock to be accessed.
	"""

	t_lock.acquire()
	print name + " has acquired the lock"

	print name + ": has started"
	while repeat:
		time.sleep(delay)
		print name + ": " + time.ctime(time.time())
		repeat -= 1
	print name + ": has completed"

	t_lock.release()
	print name + " has released the lock"

def main():
	t1 = Thread(target=timer, args=("Thread1", 1, 5))
	t2 = Thread(target=timer, args=("Thread2", 2, 5))

	t1.start()
	t2.start()

	print "Main has completed"

if __name__ == "__main__":
	main()
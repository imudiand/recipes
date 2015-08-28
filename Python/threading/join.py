from threading import Thread
import time

class AsyncWriteThread(Thread):
	def __init__(self, text, outfile):
		super(AsyncWriteThread, self).__init__()
		self.text = text
		self.outfile = outfile

	def run(self):
		with open(self.outfile, 'a') as outfile:
			outfile.write(self.text)

		time.sleep(2)
		print "Finished background file write to: " + self.outfile

def main():
	message = raw_input("Write a message to save")
	background_thread = AsyncWriteThread(message, "out.txt")
	background_thread.start()

	print "The main program has continued running after starting the thread"
	for i in xrange(2):
		print str(i)

	background_thread.join()

	print "This part of main program only runs after the thread ends"
	for i in xrange(2):
		print str(i)

if __name__ == "__main__":
	main()
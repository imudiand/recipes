import socket

# bind
# listen
# accept -return a new socket
#	recv
#	send
# close

def main():
	host = "127.0.0.1"
	port = 6000

	s = socket.socket()
	s.bind((host, port))

	s.listen(1)
	(c, addr) = s.accept()
	print "Received a connect from addr: " + str(addr)

	while(1):
		data = c.recv(1024)
		if not data:
			break
		print "Data from user is: " + str(data)
		data = str(data).upper()
		print "Sending to user: " + data
		c.send(data)
	c.close()

if __name__ == "__main__":
	main()
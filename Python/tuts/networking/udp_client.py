import socket

def main():
	hostname = "127.0.0.1"
	port = 7001 # This must be different than the server port for UDP

	server = ("127.0.0.1", 7000)

	s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
	s.bind((hostname, port))

	message = raw_input("->")
	while(message != 'q'):
		s.sendto(message, server)
		(data, addr) = s.recvfrom(1024)
		print "Received data: %s from addr: %s " % (str(data), addr)
		message = raw_input("->")

	s.close()

if __name__ == "__main__":
	main()
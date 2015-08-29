import socket

def main():
	hostname = "127.0.0.1"
	port = 7000

	s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
	s.bind((hostname, port))

	print "Server has started"
	while(1):
		(data, addr) = s.recvfrom(1024)
		print "Message from: " + str(addr)
		print "Data: " + str(data)

		data = str(data).upper()
		s.sendto(data, addr)
	s.close()

if __name__ == "__main__":
	main()


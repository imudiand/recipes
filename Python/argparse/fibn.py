from argparse import ArgumentParser

def fib(n):
	a, b = 0, 1
	for i in range(n):
		a, b = b, a+b
	return a

def main():
	parser = ArgumentParser()

	# Add a required argument called num
	parser.add_argument("num", help="position where fibonacci" + \
		"number is needed", type=int)

	# Add an optional argument called output
	parser.add_argument("-o", "--output", help="Output the result " +\
		"to a file", action="store_true")
	args = parser.parse_args()


	result = fib(args.num)
	print "The "+str(args.num)+"th fibonacci number is "+str(result)
	if args.output:
		f = open("fib.txt", 'a')
		f.write(str(result)+"\n")

if __name__ == "__main__":
	main()
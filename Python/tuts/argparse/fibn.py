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

	# Add a mutually exclusive group for 2 new arguments
	group = parser.add_mutually_exclusive_group()
	group.add_argument("-v", "--verbose", help="Print verbose result", action="store_true")
	group.add_argument("-q", "--quiet", help="Only print the result", action="store_true")

	args = parser.parse_args()

	result = fib(args.num)
	if args.verbose:
		print "The "+str(args.num)+"th fibonacci number is "+str(result)
	elif args.quiet:
		print result
	else:
		print "fib("+str(args.num)+") = "+str(result)
	if args.output:
		f = open("fib.txt", 'a')
		f.write(str(result)+"\n")

if __name__ == "__main__":
	main()
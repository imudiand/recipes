

def simple_generator():
	yield 1
	yield 2
	yield 3


def main():

	print "Iterate over the Generator using for"
	for item in simple_generator():
		print item

	print "Use next keyword to iterate on generator"
	our_generator = simple_generator()
	print next(our_generator)
	print next(our_generator)
	print next(our_generator)


if __name__ == "__main__":
	main()
# One way to create a reusable generator is Object based 
# generators which does not hold any state. Any class with
# a __iter__ method which yields data can be used as a object
# generator. In the following example we will recreate out counter generator.


# Reusable Generator
class Counter(object):
	def __init__(self, low, high):
		self.low = low
		self.high = high

	def __iter__(self):
		counter = self.low
		while (self.high >= counter):
			yield counter
			counter += 1

# Non Reusable generator
def counter_gen(low, high):
	counter = low
	while(high >= counter):
		yield counter
		counter += 1


def main():
	counter = Counter(0, 10)
	for i in counter:
		print i
	for i in counter:
		print i

	print "---------------------\n"
	counter = counter_gen(0,10)
	for i in counter:
		print i
	for i in counter:
		print i


if __name__ == "__main__":
	main()
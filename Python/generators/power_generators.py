import math


def is_prime(number):
	if number > 1:
		if number == 2:
			return True
		if number % 2 == 0:
			return False
		for current in range(3, int(math.sqrt(number) + 1), 2):
			if number % current == 0:
				return False
		return True
	return False


# Generator Function
def get_primes(number):
	while(True):
		if is_prime(number):
			number = yield number
		number += 1


# NOTE: here we dont use the for loop over the generator
# directly. Instead we iterate over range(iterations) &
# do a send(number) on the generator
def print_successive_primes(iterations=3, base=10):

	prime_generator = get_primes(base) # Generator
	prime_generator.send(None)
	for power in range(iterations):
		print prime_generator.send( (base ** power) )


def main():
	print_successive_primes(iterations=3, base=10)

if __name__ == "__main__":
	main()
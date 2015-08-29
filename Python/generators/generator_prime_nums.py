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
def get_primes_generator_function(start=0, end=100):
	# NOTE: while(1) creates an infinite sequence.
	# It must be stopped at the main function
	while(start <= end):
		if is_prime(start):
			yield start
		start += 1

# Generator (its created from the generator function)
def get_primes(start=0, end=100):
	prime_numbers_list = []
	for item in get_primes_generator_function(start, end):
		prime_numbers_list.append(item)
	return prime_numbers_list


def main():
	print get_primes(start=0, end=100)


if __name__ == "__main__":
	main()

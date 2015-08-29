import math

# Non-Generator Implementation - Get prime Numbers

def get_primes(input_list):
	prime_numbers_list = []
	for item in input_list:
		if is_prime(item):
			prime_numbers_list.append(item)
	return prime_numbers_list

def get_primes2(input_list):
	return [ item for item in input_list if is_prime(item) ]

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

def main():
	print get_primes(range(100))
	print get_primes2(range(100))


if __name__ == "__main__":
	main()
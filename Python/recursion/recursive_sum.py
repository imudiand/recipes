

def r_sum(num_list):
	sum = 0
	for item in num_list:
		if type(item) == type([]):
			sum += r_sum(item)
		else:
			sum += item
	return sum

def main():
	list1 = [3, 5, 9, 20, 100]
	print r_sum(list1)

	list2 = [3, [4, 2, 4], 2, [3, 4, [5, 3], 12], 2, 9]
	print r_sum(list2)

if __name__ == "__main__":
	main()

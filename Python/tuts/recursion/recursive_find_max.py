


def r_find_max(num_list):
	if not len(num_list):
		return

	largest = None
	for item in num_list:
		if type(item) == type([]):
			item = r_find_max(item)
		if item > largest:
			largest = item

	return largest





def main():
	list2 = [3, [4, 2, 4], 2, [3, 4, [15, 3], 12], 2, 9]
	print r_find_max(list2)

if __name__ == "__main__":
	main()
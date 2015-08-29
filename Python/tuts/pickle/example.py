import pickle


dict1 = dict(a="100", b="200", c="300")
list1 = [400, 500, 600]

with open("out.txt", "wb") as outfile:
	pickle.dump(dict1, outfile)
	pickle.dump(list1, outfile)

print dict1
print list1

print "------------"


with open("out.txt", "rb") as infile:
	dict2 = pickle.load(infile)
	list2 = pickle.load(infile)

print dict2
print list2
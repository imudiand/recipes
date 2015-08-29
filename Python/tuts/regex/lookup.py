import re
import optparse

def main():
	parser = optparse.OptionParser("usage %prog -w <word> -f <file>")
	parser.add_option("-w", dest="word", type="string", help="Specify a word to search for")
	parser.add_option("-f", dest="fname", type="string", help="Specify a file to search in")

	(options, args) = parser.parse_args()
	if (not options.word or not options.fname):
		print parser.usage
		exit(0)
	else:
		word = options.word
		fname = options.fname

	with open(fname) as search_file:
		line_num = 0
		for line in search_file.readlines():
			line = line.strip("\n\r")
			line_num += 1
			search_result = re.search(word, line, re.M|re.I)
			if search_result:
				print str(line_num) + ": " + line

if __name__ == "__main__":
	main()

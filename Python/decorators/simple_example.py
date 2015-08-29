

def tags_decor(func):
	def func_wrapper(name):
		return "<p>%s</p>" % (func(name))
	return func_wrapper

@tags_decor
def get_text(name):
	return "Hello %s" % (name)

def main():
	print get_text("Harshit")

if __name__ == "__main__":
	main()
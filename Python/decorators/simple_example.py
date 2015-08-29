
# Simple decorator example
def tags_decor(func):
	def func_wrapper(name):
		return "<p>%s</p>" % (func(name))
	return func_wrapper

@tags_decor
def get_text(name):
	return "Hello %s" % (name)





# Multiple Decorators example

def p_tags_decor(func):
	def func_wrapper(name):
		return "<p>%s</p>" % (func(name))
	return func_wrapper


def div_tags_decor(func):
	def func_wrapper(name):
		return "<div>%s</div>" % (func(name))
	return func_wrapper


def h1_tags_decor(func):
	def func_wrapper(name):
		return "<h1>%s</h1>" % (func(name))
	return func_wrapper

@p_tags_decor
@div_tags_decor
@h1_tags_decor
def get_text2(name):
	return "Hello %s" % (name)





def main():
	print get_text("Harshit")
	print get_text2("Hemant")

if __name__ == "__main__":
	main()
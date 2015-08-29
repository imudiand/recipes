from functools import wraps


# Why use functools.wraps ??
# When you print get_text.__name__ doesnt return get_text
# without using wraps; you'l see that the name is overridden
# to the wrapper functions name - func_wrapper.
# Hence, use this @wraps decorator on the wrapper_function
# and pass the func as an argument to this decorator so that
# it sets these attributes correctly. It helps a lot in debugging
# when you want to know what the name of the function is.
# With using @wraps; the name is correctly set to "get_text"


# Simple decorator example
def tags_decor(func):
	@wraps(func)
	def func_wrapper(name):
		return "<p>%s</p>" % (func(name))
	return func_wrapper

@tags_decor
def get_text(name):
	return "Hello %s" % (name)





# Multiple Decorators example

def p_tags_decor(func):
	@wraps(func)
	def func_wrapper(name):
		return "<p>%s</p>" % (func(name))
	return func_wrapper


def div_tags_decor(func):
	@wraps(func)
	def func_wrapper(name):
		return "<div>%s</div>" % (func(name))
	return func_wrapper


def h1_tags_decor(func):
	@wraps(func)
	def func_wrapper(name):
		return "<h1>%s</h1>" % (func(name))
	return func_wrapper

@p_tags_decor
@div_tags_decor
@h1_tags_decor
def get_text2(name):
	return "Hello %s" % (name)



# Passing Arguments to Decorators

def tags(tagname):
	def tags_decor(func):
		@wraps(func)
		def func_wrapper(name):
			return "<{0}>{1}</{0}>".format(tagname, func(name))
		return func_wrapper
	return tags_decor

@tags("p")
@tags("div")
@tags("h1")
def get_text3(name):
	return "Hello %s" % (name)





# testing code here

def main():
	print get_text("Harshit")
	print get_text2("Hemant")
	print get_text3("Hemant")


if __name__ == "__main__":
	main()
from string import Template

def main():
	cart = []
	cart.append(dict(item="Coke", price=10, qty=1000))
	cart.append(dict(item="Pepsi", price=9, qty=299))
	cart.append(dict(item="Gingerale", price=12, qty=483))

	t = Template("$qty x $item = $price")
	total = 0
	print "Cart:"
	for data in cart:
		print t.substitute(data)
		total += data.get('price', 0)

	print "Total:", str(total)

if __name__ == "__main__":
	main()

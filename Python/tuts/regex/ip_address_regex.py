import re



def main():

	num_0_9 = "[0-9]"	# NOTE [0-9] can be replaced by [\d]
	num_10_99 = "[1-9][0-9]"
	num_100_199 = "1[0-9]{2}"
	num_200_249 = "2[0-4][0-9]"
	num_250_255 = "25[0-5]"

	num = "(" + num_0_9 + "|" + num_10_99 + "|" + num_100_199 + "|" + num_200_249 + "|" +  num_250_255 + ")"
	num_with_dot = "(" + num + "\." + ")"

	valid_ip_regex = "^" + num_with_dot + "{3}" + num + "$"
	#valid_ip_regex = "^(([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])\.){3}([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])$";


	while(True):

		ip = raw_input("Enter IP address here ->")
		

		# Uncompiled Matching
		uncompiled_match_result = re.match(valid_ip_regex, ip, re.M|re.I)
		if uncompiled_match_result:
			print "UNCOMPILED_MATCH: Valid IP"
		else:
			print "UNCOMPILED_MATCH: Invalid IP"


		# Compiled Matching
		compiled_pattern = re.compile(valid_ip_regex, re.M|re.I)
		compiled_match_result = compiled_pattern.match(ip)
		if compiled_match_result:
			print "COMPILED_MATCH: Valid IP"
		else:
			print "COMPILED_MATCH: Invalid IP"





if __name__ == "__main__":
	main()


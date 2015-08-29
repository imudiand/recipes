import random


def get_data():
    return random.sample(range(10), 3)


# Generator function
def consume():
    items_seen = 0
    running_sum = 0
    while(1):
        data = yield
        items_seen += len(data)
        running_sum += sum(data)
        print "The running sum is {}".format(running_sum/float(items_seen))


# Generator Function
def produce(consumer):
    while(1):
        data = get_data()
        consumer.send(data)
        yield data


def main():
    consumer = consume()
    consumer.send(None)
    producer = produce(consumer) # Generator
    for i in range(10):
        data = next(producer)
        print "Producer is producing...{}".format(data)

if __name__ == "__main__":
    main()

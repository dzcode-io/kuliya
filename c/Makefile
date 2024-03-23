INCLUDES= -I./

test:
	gcc test/test.c $(INCLUDES) -g -o test/$@
	./test/$@

build:
	gcc build.c $(INCLUDES) -g -o $@
	./$@

example:
	gcc example/main.c $(INCLUDES) -g -o example/$@
	./example/$@

clean:
	rm -f ./test/test
	rm -f ./build
	rm -f ./example/example

.PHONY: test build example clean

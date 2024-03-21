INCLUDES= -I./

test:
	gcc test/test.c $(INCLUDES) -g -o test/$@
	./test/$@

build:
	gcc build.c $(INCLUDES) -g -o $@
	./$@

clean:
	rm -f ./test/test
	rm -f ./build

.PHONY: test build clean

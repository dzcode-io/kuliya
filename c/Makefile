INCLUDES= -I./

test:
	gcc test/test.c $(INCLUDES) -g -o test/$@
	./test/$@

clean:
	rm -f ./test/test

.PHONY: test clean

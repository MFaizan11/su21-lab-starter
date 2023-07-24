G = gcc
E = ex1
TE = test_ex1

.PHONY: run
run: exe
	./a.out

exe:
	$(G) $(E).c $(TE).c

.PHONY: clean
clean:
	rm -f a.out

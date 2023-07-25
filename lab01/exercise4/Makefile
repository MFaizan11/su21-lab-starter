G = gcc
E = ll_cycle
TE = test_ll_cycle
OUT = ll_cycle

.PHONY: run
run: exe
	./$(OUT)

exe:
	$(G) $(E).c $(TE).c -o $(OUT)

.PHONY: clean
clean:
	rm -f $(OUT)

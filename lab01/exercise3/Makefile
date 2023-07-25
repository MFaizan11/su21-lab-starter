G = gcc
E = linked_list
TE = test_linked_list
OUT = linked_list

.PHONY: run
run: exe
	./$(OUT)

exe:
	$(G) $(E).c $(TE).c -o $(OUT)

.PHONY: clean
clean:
	rm -f $(OUT)




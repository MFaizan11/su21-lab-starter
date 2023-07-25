G = gcc
E = pwd_checker
TE = test_pwd_checker
OUT = pwd_checker

.PHONY: run
run: exe
	./$(OUT)

exe:
	$(G) $(E).c $(TE).c -o $(OUT)

.PHONY: clean
clean:
	rm -f $(OUT)



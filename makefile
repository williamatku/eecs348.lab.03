salesreport:
	clang salesreport.c -o sales.out
	./sales.out ./ex.txt
	rm ./sales.out

dev:
	clang main.c -o a.out
	./a.out
	rm ./a.out
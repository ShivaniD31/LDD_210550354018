D=gcc

main:	main.o ascend.o descend.o sort.h
	$(D) -o main main.o ascend.o descend.o

main.o: main.c
	$(D) -c main.c

ascend.o: ascend.c
	$(D) -c ascend.c

descend.o: descend.c
	$(D) -c descend.c

clean:
	rm -rf **.o main

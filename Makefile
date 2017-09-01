SOURCE= arrayList.c arrayList.h

test : tryList
	./tryList <test1.txt
	
valgrind : tryList
	valgrind --leak-check=full tryList <test1.txt
	
tryList : tryList.c arrayList.c arrayList.h
	gcc -Wall -g -o tryList tryList.c arrayList.c
	
clean : 
	-rm tryList

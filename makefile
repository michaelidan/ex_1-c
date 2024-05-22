CC=gcc
FLAG= -Wall -g
OBJECTS_LOOPS=  advancedClassificationLoop.o basicClassification.o
OBJECTS_REC= advancedClassificationRecursion.o basicClassification.o 

all: libclassrec.so libclassrec.a libclassloops.so libclassloops.a mains maindloop maindrec
mains: main.o libclassrec.a 
	$(CC) $(FLAG) -o mains main.o libclassrec.a -lm
maindloop: main.o libclassloops.so 
	$(CC) $(FLAG) -o maindloop main.o ./libclassloops.so -lm
maindrec: main.o libclassrec.so 
	$(CC) $(FLAG) -o maindrec main.o ./libclassrec.so -lm	
libclassloops.a: $(OBJECTS_LOOPS)
	ar -rcs libclassloops.a $(OBJECTS_LOOPS)
libclassrec.a: $(OBJECTS_REC)
	ar -rcs libclassrec.a $(OBJECTS_REC) 
libclassrec.so: $(OBJECTS_REC)
	$(CC) -shared -o libclassrec.so $(OBJECTS_REC)	
libclassloops.so: $(OBJECTS_LOOPS)
	$(CC) -shared -o libclassloops.so $(OBJECTS_LOOPS)
basicClassification.o: basicClassification.c NumClass.h 
	$(CC)  $(FLAG) -c basicClassification.c 
advancedClassificationRecursion.o: advancedClassificationRecursion.c NumClass.h
	$(CC)  $(FLAG) -c advancedClassificationRecursion.c
advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h
	$(CC)  $(FLAG) -c advancedClassificationLoop.c 
main.o: main.c NumClass.h 
	$(CC)  $(FLAG) -c main.c
.PHONY: clean

clean: 
	rm -f *.o *.a *.so mains maindloop maindrec









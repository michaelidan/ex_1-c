.PHONY: clean all

CC = gcc
AR = ar 
RANLIB = ranlib 


CFLAGS = -Wall 
LFLAGS = -shared 
SFLAGS = rcu 
FPIC = -fPIC 
LIBM = -lm 

MAIN = main
HEADER = NumClass.h
BASIC = basicClassification
LOOP = advancedClassificationLoop
REC = advancedClassificationRecursion


STAT_LIB_LOOP = libclassloops.a 
DYN_LIB_LOOP = libclassloops.so 
STAT_LIB_REC = libclassrec.a 
DYN_LIB_REC = libclassrec.so 


all: loops loopd recursives recursived mains maindrec maindloop



clean: 
	rm -f *.o *.a *.so mains maindrec maindloop

$(MAIN).o: $(MAIN).c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(BASIC).o: $(BASIC).c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@ $(FPIC)

$(LOOP).o: $(LOOP).c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@ $(FPIC)

$(REC).o: $(REC).c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@ $(FPIC)




loops: $(STAT_LIB_LOOP)

$(STAT_LIB_LOOP): $(LOOP).o $(BASIC).o
	$(AR) $(SFLAGS) $@ $^
	$(RANLIB) $@


loopd: $(DYN_LIB_LOOP)

$(DYN_LIB_LOOP): $(LOOP).o $(BASIC).o
	$(CC) $(LFLAGS) $(CFLAGS) $^ -o $@


maindloop: $(MAIN).o $(DYN_LIB_LOOP)
	$(CC) $(CFLAGS) $< ./$(DYN_LIB_LOOP) -o $@ $(LIBM)


recursives: $(STAT_LIB_REC)

$(STAT_LIB_REC): $(REC).o $(BASIC).o
	$(AR) $(SFLAGS) $@ $^
	$(RANLIB) $@

mains: $(MAIN).o $(STAT_LIB_REC)
	$(CC) $(CFLAGS) $< ./$(STAT_LIB_REC) -o $@ $(LIBM)



recursived: $(DYN_LIB_REC)

$(DYN_LIB_REC): $(REC).o $(BASIC).o
	$(CC) $(LFLAGS) $(CFLAGS) $^ -o $@

maindrec: $(MAIN).o $(DYN_LIB_REC)
	$(CC) $(CFLAGS) $< ./$(DYN_LIB_REC) -o $@ $(LIBM)
# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

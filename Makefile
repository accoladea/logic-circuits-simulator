SRCS = proj173num5/Value.c proj173num5/Gates.c proj173num5/Circuit.c proj173num5/main.c
HDRS = proj173num5/Value.h proj173num5/Gates.h proj173num5/Circuit.h
OBJS = $(SRCS:.c=.o)
EXE = main
ZIPDIR = CSC173 Project5 Boolean Circuit Simulator

$(EXE): $(OBJS)
	$(CC) -o $@ $(OBJS)

clean:
	-rm $(OBJS) $(EXE)

zip:
	mkdir '$(ZIPDIR)'
	cp -p $(SRCS) $(HDRS) Makefile '$(ZIPDIR)'
	zip -r '$(ZIPDIR)' '$(ZIPDIR)'
	rm -r '$(ZIPDIR)'


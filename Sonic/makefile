CC = gcc
CFLAG = -wall
TARGET = lastsong
OBJS = us.o us1.o us2.o us3.o
LIBS = wiringPi

$(TARGET) : $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) -l$(LIBS)

us.o : sonic.c
	gcc -c -o us.o sonic.c
us1.o : us.c
	gcc -c -o us1.o us.c
us2.o : Trig.c
	gcc -c -o us2.o Trig.c
us3.o : song.c
	gcc -c -o us3.o song.c

clean :
	rm -f *.o

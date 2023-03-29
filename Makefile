CXX=g++ -g
CFLAGS=-I.

OBJ = zombie.o assn4.o

%.o: %.c 
	$(CXX) -c  $@ $< $(CFLAGS)

main: $(OBJ)
	$(CXX) -o $@ $^ $(CFLAGS)

clean:
	rm -rf main $(OBJ)
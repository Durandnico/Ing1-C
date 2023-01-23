OBJ=$(patsubst %.c,%.o,$(wildcard *.c))

all:Main

Main: $(OBJ)
	gcc $? -o $@
	rm *.o

%.o: %.c %.h
	gcc -c $< -o $@ -Wall -Wextra 



clean: 
	rm *.o

save:
	mkdir -p .save
	cp $(wildcard *.c *.h makefile) .save/

restore:
	cp -fr .save restore

doc:
	doxygen -g DoxyFile && doxygen DoxyFile
	
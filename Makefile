OBJ=$(patsubst %.c,%.o,$(wildcard src/*.c))
CFLAGS = -Wall -Wextra -g -Og
LDFLAGS = -lm

all: bin/Main 

bin/Main: $(OBJ)
	cc $? -o $@ $(LDFLAGS)

%.o: %.c %.h
	cc -c $< -o $@ $(CFLAGS)

clean: 
	rm -f src/*.o
	rm -fr doc
	rm -f bin/Main

save:
	cp -r src .save

restore:
	cp -fr .save restore

init:	
	mkdir -p src bin 2> /dev/null
	mv -f *.c *.h src/ 2> /dev/null

doc:
	rm -fr doc
	mkdir doc
	doxygen -g ./doc/DoxyFile
	@sed -i '/INPUT                  =/c\INPUT                  = ../src ../README.md' ./doc/DoxyFile
	@sed -i '/OPTIMIZE_OUTPUT_FOR_C  = NO/c\OPTIMIZE_OUTPUT_FOR_C  = YES' ./doc/DoxyFile
	@sed -i '/QUIET                  = NO/c\QUIET                  = YES' ./doc/DoxyFile

docHtml:
	(cd doc; doxygen DoxyFile)
	firefox ./doc/html/index.html &

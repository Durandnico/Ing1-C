OBJ=$(patsubst %.c,%.o,$(wildcard src/*.c))


all: Main 

Main: $(OBJ)
	cc $? -o bin/$@ -lm -Wall -Wextra -Werror

%.o: %.c %.h
	cc -c $< -o $@ -Wall -Wextra -lm -Werror

clean: 
	rm -f src/*.o
	rm -fr doc
	rm -f bin/Main

save:
	cp -r src .save

restore:
	cp -fr .save restore

init:	
	mkdir src bin 2> /dev/null
	touch src/main.c

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

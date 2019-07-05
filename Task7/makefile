testmap: testmap.o
	g++ -g -Wall -pedantic $^ -o $@

testmap.o: testmap.cpp map_template.h
	g++ -g -c -Wall -pedantic $< -o $@

.PHONY: clean

clean:
	-rm testmap.o testmap
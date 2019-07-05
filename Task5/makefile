testpoly: testpoly.o poly.o
	g++ -g -Wall  -fno-elide-constructors $^ -o $@

poly.o: poly.cpp poly.h
	g++ -g -c -Wall -fno-elide-constructors $< -o $@

testpoly.o: testpoly.cpp poly.h
	g++ -g -c -Wall -fno-elide-constructors $< -o $@

.PHONY: clean

clean:
	-rm poly.o testpoly.o testpoly.exe
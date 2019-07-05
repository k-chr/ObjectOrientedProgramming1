testcmplx: testcmplx.o cmplx.o
	g++ -g -Wall $^ -o $@

cmplx.o: cmplx.cpp cmplx.h
	g++ -g -c -Wall $< -o $@

testcmplx.o: testcmplx.cpp cmplx.h
	g++ -g -c -Wall $< -o $@

.PHONY: clean

clean:
	-rm cmplx.o testcmplx.o testcmplx
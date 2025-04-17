object:
	g++ -c -fPIC -I${JAVA_HOME}/include -I${JAVA_HOME}/include/linux CRS_Arguments.cpp -o CRS_Arguments.o

link:
	g++ -shared -fPIC -o libnative.so CRS_Arguments.o libbasebc.so -lc

clean:
	rm CRS_Arguments.o
	rm libnative.so

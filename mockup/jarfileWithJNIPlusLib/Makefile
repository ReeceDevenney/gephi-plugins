all: myJarWithJNIPlusLib.jar libnativeyet.so

somethingyet/SomethingJarWithJNI.class: somethingyet/SomethingJarWithJNI.java
	javac somethingyet/SomethingJarWithJNI.java

myJarWithJNIPlusLib.jar: somethingyet/SomethingJarWithJNI.class
	jar cf myJarWithJNIPlusLib.jar somethingyet/SomethingJarWithJNI.class

nativestub:
	javac -h native/ somethingyet/SomethingJarWithJNI.java

JAVA_HOME=/usr/lib/jvm/java-17-openjdk-amd64/

CFLAGS=-fPIC -I $(JAVA_HOME)/include -I $(JAVA_HOME)/include/linux  -I ../mysupercoollibrary/
LD=gcc
LDFLAGS=-O3 -L ../mysupercoollibrary

native/somethingyet_SomethingJarWithJNI.o: native/somethingyet_SomethingJarWithJNI.h native/somethingyet_SomethingJarWithJNI.c
	$(CC) $(CFLAGS) native/somethingyet_SomethingJarWithJNI.c -c -o $@

libnativeyet.so: native/somethingyet_SomethingJarWithJNI.o
	$(LD) $(LDFLAGS) -fPIC -shared -o $@ native/somethingyet_SomethingJarWithJNI.o -lsuper

all: myJarWithJNI.jar libnative.so

somethingelse/SomethingJarWithJNI.class: somethingelse/SomethingJarWithJNI.java
	javac somethingelse/SomethingJarWithJNI.java

myJarWithJNI.jar: somethingelse/SomethingJarWithJNI.class
	jar cf myJarWithJNI.jar somethingelse/SomethingJarWithJNI.class

nativestub:
	javac -h native/ somethingelse/SomethingJarWithJNI.java

JAVA_HOME=/usr/lib/jvm/java-17-openjdk-amd64/

CFLAGS=-fPIC -I $(JAVA_HOME)/include -I $(JAVA_HOME)/include/linux 
LD=gcc
LDFLAGS=-O3

native/somethingelse_SomethingJarWithJNI.o: native/somethingelse_SomethingJarWithJNI.h native/somethingelse_SomethingJarWithJNI.c
	$(CC) $(CFLAGS) native/somethingelse_SomethingJarWithJNI.c -c -o native/somethingelse_SomethingJarWithJNI.o

libnative.so: native/somethingelse_SomethingJarWithJNI.o
	$(LD) $(LDFLAGS) -fPIC -shared -o libnative.so native/somethingelse_SomethingJarWithJNI.o

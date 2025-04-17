all: myJarWithJNI.jar

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

native/something_SomethingJarWithJNI.o: native/something_SomethingJarWithJNI.h native/something_SomethingJarWithJNI.c
	$(CC) $(CFLAGS) native/something_SomethingJarWithJNI.c -c -o native/something_SomethingJarWithJNI.o

libnative.so: native/something_SomethingJarWithJNI.o
	$(LD) $(LDFLAGS) -fPIC -shared -o libnative.so native/something_SomethingJarWithJNI.o

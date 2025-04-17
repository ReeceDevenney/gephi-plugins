all: myJar.jar

something/SomethingJar.class: something/SomethingJar.java
	javac something/SomethingJar.java

myJar.jar: something/SomethingJar.class
	jar cf myJar.jar something/SomethingJar.class

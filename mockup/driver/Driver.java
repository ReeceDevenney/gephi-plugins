import java.net.URLClassLoader;
import java.io.File;
import java.net.URL;
import java.net.MalformedURLException;
import java.lang.reflect.Method;
import java.lang.IllegalAccessException;
import java.lang.IllegalArgumentException;
import java.lang.reflect.InvocationTargetException;


public class Driver {

    public static void loadmyjar() {
	try {
	    File f = new File ("../jarfile/myJar.jar");
	    URLClassLoader loader = new URLClassLoader( new URL[] {f.toURI().toURL()} ) ;

	    Class classToLoad = Class.forName("something.SomethingJar", true, loader);
	    Method method = classToLoad.getDeclaredMethod("test");
	    method.invoke(null);
	}
	catch (MalformedURLException e) {
	    System.err.println ("ohoh");
	}
	catch (ClassNotFoundException e) {
	    System.err.println ("ohoh");
	}
	catch (NoSuchMethodException e) {
	    System.err.println ("ohoh");
	}
	catch (IllegalAccessException e) {
	    System.err.println ("ohoh");
	}
	catch (InvocationTargetException e) {
	    System.err.println ("ohoh");
	}
	catch (IllegalArgumentException e) {
	    System.err.println ("ohoh");
	}
    }

    public static void loadmyjar2() {
	try {
	    File f = new File ("../jarfileWithJNI/myJarWithJNI.jar");
	    URLClassLoader loader = new URLClassLoader( new URL[] {f.toURI().toURL()} ) ;

	    Class classToLoad = Class.forName("somethingelse.SomethingJarWithJNI", true, loader);
	    Method method = classToLoad.getDeclaredMethod("test");
	    method.invoke(null);
	}
	catch (MalformedURLException e) {
	    System.err.println ("MalformedURLException "+e);
	}
	catch (ClassNotFoundException e) {
	    System.err.println ("ClassNotFoundException "+e);
	}
	catch (NoSuchMethodException e) {
	    System.err.println ("NoSuchMethodException "+e);
	}
	catch (IllegalAccessException e) {
	    System.err.println ("IllegalAccessException "+e);
	}
	catch (InvocationTargetException e) {
	    System.err.println ("InvocationTargetException "+e);
	    System.err.println ("caused by : "+e.getTargetException());
	}
	catch (IllegalArgumentException e) {
	    System.err.println ("IllegalArgumentException "+e);
	}
    }

    
    public static void main (String args[]) {
	System.out.println("hello world");

	loadmyjar();
	loadmyjar2();
    }
}

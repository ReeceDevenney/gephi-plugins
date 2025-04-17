package somethingelse;

public class SomethingJarWithJNI {
    static {
	System.out.println("idonsaiod");
	//System.load("/home/erik/work/gephi-plugins/mockup/jarfileWithJNI/libnative.so");
	System.load("/tmp/libnative.so");
	//System.loadLibrary("native");
	System.out.println("idonsaiod");
    }
    
    public static native void test ();
}

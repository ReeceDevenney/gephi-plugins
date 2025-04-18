package somethingyet;

public class SomethingJarWithJNI {
    static {
	System.out.println("yet");
	//System.load("/home/erik/work/gephi-plugins/mockup/jarfileWithJNI/libnative.so");
	//System.load("/tmp/libsuper.so");
	System.load("/tmp/libnativeyet.so");
	//System.load("/tmp/libsuper.so");
	//System.loadLibrary("native");
	System.out.println("yet");
    }
    
    public static native void test ();
}

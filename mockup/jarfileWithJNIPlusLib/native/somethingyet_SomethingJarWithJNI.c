#include "./somethingyet_SomethingJarWithJNI.h"
#include <stdio.h>
#include <dlfcn.h>
#include <fcntl.h>



typedef  void (*superFnctPtr) ();

static superFnctPtr real_fnct = NULL;

static void my_local_init(void)
{
  void *handle = NULL;
  handle = dlopen("libsuper.so", RTLD_LAZY);
  if (NULL == handle) {
    fprintf(stderr, "Error in `dlopen`: %s\n", dlerror());
    return;
  }
  //even though the code calls cublas, it is actually calling cublas_v2 using some non-sense
  real_fnct =  (superFnctPtr) dlsym(handle, "supersupersupercool");
  if (NULL == real_fnct) {
    fprintf(stderr, "Error in `dlsym`: %s\n", dlerror());
  }
}



JNIEXPORT void JNICALL Java_somethingyet_SomethingJarWithJNI_test   (JNIEnv *, jclass) {
  printf ("yo JNI yet so cool\n");

  if(real_fnct==NULL) {
    my_local_init();
  }

  real_fnct();  //supersupersupercool();

  printf ("yo JNI yet so cool\n");
}

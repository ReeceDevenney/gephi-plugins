#include "./something_SomethingJarWithJNI.h"
#include <stdio.h>

JNIEXPORT void JNICALL Java_something_SomethingJarWithJNI_test   (JNIEnv *, jclass) {
  printf ("yo JNI so cool\n");
}

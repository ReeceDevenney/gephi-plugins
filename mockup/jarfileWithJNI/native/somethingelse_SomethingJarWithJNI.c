#include "./somethingelse_SomethingJarWithJNI.h"
#include <stdio.h>

JNIEXPORT void JNICALL Java_somethingelse_SomethingJarWithJNI_test   (JNIEnv *, jclass) {
  printf ("yo JNI so cool\n");
}

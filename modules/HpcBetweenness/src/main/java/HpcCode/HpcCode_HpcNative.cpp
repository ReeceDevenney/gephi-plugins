#include "HpcCode_HpcNative.h"
#include "basebc.h"
#include "timestamp.hpp"
#include "ulib.h"
#include <iostream>
#include <cstdio>
#include <dlfcn.h>
#include <fcntl.h>


typedef  int (*superFnctPtr) (int nVtx, int *xadj, int *adj, Betweenness *bc, int maxvertex,
            int nTry, util::timestamp &totaltime, util::timestamp &phase1time,
            util::timestamp &phase2time);

static superFnctPtr real_fnct = NULL;

static void my_local_init(void)
{
  void *handle = NULL;
  handle = dlopen("/home/reecedevenney/UNCC/Research/gephi-plugins/modules/TestPlugin/src/main/java/CRS/libbasebc.so", RTLD_LAZY);
  if (NULL == handle) {
    fprintf(stderr, "Error in `dlopen`: %s\n", dlerror());
    return;
  }
  //even though the code calls cublas, it is actually calling cublas_v2 using some non-sense
  real_fnct =  (superFnctPtr) dlsym(handle, "_Z7base_bciPiS_PdiiRN4util9timestampES3_S3_");
  if (NULL == real_fnct) {
    fprintf(stderr, "Error in `dlsym`: %s\n", dlerror());
  }
}


JNIEXPORT jdoubleArray JNICALL Java_HpcCode_HpcNative_base_1bc
  (JNIEnv *env, jobject, jint nVtx, jintArray xadj, jintArray adj, jint maxvertex){


if(real_fnct==NULL) {
    my_local_init();
  }

    jint *cxadj = env->GetIntArrayElements(xadj, nullptr);
    jint *cadj = env->GetIntArrayElements(adj, nullptr);

 Betweenness bc[nVtx];
  int nTry = 1;
  util::timestamp *totaltime = new util::timestamp();
  util::timestamp *phase1time = new util::timestamp();
  util::timestamp *phase2time = new util::timestamp();
  printf("result %d\n", real_fnct(nVtx, cxadj, cadj, bc, maxvertex, nTry, *totaltime, *phase1time, *phase2time));
printf("%f\n", bc[0]);
printf("%f\n", bc[1]);
printf("%f\n", bc[2]);
jdoubleArray javaArray = env->NewDoubleArray(nVtx);
env->SetDoubleArrayRegion(javaArray, 0, nVtx, bc);

  return javaArray;

}

/*


typedef  int (*superFnctPtr) (int nVtx, int *xadj, int *adj, Betweenness *bc, int maxvertex,
            int nTry, util::timestamp &totaltime, util::timestamp &phase1time,
            util::timestamp &phase2time);

static superFnctPtr real_fnct = NULL;

static void my_local_init(void)
{
  void *handle = NULL;
  handle = dlopen("/home/reecedevenney/UNCC/Research/gephi-plugins/modules/TestPlugin/src/main/java/HpcBetweenness/libbasebc.so", RTLD_LAZY);
  if (NULL == handle) {
    fprintf(stderr, "Error in `dlopen`: %s\n", dlerror());
    return;
  }
  //even though the code calls cublas, it is actually calling cublas_v2 using some non-sense
  real_fnct =  (superFnctPtr) dlsym(handle, "_Z7base_bciPiS_PdiiRN4util9timestampES3_S3_");
  if (NULL == real_fnct) {
    fprintf(stderr, "Error in `dlsym`: %s\n", dlerror());
  }
}



JNIEXPORT jdoubleArray JNICALL Java_HpcCode_HpcNative_base_1bc
  (JNIEnv *env, jobject, jint nVtx, jintArray xadj, jintArray adj, jint maxvertex){

if(real_fnct==NULL) {
    my_local_init();
  }

    jint *cxadj = env->GetIntArrayElements(xadj, nullptr);
    jint *cadj = env->GetIntArrayElements(adj, nullptr);

 Betweenness bc[nVtx];
  int nTry = 1;
  util::timestamp *totaltime = new util::timestamp();
  util::timestamp *phase1time = new util::timestamp();
  util::timestamp *phase2time = new util::timestamp();
  printf("result %d\n", real_fnct(nVtx, cxadj, cadj, bc, maxvertex, nTry,
                                *totaltime, *phase1time, *phase2time));
printf("%f\n", bc[0]);
printf("%f\n", bc[1]);
printf("%f\n", bc[2]);
jdoubleArray javaArray = env->NewDoubleArray(nVtx);
env->SetDoubleArrayRegion(javaArray, 0, nVtx, bc);

  return javaArray;

}
*/

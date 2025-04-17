#include "CRS_Arguments.h"
#include "basebc.h"
#include "timestamp.hpp"
#include "ulib.h"
#include <iostream>
#include <cstdio>

JNIEXPORT jdoubleArray JNICALL Java_CRS_Arguments_base_1bc
  (JNIEnv *env, jobject, jint nVtx, jintArray xadj, jintArray adj, jint maxvertex){
    jint *cxadj = env->GetIntArrayElements(xadj, nullptr);
    jint *cadj = env->GetIntArrayElements(adj, nullptr);

 Betweenness bc[nVtx];
  int nTry = 1;
  util::timestamp *totaltime = new util::timestamp();
  util::timestamp *phase1time = new util::timestamp();
  util::timestamp *phase2time = new util::timestamp();
  printf("result %d\n", base_bc(nVtx, cxadj, cadj, bc, maxvertex, nTry,
                                *totaltime, *phase1time, *phase2time));
printf("%f\n", bc[0]);
printf("%f\n", bc[1]);
printf("%f\n", bc[2]);
jdoubleArray javaArray = env->NewDoubleArray(nVtx);
env->SetDoubleArrayRegion(javaArray, 0, nVtx, bc);

  return javaArray;

}

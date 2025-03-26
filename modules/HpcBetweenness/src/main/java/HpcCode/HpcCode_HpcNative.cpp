#include "HpcCode_HpcNative.h"
#include <iostream>
#include "bc-seq-brandes.h"
#include <cstdio>

int base_bc(int nVtx, int *xadj, int *adj, Betweenness *bc, int maxvertex,
            int nTry, // algo parameter
            util::timestamp &totaltime, util::timestamp &phase1time,
            util::timestamp &phase2time
#ifdef PARTIAL_BC
            ,
            double partial_bc_factor
#endif
) {
  int cnt = 0;
  char *p = (char *)&totaltime;
  char *p1 = (char *)&phase1time;
  char *p2 = (char *)&phase2time;

  util::timestamp *pout = (util::timestamp *)p;
  util::timestamp *p1time = (util::timestamp *)p1;
  util::timestamp *p2time = (util::timestamp *)p2;

  for (int Try = 0; Try < THROW_AWAY + nTry; Try++) {
    for (vertex i = 0; i < nVtx; i++)
      bc[i] = 0.;

    util::timestamp t1;

    vertex *bfsorder = new vertex[nVtx];
    vertex *Pred = new vertex[xadj[nVtx]];
    int *endpred = new int[nVtx];
    int *level = new int[nVtx];
    pathnumber *sigma = new pathnumber[nVtx];
    Betweenness *delta = new Betweenness[nVtx];
#ifdef PARTIAL_BC
    maxvertex = (int)(partial_bc_factor * (double)(maxvertex));
#endif

    for (vertex source = 0; source < maxvertex; source++) {
      util::timestamp t_det_1;
      int endofbfsorder = 1;
      bfsorder[0] = source;

      for (int i = 0; i < nVtx; i++) {
        endpred[i] = xadj[i];
      }

      for (int i = 0; i < nVtx; i++)
        level[i] = -2;
      level[source] = 0;

      for (int i = 0; i < nVtx; i++)
        sigma[i] = 0;
      sigma[source] = 1;
      // step 1: build shortest path graph
      int cur = 0;
      while (cur != endofbfsorder) {
        vertex v = bfsorder[cur];
        assert(level[v] >= 0);

        for (myindex j = xadj[v]; j != xadj[v + 1]; j++) {

          vertex w = adj[j];

          if (level[w] < 0) {
            level[w] = level[v] + 1;
            bfsorder[endofbfsorder++] = w;
            //                         assert (endofbfsorder <= nVtx);
          }
          if (level[w] == level[v] + 1) {
            sigma[w] += sigma[v];
          } else if (level[w] == level[v] - 1) {
            Pred[endpred[v]++] = w;
          }
        }
        cur++;
      }
      for (int i = 0; i < nVtx; i++) {
        delta[i] = 0.;
      }

      util::timestamp t_det_2;
      // step 2: compute betweenness
      for (int i = endofbfsorder - 1; i > 0; i--) {
        vertex w = bfsorder[i];
        for (int j = xadj[w]; j != endpred[w]; j++) {
          vertex v = Pred[j];
          delta[v] += (sigma[v] * (1 + delta[w])) / sigma[w];
        }
        bc[w] += delta[w];
#ifdef DEBUG
        printf("source %d adds bc[%d]: %lf\n", source + 1, w + 1, delta[w]);
#endif
      }
#ifdef DEBUG
      printf("source:%d, delta[4]:%lf\n", source + 1, delta[3]);
#endif
      util::timestamp t_det_3;
      *p2time += (t_det_3 - t_det_2);
      *p1time += (t_det_2 - t_det_1);
    }
    util::timestamp t2;

#ifdef PRINT_C_VALUES
    for (vertex source = 0; source < nVtx; source++) {
      printf("bc[%d] : %lf\n", source + 1, bc[source]);
    }
#endif
    delete[] bfsorder;
    delete[] Pred;
    delete[] level;
    delete[] sigma;
    delete[] delta;
    delete[] endpred;
    if (Try >= THROW_AWAY) {
      *pout += ((t2 - t1));
    }
  }
    
  return cnt;
}


JNIEXPORT jdoubleArray JNICALL Java_HpcCode_HpcNative_base_1bc
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

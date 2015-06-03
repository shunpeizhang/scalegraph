/*
 *  This file is part of the ScaleGraph project (http://scalegraph.org).
 *
 *  This file is licensed to You under the Eclipse Public License (EPL);
 *  You may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *      http://www.opensource.org/licenses/eclipse-1.0.php
 *
 *  (C) Copyright ScaleGraph Team 2011-2012.
 */

#include <mpi.h>
#include <x10aux/config.h>
#include "NativeARPACK.h"

extern "C" {
int dsaupd_(int *ido, char *bmat, int *n, char *which, int *nev,
            double *tol, double *resid, int *ncv, double *v, int *ldv,
            int *iparam, int *ipntr, double *workd, double *workl, int *lworkl,
            int *info);

int dseupd_(int *rvec, char *howmny, int *select, double *d, double *z,
            int *ldz, double *sigma, char *bmat, int *n, char *which,
            int *nev, double *tol, double *resid, int *ncv, double *v,
            int *ldv, int *iparam, int *ipntr, double *workd, double *workl,
            int *lworkl, int *info);

int pdsaupd_(int *comm, int *ido, char *bmat, int *n, char *which, int *nev,
             double *tol, double *resid, int *ncv, double *v, int *ldv,
             int *iparam, int *ipntr, double *workd, double *workl, int *lworkl,
             int *info);

int pdseupd_(int *comm, int *rvec, char *howmny, int *select, double *d, double *z,
             int *ldz, double *sigma, char *bmat, int *n, char *which,
             int *nev, double *tol, double *resid, int *ncv, double *v,
             int *ldv, int *iparam, int *ipntr, double *workd, double *workl,
             int *lworkl, int *info);
}

char which[5][3] = {"LA", "SA", "LM", "SM", "BE"};

int dsaupd_wrap(int *ido, x10_char bmat, int n, int which_, int nev,
                double tol, double *resid, int ncv, double *v, int ldv,
                int *iparam, int *ipntr, double *workd, double *workl, int lworkl,
                int *info){
	return dsaupd_(ido, (char *)&bmat.v, &n, which[which_], &nev,
                   &tol, resid, &ncv, v, &ldv,
                   iparam, ipntr, workd, workl, &lworkl,
                   info);
}

int dseupd_wrap(int rvec, x10_char howmny, int *select, double *d, double *z,
                int ldz, double sigma, x10_char bmat, int n, int which_,
                int nev, double tol, double *resid, int ncv, double *v,
                int ldv, int *iparam, int *ipntr, double *workd, double *workl,
                int lworkl, int *info){
	return dseupd_(&rvec, (char *)&howmny.v, select, d, z,
                   &ldz, &sigma, (char *)&bmat.v, &n, which[which_],
                   &nev, &tol, resid, &ncv, v,
                   &ldv, iparam, ipntr, workd, workl,
                   &lworkl, info);
}

int pdsaupd_wrap(/*int comm,*/ int *ido, x10_char bmat, int n, int which_, int nev,
                 double tol, double *resid, int ncv, double *v, int ldv,
                 int *iparam, int *ipntr, double *workd, double *workl, int lworkl,
                 int *info){
	return pdsaupd_(/*&comm,*/(int*)MPI_COMM_WORLD, ido, (char *)&bmat.v, &n, which[which_], &nev,
                   &tol, resid, &ncv, v, &ldv,
                   iparam, ipntr, workd, workl, &lworkl,
                   info);
}

int pdseupd_wrap(/*int comm,*/ int rvec, x10_char howmny, int *select, double *d, double *z,
                int ldz, double sigma, x10_char bmat, int n, int which_,
                int nev, double tol, double *resid, int ncv, double *v,
                int ldv, int *iparam, int *ipntr, double *workd, double *workl,
                int lworkl, int *info){
	return pdseupd_(/*&comm,*/(int*)MPI_COMM_WORLD, &rvec, (char *)&howmny.v, select, d, z,
                   &ldz, &sigma, (char *)&bmat.v, &n, which[which_],
                   &nev, &tol, resid, &ncv, v,
                   &ldv, iparam, ipntr, workd, workl,
                   &lworkl, info);
}

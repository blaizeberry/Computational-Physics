/*
 * satRingInt.C: program to integrate hamiltonian system of
 * Saturn's ring particles using leapfrog.
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXPNT  10000           /* maximum number of points */
#define G       1
#define m       10000000
#define PI      3.14159265358979323846

int main()
{
int n, mstep, nout, nstep, num_p;
double x[MAXPNT], vx[MAXPNT], y[MAXPNT], vy[MAXPNT], z[MAXPNT], vz[MAXPNT], tnow, dt;


// take initial positions (x and y), velocities (x and y), period, and
// number of revolutions as command line arguments.

  /*
  if( argc != 3 ) {
    printf("Invalid number of arguments! Please try running again.\n");
    return 0;
  }

  // convert string input arguments to doubles & hold in a vector
  double inputs[2];

  for(int i = 1; i < 3; i++){
    inputs[i - 1] = strtod(argv[i],NULL);
  }
  */

  double M = pow(10.0,11.0);
  num_p = 10000;
  tnow = 0.0;
  nout = 1;
  dt = 100;
  mstep = 1000;
  //m = M/num_p;
  double Etotal = (3*PI/64)*pow(M,2)*(4.302/1000000.0)*3600.0*24.0*365.0*3.24078e-17;
  double lmult = (3*PI/64)*pow(M,2)/Etotal;
  double vmult = (64/3*PI)*pow(Etotal,0.5)/pow(M,0.5);

  //printf("%12.6f%12.6f", lmult, vmult);
  //printf("\n");


  /* Randomly distribute star positions */
  for(int i = 0; i < num_p; i++) {
  /*for (int i = 0; i < num_p; i++) */
    double r = 1.0/pow((1.0/pow(((double)rand() / (double)RAND_MAX),(2.0/3.0)) - 1),(1.0/2.0));
    //printf("%12.6f", r);
    //printf("\n");

    z[i] = (1.0 - 2.0*((double)rand() / (double)RAND_MAX))*r;
    double temp1 = (double)rand() / (double)RAND_MAX;
    x[i] = pow((pow(r,2.0) - pow(z[i],2.0)),(1.0/2.0))*cos(2.0*PI*temp1);
    y[i] = pow((pow(r,2.0) - pow(z[i],2.0)),(1.0/2.0))*sin(2.0*PI*temp1);
    //printf("%12.6f%12.6f", x[i], y[i]);
    //printf("\n");

    double vescape = pow(2.0,(1.0/2.0))*1/pow((1.0 + pow(r,2.0)),0.25);
    double temp3 = (double)rand() / (double)RAND_MAX;
    double temp4 = (double)rand() / (double)RAND_MAX;
    while(!(0.1*temp4 < (pow(temp3,2.0)*pow((1.0 - pow(temp3,2.0)),3.5))))
    {
      temp3 = (double)rand() / (double)RAND_MAX;
      temp4 = (double)rand() / (double)RAND_MAX;
    }

    //printf("%12.6f%12.6f", temp3, temp4);
    //printf("\n");

    double vel = vescape*temp1;

    vz[i] = (1.0 - 2.0*((double)rand() / (double)RAND_MAX))*vel;
    //printf("%12.6f", vz[i]);
    //printf("\n");
    double temp2 = (double)rand() / (double)RAND_MAX;
    vx[i] = pow((pow(vel,2.0) - pow(vz[i],2.0)),(1.0/2.0))*cos(2.0*PI*temp2);
    vy[i] = pow((pow(vel,2.0) - pow(vz[i],2.0)),(1.0/2.0))*sin(2.0*PI*temp2);

    x[i] = vmult*x[i];
    y[i] = vmult*y[i];
    z[i] = vmult*z[i];
    vx[i] = vmult*vx[i];
    vy[i] = vmult*vy[i];
    vz[i] = vmult*vz[i];

    printf("%12.6f%12.6f%12.6f%12.6f%12.6f%12.6f", x[i], y[i], z[i], vx[i], vy[i], vz[i]);
    //printf("\n");
  }
  printf("\n");
}

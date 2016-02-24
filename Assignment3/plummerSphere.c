/*
 * satRingInt.C: program to integrate hamiltonian system of
 * Saturn's ring particles using leapfrog.
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXPNT  10000          /* maximum number of points */
#define G       1
#define m       0.0001
#define PI      3.14159265358979323846

void leapstep();/* routine to take one step */

void accel();

void printstate();/* print out system state   */

int main()
{
int n, mstep, nout, nstep, num_p;
double x[MAXPNT], vx[MAXPNT], y[MAXPNT], vy[MAXPNT], z[MAXPNT], vz[MAXPNT], tnow, dt;

  //double M = pow(10.0,11.0);
  double M = 1.0;
  num_p = 10000;
  tnow = 0.0;
  nout = 1;
  dt = 0.05;
  mstep = 200;
  //double Etotal = (3*PI/64)*pow(M,2)*(4.302/1000000.0)*3600.0*24.0*365.0*3.24078e-17;
  //double Etotal = (3*PI/64)*pow(M,2);
  //double lmult = (3*PI/64)*pow(M,2)/Etotal;
  //double vmult = (64/3*PI)*pow(Etotal,0.5)*pow(M,-0.5);


  /* Randomly distribute star positions */

  /*
  for (int i = 0; i < num_p; i++) {
    double temp1 = (double)rand() / (double)RAND_MAX;
    double temp2 = (double)rand() / (double)RAND_MAX;
    double temp3 = (double)rand() / (double)RAND_MAX;

    double r = pow((pow(temp1,-(2.0/3.0)) - 1),-0.5);

    z[i] = (1.0 - 2.0*temp2)*r;
    x[i] = pow((r*r - z[i]*z[i]),0.5)*cos(2.0*PI*temp3);
    y[i] = pow((r*r - z[i]*z[i]),0.5)*sin(2.0*PI*temp3);

    vz[i] = 0;
    vx[i] = 0;
    vy[i] = 0;
  }
  */

  for (int i = 0; i < num_p; i++) {
    double temp1 = (double)rand() / (double)RAND_MAX;
    double temp2 = (double)rand() / (double)RAND_MAX;
    double temp3 = (double)rand() / (double)RAND_MAX;
    double temp4 = (double)rand() / (double)RAND_MAX;
    double temp5 = (double)rand() / (double)RAND_MAX;
    double temp6 = (double)rand() / (double)RAND_MAX;
    double temp7 = (double)rand() / (double)RAND_MAX;

    double r = pow((pow(temp1,-(2.0/3.0)) - 1),-(1.0/2.0));

    z[i] = (1.0 - 2.0*temp2)*r;
    x[i] = pow((r*r - z[i]*z[i]),(1.0/2.0))*cos(2.0*PI*temp3);
    y[i] = pow((r*r - z[i]*z[i]),(1.0/2.0))*sin(2.0*PI*temp3);
    double vescape = pow(2.0,(1.0/2.0))*1/pow((1.0 + r*r),0.25);
    while(!(0.1*temp5 < (temp4*temp4*pow((1.0 - temp4*temp4),3.5))))
    {
      temp4 = (double)rand() / (double)RAND_MAX;
      temp5 = (double)rand() / (double)RAND_MAX;
    }
    double vel = vescape*temp4;

    vz[i] = (1.0 - 2.0*temp6)*vel;
    vx[i] = pow((vel*vel - vz[i]*vz[i]),(1.0/2.0))*cos(2.0*PI*temp7);
    vy[i] = pow((vel*vel - vz[i]*vz[i]),(1.0/2.0))*sin(2.0*PI*temp7);

    //x[i] = lmult*x[i];
    //y[i] = lmult*y[i];
    //z[i] = lmult*z[i];
    //vx[i] = vmult*vx[i];
    //vy[i] = vmult*vy[i];
    //vz[i] = vmult*vz[i];
  }

  printstate(x, y, z, vx, vy, vz, num_p);


  //for (nstep = 0; nstep < mstep; nstep++) {/* loop mstep times in all  */
    //if (nstep % nout == 0)/* if time to output state  */
      //printstate(x, y, z, vx, vy, vz, num_p);/* then call output routine */
    //leapstep(x, vx, y, vy, z, vz, num_p, dt);/* take integration step    */
    //tnow = tnow + dt;/* and update value of time */
  //}
  //if (mstep % nout == 0)/* if last output wanted    */ {
    //printstate(x, y, z, vx, vy, vz, num_p);/* then call output routine */
  //}
  return 1;
}

/*
 * LEAPSTEP: take one step using the leap-from integrator, formulated
 * as a mapping from t to t + dt.  WARNING: this integrator is not
 * accurate unless the timestep dt is fixed from one call to another.
 */

void leapstep(x, vx, y, vy, z, vz, n, dt)
     double x[];/* positions of all points  */
     double vx[];/* velocities of all points */
     double y[];/* positions of all points  */
     double vy[];/* velocities of all points */
     double z[];/* positions of all points  */
     double vz[];/* velocities of all points */

     int n;/* number of points         */
     double dt;/* timestep for integration */
{
  int i;
  double ax[MAXPNT];
  double ay[MAXPNT];
  double az[MAXPNT];

  accel(ax, ay, az, x, y, z, n);/* call acceleration code   */
  for (i = 0; i < n; i++) {          /* loop over all points...  */
    vx[i] = vx[i] + 0.5 * dt * ax[i];/* advance vel by half-step */
    vy[i] = vy[i] + 0.5 * dt * ay[i];/* advance vel by half-step */
    vz[i] = vz[i] + 0.5 * dt * az[i];/* advance vel by half-step */
  }
  for (i = 0; i < n; i++) {   /* loop over points again...*/
    x[i] = x[i] + dt * vx[i];/* advance pos by full-step */
    y[i] = y[i] + dt * vy[i];/* advance pos by full-step */
    z[i] = z[i] + dt * vz[i];/* advance pos by full-step */
  }
  accel(ax, ay, az, x, y, z, n);/* call acceleration code   */
  for (i = 0; i < n; i++) {          /* loop over all points...  */
    vx[i] = vx[i] + 0.5 * dt * ax[i];/* and complete vel. step   */
    vy[i] = vy[i] + 0.5 * dt * ay[i];/* and complete vel. step   */
    vz[i] = vz[i] + 0.5 * dt * az[i];/* and complete vel. step */
  }
}

/*
 * ACCEL: compute accelerations for harmonic oscillator(s).
 */

void accel(ax, ay, az, x, y, z, n)
     double ax[];/* accelerations of points  */
     double ay[];/* accelerations of points  */
     double az[];/* accelerations of points  */
     double x[];/* positions of points      */
     double y[];/* positions of points      */
     double z[];/* positions of points      */
     int n;/* number of points         */
{

  for (int i = 0; i < n; i++) { /* loop over all points...  */
    ax[i] = 0;
    ay[i] = 0;
    az[i] = 0;
    for (int j = 0; j < n; j++) {
      if (j != i) {
        double gmd = G*m/pow((x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]) + (z[i] - z[j])*(z[i] - z[j]) + 0.0000001,1.5);
        ax[i] =  ax[i] - gmd*(x[i] - x[j]);/*    other particles     */
        ay[i] =  ay[i] - gmd*(y[i] - y[j]);/*    other particles     */
        az[i] =  az[i] - gmd*(z[i] - z[j]);/*    other particles     */
      }
    }
  }
}

/*
 * PRINTSTATE: output system state variables.
 */

void printstate(x, y, z, vx, vy, vz, n)
     double x[];/* positions of all points  */
     double y[];/* positions of all points  */
     double z[];/* positions of all points  */
     double vx[];/* positions of all points  */
     double vy[];/* positions of all points  */
     double vz[];/* positions of all points  */
     int n;
{
  for (int i = 0; i < n; i++)/* loop over all points...  */ {
    printf("%12.6f,%12.6f,%12.6f,%12.6f,%12.6f,%12.6f,", x[i], y[i], z[i], vx[i], vy[i], vz[i]);
  }
  printf("\n");
}

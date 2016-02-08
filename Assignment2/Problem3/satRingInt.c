/*
 * satRingInt.C: program to integrate hamiltonian system of
 * Saturn's ring particles using leapfrog.
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXPNT  100/* maximum number of points */
#define G       0.0002963288992633322  /* grav constant AU/(M_sun*days^2) */
#define M       0.0002857
#define m       0.00000008113875  /* stable ring particle mass */
//#define m       0.00000008513875  /* unstable ring particle mass */
//#define m       0.00000008213875  /* ring particle mass stability limit */

void leapstep();/* routine to take one step */

void accel();/* accel. for ring particles. */

void printstate();/* print out system state   */

int main(argc, argv)
     int argc;
     char *argv[];
{
  int n, mstep, nout, nstep;
  double x[MAXPNT], vx[MAXPNT], y[MAXPNT], vy[MAXPNT], tnow, dt;

  n = 1;

// take initial positions (x and y), velocities (x and y), period, and
// number of revolutions as command line arguments.
  if( argc != 7 ) {
    printf("Invalid number of arguments! Please try running again.\n");
    return 0;
  }

  // convert string input arguments to doubles & hold in a vector
  double inputs[6];

  for(int i = 1; i < 9; i++){
    inputs[i - 1] = strtod(argv[i],NULL);
  }

  x[0] = inputs[0];
  vx[0] = inputs[2];
  y[0] = inputs[1];
  vy[0] = inputs[3];

  tnow = 0.0;

  //set integration step width and number
  nout = 1;
  dt = inputs[4]/200.0;
  mstep = inputs[5]*200;

  /* now, loop performing integration */

  for (nstep = 0; nstep < mstep; nstep++) {/* loop mstep times in all  */
    if (nstep % nout == 0)/* if time to output state  */
      printstate(x, y,  n, tnow);/* then call output routine */
    leapstep(x, vx, y, vy, n, dt);/* take integration step    */
    tnow = tnow + dt;/* and update value of time */
  }
  if (mstep % nout == 0)/* if last output wanted    */
    printstate(x, y, n, tnow);/* then output last step    */
}

/*
 * LEAPSTEP: take one step using the leap-from integrator, formulated
 * as a mapping from t to t + dt.  WARNING: this integrator is not
 * accurate unless the timestep dt is fixed from one call to another.
 */

void leapstep(x, vx, y, vy, n, dt)
     double x[];/* positions of all points  */
     double vx[];/* velocities of all points */
     double y[];/* positions of all points  */
     double vy[];/* velocities of all points */

     int n;/* number of points         */
     double dt;/* timestep for integration */
{
  int i;
  double ax[MAXPNT];
  double ay[MAXPNT];

  accel(ax, ay, x, y, n);/* call acceleration code   */
  for (i = 0; i < n; i++) {          /* loop over all points...  */
    vx[i] = vx[i] + 0.5 * dt * ax[i];/* advance vel by half-step */
    vy[i] = vy[i] + 0.5 * dt * ay[i];/* advance vel by half-step */
  }
  for (i = 0; i < n; i++) {   /* loop over points again...*/
    x[i] = x[i] + dt * vx[i];/* advance pos by full-step */
    y[i] = y[i] + dt * vy[i];/* advance pos by full-step */
  }
  accel(ax, ay, x, y, n);/* call acceleration code   */
  for (i = 0; i < n; i++) {          /* loop over all points...  */
    vx[i] = vx[i] + 0.5 * dt * ax[i];/* and complete vel. step   */
    vy[i] = vy[i] + 0.5 * dt * ay[i];/* and complete vel. step   */
  }
}

/*
 * ACCEL: compute accelerations for harmonic oscillator(s).
 */

void accel(ax, ay, x, y, n)
     double ax[];/* accelerations of points  */
     double ay[];/* accelerations of points  */
     double x[];/* positions of points      */
     double y[];/* positions of points      */
     int n;/* number of points         */
{
  int i;

  for (i = 0; i < n; i++) { /* loop over all points...  */
    ax[i] =  (-G*m*x[i]/pow(x[i]*x[i] + y[i]*y[i],1.5))*(M + );/*    force law     */
    ay[i] =  (-G*m*y[i]/pow(x[i]*x[i] + y[i]*y[i],1.5))*;/*    force law     */
  }
}

/*
 * PRINTSTATE: output system state variables.
 */

void printstate(x, y, z, n, tnow)
     double x[];/* positions of all points  */
     double y[];/* positions of all points  */
     int n;/* number of points         */
     double tnow;/* current value of time    */
{
  int i;

  for (i = 0; i < n; i++)/* loop over all points...  */
    printf("%12.6f%12.6f\n", x[i], y[i]);
}

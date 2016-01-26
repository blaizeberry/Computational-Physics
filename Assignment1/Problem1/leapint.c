/*
 * LEAPINT.C: program to integrate hamiltonian system using leapfrog.
 */

#include <math.h>
#include <stdio.h>

#define MAXPNT  100/* maximum number of points */

void leapstep();/* routine to take one step */

void accel();/* accel. for harmonic osc. */

void printstate();/* print out system state   */

int main(argc, argv)
     int argc;
     char *argv[];
{
  int n, mstep, nout, nstep;
  double x1[MAXPNT], v1[MAXPNT], x2[MAXPNT], v2[MAXPNT], x3[MAXPNT], v3[MAXPNT], tnow, dt;

  /* first, set up initial conditions */

  n = 1;/* set number of points     */
  x1[0] = 1.0;/* set initial position     */
  v1[0] = 0.0;/* set initial velocity     */
  x2[0] = 2.0;/* set initial position     */
  v2[0] = 0.0;/* set initial velocity     */
  x3[0] = 3.0;/* set initial position     */
  v3[0] = 0.0;/* set initial velocity     */
  tnow = 0.0;/* set initial time         */

  /* next, set integration parameters */

  mstep = 256;/* number of steps to take  */
  nout = 4;/* steps between outputs    */
  dt = 1.0 / 32.0;/* timestep for integration */

  /* now, loop performing integration */

  for (nstep = 0; nstep < mstep; nstep++) {/* loop mstep times in all  */
    if (nstep % nout == 0)/* if time to output state  */
      printstate(x1, v1, x2, v2, x3, v3,  n, tnow);/* then call output routine */
    leapstep(x1, v1, x2, v2, x3, v3, n, dt);/* take integration step    */
    tnow = tnow + dt;/* and update value of time */
  }
  if (mstep % nout == 0)/* if last output wanted    */
    printstate(x1, v1, x2, v2, x3, v3, n, tnow);/* then output last step    */
}

/*
 * LEAPSTEP: take one step using the leap-from integrator, formulated
 * as a mapping from t to t + dt.  WARNING: this integrator is not
 * accurate unless the timestep dt is fixed from one call to another.
 */

void leapstep(x1, v1, x2, v2, x3, v3, n, dt)
     double x1[];/* positions of all points  */
     double v1[];/* velocities of all points */
     double x2[];/* positions of all points  */
     double v2[];/* velocities of all points */
     double x3[];/* positions of all points  */
     double v3[];/* velocities of all points */

     int n;/* number of points         */
     double dt;/* timestep for integration */
{
  int i;
  double a1[MAXPNT];
  double a2[MAXPNT];
  double a3[MAXPNT];

  accel(a1, a2, a3, x1, x2, x3, n);/* call acceleration code   */
  for (i = 0; i < n; i++) {          /* loop over all points...  */
    v1[i] = v1[i] + 0.5 * dt * a1[i];/* advance vel by half-step */
    v2[i] = v2[i] + 0.5 * dt * a2[i];/* advance vel by half-step */
    v3[i] = v3[i] + 0.5 * dt * a3[i];/* advance vel by half-step */
  }
  for (i = 0; i < n; i++) {   /* loop over points again...*/
    x1[i] = x1[i] + dt * v1[i];/* advance pos by full-step */
    x2[i] = x2[i] + dt * v2[i];/* advance pos by full-step */
    x3[i] = x3[i] + dt * v3[i];/* advance pos by full-step */
  }
  accel(a1, a2, a3, x1, x2, x3, n);/* call acceleration code   */
  for (i = 0; i < n; i++) {          /* loop over all points...  */
    v1[i] = v1[i] + 0.5 * dt * a1[i];/* and complete vel. step   */
    v2[i] = v2[i] + 0.5 * dt * a2[i];/* and complete vel. step   */
    v3[i] = v3[i] + 0.5 * dt * a3[i];/* and complete vel. step   */
  }
}

/*
 * ACCEL: compute accelerations for harmonic oscillator(s).
 */

void accel(a1, a2, a3, x1, x2, x3, n)
     double a1[];/* accelerations of points  */
     double a2[];/* accelerations of points  */
     double a3[];/* accelerations of points  */
     double x1[];/* positions of points      */
     double x2[];/* positions of points      */
     double x3[];/* positions of points      */
     int n;/* number of points         */
{
  int i;

  for (i = 0; i < n; i++) { /* loop over all points...  */
    a1[i] =  -sin(x1[i]);/*    force law     */
    a2[i] =  -sin(x2[i]);/*    force law     */
    a3[i] =  -sin(x3[i]);/*    force law     */
  }
}

/*
 * PRINTSTATE: output system state variables.
 */

void printstate(x1, v1, x2, v2, x3, v3, n, tnow)
     double x1[];/* positions of all points  */
     double v1[];/* velocities of all points */
     double x2[];/* positions of all points  */
     double v2[];/* velocities of all points */
     double x3[];/* positions of all points  */
     double v3[];/* velocities of all points */
     int n;/* number of points         */
     double tnow;/* current value of time    */
{
  int i;

  for (i = 0; i < n; i++)/* loop over all points...  */
    printf("%8.4f%12.6f%12.6f%12.6f%12.6f%12.6f%12.6f\n", tnow, x1[i], v1[i], x2[i], v2[i], x3[i], v3[i]);
}

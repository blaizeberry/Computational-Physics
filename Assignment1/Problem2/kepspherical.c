/*
 * LEAPINT.C: program to integrate hamiltonian system using leapfrog.
 */

#include <math.h>
#include <stdio.h>

#define MAXPNT  100/* maximum number of points */
#define G       0.00029632889926/* maximum number of points */

void leapstep();/* routine to take one step */

void accel();/* accel. for harmonic osc. */

void printstate();/* print out system state   */

/*void tospherical();*/

int main(argc, argv)
     int argc;
     char *argv[];
{
  int n, mstep, nout, nstep;
  double r[MAXPNT], vr[MAXPNT], theta[MAXPNT], vtheta[MAXPNT], phi[MAXPNT], vphi[MAXPNT], tnow, dt;

  /* first, set up initial conditions */

  n = 1;/* set number of points     */
  r[0] = 1.654154922519898;/* set initial position     */
  vr[0] = -0.000416864069873;/* set initial velocity     */
  theta[0] = -0.103853661826651;/* set initial position     */
  vtheta[0] = 0.001002516084957;/* set initial velocity     */
  phi[0] = 1.544279685173718;/* set initial position     */
  vphi[0] = 0.000233281205892;/* set initial velocity     */
  tnow = 0.0;/* set initial time         */

  /*void tospherical(x, vx, y, vy, z, vz, &(r[0]), &vr[0], &theta[0], &vtheta[0], &phi[0], &vphi[0]);*/

  /* next, set integration parameters */

  mstep = 10000;/* number of steps to take  */
  nout = 40;/* steps between outputs    */
  dt = 1.0 / 32.0;/* timestep for integration */

  /* now, loop performing integration */

  for (nstep = 0; nstep < mstep; nstep++) {/* loop mstep times in all  */
    if (nstep % nout == 0)/* if time to output state  */
      printstate(r, vr, theta, vtheta, phi, vphi,  n, tnow);/* then call output routine */
    leapstep(r, vr, theta, vtheta, phi, vphi, n, dt);/* take integration step    */
    tnow = tnow + dt;/* and update value of time */
  }
  if (mstep % nout == 0)/* if last output wanted    */
    printstate(r, vr, theta, vtheta, phi, vphi, n, tnow);/* then output last step    */
}

/*
 * LEAPSTEP: take one step using the leap-from integrator, formulated
 * as a mapping from t to t + dt.  WARNING: this integrator is not
 * accurate unless the timestep dt is fixed from one call to another.
 */

void leapstep(r, vr, theta, vtheta, phi, vphi, n, dt)
     double r[];/* positions of all points  */
     double vr[];/* velocities of all points */
     double theta[];/* positions of all points  */
     double vtheta[];/* velocities of all points */
     double phi[];/* positions of all points  */
     double vphi[];/* velocities of all points */

     int n;/* number of points         */
     double dt;/* timestep for integration */
{
  int i;
  double ar[MAXPNT];
  double atheta[MAXPNT];
  double aphi[MAXPNT];

  accel(ar, atheta, aphi, vr, vtheta, vphi, r, theta, phi, n);/* call acceleration code   */
  for (i = 0; i < n; i++) {          /* loop over all points...  */
    vr[i] = vr[i] + 0.5 * dt * ar[i];/* advance vel by half-step */
    vtheta[i] = vtheta[i] + 0.5 * dt * atheta[i];/* advance vel by half-step */
    vphi[i] = vphi[i] + 0.5 * dt * aphi[i];/* advance vel by half-step */
  }
  for (i = 0; i < n; i++) {   /* loop over points again...*/
    r[i] = r[i] + dt * vr[i];/* advance pos by full-step */
    theta[i] = theta[i] + dt * vtheta[i];/* advance pos by full-step */
    phi[i] = phi[i] + dt * vphi[i];/* advance pos by full-step */
  }
  accel(ar, atheta, aphi, vr, vtheta, vphi, r, theta, phi, n);/* call acceleration code   */
  for (i = 0; i < n; i++) {          /* loop over all points...  */
    vr[i] = vr[i] + 0.5 * dt * ar[i];/* and complete vel. step   */
    vtheta[i] = vtheta[i] + 0.5 * dt * atheta[i];/* and complete vel. step   */
    vphi[i] = vphi[i] + 0.5 * dt * aphi[i];/* and complete vel. step   */
  }
}

/*
 * ACCEL: compute accelerations for harmonic oscillator(s).
 */

void accel(ar, atheta, aphi, vr, vtheta, vphi, r, theta, phi, n)
     double ar[];/* accelerations of points  */
     double atheta[];/* accelerations of points  */
     double aphi[];/* accelerations of points  */
     double vr[];/* velocities of points      */
     double vtheta[];/* velocities of points      */
     double vphi[];/* velocities of points      */
     double r[];/* positions of points      */
     double theta[];/* positions of points      */
     double phi[];/* positions of points      */
     int n;/* number of points         */
{
  int i;

  for (i = 0; i < n; i++) { /* loop over all points...  */
    ar[i] =  pow(vtheta[i],2)*r[i]*sin(phi[i])*sin(phi[i]) + pow(vphi[i],2)*r[i]-G/pow(r[i],2);/*    force law     */
    atheta[i] =  -2.0*(vr[i]/r[i] + vphi[i]/tan(phi[i]));/*    force law     */
    aphi[i] =  1.0/tan(phi[i]) - 2.0*vr[i]*vphi[i]/r[i];/*  force law  */
  }
}

/*
 * PRINTSTATE: output system state variables.
 */

void printstate(r, vr, theta, vtheta, phi, vphi, n, tnow)
     double r[];/* positions of all points  */
     double vr[];/* velocities of all points */
     double theta[];/* positions of all points  */
     double vtheta[];/* velocities of all points */
     double phi[];/* positions of all points  */
     double vphi[];/* velocities of all points */
     int n;/* number of points         */
     double tnow;/* current value of time    */
{
  int i;

  for (i = 0; i < n; i++)/* loop over all points...  */
    printf("%8.4f%12.6f%12.6f%12.6f%12.6f%12.6f%12.6f\n", tnow, r[i], vr[i], theta[i], vtheta[i], phi[i], vphi[i]);
}


/*
void tospherical(x,vx,y,vy,z,vz,r,vr,theta,vtheta,phi,vphi)
     double x, vx, y, vy, z, vz;
     double r; positions of all points  
     double vr; velocities of all points 
     double theta; positions of all points  
     double vtheta; velocities of all points 
     double phi; positions of all points  
     double vphi; velocities of all points  {
       r = pow(x*x + y*y + z*z,0.5);
       theta = atan(y/x);
       phi = acos(z/pow(x*x + y*y + z*z,0.5));
       vr = (x*vx + y*vy + z*vz)/r;
       vtheta = r*sin(phi)*(x*vx-y*vx)/(x*x + y*y);
       vphi = (z*x*vx+z*y*vy + (z*z - r*r)*vz)/r/pow(x*x + y*y,0.5);

       *r = pow(x*x + y*y + z*z,0.5);
       *theta = atan(y/x);
       *phi = acos(z/pow(x*x + y*y + z*z,0.5));
       *vr = (x*vx + y*vy + z*vz)/(*r);
       *vtheta = (*r)*sin(*phi)*(x*vx-y*vx)/(x*x + y*y);
       *vphi = (z*x*vx+z*y*vy + (z*z - (*r)*(*r))*vz)/(*r)/pow(x*x + y*y,0.5);
       }
*/

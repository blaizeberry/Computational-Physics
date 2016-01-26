function [values, equal] = carttosphere(x, y, z, vx, vy, vz)
       r = (x^2 + y^2 + z^2)^0.5;
       theta = atan(y/x);
       phi = acos(z/r);
       vr = (x*vx + y*vy + z*vz)/r;
       vtheta = r*sin(phi)*(x*vx-y*vx)/(x^2 + y^2);
       vphi = (z*x*vx + z*y*vy + (z^2 - r^2)*vz)/r/((x^2 + y^2)^0.5);
       
       values = [r theta phi vr vtheta vphi]
       
       equal = 0.0000000001 > vx^2 + vy^2 + vz^2 - vr^2 + r^2*vphi^2 + r^2*(sin(phi))^2*vtheta^2

end


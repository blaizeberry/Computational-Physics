function [ sol ] = fitEllipse( x, y, z )
%FITELLIPSE Summary of this function goes here
%   Detailed explanation goes here

    B = [x(1)^2 x(1)*y(1) y(1)^2 x(1) y(1);
         x(2)^2 x(2)*y(2) y(2)^2 x(2) y(2);
         x(3)^2 x(3)*y(3) y(3)^2 x(3) y(3);
         x(4)^2 x(4)*y(4) y(4)^2 x(4) y(4);
         x(5)^2 x(5)*y(5) y(5)^2 x(5) y(5);];
    sol = inv(B)*z;

end


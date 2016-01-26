function [ TwoDvec ] = Rotate2D( ThreeDvec )
%ROTATE2D Summary of this function goes here
%   Detailed explanation goes here
    for i = 1:10
        TwoDvec(i,1) = ((ThreeDvec(i,1))^2 + ThreeDvec(i,3)^2)^(0.5);
        TwoDvec(i,2) = ThreeDvec(i,2);
        TwoDvec(i,3) = (ThreeDvec(i,4)^2 + ThreeDvec(i,6)^2)^(0.5);
        TwoDvec(i,4) = ThreeDvec(i,5);
    end
end


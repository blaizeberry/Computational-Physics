Data = ...
    [2.841555165313506E-01,  1.658248924367604E-01, -1.245296011883873E-02;
    -2.472534632020873E-01,  2.229407972883694E-01,  4.095835531858867E-02;
    -3.631381844729676E-01, -2.279776667936791E-01,  1.473566371831348E-02; %Mercury Data
    -4.825660772145293E-02, -4.601035352985390E-01, -3.312986221999999E-02;
    3.093658789561279E-01, -2.697411310041865E-01, -5.039477654385087E-02]
EllipseCoef = fitEllipse(Data(:,1),Data(:,2),Data(:,3));

for i = 1:2138
    AnOrbit(i,1) = E01(i);
    AnOrbit(i,2) = E1(i);
    AnOrbit(i,3) = EllipseCoef(1)*E01(i)^2 + EllipseCoef(2)*E1(i)*E01(i) ...
        + EllipseCoef(3)*E1(i)^2 + EllipseCoef(4)*E01(i) ...
        + EllipseCoef(5)*E1(i);
end

plot3(AnOrbit(:,1),AnOrbit(:,2),AnOrbit(:,3),Planets(:,1),Planets(:,2),Planets(:,3))
title('Mercury')
xlabel('x (AU)')
ylabel('y (AU)')
zlabel('z (AU)')
legend('Analytic Orbit','Numerical Orbit')

% VenusCos = fitEllipse(Ven(:,1),Ven(:,2),Ven(:,3));
% 
% EarthCos = fitEllipse(Ear(:,1),Ear(:,2),Ear(:,3));
% 
% MarsCos = fitEllipse(Mar(:,1),Mar(:,2),Mar(:,3));
% 
% JupiterCos = fitEllipse(Jup(:,1),Jup(:,2),Jup(:,3));
% 
% SaturnCos = fitEllipse(Sat(:,1),Sat(:,2),Sat(:,3));
% 
% UranusCos = fitEllipse(Ur(:,1),Ur(:,2),Ur(:,3));
% 
% NeptuneCos = fitEllipse(Nep(:,1),Nep(:,2),Nep(:,3));
% 
% PlutoCos = fitEllipse(Plu(:,1),Plu(:,2),Plu(:,3));


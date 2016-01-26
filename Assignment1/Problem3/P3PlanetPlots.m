Planets = [];

Planets(:,1:3) = dlmread('Mercury2D.csv');
Planets(:,4:6) = dlmread('Venus2D.csv');
Planets(:,7:9) = dlmread('Earth2D.csv');
Planets(:,10:12) = dlmread('Mars2D.csv');
Planets(:,13:15) = dlmread('Jupiter2D.csv');
Planets(:,16:18) = dlmread('Saturn2D.csv');
Planets(:,19:21) = dlmread('Uranus2D.csv');
Planets(:,22:24) = dlmread('Neptune2D.csv');
Planets(:,25:27) = dlmread('Pluto2D.csv');

AUconv = 6.68459e-3;
semimaj = AUconv*[57.91 108.21 149.60 227.92 778.57 1433.53 2872.46 4495.06 5906.38]';
periods = [88 225 365 687 4333 10759 30685 60189 90560]';
eccs = [0.2056 0.0067 0.0167 0.0935 0.0489 0.0565 0.0457 0.0113 0.2488]';
semimin = [0 0 0 0 0 0 0 0 0]';
AnPlanets = zeros(200,18);

for i=1:9
    semimin(i) = (((semimaj(i))^2)*(1-(eccs(i))^2))^(0.5);
end

for i = 1:155
    for j = 1:2:17
        AnPlanets(i,j) = semimaj((j+1)/2)*cos(2*i*pi/201);
        AnPlanets(i,j+1) = semimin((j+1)/2)*sin(2*i*pi/201);
    end
end

for i = 1:155
    for j = 1:9
        Error(i,j) = (Planets((j-1)*1500 + i,1) - ...
            AnPlanets(i,1))^2 + (Planets((j-1)*1500 + i,2) ...
            - AnPlanets(i,2))^2;
    end
end

sqerror = zeros(9);
for i = 1:155
    for j = 1:9
        sqerror(j) = sqerror(j) + Error(i,j);
    end
end

sqerror = (sqerror/205)^(0.5);

for i = 1:9
    sqerror(i,2) = (i-1)*10 + 1;
end

plot(sqerror(1:9,2),sqerror(1:9,1))
title('Mercury Error Propogation')
xlabel('Number of Revolutions')
ylabel('RMS Error')


plot(Planets(1:155,1),Planets(1:155,2), ...
    Planets(1501:1655,1),Planets(1501:1655,2), ...
    Planets(3001:3155,1),Planets(3001:3155,2), ...
    Planets(4501:4655,1),Planets(4501:4655,2), ...
    Planets(6001:6155,1),Planets(6001:6155,2), ...
    Planets(7501:7655,1),Planets(7501:7655,2), ...
    Planets(9001:9155,1),Planets(9001:9155,2), ...
    Planets(10501:10655,1),Planets(10501:10655,2), ...
    Planets(12001:12155,1),Planets(12001:12155,2), ...
    Planets(13501:13655,1),Planets(13501:13655,2))
title('Mercury Numerical Error Accumulation over 100 Revolutions')
xlabel('x (AU)')
ylabel('y (AU)')
print('MercuryError','-dpng')


% plot(AnPlanets(1:205,1),AnPlanets(1:205,2), ...
%     Planets(1:205,1),Planets(1:205,2))
% title('Mercury Numerical vs. Analytic')
% xlabel('x (AU)')
% ylabel('y (AU)')
% legend('Analytical','Numerical')
% print('MercuryNvA','-dpng')
% 
% plot(AnPlanets(1:205,3),AnPlanets(1:205,4), ...
%     Planets(1:205,4),Planets(1:205,5))
% title('Venus Numerical vs. Analytic')
% xlabel('x (AU)')
% ylabel('y (AU)')
% legend('Analytical','Numerical')
% print('VenusNvA','-dpng')
% 
% plot(AnPlanets(1:205,5),AnPlanets(1:205,6), ...
%     Planets(1:205,7),Planets(1:205,8))
% title('Earth Numerical vs. Analytic')
% xlabel('x (AU)')
% ylabel('y (AU)')
% legend('Analytical','Numerical')
% print('EarthNvA','-dpng')
% 
% plot(AnPlanets(1:205,7),AnPlanets(1:205,8), ...
%     Planets(1:205,10),Planets(1:205,11))
% title('Mars Numerical vs. Analytic')
% xlabel('x (AU)')
% ylabel('y (AU)')
% legend('Analytical','Numerical')
% print('MarsNvA','-dpng')
% 
% plot(AnPlanets(1:205,9),AnPlanets(1:205,10), ...
%     Planets(1:205,13),Planets(1:205,14))
% title('Jupiter Numerical vs. Analytic')
% xlabel('x (AU)')
% ylabel('y (AU)')
% legend('Analytical','Numerical')
% print('JupiterNvA','-dpng')
% 
% plot(AnPlanets(1:205,11),AnPlanets(1:205,12), ...
%     Planets(1:205,16),Planets(1:205,17))
% title('Saturn Numerical vs. Analytic')
% xlabel('x (AU)')
% ylabel('y (AU)')
% legend('Analytical','Numerical')
% print('SaturnNvA','-dpng')
% 
% plot(AnPlanets(1:205,13),AnPlanets(1:205,14), ...
%     Planets(1:205,19),Planets(1:205,20))
% title('Uranus Numerical vs. Analytic')
% xlabel('x (AU)')
% ylabel('y (AU)')
% legend('Analytical','Numerical')
% print('UranusNvA','-dpng')
% 
% plot(AnPlanets(1:205,15),AnPlanets(1:205,16), ...
%     Planets(1:205,22),Planets(1:205,23))
% title('Neptune Numerical vs. Analytic')
% xlabel('x (AU)')
% ylabel('y (AU)')
% legend('Analytical','Numerical')
% print('NeptuneNvA','-dpng')
% 
% plot(AnPlanets(1:205,17),AnPlanets(1:205,18), ...
%     Planets(1:205,25),Planets(1:205,26))
% title('Pluto Numerical vs. Analytic')
% xlabel('x (AU)')
% ylabel('y (AU)')
% legend('Analytical','Numerical')
% print('PlutoNvA','-dpng')


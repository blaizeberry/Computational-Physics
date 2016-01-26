Planets = [];

Planets(:,1:3) = dlmread('Mercury.csv');
Planets(:,4:6) = dlmread('Venus.csv');
Planets(:,7:9) = dlmread('Earth.csv');
Planets(:,10:12) = dlmread('Mars.csv');
Planets(:,13:15) = dlmread('Jupiter.csv');
Planets(:,16:18) = dlmread('Saturn.csv');
Planets(:,19:21) = dlmread('Neptune.csv');
Planets(:,22:24) = dlmread('Uranus.csv');
Planets(:,25:27) = dlmread('Pluto.csv');
Planets(:,28:30) = dlmread('HaleyComet.csv');

plot3(Planets(:,1),Planets(:,2),Planets(:,3),Planets(:,4),Planets(:,5),...
Planets(:,6),Planets(:,7),Planets(:,8),Planets(:,9),Planets(:,10),...
Planets(:,11),Planets(:,12),Planets(:,13),Planets(:,14),Planets(:,15),...
Planets(:,16),Planets(:,17),Planets(:,18),Planets(:,19),Planets(:,20),...
Planets(:,21),Planets(:,22),Planets(:,23),Planets(:,24),Planets(:,25),...
Planets(:,26),Planets(:,27))
title('Solar System Numerical Plot')
xlabel('x (AU)')
ylabel('y (AU)')
zlabel('z (AU)')
legend('Mercury','Venus','Earth','Mars','Jupiter','Saturn','Uranus',...
    'Neptune','Pluto')
print('SolarSystem','-dpng')

plot3(Planets(:,1),Planets(:,2),Planets(:,3),Planets(:,4),Planets(:,5),...
Planets(:,6),Planets(:,7),Planets(:,8),Planets(:,9),Planets(:,10),...
Planets(:,11),Planets(:,12))
title('Inner Planets Numerical Plot')
xlabel('x (AU)')
ylabel('y (AU)')
zlabel('z (AU)')
legend('Mercury','Venus','Earth','Mars')
print('InnerPlanets','-dpng')


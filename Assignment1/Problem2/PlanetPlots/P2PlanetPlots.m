Planets = [];

Planets(:,1:3) = csvread('Mercury.csv');
Planets(:,4:6) = csvread('Venus.csv');
Planets(:,7:9) = csvread('Earth.csv');
Planets(:,10:12) = csvread('Mars.csv');
Planets(:,13:15) = csvread('Jupiter.csv');
Planets(:,16:18) = csvread('Saturn.csv');
Planets(:,19:21) = csvread('Neptune.csv');
Planets(:,22:24) = csvread('Uranus.csv');
Planets(:,25:27) = csvread('Pluto.csv');
Planets(:,28:30) = csvread('HaleyComet.csv');

% plot3(Planets(:,1),Planets(:,2),Planets(:,3),Planets(:,4),Planets(:,5),...
% Planets(:,6),Planets(:,7),Planets(:,8),Planets(:,9),Planets(:,10),...
% Planets(:,11),Planets(:,12),Planets(:,13),Planets(:,14),Planets(:,15),...
% Planets(:,16),Planets(:,17),Planets(:,18),Planets(:,19),Planets(:,20),...
% Planets(:,21),Planets(:,22),Planets(:,23),Planets(:,24),Planets(:,25),...
% Planets(:,26),Planets(:,27))
% title('Solar System Numerical Plot')
% xlabel('x (AU)')
% ylabel('y (AU)')
% zlabel('z (AU)')
% legend('Mercury','Venus','Earth','Mars','Jupiter','Saturn','Uranus',...
%     'Neptune','Pluto')
% print('SolarSystem','-dpng')
% 
% plot3(Planets(:,1),Planets(:,2),Planets(:,3),Planets(:,4),Planets(:,5),...
% Planets(:,6),Planets(:,7),Planets(:,8),Planets(:,9),Planets(:,10),...
% Planets(:,11),Planets(:,12))
% title('Inner Planets Numerical Plot')
% xlabel('x (AU)')
% ylabel('y (AU)')
% zlabel('z (AU)')
% legend('Mercury','Venus','Earth','Mars')
% print('InnerPlanets','-dpng')
% 
% plot3(Planets(:,1),Planets(:,2),Planets(:,3))
% title('Mercury Orbit')
% xlabel('x (AU)')
% ylabel('y (AU)')
% zlabel('z (AU)')
% print('Mercury','-dpng')
% 
% plot3(Planets(:,4),Planets(:,5),Planets(:,6))
% title('Venus Orbit')
% xlabel('x (AU)')
% ylabel('y (AU)')
% zlabel('z (AU)')
% print('Venus','-dpng')
% 
% plot3(Planets(:,7),Planets(:,8),Planets(:,9))
% title('Earth Orbit')
% xlabel('x (AU)')
% ylabel('y (AU)')
% zlabel('z (AU)')
% print('Earth','-dpng')
% 
% plot3(Planets(:,10),Planets(:,11),Planets(:,12))
% title('Mars Orbit')
% xlabel('x (AU)')
% ylabel('y (AU)')
% zlabel('z (AU)')
% print('Mars','-dpng')
% 
% plot3(Planets(:,13),Planets(:,14),Planets(:,15))
% title('Jupiter Orbit')
% xlabel('x (AU)')
% ylabel('y (AU)')
% zlabel('z (AU)')
% print('Jupiter','-dpng')
% 
% plot3(Planets(:,16),Planets(:,17),Planets(:,18))
% title('Saturn Orbit')
% xlabel('x (AU)')
% ylabel('y (AU)')
% zlabel('z (AU)')
% print('Saturn','-dpng')
% 
% plot3(Planets(:,19),Planets(:,20),Planets(:,21))
% title('Uranus Orbit')
% xlabel('x (AU)')
% ylabel('y (AU)')
% zlabel('z (AU)')
% print('Uranus','-dpng')
% 
% plot3(Planets(:,22),Planets(:,23),Planets(:,24))
% title('Neptune Orbit')
% xlabel('x (AU)')
% ylabel('y (AU)')
% zlabel('z (AU)')
% print('Neptune','-dpng')
% 
% plot3(Planets(:,25),Planets(:,26),Planets(:,27))
% title('Pluto Orbit')
% xlabel('x (AU)')
% ylabel('y (AU)')
% zlabel('z (AU)')
% print('Pluto','-dpng')

plot3(Planets(:,28),Planets(:,29),Planets(:,30))
title('Halley Comet Orbit')
xlabel('x (AU)')
ylabel('y (AU)')
zlabel('z (AU)')
print('HalleyComet','-dpng')

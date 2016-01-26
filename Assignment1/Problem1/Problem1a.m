% fileID = fopen('PHYS241_1_1a3.txt','r');
% formatSpec = '%i %f';
% sizeA = [4 Inf];
% A = fscanf(fileID,formatSpec,sizeA)
% fclose(fileID);
% A = A'

plot(C(:,2),C(:,3),B(:,2),B(:,3),A(:,2),A(:,3))
title('Problem 1A 2D')
xlabel('x')
ylabel('v')
legend('x_0 = 1','x_0 = 2','x_0 = 3')


plot3(C(:,2),C(:,3),C(:,1),B(:,2),B(:,3),B(:,1),A(:,2),A(:,3),A(:,1))
title('Problem 1A 3D')
xlabel('x')
ylabel('v')
zlabel('t')
legend('x_0 = 1','x_0 = 2','x_0 = 3')
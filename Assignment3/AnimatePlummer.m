Plummer = dlmread('Plummer.txt');

v = VideoWriter('UnstablePlummer2.mp4','MPEG-4');

open(v);

figure('Color','black')
axis off
hold on
for i = 1:6:59995
    h((i+5)/6) = line(0,0);
    set(h((i+5)/6), 'Marker','.', 'Markersize', 1, 'Color', 'y');
end
%hold off

%hold on
plot(0,0,'k.','Markersize',1)
axis([-1 1 -1 1])

for i = 1:1:200
      for j = 1:6:59995
        set(h((j+5)/6),'XData',Plummer(i,j),'YData',Plummer(i,j+1));
      end
      %Plummer(i,j)
      %Plummer(i,j+1)
      drawnow
      frame = getframe(1);
      writeVideo(v, frame);
end

close(v);
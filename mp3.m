[y,Fs] = audioread('C:\Users\Belal\Desktop\test.mp3');
y=y(:,1);
y=y(1:2*Fs);
x = resample(y,8000,Fs);
x=x+abs(min(x));
sound(x,8000);
x=x*255/max(x);
x=cast(x,'uint8');
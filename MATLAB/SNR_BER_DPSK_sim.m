clc,clear,close all
x=0:10;
BitRate=10000;
SimulationTime=20;
M=2; %BPSK星座点数
for k=1:length(x)
 SNR=x(k);
 sim('simout.mdl');
 ber(k)=mean(simout(:,1));
 fprintf('%d dB,%d\n ',SNR,ber(k));
end
M1=4; %QPSK星座点数
for k=1:length(x)
 SNR=x(k);
 sim('simout_DPSK.mdl');
 ber_DPSK(k)=mean(simout(:,1));
 fprintf('%d dB,%d\n ',SNR,ber_DPSK(k));
end
semilogy(x,ber,'r.-',x,ber_DPSK,'bo-');
xlabel('SNR(dB)');
ylabel('BER');
title('BERBPSK-QPSK的-AWGN误码率性能-命令行动态仿真');
legend('BPSK','QPSK');
grid on
clc,clear,close all 
x=0:12; 
BitRate=10000; 
SimulationTime=20;
M1=[2,4];
for k=1:length(M1)
    M=M1(k)
    simout=0;
    for p=1:length(x)
        SNR=x(p);
        sim('xmsa.mdl');
        ber(k,p)=mean(simout(:,1)); 
        fprintf('%d dB,%d\n',SNR,ber(k,p));
    end
end
semilogy(x,ber(1,:),'bo-'); 
hold on
semilogy(x,ber(2,:),'r*-');
legend('BPSK','QPSK');
xlabel('SNR(dB)') 
ylabel('BER') 
title('BPSK-QPSK的 -AWGN误码率性能-命令行动态仿真') 
grid on 
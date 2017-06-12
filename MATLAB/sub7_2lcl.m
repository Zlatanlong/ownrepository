clc,clear,close all
Xframe_Len=1024;%帧长
Multipath=[1 0 0 0 0 0.6];
SNRdB=0:10;
LenSNR=length(SNRdB);
Nframe=200; %测试 200 帧信号总的误比特率
CP=1/4; %CP 长度为原序列的后 1/4
for k=1:length(SNRdB)
    Error_BPSK=0;
    Error_QPSK=0;
    for p=1:Nframe
        Data_in=randi([0,1],1,Xframe_Len);
        MappCode_BPSK=mappingBPSK(Data_in);%映射
         MappCode_QPSK=mappingQPSK(Data_in);
        MappCode_bing_BPSK=MappCode_BPSK';%串并
         MappCode_bing_QPSK=MappCode_QPSK';%QPSK串并
        %IFFT 对并行的序列做快速傅立叶变换
        Ifft_BPSK =ifft(MappCode_bing_BPSK);
         Ifft_QPSK =ifft(MappCode_bing_QPSK);
        %加CP
        CPCode_BPSK=[Ifft_BPSK(floor(length(Ifft_BPSK)*(1-CP))+1:end);Ifft_BPSK];
         CPCode_QPSK=[Ifft_QPSK(floor(length(Ifft_QPSK)*(1-CP))+1:end);Ifft_QPSK];
        %加噪声======================================
        awgn_BPSK=awgn(CPCode_BPSK,SNRdB(k),'measured');
         awgn_QPSK=awgn(CPCode_QPSK,SNRdB(k),'measured');
        %加多径=======================================
        if~isempty(Multipath)
            BaseSignal_filter_BPSK=filter(Multipath,1,awgn_BPSK);
             BaseSignal_filter_QPSK=filter(Multipath,1,awgn_QPSK);
        end
        %去CP
        deCP_BPSK=BaseSignal_filter_BPSK((length(BaseSignal_filter_BPSK)-length(Ifft_BPSK)+1):end);
         deCP_QPSK=BaseSignal_filter_QPSK((length(BaseSignal_filter_QPSK)-length(Ifft_QPSK)+1):end);
        %傅立叶逆变换；
        fft_BPSK=fft(deCP_BPSK);
         fft_QPSK=fft(deCP_QPSK);
        %并串
        MappCode_chuan_BPSK=fft_BPSK';
         MappCode_chuan_QPSK=fft_QPSK';
        %反映射
        Data_out_BPSK=demappingBPSK(MappCode_chuan_BPSK);
         Data_out_QPSK=demappingQPSK(MappCode_chuan_QPSK);
        Error_BPSK=Error_BPSK+biterr(Data_in,Data_out_BPSK);
         Error_QPSK=Error_QPSK+biterr(Data_in,Data_out_QPSK);
    end
    BER_BPSK(k)=Error_BPSK/(Nframe*Xframe_Len);
     BER_QPSK(k)=Error_QPSK/(Nframe*Xframe_Len);
    fprintf('%d dB  %d %d\n',SNRdB(k),BER_BPSK(k),BER_QPSK(k));
end
semilogy(SNRdB,BER_BPSK,'r*-',SNRdB,BER_QPSK,'b*-');
xlabel('SNR');
ylabel('BER');
title(' BPSK 和 QPSK 调制在 AWGN-多径信道下的SNR-BER 误码率性能评估');
legend('BPSK','QPSK');
grid on;
function BPSKCode = mappingBPSK(Xframe)
for k=1:length(Xframe)
    if(Xframe(k)==0) 
        BPSKCode(k)=1;
    else
        BPSKCode(k)=-1;
    end
end
end
function deBPSKCode = demappingBPSK(PskCode)
for k=1:length(PskCode)
    if(PskCode(k)>=0) 
        deBPSKCode(k)=0;
    else
        deBPSKCode(k)=1;
    end
end
end
function yn = mappingQPSK(Xframe)
k=1;
for p=1:2:length(Xframe)
    if Xframe(p)==0 && Xframe(p+1)==0
        yn(k)=1+1i;
    end
     if Xframe(p)==0 && Xframe(p+1)==1
        yn(k)=-1+1i;
     end
    if Xframe(p)==1 && Xframe(p+1)==1
        yn(k)=-1-1i;
    end
    if Xframe(p)==1 && Xframe(p+1)==0
        yn(k)=1-1i;
    end
    k=k+1;
end

end
function deQPSKCode = demappingQPSK(PskCode)
for k=1:length(PskCode)
    if real(PskCode(k))>=0 && imag(PskCode(k))>0
        deQPSKCode(2*(k-1)+1)=0;
        deQPSKCode(2*(k-1)+2)=0;
    elseif real(PskCode(k))>0 && imag(PskCode(k))<=0
        deQPSKCode(2*(k-1)+1)=1;
        deQPSKCode(2*(k-1)+2)=0;
    elseif real(PskCode(k))<=0 && imag(PskCode(k))<0
        deQPSKCode(2*(k-1)+1)=1;
        deQPSKCode(2*(k-1)+2)=1;
    elseif real(PskCode(k))<0 && imag(PskCode(k))>=0
        deQPSKCode(2*(k-1)+1)=0;
        deQPSKCode(2*(k-1)+2)=1;
    end
end
end
    
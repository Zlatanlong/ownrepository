clc,clear,close all
Xframe_Len=256;%帧长
Multipath=[1 0 0 0 0 0.6];
SNRdB=0:10;
LenSNR=length(SNRdB);
Nframe=200; %测试 200 帧信号总的误比特率
CP=1/4; %CP 长度为原序列的后 1/4
for k=1:length(SNRdB)
    Error_BPSK=0;
    Error_QPSK=0;
    Error_QPSK_inter=0;
    for p=1:Nframe
        Data_in=randi([0,1],1,Xframe_Len);
        [data_inter,index]=lincol_inter(Data_in);%交织
        MappCode_BPSK=mappingBPSK(Data_in);%BPSK映射
         MappCode_QPSK=mappingQPSK(Data_in);%QPSK映射
          MappCode_QPSK_inter=mappingQPSK(data_inter);
        MappCode_bing_BPSK=MappCode_BPSK';%串并
         MappCode_bing_QPSK=MappCode_QPSK';%QPSK串并
          MappCode_bing_QPSK_inter=MappCode_QPSK_inter';
        %IFFT 对并行的序列做快速傅立叶变换
        Ifft_BPSK =ifft(MappCode_bing_BPSK);
         Ifft_QPSK =ifft(MappCode_bing_QPSK);
          Ifft_QPSK_inter =ifft(MappCode_bing_QPSK_inter);
        %加CP
        CPCode_BPSK=[Ifft_BPSK(floor(length(Ifft_BPSK)*(1-CP))+1:end);Ifft_BPSK];
         CPCode_QPSK=[Ifft_QPSK(floor(length(Ifft_QPSK)*(1-CP))+1:end);Ifft_QPSK];
          CPCode_QPSK_inter=[Ifft_QPSK_inter(floor(length(Ifft_QPSK_inter)*(1-CP))+1:end);Ifft_QPSK_inter];
        %加噪声======================================
        awgn_BPSK=awgn(CPCode_BPSK,SNRdB(k),'measured');
         awgn_QPSK=awgn(CPCode_QPSK,SNRdB(k),'measured');
          awgn_QPSK_inter=awgn(CPCode_QPSK_inter,SNRdB(k),'measured');
        %加多径=======================================
        if~isempty(Multipath)
            BaseSignal_filter_BPSK=filter(Multipath,1,awgn_BPSK);
             BaseSignal_filter_QPSK=filter(Multipath,1,awgn_QPSK);
              BaseSignal_filter_QPSK_inter=filter(Multipath,1,awgn_QPSK_inter);
        end
        %去CP
        deCP_BPSK=BaseSignal_filter_BPSK((length(BaseSignal_filter_BPSK)-length(Ifft_BPSK)+1):end);
         deCP_QPSK=BaseSignal_filter_QPSK((length(BaseSignal_filter_QPSK)-length(Ifft_QPSK)+1):end);
          deCP_QPSK_inter=BaseSignal_filter_QPSK_inter((length(BaseSignal_filter_QPSK_inter)-length(Ifft_QPSK_inter)+1):end);
        %傅立叶逆变换；
        fft_BPSK=fft(deCP_BPSK);
         fft_QPSK=fft(deCP_QPSK);
          fft_QPSK_inter=fft(deCP_QPSK_inter);
        %并串
        MappCode_chuan_BPSK=fft_BPSK';
         MappCode_chuan_QPSK=fft_QPSK';
          MappCode_chuan_QPSK_inter=fft_QPSK_inter';
        %反映射
        Data_out_BPSK=demappingBPSK(MappCode_chuan_BPSK);
         Data_out_QPSK=demappingQPSK(MappCode_chuan_QPSK);
          Data_out_QPSK_inter=demappingQPSK(MappCode_chuan_QPSK_inter);
          %解交织
          Data_out_QPSK_deinter=de_inter(Data_out_QPSK_inter,index);
        %查错
        Error_BPSK=Error_BPSK+biterr(Data_in,Data_out_BPSK);
         Error_QPSK=Error_QPSK+biterr(Data_in,Data_out_QPSK);
          Error_QPSK_inter=Error_QPSK_inter+biterr(Data_in,Data_out_QPSK_deinter);
    end
    BER_BPSK(k)=Error_BPSK/(Nframe*Xframe_Len);
     BER_QPSK(k)=Error_QPSK/(Nframe*Xframe_Len);
       BER_QPSK_inter(k)=Error_QPSK_inter/(Nframe*Xframe_Len);
    fprintf('%d dB  BPSK:%d  QPSK:%d  QPSK交织:%d\n',SNRdB(k),BER_BPSK(k),BER_QPSK(k),BER_QPSK_inter(k));
end
semilogy(SNRdB,BER_BPSK,'r*-',SNRdB,BER_QPSK,'b*-',SNRdB,BER_QPSK_inter,'b s-');
xlabel('SNR');
ylabel('BER');
title(' QPSK交织系统对BPSK 和 QPSK 调制在 AWGN-多径信道下的误码率性能的改善情况');
legend('BPSK','QPSK','QPSK-OFDM');
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
function [datainter, index]=lincol_inter(datain)
% lincol_inter具有行列交织的功能
%datai为待交织的二进制序列
%datainter为交织后的序列
%index为交织后的序号
n=length(datain);
ys=[1:n];
bl=[ys zeros(1,ceil(sqrt(ys(end)))^2-ys(end))];
zz=reshape(bl,ceil(sqrt(ys(end))),ceil(sqrt(ys(end))))';
zz(find(zz==0))=[];
index=zz;
datainter=datain(index);
end
function dataout=de_inter (datare,index)
% datare为反交织器接收到的数据
%index为发送端产生的交织序列号
% dataout为反交织后的序列
dataout(index)=datare;
end
    
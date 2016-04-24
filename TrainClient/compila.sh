#!/bin/bash

printf "\n\rCompilando..."
#Alterar o no me da pasta onde salvou o ti-process-sdk
source /opt/ti-processor-sdk-linux-am335x-evm-02.00.01.07/linux-devkit/environment-setup


rm moc_*
rm ui_*
rm *.o
rm Makefile
 
qmake
make
 
rm moc_*
rm ui_*
rm *.o
rm Makefile

#Alterar o nome do executável 'AnalysisTime'
printf "\n\rCopiando para a BBB (em /home/debian)..."
sshpass -p 'temppwd' scp TrainClient debian@192.168.7.2:~

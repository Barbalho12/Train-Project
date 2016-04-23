/*
 * Antes de executar digitar o comando abaixo para habilitar as portas
 *
 * sudo sh -c "echo 'BB-ADC' > /sys/devices/platform/bone_capemgr/slots"
 *
 */

#include <unistd.h>
#include "libs/BlackLib/v3_0/BlackGPIO/BlackGPIO.h"
#include <iostream>
#include <csignal>
#include <thread>
#include <arpa/inet.h>  //inet_addr
//#include <netinet/in.h> //htons
//#include <sys/socket.h> //socket


#define PORTNUM 4325
#define IP_SERV "192.168.0.102"

#define DELAY 2

#define PATH_ADC "/sys/bus/iio/devices/iio:device0/in_voltage"


using namespace std;



struct Mensagem {
    public:
        int trainID;
        float speed;
        bool travado;
};

Mensagem mensagem;


/*---------------------------------------------------------------------------------*/

int readAnalog(int number){
   stringstream ss;
   ss << PATH_ADC << number << "_raw";
   fstream fs;
   fs.open(ss.str().c_str(), fstream::in);
   fs >> number;
   fs.close();
   return number;
}

void pot(){
    while(true){
        usleep(100);
        int valor = readAnalog(1);
        mensagem.speed = valor;
        cout << "Potenciômetro: " << valor << endl;
        sleep(DELAY);
    }
}

/*---------------------------------------------------------------------------------*/

void createSocket(Mensagem mensagem){
    struct sockaddr_in endereco;
    int socketId;

    int bytesenviados;

    memset(&endereco, 0, sizeof(endereco));
    endereco.sin_family = AF_INET;
    endereco.sin_port = htons(PORTNUM);
    endereco.sin_addr.s_addr = inet_addr(IP_SERV);

    /*
     * Criando o Socket
     *
     * PARAM1: AF_INET ou AF_INET6 (IPV4 ou IPV6)
     * PARAM2: SOCK_STREAM ou SOCK_DGRAM
     * PARAM3: protocolo (IP, UDP, TCP, etc). Valor 0 escolhe automaticamente
    */
    socketId = socket(AF_INET, SOCK_STREAM, 0);

    //Verificar erros
    if (socketId == -1){
        printf("Falha ao executar socket()\n");
        kill(getpid(), SIGINT);
    }

    if ( connect (socketId, (struct sockaddr *)&endereco, sizeof(struct sockaddr)) == -1 ){
        printf("Falha ao executar connect()\n");
        kill(getpid(), SIGINT);
    }

    bytesenviados = send(socketId,&mensagem,sizeof(mensagem),0);

    if (bytesenviados == -1){
        printf("Falha ao executar send()");
        kill (getpid(), SIGINT);
    }
    close(socketId);
}

/*---------------------------------------------------------------------------------*/

void tsocket(){
    usleep(100000);
    while(true){
        mensagem.speed = 1000;
        createSocket(mensagem);
        sleep(DELAY);
    }
}

thread t2(pot);
thread t4(tsocket);

void funcaoSignalHandler (int sig){
    t2.detach();
    t4.detach();
    exit(EXIT_SUCCESS);
}

int main(int argc, char *argv[]){

    signal(SIGINT, funcaoSignalHandler);

    t2.join();
    t4.join();
    return 0;
}

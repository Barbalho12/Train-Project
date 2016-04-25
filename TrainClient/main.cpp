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
#define IP_SERV "127.0.0.1"

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

void readVelocity(){
    int valor = readAnalog(1);
    mensagem.speed = valor;
}

/*---------------------------------------------------------------------------------*/
bool serverConnected = false;

void disconnectedServer(){
    if(serverConnected){
        serverConnected = false;
        printf("Server Disconnected\n");
    }else{
        printf("Server is not connected\n");
    }

}

bool connectSocket(int *socketId){
    struct sockaddr_in endereco;
    //int socketId;

    memset(&endereco, 0, sizeof(endereco));
    endereco.sin_family = AF_INET;
    endereco.sin_port = htons(PORTNUM);
    endereco.sin_addr.s_addr = inet_addr(IP_SERV);
    *socketId = socket(AF_INET, SOCK_STREAM, 0);

    if (*socketId == -1){
        //printf("Falha ao executar socket()\n");
        close(*socketId);
        return false;
    }

    if ( connect (*socketId, (struct sockaddr *)&endereco, sizeof(struct sockaddr)) == -1 ){
        //printf("Falha ao executar connect()\n");
        close(*socketId);
        return false;
    }
    return true;
}

void connectedServer(){
    int socketId;
    if(connectSocket(&socketId) && !serverConnected){
        //close(socketId);
        serverConnected = true;
        printf("Server Connected\n");
    }else if(connectSocket(&socketId) && serverConnected){
        printf("server is already connected\n");
    }else{
        printf("It was not possible to connect to the server\n");
    }

}

void sendMensage(Mensagem mensagem){
    int socketId;
    int bytesenviados;
    if (connectSocket(&socketId) && serverConnected){
        bytesenviados = send(socketId,&mensagem,sizeof(mensagem),0);
        if (bytesenviados == -1){
            printf("Falha ao executar send()");
            //disconnectedServer();
            return;
        }
    }else if(!serverConnected){
        printf("Connect to the server before sending data\n");
    }
    //close(socketId);
}

/*---------------------------------------------------------------------------------*/

void teste(){
    while(true){
        int n;
        cin >> n;

        if(n == 2){
            readVelocity();
            sendMensage(mensagem);
            sleep(1);

        } else if(n == 1){
            disconnectedServer();
            sleep(1);
        } else if(n == 3){
            connectedServer();
            sleep(1);
        }
    }
}

void buttonsRead(){
    BlackLib::BlackGPIO   botaoUp(BlackLib::GPIO_115,BlackLib::input, BlackLib::SecureMode);
    BlackLib::BlackGPIO   botaoPlay(BlackLib::GPIO_113,BlackLib::input, BlackLib::SecureMode);
    BlackLib::BlackGPIO   botaoDown(BlackLib::GPIO_117,BlackLib::input, BlackLib::SecureMode);

    int up,play,down;

    while(true){
        up = botaoUp.getNumericValue();
        play = botaoPlay.getNumericValue();
        down = botaoDown.getNumericValue();

        if(play == 1){
            readVelocity();
            sendMensage(mensagem);
            sleep(1);

        } else if(up == 1){
            disconnectedServer();
            sleep(1);
        } else if(down == 1){
            connectedServer();
            sleep(1);
        }
        //cout << "Valor do botão é: " << up << " - " <<  play << " - " << down << endl;
    }

}

// Play all trains
void playAllTrains() {
    mensagem.trainID = -2;
}

// Pause all trains
void pauseAllTrains() {
    mensagem.trainID = -1;
}

// Play a train
void playTrain(int id) {
    mensagem.trainID = id;
    mensagem.travado = false;
}

// Pause a train
void pauseTrain(int id) {
    mensagem.trainID = id;
    mensagem.travado = true;
}

// Change speed
void changeSpeedTrain(int id) {
    mensagem.trainID = id;
    mensagem.speed = 10;
}

/*---------------------------------------------------------------------------------*/

int main(int argc, char *argv[]){
    //signal(SIGINT, funcaoSignalHandler);

    thread t1(buttonsRead);
    thread test(teste);
    //connectSocket();
    //disconnectedSocket();
    //playAllTrains();
    //pauseAllTrains();
    //playTrain(int id);
    //pauseTrain(int id);
    //changeSpeedTrain(int id);

    t1.join();
    test.join();
    return 0;
}

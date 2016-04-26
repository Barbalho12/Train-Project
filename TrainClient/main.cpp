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
#include <vector>
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

int readAnalog(int number){
   stringstream ss;
   ss << PATH_ADC << number << "_raw";
   fstream fs;
   fs.open(ss.str().c_str(), fstream::in);
   fs >> number;
   fs.close();
   return number;
}

int readVelocityOption(){
    return readAnalog(1);
}

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

vector<string> options;
vector<string> trains;
void initOptionMenu(){
    options.push_back("Connect to the server");
    options.push_back("Close connect to the server");
    options.push_back("Play all trains");
    options.push_back("Off all trains");
    options.push_back("Play a train");
    options.push_back("Off a train");
    options.push_back("Change the speed of a train");

    //cout << options.size() << endl;

    trains.push_back("Train 0");
    trains.push_back("Train 1");
    trains.push_back("Train 2");
    trains.push_back("Train 3");
    trains.push_back("Train 4");
    trains.push_back("Train 5");
}

/*---------------------------------------------------------------------------------*/
// Play all trains
void playAllTrains() {
    if(serverConnected){
        mensagem.trainID = -1;
        mensagem.travado = false;
        sendMensage(mensagem);
    }else{
        cout << "Connect to the server before" << endl;
    }

}

// Pause all trains
void pauseAllTrains() {
    if(serverConnected){
        mensagem.trainID = -1;
        mensagem.travado = true;
        sendMensage(mensagem);
    }else{
        cout << "Connect to the server before" << endl;
    }
}

// Play a train
void playTrain(int id) {
    if(serverConnected){
        mensagem.trainID = id;
        mensagem.travado = false;
        mensagem.speed = -1;
        sendMensage(mensagem);
    }else{
        cout << "Connect to the server before" << endl;
    }
}

// Pause a train
void pauseTrain(int id) {

    if(serverConnected){
        mensagem.trainID = id;
        mensagem.travado = true;
        mensagem.speed = -1;
        sendMensage(mensagem);
    }else{
        cout << "Connect to the server before" << endl;
    }
}

// Change speed
void changeSpeedTrain(int id) {
    if(serverConnected){
        mensagem.trainID = id;
        mensagem.speed = readVelocityOption();
        sendMensage(mensagem);
    }else{
        cout << "Connect to the server before" << endl;
    }
}

/*---------------------------------------------------------------------------------*/

void menuExecute(int option, int id){
    // Select the option
    switch (option) {
    case 0:
        connectedServer();
        break;
    case 1:
        disconnectedServer();
        break;
    case 2:
        playAllTrains();
        break;
    case 3:
        pauseAllTrains();
        break;
    case 4:
        playTrain(id);
        break;
    case 5:
        pauseTrain(id);
        break;
    case 6:
        changeSpeedTrain(id);
        break;
    default:
        break;
    }
}

void teste(){
    int optionActive = 0;
    while(true){
        system("clear");
        for (int i = 0; i <= 6; i++) {
            //
            if (i == optionActive) {
                cout << "> ";
            } else {
                cout << "  ";
            }
            cout << options[i];
            if (i == optionActive) {
                cout << " <";
            }
            cout << endl;
        }

        int n;
        cin >> n;

        if(n == 2){
            int id;
            if(optionActive >= 4 && optionActive <= 6){
                cout << "Digite o id: ";
                cin >> id;
            }
            menuExecute(optionActive, id);
        } else if(n == 1){
            ++optionActive;
            if(optionActive == options.size()){ optionActive = 0;}
            system("clear");
        } else if(n == 3){
            --optionActive;
            if(optionActive == -1){ optionActive = options.size() -1;}
            system("clear");
        }

        usleep(50000);
    }
}

void buttonsRead(){
    BlackLib::BlackGPIO   botaoUp(BlackLib::GPIO_115,BlackLib::input, BlackLib::SecureMode);
    BlackLib::BlackGPIO   botaoPlay(BlackLib::GPIO_113,BlackLib::input, BlackLib::SecureMode);
    BlackLib::BlackGPIO   botaoDown(BlackLib::GPIO_117,BlackLib::input, BlackLib::SecureMode);

    int up,play,down;


    int optionActive = 0;
    cout << options[optionActive] << endl;
    while(true){
        up = botaoUp.getNumericValue();
        play = botaoPlay.getNumericValue();
        down = botaoDown.getNumericValue();

        if(play == 1){
            int id;
            if(optionActive >= 4 && optionActive <= 6){
                cout << "Digite o id: ";
                cin >> id;
            }
            menuExecute(optionActive, id);
        } else if(up == 1){
            system("clear");
            optionActive++;
            if(optionActive == options.size()) optionActive = 0;
            cout << options[optionActive] << endl;
        } else if(down == 1){
            system("clear");
            optionActive--;
            if(optionActive == -1) optionActive = options.size() -1;
            cout << options[optionActive] << endl;
        }

        sleep(1);
        //cout << "Valor do botão é: " << up << " - " <<  play << " - " << down << endl;
    }

}

/*---------------------------------------------------------------------------------*/

int main(int argc, char *argv[]){
    //signal(SIGINT, funcaoSignalHandler);
    initOptionMenu();
    thread t1(buttonsRead);
    thread test(teste);

    t1.join();
    test.join();
    return 0;
}

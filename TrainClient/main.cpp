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

#define PORTNUM 4325
//#define IP_SERV "127.0.0.1"
#define IP_SERV "192.168.7.1"
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
bool serverConnected = false;
vector<string> options;


/*---------------------------------OPÇÕES DE LEITURA--------------------------------*/

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


/*-----------------------------------OPÇÕES DE MENU---------------------------------*/

void initOptionMenu(){
    options.push_back("Connect to the server");
    options.push_back("Close connect to the server");
    options.push_back("Play all trains");
    options.push_back("Off all trains");
    options.push_back("Play a train");
    options.push_back("Off a train");
    options.push_back("Change the speed of a train");
}

void colorir(bool condition, int mode){
    if(condition){
        printf("%c[%d;%d;%dm", 0x1B, 1,31,mode);
    }else{
        printf("%c[%d;%d;%dm", 0x1B, 1,31,0);
    }
}

void menuAnimation(int &optionActive){
    system("clear");
    colorir(true, 92);
    cout << "=================Menu================[ "<< (40+(readAnalog(1)/10)) << " ]" << endl;
    colorir(false, 92);
    for (int i = 0; i <= 6; i++) {
        //
        if (i == optionActive) {
            colorir(true, 40);
            cout << "> ";
        } else {
            cout << "  ";
        }

        cout << options[i];
        if (i == optionActive) {

            cout << " <";
            colorir(false, 40);
        }
        cout << endl;
    }
    colorir(true, 92);
    cout << "======================================" << endl;
    colorir(false, 92);
}

int menuGetId(){
    int id;
    colorir(true, 92);
    cout << "===============OPTION=================" << endl;
    colorir(false, 92);

    cout << "Digite o id: ";
    cin >> id;

    colorir(true, 92);
    cout << "======================================" << endl;
    colorir(false, 92);

    return id;
}

void printMensage(string message, int cor){
    colorir(true, cor);
    cout << message << endl;
    colorir(false, cor);
}



/*---------------------------------OPÇÕES DE SERVIDOR--------------------------------*/

void disconnectedServer(){
    if(serverConnected){
        serverConnected = false;
        printMensage("Server Disconnected", 94);
    }else{
        printMensage("Server is not connected", 93);
    }
}

bool connectSocket(int *socketId){
    struct sockaddr_in endereco;

    memset(&endereco, 0, sizeof(endereco));
    endereco.sin_family = AF_INET;
    endereco.sin_port = htons(PORTNUM);
    endereco.sin_addr.s_addr = inet_addr(IP_SERV);
    *socketId = socket(AF_INET, SOCK_STREAM, 0);

    if (*socketId == -1){
        close(*socketId);
        return false;
    }

    if ( connect (*socketId, (struct sockaddr *)&endereco, sizeof(struct sockaddr)) == -1 ){
        close(*socketId);
        return false;
    }
    return true;
}

void connectedServer(){
    int socketId;
    if(connectSocket(&socketId) && !serverConnected){
        serverConnected = true;
        printMensage("Server Connected", 94);
    }else if(connectSocket(&socketId) && serverConnected){
        printMensage("server is already connected", 93);
    }else{
        printMensage("It was not possible to connect to the server", 93);
    }

}

void sendMensage(Mensagem mensagem){
    int socketId;
    int bytesenviados;
    if (connectSocket(&socketId) && serverConnected){
        bytesenviados = send(socketId,&mensagem,sizeof(mensagem),0);
        if (bytesenviados == -1){
            printMensage("Falha ao executar send()", 5);
            return;
        }
    }else if(!serverConnected){
        printMensage("Connect to the server before sending data", 93);
    }
}

/*---------------------------------------------------------------------------------*/

// Play all trains
void playAllTrains() {
    if(serverConnected){
        mensagem.trainID = -1;
        mensagem.travado = false;
        sendMensage(mensagem);
    }else{
        printMensage("Connect to the server before", 93);
    }
}

// Pause all trains
void pauseAllTrains() {
    if(serverConnected){
        mensagem.trainID = -1;
        mensagem.travado = true;
        sendMensage(mensagem);
    }else{
        printMensage("Connect to the server before", 93);
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
        printMensage("Connect to the server before", 93);
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
        printMensage("Connect to the server before", 93);
    }
}

// Change speed
void changeSpeedTrain(int id) {
    if(serverConnected){
        mensagem.trainID = id;
        mensagem.speed = (40+(readAnalog(1)/10));
        sendMensage(mensagem);
    }else{
        printMensage("Connect to the server before", 93);
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
        menuAnimation(optionActive);

        int n;
        cin >> n;

        if(n == 2){
            int id;
            if(optionActive >= 4 && optionActive <= 6){
                id = menuGetId();
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
        usleep(500000);
        menuAnimation(optionActive);

        up = botaoUp.getNumericValue();
        play = botaoPlay.getNumericValue();
        down = botaoDown.getNumericValue();

        if(play == 1){
            int id;
            if(optionActive >= 4 && optionActive <= 6){
                id = menuGetId();
            }
            menuExecute(optionActive, id);
        } else if(up == 1){
            ++optionActive;
            if(optionActive == options.size()){ optionActive = 0;}
            system("clear");
        } else if(down == 1){
            --optionActive;
            if(optionActive == -1){ optionActive = options.size() -1;}
            system("clear");
        }


    }

}

/*---------------------------------------------------------------------------------*/

void funcaoSignalHandler (int sig){
    colorir(false, 40);
    exit(EXIT_SUCCESS);
}

int main(int argc, char *argv[]){
    signal(SIGINT, funcaoSignalHandler);

    initOptionMenu();
    thread t1(buttonsRead);
    //thread test(teste);

    t1.join();
    //test.join();
    return 0;
}

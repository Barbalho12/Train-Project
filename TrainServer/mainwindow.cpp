#include <cstdio>       //printf
#include <cstring>      //memset
#include <cstdlib>      //exit
#include <netinet/in.h> //htons
#include <arpa/inet.h>  //inet_addr
#include <sys/socket.h> //socket
#include <unistd.h>     //close
#include <thread>
#include <iostream>
#include <vector>
#include "mainwindow.h"
#include "ui_mainwindow.h"

// Constantes
#define MAXMSG 1024
#define MAXNAME 100


void MainWindow::socketHandler(int socketDescriptor, Mensagem mensagem) {
    int byteslidos;

    if (socketDescriptor == -1) {
        printf("Falha ao executar accept().");
        exit(EXIT_FAILURE);
    }


    byteslidos = recv(socketDescriptor,&mensagem,sizeof(mensagem),0);
    cout << byteslidos << endl;

    this->mensagem = mensagem;
    updateTrains();

    if (byteslidos == -1) {
        printf("Falha ao executar recv()");
        exit(EXIT_FAILURE);
    }

    else if (byteslidos == 0) {
        printf("Cliente finalizou a conexão\n");
        //exit(EXIT_SUCCESS);
    }

    //printf("Servidor recebeu a seguinte msg do cliente [%s:%d]: %s \n", mensagem.trainID, mensagem.speed);

    ::close(socketDescriptor);
}

void MainWindow::server() {

    // Variáveis do servidor
    struct sockaddr_in endereco;
    //int socketId;

    // Variáveis relacionadas com as conexões clientes
    struct sockaddr_in enderecoCliente;
    socklen_t tamanhoEnderecoCliente = sizeof(struct sockaddr);
    int conexaoClienteId;

    Mensagem mensagem;

    memset(&endereco, 0, sizeof(endereco));
    endereco.sin_family = AF_INET;
    endereco.sin_port = htons(PORTNUM);
    endereco.sin_addr.s_addr = inet_addr(IP_SERV);

    socketId = socket(AF_INET, SOCK_STREAM, 0);

    if (socketId == -1) {
        printf("Falha ao executar socket().\n");
        exit(EXIT_FAILURE);
    }

    if (bind(socketId, (struct sockaddr *)&endereco, sizeof(struct sockaddr)) == -1 ) {
        printf("Falha ao executar bind().\n");
        exit(EXIT_FAILURE);
    }

    if (listen( socketId, 10 ) == -1) {
        printf("Falha ao executar listen().\n");
        exit(EXIT_FAILURE);
    }

    // Servidor ficar em um loop infinito
    while(true) {
        printf("Servidor: esperando conexões clientes\n");

        // Servidor fica bloqueado esperando uma conexão do cliente
        conexaoClienteId = accept(socketId,(struct sockaddr *) &enderecoCliente, &tamanhoEnderecoCliente);


        printf("Servidor: recebeu conexão de %s\n", inet_ntoa(enderecoCliente.sin_addr));

        threadServer = std::thread(&MainWindow::socketHandler,this, conexaoClienteId, mensagem);

        threadServer.detach();

        sleep(1);
        //::close(conexaoClienteId);
    }
}

Trem *MainWindow::createTrem(int id, int velocidade, int step, bool clockwise, QRect qtrem, QRect qtrilho){
    int x = qtrem.x();
    int y = qtrem.y();
    int top = qtrilho.y();
    int left = qtrilho.x();
    int right = left + qtrilho.width();
    int bottom = top + qtrilho.height();
    Trem *trem = new Trem(id, x, y, velocidade, step, clockwise, top, left,right,bottom);

    return trem;
}

void MainWindow::updateTrains(){
    switch (mensagem.trainID) {
        case -1:
            if(mensagem.travado){
                trem1->setEnable(false);
                trem2->setEnable(false);
                trem3->setEnable(false);
                trem4->setEnable(false);
                trem5->setEnable(false);
                trem6->setEnable(false);
            }else{
                trem1->setEnable(true);
                trem2->setEnable(true);
                trem3->setEnable(true);
                trem4->setEnable(true);
                trem5->setEnable(true);
                trem6->setEnable(true);
            }
        break;
        case 1:
            if(mensagem.speed != -1) trem1->setVelocidade(mensagem.speed);
            else
            if(mensagem.travado == false)  trem1->setEnable(true);
        break;
        case 2:
            if(mensagem.speed != -1) trem2->setVelocidade(mensagem.speed);
            else
            trem2->setEnable(!mensagem.travado);
        break;
        case 3:
            if(mensagem.speed != -1) trem3->setVelocidade(mensagem.speed);
            else
            trem3->setEnable(!mensagem.travado);
        break;
        case 4:
            if(mensagem.speed != -1) trem4->setVelocidade(mensagem.speed);
            else
            trem4->setEnable(!mensagem.travado);
        break;
        case 5:
            if(mensagem.speed != -1) trem5->setVelocidade(mensagem.speed);
            else
            trem5->setEnable(!mensagem.travado);
        break;
        case 6:
            if(mensagem.speed != -1) trem6->setVelocidade(mensagem.speed);
            else
            trem6->setEnable(!mensagem.travado);
        break;
        default:

        break;
    }
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {

    ui->setupUi(this);

    sem1 = new Semaforo(991,1,IPC_CREAT|0600);
    sem2 = new Semaforo(992,1,IPC_CREAT|0600);
    sem3 = new Semaforo(993,1,IPC_CREAT|0600);
    sem4 = new Semaforo(994,1,IPC_CREAT|0600);
    sem5 = new Semaforo(995,1,IPC_CREAT|0600);
    sem6 = new Semaforo(996,1,IPC_CREAT|0600);
    sem7 = new Semaforo(997,1,IPC_CREAT|0600);
    sem8 = new Semaforo(998,1,IPC_CREAT|0600);

    trem1 = createTrem(1, 120, 10, true, ui->labelTrem01->geometry(), ui->labelTrilho01->geometry());
    trem2 = createTrem(2, 140, 10, false, ui->labelTrem02->geometry(), ui->labelTrilho02->geometry());
    trem3 = createTrem(3, 90, 10, true, ui->labelTrem03->geometry(), ui->labelTrilho03->geometry());
    trem4 = createTrem(4, 135, 10, false, ui->labelTrem04->geometry(), ui->labelTrilho04->geometry());
    trem5 = createTrem(5, 50,  10, true, ui->labelTrem05->geometry(), ui->labelTrilho05->geometry());
    trem6 = createTrem(6, 80, 10, true, ui->labelTrem06->geometry(), ui->labelTrilho06->geometry());

    RegiaoCritica *regiao12 =  new RegiaoCritica(160, 20, 160, 120, sem1); //1 e 2     ==
    RegiaoCritica *regiao14 =  new RegiaoCritica(160, 120, 90, 120, sem3); //1 e 4

    RegiaoCritica *regiao21 =  regiao12;
    RegiaoCritica *regiao24 =  new RegiaoCritica(160, 120, 300, 120, sem4); //2 e 4
    RegiaoCritica *regiao23 =  new RegiaoCritica(300, 120, 300, 20, sem2); //2 e 3

    RegiaoCritica *regiao34 =  new RegiaoCritica(370, 120, 300, 120, sem5); //3 e 4    ==
    RegiaoCritica *regiao32 =  regiao23;

    RegiaoCritica *regiao45 =  new RegiaoCritica(90, 220, 230, 220, sem6); //4 e 5
    RegiaoCritica *regiao46 =  new RegiaoCritica(230, 220, 370, 220, sem7); //4 e 6
    RegiaoCritica *regiao43 =  regiao34;
    RegiaoCritica *regiao42 =  new RegiaoCritica(300, 120, 160, 120, sem4); //4 e 2
    RegiaoCritica *regiao41 =  regiao14;

    RegiaoCritica *regiao54 =  regiao45;
    RegiaoCritica *regiao56 =  new RegiaoCritica(230, 220, 230, 320, sem8); //5 e 6

    RegiaoCritica *regiao64 =  regiao46;
    RegiaoCritica *regiao65 =  new RegiaoCritica(230, 320, 230, 220, sem8); //6 e 5

    trem1->addRegiaoCritica(regiao12,regiao14);
    trem2->addRegiaoCritica(regiao21,regiao24,regiao23);
    trem3->addRegiaoCritica(regiao34,regiao32);
    trem4->addRegiaoCritica(regiao45,regiao46,regiao43);
    trem4->addRegiaoCritica(regiao42,regiao41);
    trem5->addRegiaoCritica(regiao54,regiao56);
    trem6->addRegiaoCritica(regiao64,regiao65);

//    trem1->setEnable(false);
//    trem2->setEnable(false);
//    trem3->setEnable(false);
//    trem4->setEnable(false);
//    trem5->setEnable(false);
//    trem6->setEnable(false);

    connect(trem1, SIGNAL(updateGUI(int, int, int)), SLOT(updateInterface(int, int, int)));
    trem1->start();
    connect(trem2, SIGNAL(updateGUI(int, int, int)), SLOT(updateInterface(int ,int, int)));
    trem2->start();
    connect(trem3, SIGNAL(updateGUI(int, int, int)), SLOT(updateInterface(int, int, int)));
    trem3->start();
    connect(trem4, SIGNAL(updateGUI(int,int, int)), SLOT(updateInterface(int, int, int)));
    trem4->start();
    connect(trem5, SIGNAL(updateGUI(int, int, int)), SLOT(updateInterface(int, int, int)));
    trem5->start();
    connect(trem6, SIGNAL(updateGUI(int, int, int)), SLOT(updateInterface(int, int, int)));
    trem6->start();

    threadStartServer = std::thread(&MainWindow::server,this);

}

MainWindow::~MainWindow() {
    delete ui;
    ::close(socketId);
    //threadServer.detach();
    threadServer.join();
    threadStartServer.join();
}

void MainWindow::updateInterface(int id, int x, int y) {
    switch(id){
        case 1:
            ui->labelTrem01->setGeometry(x, y, 20, 20);
            break;
        case 2:
            ui->labelTrem02->setGeometry(x, y, 20, 20);
            break;
        case 3:
            ui->labelTrem03->setGeometry(x, y, 20, 20);
            break;
        case 4:
            ui->labelTrem04->setGeometry(x, y, 20, 20);
            break;
        case 5:
            ui->labelTrem05->setGeometry(x, y, 20, 20);
            break;
        case 6:
            ui->labelTrem06->setGeometry(x, y, 20, 20);
            break;
        default:
            break;
    }
}

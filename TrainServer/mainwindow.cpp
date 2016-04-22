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

    //Verificando erros
    if (socketDescriptor == -1) {
        printf("Falha ao executar accept().");
        exit(EXIT_FAILURE);
    }

    //receber uma msg do cliente
    //printf("Servidor vai ficar esperando uma mensagem\n");
    byteslidos = recv(socketDescriptor,&mensagem,sizeof(mensagem),0);

    if (byteslidos == -1) {
        printf("Falha ao executar recv()");
        exit(EXIT_FAILURE);
    }
    else if (byteslidos == 0) {
        printf("Cliente finalizou a conexão\n");
        exit(EXIT_SUCCESS);
    }

    if (mensagem.trainID == -1) {
        //
        trem1->setVelocidade(0);
    }

    printf("Servidor recebeu a seguinte msg do cliente [%s:%d]: %s \n", mensagem.trainID, mensagem.speed);

    ::close(socketDescriptor);
}

void MainWindow::server() {
    printf("o1");

    // Variáveis do servidor
    struct sockaddr_in endereco;
    int socketId;

    // Variáveis relacionadas com as conexões clientes
    struct sockaddr_in enderecoCliente;
    socklen_t tamanhoEnderecoCliente = sizeof(struct sockaddr);
    int conexaoClienteId;

    // Mensagem enviada pelo cliente
    Mensagem mensagem;

    /*
     * Configurações do endereço
     */
    memset(&endereco, 0, sizeof(endereco));
    endereco.sin_family = AF_INET;
    endereco.sin_port = htons(PORTNUM);
    // endereco.sin_addr.s_addr = INADDR_ANY;
    endereco.sin_addr.s_addr = inet_addr(IP_SERV);

    /*
     * Criando o Socket
     *
     * PARAM1: AF_INET ou AF_INET6 (IPV4 ou IPV6)
     * PARAM2: SOCK_STREAM ou SOCK_DGRAM
     * PARAM3: protocolo (IP, UDP, TCP, etc). Valor 0 escolhe automaticamente
     */
    socketId = socket(AF_INET, SOCK_STREAM, 0);

    // Verificar erros
    if (socketId == -1) {
        printf("Falha ao executar socket().\n");
        exit(EXIT_FAILURE);
    }

    // Conectando o socket a uma porta. Executado apenas no lado servidor
    if (bind(socketId, (struct sockaddr *)&endereco, sizeof(struct sockaddr)) == -1 ) {
        printf("Falha ao executar bind().\n");
        exit(EXIT_FAILURE);
    }

    // Habilitando o servidor a receber conexoes do cliente
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

        // Disparar a thread
        std::thread t(socketHandler, conexaoClienteId, mensagem);
        t.detach();

        //
        sleep(1);
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

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {

    ui->setupUi(this);

    trem1 = createTrem(1, 250, 10, true, ui->labelTrem01->geometry(), ui->labelTrilho01->geometry());
    trem2 = createTrem(2, 140, 10, false, ui->labelTrem02->geometry(), ui->labelTrilho02->geometry());
    trem3 = createTrem(3, 180, 10, true, ui->labelTrem03->geometry(), ui->labelTrilho03->geometry());
    trem4 = createTrem(4, 300, 10, false, ui->labelTrem04->geometry(), ui->labelTrilho04->geometry());
    trem5 = createTrem(5, 80, 10, true, ui->labelTrem05->geometry(), ui->labelTrilho05->geometry());
    trem6 = createTrem(6, 250, 10, true, ui->labelTrem06->geometry(), ui->labelTrilho06->geometry());

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
}

MainWindow::~MainWindow() {
    delete ui;
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

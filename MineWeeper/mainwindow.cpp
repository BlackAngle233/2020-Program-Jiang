#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QVBoxLayout"
#include "QHBoxLayout"
#include "QDebug"
#include "QMessageBox"
#include "QQueue"
#include "QPair"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label_2->setVisible(false);
    ui->label_3->setVisible(false);
    ui->widget->setVisible(false);
    Timer = new QTimer(this);
    Timer->stop();
    Timer->setInterval(1000);
    connect(Timer,SIGNAL(timeout()),this,SLOT(display_time()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::display_time() {
    int time = gamemanager.getTime();
    time ++;
    ui->label_2->setText("时间：" + QString::number(time));
    gamemanager.setTime(time);
}


void MainWindow::on_pushButton_clicked()
{
    mineweeper.newMineWeeper(9, 9, 10);
    gamemanager.setTime(0);
    gamemanager.setMines(10);
    gamemanager.setNum(39);
    gamemanager.initialFlags(9, 9);

    Timer->start();

    ui->label->setVisible(false);
    ui->pushButton->setVisible(false);
    ui->pushButton_2->setVisible(false);
    ui->pushButton_3->setVisible(false);
    ui->label_2->setVisible(true);
    ui->label_3->setVisible(true);
    ui->widget->setVisible(true);

    createMineButton(9, 9);
}

void MainWindow::on_pushButton_2_clicked()
{
    mineweeper.newMineWeeper(16, 16, 40);
    gamemanager.setTime(0);
    gamemanager.setMines(40);
    gamemanager.setNum(216);
    gamemanager.initialFlags(16, 16);

    Timer->start();

    ui->label->setVisible(false);
    ui->pushButton->setVisible(false);
    ui->pushButton_2->setVisible(false);
    ui->pushButton_3->setVisible(false);
    ui->label_2->setVisible(true);
    ui->label_3->setVisible(true);
    ui->widget->setVisible(true);

    createMineButton(16, 16);
}

void MainWindow::on_pushButton_3_clicked()
{
    mineweeper.newMineWeeper(30, 16, 99);
    gamemanager.setTime(0);
    gamemanager.setMines(99);
    gamemanager.setNum(381);
    gamemanager.initialFlags(30, 16);

    Timer->start();

    ui->label->setVisible(false);
    ui->pushButton->setVisible(false);
    ui->pushButton_2->setVisible(false);
    ui->pushButton_3->setVisible(false);
    ui->label_2->setVisible(true);
    ui->label_3->setVisible(true);
    ui->widget->setVisible(true);

    createMineButton(30, 16);
}

void MainWindow::clickMine(int t) {
    int x = t / 100;
    int y = t % 100;
    bool isMine = mineweeper.checkMine(x, y);
    if(isMine) {
        gameOver();
    }
    else {
        buttons[x][y]->setEnabled(false);
        gamemanager.openFlag(x, y);
        if(mineweeper.checkNum(x, y)) {
            buttons[x][y]->setText(QString::number(mineweeper.getNum(x, y)));
        }
        else {
            QQueue<QPair<int, int> > q;
            QPair<int, int> tmp = QPair<int, int>(x, y);
            q.enqueue(tmp);

            while(!q.empty()) {
                tmp = q.dequeue();
                for(int i = 0; i < 8; i ++) {
                    int nx = tmp.first + x_offset[i];
                    int ny = tmp.second + y_offset[i];
                    if(mineweeper.isValid(nx, ny) && gamemanager.getFlag(nx, ny) != 1) {
                        if(!mineweeper.checkMine(nx, ny)) {
                            gamemanager.openFlag(nx, ny);
                            buttons[nx][ny]->setEnabled(false);
                            if(mineweeper.checkNum(nx, ny)) {
                                buttons[nx][ny]->setText(QString::number(mineweeper.getNum(nx, ny)));
                            }
                            else {
                                q.enqueue(QPair<int, int>(nx, ny));
                            }
                        }
                    }
                }
            }
        }
    }
    if(gamemanager.isWin()) {
        QMessageBox::information(NULL, "Win", "你赢了", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        close();
    }
}

void MainWindow::testMine(int t) {
    int x = t / 100;
    int y = t % 100;
    gamemanager.setFlag(x, y);
    switch(gamemanager.getFlag(x, y)) {
    case 0:
        buttons[x][y]->setText(" ");
        break;
    case 2:
        buttons[x][y]->setText("*");
        break;
    case 3:
        buttons[x][y]->setText("?");
        break;
    default:
        break;
    }
    ui->label_3->setText("剩余：" + QString::number(gamemanager.getMines()));
}

void MainWindow::createMineButton(int x, int y) {
    signalMapper1 = new QSignalMapper(this);
    signalMapper2 = new QSignalMapper(this);
    QWidget * wdg = ui->widget;
    QHBoxLayout *hlay = new QHBoxLayout(wdg);
    for(int i = 0; i < x; ++i) {
        QVector<QPushButton *> tmp;
        QVBoxLayout *vlay = new QVBoxLayout(wdg);
        for (int j = 0; j < y; ++j) {
            QPushButton *btn = new QPushButton(" ");
            btn->resize(40, 40);
            connect(btn, SIGNAL(clicked()), signalMapper1, SLOT(map()));
            signalMapper1->setMapping(btn, i * 100 + j);
            btn->setContextMenuPolicy(Qt::CustomContextMenu);
            connect(btn, SIGNAL(customContextMenuRequested(QPoint)), signalMapper2, SLOT(map()));
            signalMapper2->setMapping(btn, i * 100 + j);
            vlay->addWidget(btn);
            tmp.push_back(btn);
        }
        hlay->addLayout(vlay);
        buttons.push_back(tmp);
    }
    connect(signalMapper1, SIGNAL(mapped(int)), this, SLOT(clickMine(int)));
    connect(signalMapper2, SIGNAL(mapped(int)), this, SLOT(testMine(int)));
    wdg->setLayout(hlay);
    wdg->resize(45 * x - 5, 45 * y - 5);
}

void MainWindow::gameOver() {
    QMessageBox::information(NULL, "GameOver", "你输了", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);

    close();
}

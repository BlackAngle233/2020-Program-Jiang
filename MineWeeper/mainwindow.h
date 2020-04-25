#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "MineWeeper.h"
#include "gamemanager.h"
#include "QSignalMapper"
#include "QPushButton"
#include "QVector"
#include "QTimer"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QVector<QVector<QPushButton* > > buttons;

private slots:
    void display_time();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void clickMine(int t);
    void testMine(int t);

private:
    Ui::MainWindow *ui;
    MineWeeper mineweeper;
    GameManager gamemanager;
    QSignalMapper *signalMapper1;
    QSignalMapper *signalMapper2;
    QTimer *Timer;

    void createMineButton(int x, int y);
    void gameOver();
};
#endif // MAINWINDOW_H

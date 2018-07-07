#ifndef MAINWINDOW_H
#define MAINWINDOW_H
// for std
#include <iostream>
#include <string>
// for qt
#include <QMainWindow>
#include <QString>
#include <QDebug>
// for python
#include <Python.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void InitializeParameters();
    void InitializeLineEdits();
    ~MainWindow();

private slots:
    void on_pushButton_submit_clicked();

private:
    Ui::MainWindow *ui;
    // link
    QString url;
    // date and time
    QString year;
    QString month, day;
    QString hour_of_day;
    // coordinates
    QString latitude, longitude;
    QString height;
    // profile type and its parameters
    QString start, stop, stepsize;
    // optional input
    QString rz12, ig12;
    QString upper_boundary;
    QString nmf2_cm3;
    QString hmf2_km;
};

#endif // MAINWINDOW_H

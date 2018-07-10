#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <Python.h>

#include <iostream>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_lat1->setText("0");
    ui->lineEdit_lon1->setText("0");
    ui->lineEdit_lat2->setText("30");
    ui->lineEdit_lon2->setText("30");
    ui->lineEdit_stepLat->setText("10");
    ui->lineEdit_stepLon->setText("10");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_submit_clicked()
{
    float lat1 = ui->lineEdit_lat1->text().toFloat();
    float lon1 = ui->lineEdit_lon1->text().toFloat();
    float lat2 = ui->lineEdit_lat2->text().toFloat();
    float lon2 = ui->lineEdit_lon2->text().toFloat();
    float stepLat = ui->lineEdit_stepLat->text().toFloat();
    float stepLon = ui->lineEdit_stepLon->text().toFloat();

    Py_Initialize();
    if(!Py_IsInitialized())
    {
        ui->textEdit_log->append("[ERROR] Not initialized.");
        return;
    }
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('./')");

    PyObject* pModule = PyImport_ImportModule("IRI_2001");
    if(!pModule)
    {
        ui->textEdit_log->append("[ERROR] Not found IRI_2001.py. Ensure that .py and executable file are in the same directory");
        return;
    }
    PyObject* pFunc = PyObject_GetAttrString(pModule, "IRI");
    if(!pFunc)
    {
        ui->textEdit_log->append("[ERROR] Get function IRI failed.");
        return;
    }
    for(float lat = min(lat1, lat2); lat < max(lat1, lat2); lat += stepLat)
    for(float lon = min(lon1, lon2); lon < max(lon1, lon2); lon += stepLon)
    {
        ui->textEdit_log->append("[INFO] Getting (latitude, longitude) = (" + QString::number(lat) + ", " + QString::number(lon) + ").");
        QApplication::processEvents();
        PyObject* pArg = Py_BuildValue("(d, d)", lat, lon);
        PyEval_CallObject(pFunc, pArg);
    }
    Py_Finalize();
    ui->textEdit_log->append("[INFO] Finished.");
}

void MainWindow::on_pushButton_edit_clicked()
{
    ui->textEdit_log->append("[INFO] Open IRI_2001.py and edit payloads, output path and file.");
}

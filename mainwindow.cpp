#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->url = "https://iri.gsfc.nasa.gov/iri.html";
    // initialize interface
    ui->setupUi(this);
    ui->comboBox_Time->addItems({"Universal", "Local"});
    ui->comboBox_CoordType->addItems({"Geographic", "Geomagnetic"});
    ui->comboBox_Profile->addItems({"Height,km[60.-2000.]", "Latitude,deg.[-90.-90.]", "Longitude,deg.[0.-360.]",
                                    "Year[1958-2009]", "Month[01-12]", "Day of month[01-31", "Day of year[1-366",
                                    "Hour profile[1.-24.]"});
    ui->comboBox_F_peak->addItems({"URSI", "CCIR"});
    ui->comboBox_BottomThickness->addItems({"B0 Table", "Gulyaeva"});
    ui->comboBox_Ion->addItems({"Danilov 95", "IRI-86"});
    ui->comboBox_forF2->addItems({"on", "off"});
    ui->comboBox_Te->addItems({"IRI-95", "TTSA-2000"});
    ui->comboBox_Ne->addItems({"IRI-95", "FPT-2000"});
    ui->comboBox_F1->addItems({"Scotto-1997 no L", "Scotto-1997 with L", "IRI-95"});

    // intialize variables
    InitializeParameters();
    InitializeLineEdits();

//    // initialize python environment
//    Py_Initialize();
//    PyRun_SimpleString("print('Hello, world')");
}

void MainWindow::InitializeParameters()
{
    // date and time
    this->year = "2000";
    this->month = "01";
    this->day = "01";
    this->hour_of_day = "1.5";
    // coordinates
    this->latitude = "50.";
    this->longitude = "40.";
    this->height = "100.";
    // profile type and its parameters
    this->start = "100.";
    this->stop = "2000.";
    this->stepsize = "50.";
    // optional input
    this->rz12 = "";
    this->ig12 = "";
    this->upper_boundary = "";
    this->nmf2_cm3 = "0.";
    this->hmf2_km = "0.";
}

void MainWindow::InitializeLineEdits()
{
    ui->lineEdit_Year->setText(this->year);
    ui->lineEdit_Month->setText(this->month);
    ui->lineEdit_Day->setText(this->day);
    ui->lineEdit_HourofDay->setText(this->hour_of_day);
    ui->lineEdit_Lat->setText(this->latitude);
    ui->lineEdit_Lon->setText(this->longitude);
    ui->lineEdit_Height->setText(this->height);
    ui->lineEdit_Start->setText(this->start);
    ui->lineEdit_Stop->setText(this->stop);
    ui->lineEdit_StepSize->setText(this->stepsize);
    ui->lineEdit_Rz12->setText(this->rz12);
    ui->lineEdit_IG12->setText(this->ig12);
    ui->lineEdit_bound->setText(this->upper_boundary);
    ui->lineEdit_NmF2->setText(this->nmf2_cm3);
    ui->lineEdit_hmF2->setText(this->hmf2_km);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_submit_clicked()
{
    // initialize python environment
    Py_Initialize();
    if(!Py_IsInitialized())
    {
        qDebug() << "[ERROR] Not initialized.";
        return;
    }
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('/home/sjy/Workspace/ionosphere/')");

    PyObject* pModule = PyImport_ImportModule("crawler");
    PyObject* pFunc = PyObject_GetAttrString(pModule, "Hello");
    if(!pFunc)
    {
        qDebug() << "Get function hello failed";
        return;
    }
    PyObject_CallFunction(pFunc, NULL);
    Py_Finalize();
}

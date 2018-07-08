#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// for qt
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_edit_clicked();
    void on_pushButton_submit_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

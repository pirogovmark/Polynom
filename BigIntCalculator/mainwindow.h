#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    std::string Delete_Scapes(std::string s);
    bool Check(std::string s);
    std::string Invertion(std::string s);
private slots:
    void on_Btn_Load_clicked();
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

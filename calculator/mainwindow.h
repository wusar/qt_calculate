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

private slots:
    void on_n1_clicked();

    void on_n2_clicked();

    void on_n3_clicked();

    void on_n4_clicked();

    void on_n5_clicked();

    void on_n6_clicked();

    void on_n7_clicked();

    void on_n8_clicked();

    void on_n9_clicked();

    void on_add_clicked();

    void on_del_clicked();

    void on_multiply_clicked();

    void on_divide_clicked();

    void on_AC_clicked();

    void on_ans_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_n0_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

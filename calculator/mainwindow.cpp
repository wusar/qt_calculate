#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
#include<stack>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_n1_clicked()
{
    QString expression=ui->screen->toPlainText();
    expression.append("1");
    ui->screen->setText(expression);
}

void MainWindow::on_n2_clicked()
{
    QString expression=ui->screen->toPlainText();
    expression.append("2");
    ui->screen->setText(expression);
}

void MainWindow::on_n3_clicked()
{
    QString expression=ui->screen->toPlainText();
    expression.append("3");
    ui->screen->setText(expression);
}

void MainWindow::on_n4_clicked()
{
    QString expression=ui->screen->toPlainText();
    expression.append("4");
    ui->screen->setText(expression);
}

void MainWindow::on_n5_clicked()
{
    QString expression=ui->screen->toPlainText();
    expression.append("5");
    ui->screen->setText(expression);
}

void MainWindow::on_n6_clicked()
{
    QString expression=ui->screen->toPlainText();
    expression.append("6");
    ui->screen->setText(expression);
}

void MainWindow::on_n7_clicked()
{
    QString expression=ui->screen->toPlainText();
    expression.append("7");
    ui->screen->setText(expression);
}

void MainWindow::on_n8_clicked()
{
    QString expression=ui->screen->toPlainText();
    expression.append("8");
    ui->screen->setText(expression);
}

void MainWindow::on_n9_clicked()
{
    QString expression=ui->screen->toPlainText();
    expression.append("9");
    ui->screen->setText(expression);
}

void MainWindow::on_add_clicked()
{
    QString expression=ui->screen->toPlainText();
    expression.append("+");
    ui->screen->setText(expression);
}

void MainWindow::on_del_clicked()
{
    QString expression=ui->screen->toPlainText();
    expression.append("-");
    ui->screen->setText(expression);
}

void MainWindow::on_multiply_clicked()
{
    QString expression=ui->screen->toPlainText();
    expression.append("*");
    ui->screen->setText(expression);
}

void MainWindow::on_divide_clicked()
{
    QString expression=ui->screen->toPlainText();
    expression.append("/");
    ui->screen->setText(expression);
}

void MainWindow::on_AC_clicked()
{
    QString expression("");
    ui->screen->setText(expression);
}

void postfix_expression(char* midfix,char *postfix)
{

    int j=0;
    std::stack<char> opera;
    int priority[256];
    priority['#']=0;
    priority['(']=1;
    priority['+']=2;
    priority['-']=3;
    priority['*']=4;
    priority['/']=5;
    priority[')']=6;
    opera.push('#');
    for(int i=0;midfix[i];i++)
    {
        if(midfix[i]<='9'&&midfix[i]>='0')
        {
            postfix[j]=midfix[i];
            j++;
            if(midfix[i+1]<='9'&&midfix[i+1]>='0');
            else{
            postfix[j]=' ';
            j++;
            }
        }
        else if(midfix[i]==')')
        {
            while (opera.top()!='(')
            {
                postfix[j]=opera.top();
                opera.pop();
                j++;
            }
            opera.pop();
        }
        else if(midfix[i]=='(')
        {
            opera.push('(');
        }
        else{
            while (priority[midfix[i]]<priority[opera.top()]) {
                postfix[j]=opera.top();
                opera.pop();
                j++;
            }
            opera.push(midfix[i]);
        }
    }
    while (opera.top()!='#')
    {
        postfix[j]=opera.top();
        opera.pop();
        j++;
    }
}

int calcu(char* postfix)
{
    int num,j=0;
    int left,right,ans;
    char temp[20]={0};
    std::stack<int> nums;
    for(int i=0;postfix[i];i++)
    {
        for(j=0;postfix[i]<='9'&&postfix[i]>='0';j++,i++)
        {
            temp[j]=postfix[i];
        }
        if(j!=0)
        {
            num=atoi(temp);
            for(int k=0;k<20;k++)temp[k]=0;
            nums.push(num);
            j=0;
        }
        else {
            right=nums.top();
            nums.pop();
            left=nums.top();
            nums.pop();
            qDebug()<<left<<right;
            if(postfix[i]=='+')
            {
                ans=left+right;
            }
            if(postfix[i]=='-')
            {
                ans=left-right;
            }
            if(postfix[i]=='*')
            {
                ans=left*right;
            }
            if(postfix[i]=='/')
            {
                ans=left/right;
            }
            nums.push(ans);
        }
    }
    return nums.top();
}

void MainWindow::on_ans_clicked()
{
    QString expression=ui->screen->toPlainText();
    char midfix[100]={0},postfix[100]={0};
    for(int i=0;i<expression.length();i++)
    {
        QChar num=expression.at(i);
        midfix[i]=num.unicode();

    }
    postfix_expression(midfix,postfix);
    int a=calcu(postfix);

    QString ans;
    ans.setNum(a);
    ui->screen->setText(ans);
}

void MainWindow::on_pushButton_clicked()
{
    QString expression=ui->screen->toPlainText();
    expression.append("(");
    ui->screen->setText(expression);
}

void MainWindow::on_pushButton_2_clicked()
{
    QString expression=ui->screen->toPlainText();
    expression.append(")");
    ui->screen->setText(expression);
}

void MainWindow::on_n0_clicked()
{
    QString expression=ui->screen->toPlainText();
    expression.append("0");
    ui->screen->setText(expression);
}

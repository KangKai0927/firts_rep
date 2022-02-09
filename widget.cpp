#include "widget.h"
#include "ui_widget.h"
#include<QFileDialog>
#include<QString>
#include<QFile>
#include<QFileInfo>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
     QString filename=QFileDialog::getOpenFileName(this,"获取文件","D:\\QT_test\\file_operation"); //注意双反斜杠
     if(filename.isEmpty()){
         return;   // 如果文件名是空 则返回
     }
     else{
         //ui->lineEdit->clear();
         ui->lineEdit->setText(filename);  //   显示文件名
         QFile file(filename);         //
         file.open(QIODevice::Append); //     定义文件为只读
         //QByteArray arr=file.readAll();  //     读取文件内的所有内容
         //QString content=QString(arr);  //     将文件内容转换成String  默认情况下可以自动转换   有时候会乱码 需要使用gdk编码
         //this->ui->textEdit->setPlainText(content); //  将文件内容显示到文本框中
//         while(!file.atEnd()){
//             QString  con=file.readLine();
//             ui->textEdit->append(con);
//         }
         QFileInfo fileinfo(filename);
         file.write("123");
         file.close();
     }
}

#include "widget.h"
#include "ui_widget.h"

#include "dialog.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    Dialog * dialog = new Dialog;
    int ret = dialog->exec();
    if (ret == QDialog::Accepted) {
        auto data = dialog->get_data();
        ui->first_name_label->setText(data.first_name);
        ui->second_name_label->setText(data.second_name);
        ui->password_label->setText(data.password);
        ui->email_label->setText(data.email);
    }
}


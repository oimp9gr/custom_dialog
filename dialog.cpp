#include "dialog.h"
#include "ui_dialog.h"

#include <QLineEdit>

namespace {

QString InsufficientInputErrorToQSting(InsufficientInputError error){
    if (error == InsufficientInputError::FirstName) {
        return "First name is not specified";
    } else if (error == InsufficientInputError::Password) {
        return "Password is not specified";
    } else if (error == InsufficientInputError::Email) {
        return "Email is not specified";
    } else {
        return "";
    }
}

}

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

const Dialog::Data &Dialog::get_data() const {
    return data;
}

void Dialog::on_first_name_lineEdit_textChanged(const QString &)
{
    auto error = check_insufficient_errors();
    ui->error_label->setText(InsufficientInputErrorToQSting(error));
}

void Dialog::on_password_lineEdit_textChanged(const QString &arg1)
{
    auto error = check_insufficient_errors();
    ui->error_label->setText(InsufficientInputErrorToQSting(error));
}

void Dialog::on_email_lineEdit_textChanged(const QString &arg1)
{
    auto error = check_insufficient_errors();
    ui->error_label->setText(InsufficientInputErrorToQSting(error));
}

InsufficientInputError Dialog::check_insufficient_errors() {
    if (ui->first_name_lineEdit->text().isEmpty()) {
        ui->error_label->setText("First name is not specified");
        return InsufficientInputError::FirstName;
    } else if (ui->password_lineEdit->text().isEmpty()) {
        ui->error_label->setText("Password is not specified");
        return InsufficientInputError::Password;
    } else if (ui->email_lineEdit->text().isEmpty()) {
        ui->error_label->setText("Email is not specified");
        return InsufficientInputError::Email;
    } else {
        return InsufficientInputError::None;
    }
}

void Dialog::collect_data() {
    data.first_name = ui->first_name_lineEdit->text();
    data.second_name = ui->second_name_lineEdit->text();
    data.password = ui->password_lineEdit->text();
    data.email = ui->email_lineEdit->text();
}

void Dialog::on_ok_pushButton_clicked()
{
    auto error = check_insufficient_errors();
    ui->error_label->setText(InsufficientInputErrorToQSting(error));
    if (error == InsufficientInputError::None) {
        collect_data();
        accept();
    }
}

void Dialog::on_cancel_pushButton_clicked()
{
    reject();
}


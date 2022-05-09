#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

enum class InsufficientInputError {
    None = 0,
    FirstName = 1,
    Password = 2,
    Email = 3
};

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

    struct Data {
        QString first_name;
        QString second_name;
        QString password;
        QString email;
    };

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

    Data const & get_data() const;

private slots:
    void on_first_name_lineEdit_textChanged(const QString &arg1);

    void on_password_lineEdit_textChanged(const QString &arg1);

    void on_email_lineEdit_textChanged(const QString &arg1);

    void on_ok_pushButton_clicked();

    void on_cancel_pushButton_clicked();

private:
    InsufficientInputError check_insufficient_errors();

    void collect_data();

private:
    Data data;

    Ui::Dialog *ui;
};

#endif // DIALOG_H

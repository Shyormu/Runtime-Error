#include "loginDialog.h"
#include "ui_loginDialog.h"

loginDialog::loginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginDialog)
{
    ui->setupUi(this);
    isLoggedIn = false; // initialize user to not logged in
}

loginDialog::~loginDialog()
{
    delete ui;
}

bool loginDialog::loggedIn()
{
    return isLoggedIn;
}

void loginDialog::on_loginButton_clicked()
{
    // get user input for username and password fields
    QString usernameInput = ui->usernameField->text();
    QString passwordInput = ui->passwordField->text();

    // check if username and password are valid
    if((usernameInput == "Admin" || usernameInput == "admin" ) && (passwordInput == "password" || passwordInput == "baseball"))
    {
        // mark user as administrator and notify them of successful login before closing
        QMessageBox::information(this, "Success", "Logged in as Administrator.");
        isLoggedIn = true;
        this->close();
    }
    else
    {
        // notify user of incorrect username/password
        QMessageBox::information(this, "Error", "Incorrect login information.");
        // clear text fields
        ui->usernameField->setText("");
        ui->passwordField->setText("");
        isLoggedIn = false;
    }
}

void loginDialog::on_cancelButton_clicked()
{
    this->close();
}

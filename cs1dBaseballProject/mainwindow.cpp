#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    isAdmin = false;

    ui->setupUi(this);

    // initialize database manager object
    const QString FILE_NAME = "baseballProject.db";

    // path is set to search in debug folder
    QString dbPath = qApp->applicationDirPath();
    dbPath.append("/../../SQLite/" + FILE_NAME);

    // open database with file path
    database = new databaseManager(dbPath);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionLog_in_triggered()
{
    // open new login window to allow user to attempt to log in
    lDialog = new loginDialog();
    lDialog->setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint & ~Qt::WindowMinMaxButtonsHint);
    lDialog->exec();
    isAdmin = lDialog->loggedIn();
    delete lDialog;
}

void MainWindow::on_actionLog_out_triggered()
{
    // set isAdmin to false and open message box notifying user they have been logged out
    isAdmin = false;
    QMessageBox::information(this, "Log Out", "You are now logged out.");
}

void MainWindow::on_actionView_Database_triggered()
{
    // open new database view window
    dbView = new databaseViewer(nullptr, isAdmin);
    dbView->exec();
    delete dbView;
    dbView = nullptr;
}

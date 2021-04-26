#include "databaseViewer.h"
#include "ui_databaseViewer.h"

databaseViewer::databaseViewer(QWidget *parent, bool adminUser, databaseManager* dbManager) :
    QDialog(parent),
    ui(new Ui::databaseViewer)
{
    vector<QString> temp;

    database = dbManager;

    ui->setupUi(this);

    temp = database->getTeamNames();

    // populate campuses combo box
    for(auto &i : database->getTeamNames())
    {
        ui->teamSelectBox->addItem(i);
        //ui->teamSelectBoxSouv->addItem(i);
    }

    // get admin status from main window
    isAdmin = adminUser;

    // populate the souvenir and campus distance models once on init
    // calling button press code for same effect
    on_displayTeamButton_clicked();
    //on_displaySouvButton_clicked();
}

databaseViewer::~databaseViewer()
{
    delete ui;
    delete database;
}

void databaseViewer::on_modifyStadiumButton_clicked()
{

}

void databaseViewer::on_addStadiumButton_clicked()
{

}

void databaseViewer::on_closeDatabaseButton_clicked()
{
    this->close();
}

void databaseViewer::on_displayTeamButton_clicked()
{
    if(ui->teamSelectBox->currentText() == "")
    {
        QMessageBox::warning(this, "Error", "Please select a team first.");
    }
    else
    {
        qDebug() << "getting info from " << ui->teamSelectBox->currentText();

        auto model = database->getTeamViewModel(ui->teamSelectBox->currentText());

        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Stadium Name"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Seating Capacity"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Location"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Playing Surface"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("League"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date Opened"));
        model->setHeaderData(6, Qt::Horizontal, QObject::tr("Distance to Center (ft)"));
        model->setHeaderData(7, Qt::Horizontal, QObject::tr("Park Typology"));
        model->setHeaderData(8, Qt::Horizontal, QObject::tr("Roof Type"));

        ui->teamTableView->setModel(model);
        ui->teamTableView->setColumnWidth(0,180);
        ui->teamTableView->setColumnWidth(1,110);
        ui->teamTableView->setColumnWidth(2,160);
        ui->teamTableView->setColumnWidth(3,160);
        ui->teamTableView->setColumnWidth(4,70);
        ui->teamTableView->setColumnWidth(5,80);
        ui->teamTableView->setColumnWidth(6,130);
        ui->teamTableView->setColumnWidth(7,90);
        ui->teamTableView->setColumnWidth(8,70);
    }
}

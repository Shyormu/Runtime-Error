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

    // populate team combo box
    for (auto &i : database->getTeamNames())
    {
        ui->teamSelectBox->addItem(i);
        //ui->teamSelectBoxSouv->addItem(i);
    }

    // populate league combo box
    ui->leagueSelectBox->addItem("American League");
    ui->leagueSelectBox->addItem("National League");
    ui->leagueSelectBox->addItem("Both Leagues");

    // populate sorting combo box
    ui->sortSelectBox->addItem("Sort by team");
    ui->sortSelectBox->addItem("Sort by stadium");
    ui->sortSelectBox->addItem("Unsorted");

    // get admin status from main window
    isAdmin = adminUser;

    if (!isAdmin)
    {
        ui->addStadiumButton->setEnabled(false);
        ui->modifyStadiumButton->setEnabled(false);
    }

    // populate the souvenir and campus distance models once on init
    // calling button press code for same effect
    //on_displayTeamButton_clicked();
    //on_displaySouvButton_clicked();
}

databaseViewer::~databaseViewer()
{
    delete ui;
    delete database;
}

void databaseViewer::on_modifyStadiumButton_clicked()
{
    // ensure user is an admin before allowing modifications
    if (isAdmin)
    {

    }
    else
    {
        QMessageBox::information(this, QObject::tr("Warning!"), tr("Only administrators can modify stadiums."));
    }
}

void databaseViewer::on_addStadiumButton_clicked()
{
    // ensure user is an admin before allowing modifications
    if (isAdmin)
    {

    }
    else
    {
        QMessageBox::information(this, QObject::tr("Warning!"), tr("Only administrators can add stadiums."));
    }
}

void databaseViewer::on_closeDatabaseButton_clicked()
{
    this->close();
}

void databaseViewer::on_displayTeamButton_clicked()
{
    if (ui->teamSelectBox->currentText() == "Select a team...")
    {
        QMessageBox::warning(this, "Error", "Please select a team first.");
    }
    else
    {
        qDebug() << "getting info from " << ui->teamSelectBox->currentText();

        auto model = database->getTeamViewModel(ui->teamSelectBox->currentText());

        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Team Name"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Stadium Name"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Seating Capacity"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Location"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Playing Surface"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("League"));
        model->setHeaderData(6, Qt::Horizontal, QObject::tr("Date Opened"));
        model->setHeaderData(7, Qt::Horizontal, QObject::tr("Distance to Center (ft)"));
        model->setHeaderData(8, Qt::Horizontal, QObject::tr("Park Typology"));
        model->setHeaderData(9, Qt::Horizontal, QObject::tr("Roof Type"));

        ui->teamTableView->setModel(model);
        ui->teamTableView->setColumnWidth(0,140);
        ui->teamTableView->setColumnWidth(1,200);
        ui->teamTableView->setColumnWidth(2,110);
        ui->teamTableView->setColumnWidth(3,160);
        ui->teamTableView->setColumnWidth(4,160);
        ui->teamTableView->setColumnWidth(5,70);
        ui->teamTableView->setColumnWidth(6,80);
        ui->teamTableView->setColumnWidth(7,130);
        ui->teamTableView->setColumnWidth(8,90);
        ui->teamTableView->setColumnWidth(9,70);
    }
}

void databaseViewer::on_displayAllButton_clicked()
{

    vector<stadium>* stadiums = database->getStadiums();


    ui->teamTableView->

    // set up the table of transactions
    ui->teamTableView->setColumnCount(5);
    ui->teamTableView->setColumnWidth(0, 275);
    ui->transactionTableWidget->setColumnWidth(1, 225);
    ui->transactionTableWidget->setColumnWidth(2, 70);
    ui->transactionTableWidget->setColumnWidth(3, 70);
    ui->transactionTableWidget->setColumnWidth(4, 108);
    ui->transactionTableWidget->setRowCount(0);
    ui->transactionTableWidget->verticalHeader()->hide();
    ui->transactionTableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Campus"));
    ui->transactionTableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Souvenir"));
    ui->transactionTableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("Price"));
    ui->transactionTableWidget->setHorizontalHeaderItem(3, new QTableWidgetItem("Quantity"));
    ui->transactionTableWidget->setHorizontalHeaderItem(4, new QTableWidgetItem("Total"));
    ui->transactionTableWidget->setSortingEnabled(false);














//    QString leagueType;

//    if (ui->leagueSelectBox->currentText() == "National League")
//    {
//        leagueType = "National";
//    }
//    else if (ui->leagueSelectBox->currentText() == "American League")
//    {
//        leagueType = "American";
//    }
//    else
//    {
//        leagueType = "Both";
//    }
//    auto model = database->getAllByLeagueModel(leagueType);

//    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Team Name"));
//    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Stadium Name"));
//    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Seating Capacity"));
//    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Location"));
//    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Playing Surface"));
//    model->setHeaderData(5, Qt::Horizontal, QObject::tr("League"));
//    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Date Opened"));
//    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Distance to Center (ft)"));
//    model->setHeaderData(8, Qt::Horizontal, QObject::tr("Park Typology"));
//    model->setHeaderData(9, Qt::Horizontal, QObject::tr("Roof Type"));

//    ui->teamTableView->setModel(model);
//    ui->teamTableView->setColumnWidth(0,140);
//    ui->teamTableView->setColumnWidth(1,200);
//    ui->teamTableView->setColumnWidth(2,110);
//    ui->teamTableView->setColumnWidth(3,160);
//    ui->teamTableView->setColumnWidth(4,160);
//    ui->teamTableView->setColumnWidth(5,70);
//    ui->teamTableView->setColumnWidth(6,80);
//    ui->teamTableView->setColumnWidth(7,130);
//    ui->teamTableView->setColumnWidth(8,90);
//    ui->teamTableView->setColumnWidth(9,70);

}

void databaseViewer::filterLeague(vector<stadium>* stadiums, QString selection)
{

}

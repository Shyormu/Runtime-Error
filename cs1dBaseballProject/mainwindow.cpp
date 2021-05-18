#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    isAdmin = false;

    ui->setupUi(this);
 ui->setupUi(this);
    QPixmap pix("/Users/aminparvizi/Desktop/teamlogo2.png");

    ui->piclbl->setPixmap(pix);

    QPixmap bkgnd("/Users/aminparvizi/Desktop/MLBback2.png");
        bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Background, bkgnd);
        this->setPalette(palette);

    ui->stackedWidget->setCurrentWidget(ui->Login);


    ui->teamcombobox->clear();
    ui->TeamCombosouv->clear();
    ui->stadiumcombobox->clear();
    ui->tripBox->clear();
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


void MainWindow::on_actionLogin_triggered()
{
    admin = new adminLogin(this);
    admin -> show();
}

void MainWindow::on_actionOpen_triggered()
{
    QString path=QFileDialog::getOpenFileName(this, "save.txt");
    QFile file(path);
    if(file.open(QIODevice::ReadOnly)){
        QTextStream instream(&file);
       renderArea->createShapeBuffer(instream);
    }
    renderArea->update();

}

void MainWindow::on_actionSave_triggered()
{
    QString path = QFileDialog::getSaveFileName(nullptr, tr("Save"), ".txt");
    QFile file(path);
    if(file.open(QIODevice::WriteOnly))
    {
        QTextStream ostream(&file);
        renderArea->readOut(ostream);
    }
    file.close();
    file.flush();
}

void MainWindow::on_actionQuit_triggered()
{
    /*GET CURRENT LOGOUT TIME*/
    QTime endTime = QTime::currentTime ();
    
    /*PERTINENT TIME INFO TO TRANSLATE TO STRING*/
    QString temp = "LOGIN TIME     : [" + initialTime.toString ("hh:mm:ss") + "]\nLOGOUT TIME : [" + endTime.toString ("hh:mm:ss") + "]";
    QString temp2 = "\nElapsed time: " + timeDifference(initialTime,endTime).toString("hh:mm:ss");
    
    /*SETTING MESSAGE BOX INFO*/
    QMessageBox msgbox;
    msgbox.setText(temp + '\n' + temp2);
    msgbox.exec ();
    
    QApplication::quit();
}


void MainWindow::on_actionShow_Info_triggered()
{
    shapeInfo = new ShapeInfo(this,ShapeInfo::SortType::ID);
    shapeInfo -> show();
}

void MainWindow::on_moveButton_clicked()
{
    //QString input = ui -> moveInput -> text();
    //renderArea->setIndex(input.toInt());

}

void MainWindow::on_actionShow_Area_triggered()
{
    shapeInfo = new ShapeInfo(this,ShapeInfo::SortType::AREA);
     shapeInfo -> show();
}

void MainWindow::on_actionShow_Perimeter_triggered()
{
    shapeInfo = new ShapeInfo(this,ShapeInfo::SortType::PERIM);
    shapeInfo -> show();
}

void MainWindow::on_actionLog_Out_triggered()
{
    renderArea -> disableAdmin();
    QMessageBox::information(this, "Log Out", "You have successfully logged out.");
}


void MainWindow::on_actionContact_Us_triggered()
{
    contactInfo = new contact(this);
    //contactInfo -> adjustSize();
    //contactInfo -> setFixedSize(contactInfo -> sizeHint());
    contactInfo -> show();
}

void MainWindow::on_actionOpen_palette_triggered()
{
    palette = new Palette(this);
    palette -> show();
}
}

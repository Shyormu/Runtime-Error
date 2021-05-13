#include "databaseViewer.h"
#include "ui_databaseViewer.h"

//=============================================================================================
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
    ui->filterSelectBox->addItem("American League");
    ui->filterSelectBox->addItem("National League");
    ui->filterSelectBox->addItem("Greatest distance to center field");
    ui->filterSelectBox->addItem("Smallest distance to center field");
    ui->filterSelectBox->addItem("Open roof type");
    ui->filterSelectBox->addItem("All teams");

    // populate sorting combo box
    ui->sortSelectBox->addItem("Sort by team");
    ui->sortSelectBox->addItem("Sort by stadium");
    ui->sortSelectBox->addItem("Sort by open date");
    ui->sortSelectBox->addItem("Sort by park typology");
    ui->sortSelectBox->addItem("Sort by seating capacity");
    ui->sortSelectBox->addItem("No sorting");

    // get admin status from main window
    isAdmin = adminUser;

    if (!isAdmin)
    {
        ui->addStadiumButton->setEnabled(false);
        ui->modifyStadiumButton->setEnabled(false);
    }

    // set up the table to display the team
    ui->teamTableWidget->setColumnCount(10);
    ui->teamTableWidget->setColumnWidth(0, 275);
    ui->teamTableWidget->setColumnWidth(0,140);
    ui->teamTableWidget->setColumnWidth(1,200);
    ui->teamTableWidget->setColumnWidth(2,110);
    ui->teamTableWidget->setColumnWidth(3,160);
    ui->teamTableWidget->setColumnWidth(4,160);
    ui->teamTableWidget->setColumnWidth(5,70);
    ui->teamTableWidget->setColumnWidth(6,80);
    ui->teamTableWidget->setColumnWidth(7,130);
    ui->teamTableWidget->setColumnWidth(8,90);
    ui->teamTableWidget->setColumnWidth(9,70);
    ui->teamTableWidget->setRowCount(1);
    ui->teamTableWidget->verticalHeader()->hide();
    ui->teamTableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Team Name"));
    ui->teamTableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Stadium Name"));
    ui->teamTableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("Seating Capacity"));
    ui->teamTableWidget->setHorizontalHeaderItem(3, new QTableWidgetItem("Location"));
    ui->teamTableWidget->setHorizontalHeaderItem(4, new QTableWidgetItem("Playing Surface"));
    ui->teamTableWidget->setHorizontalHeaderItem(5, new QTableWidgetItem("League"));
    ui->teamTableWidget->setHorizontalHeaderItem(6, new QTableWidgetItem("Date Opened"));
    ui->teamTableWidget->setHorizontalHeaderItem(7, new QTableWidgetItem("Distance to Center (ft)"));
    ui->teamTableWidget->setHorizontalHeaderItem(8, new QTableWidgetItem("Park Typology"));
    ui->teamTableWidget->setHorizontalHeaderItem(9, new QTableWidgetItem("Roof Type"));
    ui->teamTableWidget->setSortingEnabled(false);

    ui->seatingLabel->setVisible(false);
    ui->roofLabel->setVisible(false);

}
//=============================================================================================



//=============================================================================================
databaseViewer::~databaseViewer()
{
    delete ui;
    delete database;
}
//=============================================================================================



//=============================================================================================
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
//=============================================================================================



//=============================================================================================
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
//=============================================================================================



//=============================================================================================
void databaseViewer::on_closeDatabaseButton_clicked()
{
    this->close();
}
//=============================================================================================



//=============================================================================================
void databaseViewer::on_displayTeamButton_clicked()
{
    stadium selectedStadium;   // stdaium whose data will be displayed
    QTableWidgetItem* newItem; // used to insert new items into the table

    // verify user has selected a team to display
    if (ui->teamSelectBox->currentIndex() == -1)
    {
        QMessageBox::warning(this, "Error", "Please select a team first.");
    }
    else
    {
        // get stadium object from database whose team name matches user's selection
        selectedStadium = database->getTeam(ui->teamSelectBox->currentText());

        // adjust number of rows in the table
        ui->teamTableWidget->setRowCount(1);

        // clear the labels for filtering/sorting
        ui->seatingLabel->setVisible(false);
        ui->roofLabel->setVisible(false);

        // for loop inserts all data for current stadium into cells
        for (int i = 0; i < 10; i++)
        {
            // switch statement to decide what data is being placed into current cell i
            switch (i)
            {
                case 0:
                    newItem = new QTableWidgetItem(selectedStadium.getTeamName());
                    break;
                case 1:
                    newItem = new QTableWidgetItem(selectedStadium.getStadiumName());
                    break;
                case 2:
                     newItem = new QTableWidgetItem( QString::number( selectedStadium.getCapacity() ) );
                    break;
                case 3:
                    newItem = new QTableWidgetItem(selectedStadium.getLocation());
                    break;
                case 4:
                     newItem = new QTableWidgetItem(selectedStadium.getSurface());
                    break;
                case 5:
                    newItem = new QTableWidgetItem(selectedStadium.getLeague());
                    break;
                case 6:
                    newItem = new QTableWidgetItem( QString::number( selectedStadium.getDate() ) );
                    break;
                case 7:
                    newItem = new QTableWidgetItem( QString::number( selectedStadium.getDistanceToCenter() ) );
                    break;
                case 8:
                    newItem = new QTableWidgetItem(selectedStadium.getParkType());
                    break;
                case 9:
                    newItem = new QTableWidgetItem(selectedStadium.getRoofType());
                    break;
                default:
                    break;
            }

            // align item text and place into cell i
            newItem->setTextAlignment(Qt::AlignCenter);
            ui->teamTableWidget->setItem(0, i, newItem);
        }
    }
}
//=============================================================================================



//=============================================================================================
void databaseViewer::on_displayAllButton_clicked()
{
    vector<stadium>* stadiums; // vector of all stadiums to be modified and displayed
    QTableWidgetItem* newItem; // used to insert new items into the table
    QString labelUpdate;       // used to update the counter label

    // output error messages if the button is pressed without selecting filter/sort options
    if (ui->filterSelectBox->currentIndex() == -1)
    {
        QMessageBox::warning(this, "Error", "Please select a league first.");
    }
    else if (ui->sortSelectBox->currentIndex() == -1)
    {
        QMessageBox::warning(this, "Error", "Please select a sorting method first.");
    }
    else
    {
        // get vector of all stadiums from database
        stadiums = database->getStadiums();

        // clear the labels for filtering/sorting stats
        ui->seatingLabel->setText("");
        ui->seatingLabel->setVisible(false);
        ui->roofLabel->setText("");
        ui->roofLabel->setVisible(false);

        // filter the stadiums held in the vector by selection
        switch (ui->filterSelectBox->currentIndex())
        {
        case 0:
            // filter by league selection (national)
            filterLeague(stadiums, ui->filterSelectBox->currentIndex());
            break;
        case 1:
            // filter by league selection (american)
            filterLeague(stadiums, ui->filterSelectBox->currentIndex());
            break;
        case 2:
            // filter by distance to center field (greatest)
            filterGreatestDistance(stadiums);
            break;
        case 3:
            // filter by distance to center field (smallest)
            filterSmallestDistance(stadiums);
            break;
        case 4:
            // filter by open roof type
            filterRoofType(stadiums);

            // update the label to display the total seating capacity of all stadiums
            labelUpdate = "Number of stadiums with an open roof type: ";
            labelUpdate.append( QString::number(stadiums->size()) );
            ui->roofLabel->setText(labelUpdate);
            ui->roofLabel->setVisible(true);
        default:
            // no filter
            break;
        }

        // sort the remaining stadiums according to selection
        switch (ui->sortSelectBox->currentIndex())
        {
        case 0:
            // sort alphabetically by team name
            sortByTeam(stadiums);
            break;
        case 1:
            // sort alphabetically by stadium name
            sortByStadium(stadiums);
            break;
        case 2:
            // sort chronologically from oldest to newest
            sortByDateOpened(stadiums);
            break;
        case 3:
            // sort alphabetically by park typology
            sortByParkTypology(stadiums);
            break;
        case 4:
            // sort smallest to largest by seating capacity
            sortByCapacity(stadiums);

            // update the label to display the total seating capacity of all stadiums
            labelUpdate = "Total seating capacity of displayed stadiums: ";
            labelUpdate.append( QString::number(totalCapacity(stadiums)) );
            ui->seatingLabel->setText(labelUpdate);
            ui->seatingLabel->setVisible(true);
            break;
        default:
            // no sorting
            break;
        }

        // adjust number of rows in the table
        ui->teamTableWidget->setRowCount(stadiums->size());

        // nested for loop iterates through each row and inserts data into each individual cell in each individual row according to # of stadiums
        for (ulong row = 0; row < stadiums->size(); row++)
        {
            for (int col = 0; col < 10; col++)
            {
                // switch statement to decide what data is being placed into current cell i
                switch (col)
                {
                    case 0:
                        newItem = new QTableWidgetItem(stadiums->at(row).getTeamName());
                        break;
                    case 1:
                        newItem = new QTableWidgetItem(stadiums->at(row).getStadiumName());
                        break;
                    case 2:
                         newItem = new QTableWidgetItem( QString::number( stadiums->at(row).getCapacity() ) );
                        break;
                    case 3:
                        newItem = new QTableWidgetItem(stadiums->at(row).getLocation());
                        break;
                    case 4:
                         newItem = new QTableWidgetItem(stadiums->at(row).getSurface());
                        break;
                    case 5:
                        newItem = new QTableWidgetItem(stadiums->at(row).getLeague());
                        break;
                    case 6:
                        newItem = new QTableWidgetItem( QString::number( stadiums->at(row).getDate() ) );
                        break;
                    case 7:
                        newItem = new QTableWidgetItem( QString::number( stadiums->at(row).getDistanceToCenter() ) );
                        break;
                    case 8:
                        newItem = new QTableWidgetItem(stadiums->at(row).getParkType());
                        break;
                    case 9:
                        newItem = new QTableWidgetItem(stadiums->at(row).getRoofType());
                        break;
                    default:
                        break;
                }

                // align item text and place into cell i
                newItem->setTextAlignment(Qt::AlignCenter);
                ui->teamTableWidget->setItem(row, col, newItem);
            }
        }
    }
}
//=============================================================================================



//=============================================================================================
void databaseViewer::filterLeague(vector<stadium>* stadiums, int index)
{
    if (index == 0)
    {
        // remove all elements in the vector that don't have the league type "American"
        for (auto it = stadiums->begin(); it != stadiums->end(); it++)
        {
            if (it->getLeague() != "American")
            {
                stadiums->erase(it);
                it--;
            }
        }
    }
    else if (index == 1)
    {
        // remove all elements in the vector that don't have the league type "National"
        for (auto it = stadiums->begin(); it != stadiums->end(); it++)
        {
            if (it->getLeague() != "National")
            {
                stadiums->erase(it);
                it--;
            }
        }

    }
    // if both leagues were selected, no changes will be made

    return;
}
//=============================================================================================



//=============================================================================================
void databaseViewer::filterGreatestDistance(vector<stadium>* stadiums)
{
    int greatestDistance = 0; // keeps track of the current greatest distance

    greatestDistance = stadiums->begin()->getDistanceToCenter();

    // find the greatest distance
    for (auto it = stadiums->begin(); it != stadiums->end(); it++)
    {
        if (it->getDistanceToCenter() > greatestDistance)
        {
            greatestDistance = it->getDistanceToCenter();
        }
    }

    // remove all elements in the vector that are less than the current greatest distance
    for (auto it = stadiums->begin(); it != stadiums->end(); it++)
    {
        if (it->getDistanceToCenter() != greatestDistance)
        {
            stadiums->erase(it);
            it--;
        }
    }

}
//=============================================================================================



//=============================================================================================
void databaseViewer::filterSmallestDistance(vector<stadium>* stadiums)
{
    int smallestDistance = 0; // keeps track of the current smallest distance

    smallestDistance = stadiums->begin()->getDistanceToCenter();

    // find the smallest distance
    for (auto it = stadiums->begin(); it != stadiums->end(); it++)
    {
        if (it->getDistanceToCenter() < smallestDistance)
        {
            smallestDistance = it->getDistanceToCenter();
        }
    }

    // remove all elements in the vector that are greater than the current smallest distance
    for (auto it = stadiums->begin(); it != stadiums->end(); it++)
    {
        if (it->getDistanceToCenter() != smallestDistance)
        {
            stadiums->erase(it);
            it--;
        }
    }
}
//=============================================================================================



//=============================================================================================
void databaseViewer::filterRoofType(vector<stadium>* stadiums)
{

    // remove all elements in the vector that don't have the roof type "Open"
    for (auto it = stadiums->begin(); it != stadiums->end(); it++)
    {
        if (it->getRoofType() != "Open")
        {
            stadiums->erase(it);
            it--;
        }
    }

    return;
}
//=============================================================================================



//=============================================================================================
void databaseViewer::sortByStadium(vector<stadium>* stadiums)
{
    // sort vector in order of stadium name
    for (ulong m = 0; m < stadiums->size(); m++)
    {
        for (ulong n = 0; n < stadiums->size() - m - 1; n++)
        {
            if (stadiums->at(n).getStadiumName() > stadiums->at(n+1).getStadiumName())
            {
                stadium temp = stadiums->at(n);
                stadiums->at(n) = stadiums->at(n+1);
                stadiums->at(n+1) = temp;
            }
        }
    }
}
//=============================================================================================



//=============================================================================================
void databaseViewer::sortByTeam(vector<stadium>* stadiums)
{
    // sort vector in order of stadium name
    for (ulong m = 0; m < stadiums->size(); m++)
    {
        for (ulong n = 0; n < stadiums->size() - m - 1; n++)
        {
            if (stadiums->at(n).getTeamName() > stadiums->at(n+1).getTeamName())
            {
                stadium temp = stadiums->at(n);
                stadiums->at(n) = stadiums->at(n+1);
                stadiums->at(n+1) = temp;
            }
        }
    }
}
//=============================================================================================



//=============================================================================================
void databaseViewer::sortByParkTypology(vector<stadium>* stadiums)
{
    // sort vector in order of stadium name
    for (ulong m = 0; m < stadiums->size(); m++)
    {
        for (ulong n = 0; n < stadiums->size() - m - 1; n++)
        {
            if (stadiums->at(n).getParkType() > stadiums->at(n+1).getParkType())
            {
                stadium temp = stadiums->at(n);
                stadiums->at(n) = stadiums->at(n+1);
                stadiums->at(n+1) = temp;
            }
        }
    }
}
//=============================================================================================



//=============================================================================================
void databaseViewer::sortByDateOpened(vector<stadium>* stadiums)
{
    // sort vector in order of stadium name
    for (ulong m = 0; m < stadiums->size(); m++)
    {
        for (ulong n = 0; n < stadiums->size() - m - 1; n++)
        {
            if (stadiums->at(n).getDate() > stadiums->at(n+1).getDate())
            {
                stadium temp = stadiums->at(n);
                stadiums->at(n) = stadiums->at(n+1);
                stadiums->at(n+1) = temp;
            }
        }
    }
}
//=============================================================================================



//=============================================================================================
void databaseViewer::sortByCapacity(vector<stadium>* stadiums)
{
    // sort vector in order of stadium seating capacity
    for (ulong m = 0; m < stadiums->size(); m++)
    {
        for (ulong n = 0; n < stadiums->size() - m - 1; n++)
        {
            if (stadiums->at(n).getCapacity() > stadiums->at(n+1).getCapacity())
            {
                stadium temp = stadiums->at(n);
                stadiums->at(n) = stadiums->at(n+1);
                stadiums->at(n+1) = temp;
            }
        }
    }
}
//=============================================================================================



//=============================================================================================
long databaseViewer::totalCapacity(vector<stadium>* stadiums)
{
    long count = 0;

    for (auto it = stadiums->begin(); it != stadiums->end(); it++)
    {
        count += it->getCapacity();
    }

    return count;
}
//=============================================================================================


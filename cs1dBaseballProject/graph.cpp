#include "graph.h"


const int MAX = 100000;

graph::graph(QObject *parent) : QObject(parent)
{
    vNum = control.getStadiumCount();
    matrix = new int*[vNum];

    for (int row = 0; row < vNum; row++)
    {
        matrix[row] = new int[vNum];
        for (int column = 0; column < vNum; column++)
        {
            matrix[row][column] = 0;
        }
    }
    addEdges();
}

void graph::addEdges()
{
     if(control.CheckEdge(control.getStadiumName(static_cast<stadiums>(row)), control.getStadiumName(static_cast<stadiums>(column))))
            {
                int distance = control.GetDistBtwnStadium(control.getStadiumName(static_cast<stadiums>(row)), control.getStadiumName(static_cast<stadiums>(column)));
                matrix[row][column] = distance;
                matrix[column][row] = distance;
            }
}

void graph::setShapeBuffer(ShapeBuffer & temp)
{
    Shape::setShapeBuffer(temp);
    temp.qRect = myRect;
}

void graph::draw(const int, const int)
{
  getQPainter()->setPen(getPen());
  getQPainter()->setBrush(getBrush());

  /*DRAW USING INTERNAL QRECT*/
  drawID ();
  getQPainter()->drawgraph(myRect);
  passQPainter(nullptr);
}



QVector<int> graph::sortStadium(stadiums v)
{
    QVector<int> vec;

    for(int j = 0; j < vNum; j++)
    {
        vec.push_back(j);
    }

    bool swap = true;
    while(swap)
    {
        swap = false;
        int size = vec.size();
        for(int i = 0; i < size - 1; i++)
        {
            if(matrix[v][vec[i]] > matrix[v][vec[i+1]])
            {
                int temp = vec[i];
                vec[i] = vec[i+1];
                vec[i+1] = temp;
                swap = true;
            }
        }
    }
    return vec;
}

QVector<QString> graph::DFS(stadiums start)
{
    distance = 0;
    QVector<QString> dfsPath;

    bool *visited = new bool[vNum];
    for(int i = 0; i < vNum; i++) {
        visited[i] = false;
    }

    DFSUtil(start, visited, dfsPath);
    return dfsPath;
}

double graph::perimeter() const
{
    return M_PI * ((3 *(radius1 + radius2)) - sqrt((3*radius1 + radius2)*(radius1 + (3 * radius2))));
}

double graph::area() const
{
    return M_PI * radius1 * radius2;
}

QVector<int> graph::dijkstra(stadiums start)
{
    QVector<int> dist(vNum);
    QVector<bool> sptSet(vNum);

    for(int i = 0; i < vNum; i++)
    {
        dist[i] = MAX;
        sptSet[i] = false;
    }

    dist[start] = 0;

    for(int count = 0; count < vNum - 1; count++)
    {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;
        for(int v = 0; v < vNum; v++)
        {
            if(!sptSet[v] && matrix[u][v] && dist[u] + matrix[u][v] < dist[v])
            {
                dist[v] = dist[u] + matrix[u][v];
            }
        }
    }
    return dist;
}

int graph::minDistance(QVector<int> dist, QVector<bool> sptSet)
{
    int min = MAX;
    int minIndex = -1;

    for(int v = 0; v < vNum; v++)
    {
        if(sptSet[v] == false && dist[v] <= min)
        {
            min = dist[v];
            minIndex = v;
        }
    }

    return minIndex;
}



#ifndef GRAPH_H
#define GRAPH_H

#include <QObject>

class graph : public QObject
{
    Q_OBJECT
public:


    graph(QObject *parent = nullptr);


    void addEdges();


    int getDistance();

    //MST

    QVector<QString> primMst();

    //BFS

    QVector<QString> bfsTraversal(stadium start);

    //DFS

    QVector<QString> DFS(stadium start);

    //Dijkstra's


    QVector<int> dijkstra(stadium start);


    int minDistance(QVector<int> dist, QVector<bool> sptSet);

signals:
private:
    int distance;
    Controller control;
    int vNum;
    int** matrix;

    //MST

    int minKey(QVector<int> key, QVector<bool> mstSet);


    QVector<QString> printMst(QVector<int> parent);

    //BFS

    QVector<int> sortStadium(stadium v);

    //DFS

    void DFSUtil(stadium start, bool visited[], QVector<QString> &dfsPath);
};

#endif // GRAPH_H

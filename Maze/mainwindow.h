#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>        // Include QTimer
#include "mazegen.h"     // Include MazeGen

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onGenerateClicked();
    void onPauseClicked();
    void onResetClicked();
    void updateMazeGeneration();
    void spinBoxRowsSet();
    void spinBoxColumnsSet();
    void spinBoxWallSizeSet();
    void spinBoxGenSpeedSet();

private:
    Ui::MainWindow *ui;
    MazeGen *mazeGen;
    QTimer *timer;
};

#endif // MAINWINDOW_H

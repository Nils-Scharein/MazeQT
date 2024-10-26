#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <mazegen.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , mazeGen(new MazeGen())
    , timer(new QTimer(this))
{
    ui->setupUi(this);

    connect(timer, &QTimer::timeout, this, &MainWindow::updateMazeGeneration);

    // Connect buttons to slots
    connect(ui->GeneratePushButton, &QPushButton::clicked, this, &MainWindow::onGenerateClicked);
    connect(ui->pausePushButton, &QPushButton::clicked, this, &MainWindow::onPauseClicked);
    connect(ui->ResetPushButton, &QPushButton::clicked, this, &MainWindow::onResetClicked);
}

int delay = 1;

MainWindow::~MainWindow()
{
    delete ui;
    delete mazeGen;
    delete timer;
}

void MainWindow::onGenerateClicked()
{
    qDebug() << "Generate pressed!\n";
    mazeGen->setPaused(false);
    timer->start(delay);  // Start the timer with a 100ms interval
}

void MainWindow::onPauseClicked()
{
    mazeGen->setPaused(true);
}

void MainWindow::onResetClicked()
{
    qDebug() << "Reset pressed!\n";
    timer->stop();  // Stop the timer
    ui->gridView->resetGrid();
    mazeGen->reset(*static_cast<Grid*>(ui->gridView));
}

void MainWindow::spinBoxRowsSet()
{
    qDebug() << "set Rows to: " << ui->gridRowsSpinBox->value();
    ui->gridView->setRows(ui->gridRowsSpinBox->value());
    ui->gridView->clearCellstoRedraw();
    ui->gridView->createGrid();
    mazeGen->reset((*static_cast<Grid*>(ui->gridView)));

}

void MainWindow::spinBoxColumnsSet()
{
    qDebug() << "set Columns to: " << ui->gridColumnsSpinBox->value();
    ui->gridView->setColums(ui->gridColumnsSpinBox->value());
    ui->gridView->clearCellstoRedraw();
    ui->gridView->createGrid();
    mazeGen->reset((*static_cast<Grid*>(ui->gridView)));

}

void MainWindow::spinBoxWallSizeSet()
{
    qDebug() << "set Wall size to: " << ui->gridWallSpinBox->value();
    ui->gridView->setWallSize(ui->gridWallSpinBox->value());
    ui->gridView->clearCellstoRedraw();
    ui->gridView->createGrid();
    mazeGen->reset((*static_cast<Grid*>(ui->gridView)));
}

void MainWindow::spinBoxGenSpeedSet()
{
    delay = ui->mazeSpeedSpinBox->value();
}

void MainWindow::updateMazeGeneration()
{
    // Print a debug message when updateMazeGeneration is called
    qDebug() << "updateMazeGeneration called";

    if (mazeGen->isPaused())
    {
        qDebug() << "   --> Gen is paused";
        timer->stop();  // Stop the timer if the generation is paused
    }
    else
    {
        qDebug() << "   --> Gen is not paused";
        mazeGen->update_generate_with_choosen(*static_cast<Grid*>(ui->gridView));
        ui->gridView->updateGrid();
    }
}

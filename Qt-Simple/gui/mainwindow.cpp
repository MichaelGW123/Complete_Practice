#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <set>
#include <QtWidgets>
#include <QtGui>

#include <mainwindow.h>

MainWindow::MainWindow(QWidget* parent): QDialog(parent){
    m_label = new QLabel(tr("Enter a number: "));
    m_lineEdit = new QLineEdit;
    m_label->setBuddy(m_lineEdit);

    m_button1 = new QRadioButton(tr("Camera 1"));
    m_button1->setChecked(true);
    m_button2 = new QRadioButton(tr("Camera 2"));
    m_button3 = new QRadioButton(tr("Camera 3"));
    m_multiply = new QPushButton(tr("Multiply"));

    m_closeButton = new QPushButton(tr("Close"));

    connect(m_button1, SIGNAL(clicked()), this, SLOT(setCamera1()));
    connect(m_button2, SIGNAL(clicked()), this, SLOT(setCamera2()));
    connect(m_button3, SIGNAL(clicked()), this, SLOT(setCamera3()));
    connect(m_multiply, SIGNAL(clicked()), this, SLOT(multiplyClicked()));
    connect(m_closeButton, SIGNAL(clicked()), this, SLOT(close()));
    
    m_view = new QLabel();
    m_view->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QPixmap image("/home/michael/Documents/Practice/OpenGL/Qt Simple/northridge.jpg");
    m_view->setPixmap(image);

    QHBoxLayout *topLeftLayout = new QHBoxLayout;
    topLeftLayout->addWidget(m_label);
    topLeftLayout->addWidget(m_lineEdit);

    QHBoxLayout *middleLeftLayout = new QHBoxLayout;
    middleLeftLayout->addWidget(m_button1);
    middleLeftLayout->addWidget(m_button2);
    middleLeftLayout->addWidget(m_button3);

    QVBoxLayout *middleLayout = new QVBoxLayout;
    middleLayout->addLayout(topLeftLayout);
    middleLayout->addLayout(middleLeftLayout);
    middleLayout->addWidget(m_multiply);

    QVBoxLayout *rightLayout = new QVBoxLayout;
    rightLayout->addWidget(m_closeButton);
    rightLayout->addStretch();

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addWidget(m_view);
    mainLayout->addLayout(middleLayout);
    mainLayout->addLayout(rightLayout);

    setLayout(mainLayout);
    setWindowTitle(tr("Test"));
    setFixedHeight(sizeHint().height());
}

void MainWindow::setCamera1(){
    m_currentCamera = 1;
}

void MainWindow::setCamera2(){
    m_currentCamera = 2;
}

void MainWindow::setCamera3(){
    m_currentCamera = 3;
}

void MainWindow::multiplyClicked(){
    temp = m_lineEdit->text().toInt();
    temp *= m_currentCamera;
    m_lineEdit->setText(QString::number(temp));
}
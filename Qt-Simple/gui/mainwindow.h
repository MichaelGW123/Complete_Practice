#pragma once

#include <QtWidgets>
#include <QDialog>
#include <string>
#include <list>
#include <iostream>
#include <omp.h>

class QLabel;
class QLineEdit;
class QPushButton;
class QRadioButton;

class MainWindow: public QDialog{
    Q_OBJECT

    public:
    MainWindow(QWidget *parent = 0);

    signals:

    private slots:
    void setCamera1();
    void setCamera2();
    void setCamera3();
    void multiplyClicked();


    private:
        std::chrono::high_resolution_clock::time_point start;
        std::chrono::high_resolution_clock::time_point end;
    
        enum PlaybackStatus{
            Playback_Playing,
            Playback_Paused,
            Playback_Stoped
        } m_status;

        std::list<std::string> m_recentPaths;
        size_t m_position;
        size_t m_lastPosition;
        
    // Widgets
        QLabel *m_view;
        QLabel *m_label;
        QLineEdit *m_lineEdit;
        QRadioButton *m_button1;
        QRadioButton *m_button2;
        QRadioButton *m_button3;
        int m_currentCamera = 1;
        int temp = 0;
        QPushButton *m_multiply;
        QPushButton *m_closeButton;
        QComboBox *m_cameraComboBox;
        QFrame *m_mediaButtonsFrame;
};
#include <QApplication>
#include <QFileDialog>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QMessageBox>

#include <Framework/TCPCommunication.h>
#include <Framework/UDPCommunication.h>

class Flip_V : public QWidget
{
 public:
    Flip_V(QWidget *parent = nullptr)
        : QWidget(parent)
    {
        // Create the main layout
        QHBoxLayout *mainLayout = new QHBoxLayout;
        QVBoxLayout *fileLayout = new QVBoxLayout;
        QVBoxLayout *messagesLayout = new QVBoxLayout;

        // Create the perform action button
        QPushButton *actionButton = new QPushButton("Perform Action");
        fileLayout->addWidget(actionButton);

        // Create the UDP send button
        QPushButton *udpButton = new QPushButton("Send via UDP");
        messagesLayout->addWidget(udpButton);

        // Create the TCP send button
        QPushButton *tcpButton = new QPushButton("Send via TCP");
        messagesLayout->addWidget(tcpButton);

        m_imageLabel = new QLabel;

        mainLayout->addWidget(m_imageLabel);
        mainLayout->addLayout(fileLayout);
        mainLayout->addLayout(messagesLayout);
        setLayout(mainLayout);

        // Connect the signals and slots
        // connect(actionButton, &QPushButton::clicked, this, &Flip_V::selectFilePath);
        // connect(udpButton, &QPushButton::clicked, this, &Flip_V::sendViaUDP);
        // connect(tcpButton, &QPushButton::clicked, this, &Flip_V::sendViaTCP);
    }

  private slots:
    void sendUDP()
    {
        if (m_imageData == nullptr) {
            QMessageBox::warning(this, "Warning", "No image loaded.");
            return;
        }

        UDPCommunication udp;
        udp.Send(m_imageData);
    }

    void sendTCP()
    {
        if (m_imageData == nullptr) {
            QMessageBox::warning(this, "Warning", "No image loaded.");
            return;
        }

        TCPCommunication tcp;
        tcp.Send(m_imageData);
    }

 private:
    QString m_filePath;
    QLabel *m_selectedFile;
    QLabel *m_imageLabel;
    unsigned char* m_imageData;
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Flip_V sender; // take tcp and udp sockets, set member variables up for
                        // on creation of object. 
    sender.show();

    return a.exec();
}
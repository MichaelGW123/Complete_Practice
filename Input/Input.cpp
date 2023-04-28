#include <QApplication>
#include <QFileDialog>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QMessageBox>

#include <Framework/TCPCommunication.h>
#include <Framework/UDPCommunication.h>

class ImageSender : public QWidget
{
 public:
    ImageSender(QWidget *parent = nullptr)
        : QWidget(parent)
    {
        // Create the main layout
        QHBoxLayout *mainLayout = new QHBoxLayout;
        QVBoxLayout *fileLayout = new QVBoxLayout;
        QVBoxLayout *messagesLayout = new QVBoxLayout;

        // Create the file path label and button
        QLabel *filePath = new QLabel("File Path:");
        fileLayout->addWidget(filePath);

        m_selectedFile = new QLabel("No Selected File");
        fileLayout->addWidget(m_selectedFile);

        QPushButton *browseButton = new QPushButton("Browse");
        fileLayout->addWidget(browseButton);

        // Create the load button
        QPushButton *loadButton = new QPushButton("Load Image");
        fileLayout->addWidget(loadButton);

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
        connect(browseButton, &QPushButton::clicked, this, &ImageSender::selectFilePath);
        connect(loadButton, &QPushButton::clicked, this, &ImageSender::loadImage);
        // connect(udpButton, &QPushButton::clicked, this, &ImageSender::sendViaUDP);
        // connect(tcpButton, &QPushButton::clicked, this, &ImageSender::sendViaTCP);
    }

  private slots:
    void selectFilePath()
    {
        // Open the file selection dialog and set the selected file path to the label text
        QString filePath = QFileDialog::getOpenFileName(this, "Select File");
        if (!filePath.isEmpty()) {
            m_selectedFile->setText(filePath);
            m_filePath = filePath;
        }
    }

    void loadImage()
    {
        if (m_filePath.isEmpty()) {
            QMessageBox::warning(this, "Warning", "No image file selected.");
            return;
        }

        QPixmap image(m_filePath);
        if (image.isNull()) {
            QMessageBox::warning(this, "Warning", "Failed to load image.");
            return;
        }

        m_imageLabel->setPixmap(image);
        QImage temp_image = image.toImage(); // Convert the pixmap to a QImage
        m_imageData = new unsigned char[temp_image.sizeInBytes()]; // Allocate memory for the raw image data
        memcpy(m_imageData, temp_image.bits(), temp_image.sizeInBytes()); // copy the raw image data into the buffer
    }

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

    ImageSender sender; // take tcp and udp sockets, set member variables up for
                        // on creation of object. 
    sender.show();

    return a.exec();
}

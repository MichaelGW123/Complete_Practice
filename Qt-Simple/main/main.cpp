#include <QApplication>
#include <mainwindow.h>

int main(int argc, char* argv[]){
    QApplication a(argc, argv);

    #pragma omp master
    {
        #ifdef _OPENMP
            int nthreads = omp_get_max_threads();
            std::cout << "Using OpenMP - There are " << nthreads << " threads available at max." << std::endl;
        #else  
            std::cout << "Not using OpenMP." << std::endl;
        #endif
    }

    MainWindow *window = new MainWindow();
    window->show();

    return a.exec();
}
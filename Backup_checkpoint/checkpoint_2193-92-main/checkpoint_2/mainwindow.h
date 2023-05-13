#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QScrollArea>
#include "file.h"
#include <QMainWindow>
#include <fstream>

#include "RabinKarp.h"
#include "RKphrases.h"
#include"RKsentences.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT



public:
    MainWindow(QWidget *parent = nullptr);

    std::ifstream inputFileStream; // Input file stream for uploaded file
    RabinKarp rabinKarp; // Rabin-Karp object for plagiarism detection
    Phrases phrases; // Phrases object for plagiarism detection
    Sentences sentences; // Sentences object for plagiarism detection

    ~MainWindow();


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();
void runprogram(std::string corpus,std::string main,QString color,bool read);




void on_pushButton_4_clicked();

void on_pushButton_5_clicked();

void on_pushButton_6_clicked();

private:
    Ui::MainWindow *ui;
    std::string main,corpus1,corpus2,corpus3;

private:


};
#endif // MAINWINDOW_H
#include <iostream>
#include <fstream>
#include <vector>




using namespace std;

struct logs
{
    string textx,texty;
    int word_index_x;
    int word_index_y;
    int sentence_x,sentence_y;
    int start_x;
    int start_y;

};


class brute_force:public file
{
private:

    vector<char> filex, filey;

    vector <vector<logs> > storage;
    vector<int> index_sentences_x;
    vector<int> index_sentences_y;
    QList<QPair<QString, QString>> newx;
    QList<QPair<QString, QString>> newy;
    QString color;
    int threshhold;
public:
    brute_force(string xfilename, string yfilename,int thre,QString c);
    vector<int> get_filex_sentences_index();
    vector<int> get_filey_sentences_index();
    void push_storage(vector<logs> x);
    void readFile();
    bool  ishamming(string x, string y, int threshold);

   void  trial(vector<char> tempy, vector<char> tempx,int index_x,int index_y,vector<logs> &plagiarized);
   QList<QPair<QString, QString>> getnewx();
   QList<QPair<QString, QString>> getnewy();

   int getWordIndex(vector<char> x, int index);

    string getword(string x, int z);
    string getphrase(string x, int z);

    vector<char> getsentence_filex(int z);
    vector<char>  getsentence_filey(int z);
    int number_of_phrases_filex();
    int  number_of_phrases_filey();

    vector<char> getfilex();
    vector<char> getfiley();
   vector <vector<logs> > getstorage();
vector<char> getfilex_vector();
vector<char> getfiley_vector();
bool filex_authentication();
bool filey_authentication();
};

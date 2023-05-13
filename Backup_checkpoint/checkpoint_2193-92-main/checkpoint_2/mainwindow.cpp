#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QString>
#include <QFileDialog>
#include <QString>
#include <QDir>
#include <sstream>
#include <QScrollArea>
#include "Mainia.h"
#include "qforeach.h"
#include<iostream>
#include<unordered_set>
#include <utility>
#include <QString>
#include "qtextedit.h"
#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QRegularExpression>
#include "about.h"
#include <QLabel>
#include <QList>
#include <QPair>
#include <QDebug>
#include <QTextEdit>
#include <QScrollArea>
#include <QTextDocument>
#include <QTextCharFormat>
#include <QTextCursor>
#include <QApplication>
#include <QMainWindow>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QRegularExpression>
#include <QTextEdit>
#include <QSyntaxHighlighter>
#include <QRegularExpression>
#include <QTextCursor>
#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QFile>
#include <QString>
#include <QRegularExpression>
#include <QRegularExpressionMatchIterator>
#include <QRegularExpressionMatch>
#include <QTextCharFormat>
#include <QTextCursor>
#include <QFont>
#include <QApplication>
#include <QLabel>
#include <QSyntaxHighlighter>
#include <QRegularExpression>
About*A;
using namespace std;
class MyHighlighter : public QSyntaxHighlighter {
public:
    MyHighlighter(QTextDocument* parent = nullptr) : QSyntaxHighlighter(parent) {
        QTextCharFormat format;
        format.setForeground(QColor(255, 0, 0)); // set text color to red
        QRegularExpression pattern("\\bQt\\b"); // match "Qt" as a whole word
        highlightingRules.append(QPair<QRegularExpression, QTextCharFormat>(pattern, format));
    }

protected:
    void highlightBlock(const QString& text) {
        for (const auto& rule : highlightingRules) {
            QRegularExpressionMatchIterator matchIterator = rule.first.globalMatch(text);
            while (matchIterator.hasNext()) {
                QRegularExpressionMatch match = matchIterator.next();
                setFormat(match.capturedStart(), match.capturedLength(), rule.second);
            }
        }
    }

private:
    QVector<QPair<QRegularExpression, QTextCharFormat>> highlightingRules;
};





MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
        QPixmap bkgnd("C:/Users/Hp/Documents/plagiarism checker interface/graph.png");
        bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Window, bkgnd);
        this->setPalette(palette);
    //ui->setupUi(this);
}
double highlightedWordPercentage(QTextEdit* textEdit, QColor color) {
    QTextCharFormat initialFormat = textEdit->textCursor().charFormat();
    QTextCharFormat highlightFormat;
    highlightFormat.setBackground(color);

    QTextDocument* doc = textEdit->document();
    QTextOption option = doc->defaultTextOption();
    option.setAlignment(Qt::AlignLeft | Qt::AlignTop);
    doc->setDefaultTextOption(option);

    QTextCursor highlightCursor(doc);
    highlightCursor.movePosition(QTextCursor::Start);

    int highlightCount = 0;
    int totalCount = 0;
    while (!highlightCursor.atEnd()) {
        highlightCursor = doc->find(highlightCursor.selectedText(), highlightCursor, QTextDocument::FindWholeWords);

        if (!highlightCursor.isNull()) {
            ++totalCount;

            QTextCharFormat format = highlightCursor.charFormat();
            if (format.background() == color) {
                ++highlightCount;
            }
        } else {
            break;
        }
    }

    double percentage = 0.0;
    if (totalCount > 0) {
        percentage = (double)highlightCount / (double)totalCount * 100.0;
    }
    return percentage;
}
MainWindow::~MainWindow()
{
    delete ui;
}
QString file;

















#include <sstream>

#include <sstream>


void output()
{
    std::cout << "cherif" << std::endl;
}
void displayFirsts(const QList<QPair<QString, QString>>& list) {
    for (const auto& pair : list) {
        cout<<pair.first.toStdString();
        cout << "\n";
    }
}
float getHighlightedWordsPercentage(QTextEdit* textEdit, QColor highlightColor)
{
    int highlightedWordsCount = 0;
    int totalWordsCount = 0;
    QString text = textEdit->toPlainText();

    // Split the text into words and count the highlighted ones
    foreach(QString word, text.split(" ")) {
        bool isHighlighted = false;
        QTextCharFormat format = textEdit->currentCharFormat();
        QTextCharFormat defaultFormat;
        if(format != defaultFormat && format.background().color() == highlightColor) {
            isHighlighted = true;
        }
        if(isHighlighted) {
            highlightedWordsCount++;
        }
        totalWordsCount++;
    }

    // Calculate the percentage of highlighted words
    float highlightedWordsPercentage = ((float)highlightedWordsCount / (float)totalWordsCount) * 100.0;
    return highlightedWordsPercentage;
}
void highlight(const QList<QPair<QString, QString>>& highlightList, QTextEdit *textEdit)
{
    QString labelText = textEdit->toPlainText();


    for (const auto& highlightPair : highlightList)
    {
        const QString& highlightString = highlightPair.first;
        const QString& highlightColor = highlightPair.second;


        QRegularExpression re(highlightString, QRegularExpression::CaseInsensitiveOption);


        QTextCursor cursor(textEdit->document());
        while (!cursor.isNull() && !cursor.atEnd())
        {
            cursor = textEdit->document()->find(re, cursor);
            if (!cursor.isNull()) {
                QTextCharFormat format;
                format.setBackground(QBrush(QColor(highlightColor)));
                cursor.mergeCharFormat(format);
            }
        }
    }
}




void MainWindow::runprogram(string corpus,string main,QString color,bool read)
{
    brute_force a(main,corpus,2,color);
    if(ui->lineEdit->text().toInt()>0 && ui->lineEdit->text().toInt()<4)
    {
    a=brute_force(main,corpus,ui->lineEdit->text().toInt(),color);
    }




  cout<<"sentence check: "<<endl;
    for (int j = 1; j <= a.number_of_phrases_filex(); j++)          // every phrase in filex vector
    {
        vector<logs> plagiarized;
        cout<<"sentence : "<<j <<" of file x check "<<endl;
        for (int i = 1; i <= a.number_of_phrases_filey(); i++)
        {
           cout<<"checking with sentence: "<<i<<" of file y"<<endl;
            vector<char> temp = a.getsentence_filey(i);
            a.trial(temp, a.getsentence_filex(j),i,j,plagiarized);
            a.push_storage(plagiarized);
        }
    }


if(!a.filex_authentication())
{

    ui->textEdit_2->setText("error while opening the file");
}
//ui->textEdit->setText(ui->textEdit->toPlainText()+ "\n"+"\n"+"\n");
if(read)
{
    QString transfer;
    for(int h=0;h<a.getfilex_vector().size();h++)
    {
        transfer += a.getfilex_vector()[h];
    }
    ui->textEdit_2->setText(transfer);



}
highlight(a.getnewx(),ui->textEdit_2);

cout<<"X PLAGIARIZED SENDTENCE FINAL"<<endl;
displayFirsts(a.getnewx());
cout<<endl;
cout<<"y PLAGIARIZED SENDTENCE FINAL"<<endl;
displayFirsts(a.getnewy());
cout<<"LOG: ///////////////////////"<<endl;

}
void MainWindow::on_pushButton_clicked()
{
    file = QFileDialog::getOpenFileName(this, tr("Open File"), QDir::homePath(), tr("Text Files (*.txt);;All Files (*.*)"));
            this->corpus1 = file.toStdString();
}


void MainWindow::on_pushButton_2_clicked()
{
    file = QFileDialog::getOpenFileName(this, tr("Open File"), QDir::homePath(), tr("Text Files (*.txt);;All Files (*.*)"));
    this->corpus2 = file.toStdString();
}


void MainWindow::on_pushButton_4_clicked()
{
    file = QFileDialog::getOpenFileName(this, tr("Open File"), QDir::homePath(), tr("Text Files (*.txt);;All Files (*.*)"));
    this->main = file.toStdString();
}


QString getFilePath(QString str) {
    QString filePath = QFileDialog::getOpenFileName(nullptr, str, QDir::homePath());
    return filePath;
}

void MainWindow::on_pushButton_3_clicked()
{
    file = QFileDialog::getOpenFileName(this, tr("Open File"), QDir::homePath(), tr("Text Files (*.txt);;All Files (*.*)"));
    this->corpus3 = file.toStdString();
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

float jaccardSimilarity(const unordered_set<string>& set1, const unordered_set<string>& set2) {
    unordered_set<string> intersection;
    unordered_set<string> unionSet;

    // Calculate intersection
    for (const auto& ngram : set1) {
        if (set2.count(ngram) > 0) {
            intersection.insert(ngram);
        }
    }

    // Calculate union
    unionSet = set1;
    for (const auto& ngram : set2) {
        unionSet.insert(ngram);
    }

    float jaccard = static_cast<float>(intersection.size()) / unionSet.size();

    return jaccard;
}

//Get N-Grams for Jaccard
vector<string> generateNGrams(const string& str, int n) {
    vector<string> ngrams;
    for (int i = 0; i <= str.length() - n; i++) {
        ngrams.push_back(str.substr(i, n));
    }
    return ngrams;
}

//Calculates the percentage of similarity in the corpus vs the main using Jaccard Similarity
void similarityPercent(string main, string c1, string c2, string c3) {

    vector<string> suspiciousNGrams = generateNGrams(main, 5);
    std::unordered_set<std::string> suspiciousSet(suspiciousNGrams.begin(), suspiciousNGrams.end());

    vector<string> referenceNGrams = generateNGrams(c1, 5);
    std::unordered_set<std::string> referenceSet(referenceNGrams.begin(), referenceNGrams.end());
    //a lot of plagarism trace it
    float similarity = jaccardSimilarity(suspiciousSet, referenceSet);   
      cout << "Similarity of: " << similarity * 100 << "% suggests plagarism";



}

list<pair<string, string>> printPoly(unordered_map<string, string> foundPolySentences, unordered_map<string, string> foundPoly4Phrases, unordered_map<string, string> foundPoly3Phrases, unordered_map<string, string> foundPoly2Phrases, int &i) {

    list<pair<string, string>> foundList;
    string color{};

    for (auto it = foundPoly4Phrases.begin(); it != foundPoly4Phrases.end(); it++) {
        color = (i == 1) ? "yellow" : ((i == 2) ? "red" : "green");
        foundList.push_back({ color , it->second });
        i = (i % 3) + 1; // Increment i and wrap around to 1 after 3
    }

    for (auto it = foundPoly3Phrases.begin(); it != foundPoly3Phrases.end(); it++) {
        color = (i == 1) ? "yellow" : ((i == 2) ? "red" : "green");
        foundList.push_back({ color , it->second });
        i = (i % 3) + 1;
    }

    for (auto it = foundPoly2Phrases.begin(); it != foundPoly2Phrases.end(); it++) {
        color = (i == 1) ? "yellow" : ((i == 2) ? "red" : "green");
        foundList.push_back({ color , it->second });
        i = (i % 3) + 1;
    }

    for (auto it = foundPolySentences.begin(); it != foundPolySentences.end(); it++) {
        color = (i == 1) ? "yellow" : ((i == 2) ? "red" : "green");
        foundList.push_back({ color , it->second });
        i = (i % 3) + 1;
    }

    return foundList;
}


QList<QPair<QString, QString>> convertList(const std::list<std::pair<std::string, std::string>>& inputList) {
    QList<QPair<QString, QString>> outputList;
    for (const auto& pair : inputList) {
        QPair<QString, QString> qPair(QString::fromStdString(pair.first), QString::fromStdString(pair.second));
        outputList.append(qPair);
    }
    return outputList;
}

/*string displayText(const QList<QPair<QString, QString>>& results, QTextEdit* textEdit, const MainWindow &w)
{

}*/




/*vector<wstring> RabinKarp::stem(string str, int i, vector<wstring> w) {
    if (i >= str.size()) {
        return w;
    }
    string strShort{};
    strShort = calcBound(str, i, 1);
    strShort = oneremoveSpaces(strShort, 1);
    stemming::english_stem<> StemEnglish;
    wstring_convert<codecvt_utf8_utf16<wchar_t>> converter; // create a converter object

    wstring wide_str = converter.from_bytes(strShort); // convert narrow string to wide string
    StemEnglish(wide_str);

    w.push_back(wide_str);

    return stem(str, i, w);
}

wstring RabinKarp::stem(string str) {
    string strShort{};
    strShort = oneCalcBound(str, 1);
    strShort = oneremoveSpaces(str, 1);
    stemming::english_stem<> StemEnglish;
    wstring_convert<codecvt_utf8_utf16<wchar_t>> converter; // create a converter object

    wstring wide_str = converter.from_bytes(strShort); // convert narrow string to wide string
    StemEnglish(wide_str);

  //  stem(str, i);

    return wide_str;
}*/



void highlightText(QList<QPair<QString, QString>> Qfound, QTextEdit *textEdit) {
    QTextCursor cursor = textEdit->textCursor();
    QTextCharFormat highlightFormat;
    QString foundText;

    for (const auto &pair : Qfound) {
        highlightFormat.setBackground(QColor(pair.first));
        foundText = pair.second;
        int pos = textEdit->toPlainText().indexOf(foundText);
        while (pos != -1) {
            cursor.setPosition(pos);
            cursor.movePosition(QTextCursor::NextCharacter, QTextCursor::KeepAnchor, foundText.length());
            cursor.setCharFormat(highlightFormat);
            pos = textEdit->toPlainText().indexOf(foundText, pos + 1);
        }
    }

}


/*int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Create a QWidget to hold the textEdit
    QWidget window;

    // Create a QVBoxLayout to hold the textEdit
    QVBoxLayout *layout = new QVBoxLayout(&window);

    // Create a QTextEdit to hold the text
    QTextEdit *textEdit = new QTextEdit();
    textEdit->setPlainText("This is some example text to highlight.");
    textEdit->setReadOnly(true);

    // Add the textEdit to the layout
    layout->addWidget(textEdit);

    // Define the substrings to highlight and their colors in a list
    QList<QPair<QString, QString>> highlightList;
    highlightList.append(QPair<QString, QString>("example text", "yellow"));
    highlightList.append(QPair<QString, QString>("text to", "yellow"));
    highlightList.append(QPair<QString, QString>("text to highlight", "yellow"));

    // Highlight the substrings in the text
    highlight(highlightList, textEdit);

    window.show();
    return app.exec();
}
*/


QString convertToQString(const std::string& str) {
    return QString::fromStdString(str);
}

#include <QFileInfo>

#include <QFileInfo>
#include <QString>

QString getFilePath(const std::string& fileName) {
    QFileInfo fileInfo(QString::fromStdString(fileName));
    if(fileInfo.exists() && fileInfo.isFile()) {
        return fileInfo.absoluteFilePath();
    }
    else {
        throw std::runtime_error("File not found: " + fileName);
    }
}



//////////////////////////////////////////////////
//////////////////////////////////////////////////
/////////////////////////////////////////////////

void MainWindow::on_pushButton_5_clicked()
{
    bool temp=true;
    QString color="yellow";
    runprogram(corpus1,main,color ,temp);

   color="red";
   temp=false;
    runprogram(corpus2,main,color,temp);
    color="green";
    runprogram(corpus3,main,color,temp);

    /////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////
    //ui->textEdit->setText("AHmed");
        //objects
        Phrases p;
        Sentences s;
        RabinKarp rk;
        MainWindow w;


    // create a new QTextEdit widget

        QList<QPair<QString, QString>> Qfound;


        //maps
        //maps
        //POLY
        unordered_map<string, string> foundPoly4PhrasesC1 = {};
        unordered_map<string, string> foundPoly3PhrasesC1 = {};
        unordered_map<string, string> foundPoly2PhrasesC1 = {};

        unordered_map<string, string> foundPoly4PhrasesC2 = {};
        unordered_map<string, string> foundPoly3PhrasesC2 = {};
        unordered_map<string, string> foundPoly2PhrasesC2 = {};

        unordered_map<string, string> foundPoly4PhrasesC3 = {};
        unordered_map<string, string> foundPoly3PhrasesC3 = {};
        unordered_map<string, string> foundPoly2PhrasesC3 = {};



        unordered_map<string, string> foundPolySentencesC1 = {};
        unordered_map<string, string> foundPolySentencesC2 = {};
        unordered_map<string, string> foundPolySentencesC3 = {};

        //FINGERPRINT
        unordered_map<string, string> foundFinger4Phrases = {};
        unordered_map<string, string> foundFinger3Phrases = {};
        unordered_map<string, string> foundFinger2Phrases = {};
        unordered_map<string, string> foundFingerSentences = {};

        list<pair<string, string>> foundListPoly;
        list<pair<string, string>> foundListPolyTemp;

        list<pair<string, string>> foundList;



        QString name2= getFilePath(corpus1);
                //"C:/Users/Hp/Documents/checkpoint_2/corpus1.txt";

        QString name1= getFilePath(main);
                //"C:/Users/Hp/Documents/checkpoint_2/main.txt";

        QString name3= getFilePath(corpus2);
                //"C:/Users/Hp/Documents/checkpoint_2/corpus2.txt";

        QString name4= getFilePath(corpus3);
                //"C:/Users/Hp/Documents/checkpoint_2/corpus3.txt";
        //files
        string c1 = rk.readFile(name2);

        string c2 = rk.readFile(name3);

        string c3 = rk.readFile(name4);

        string main = rk.readFile(name1);

       // vector<wstring> w;


      //  w = rk.stem(main, 0, w);
    //I have sent the main now I need to make w work with everyhitng else


        //found = rabinKarp(main, c1, c2, c3);
        foundPoly4PhrasesC1 = p.rabinKarpPolyPhrases(main, c1, 4);
        foundPoly3PhrasesC1 = p.rabinKarpPolyPhrases(main, c1, 3);
        foundPoly2PhrasesC1 = p.rabinKarpPolyPhrases(main, c1, 2);

        foundPoly4PhrasesC2 = p.rabinKarpPolyPhrases(main, c2, 4);
        foundPoly3PhrasesC2 = p.rabinKarpPolyPhrases(main, c2, 3);
        foundPoly2PhrasesC2 = p.rabinKarpPolyPhrases(main, c2, 2);

        foundPoly4PhrasesC3 = p.rabinKarpPolyPhrases(main, c3, 4);
        foundPoly3PhrasesC3 = p.rabinKarpPolyPhrases(main, c3, 3);
        foundPoly2PhrasesC3 = p.rabinKarpPolyPhrases(main, c3, 2);
        //still need to fix in sentences
        foundPolySentencesC1 = s.rabinKarpPolySentences(main, c1);
        foundPolySentencesC2 = s.rabinKarpPolySentences(main, c2);
        foundPolySentencesC3 = s.rabinKarpPolySentences(main, c3);


        //firgure out how to send doucment
        //C1
        int document = 1;

        foundListPoly = printPoly(foundPolySentencesC1, foundPoly4PhrasesC1, foundPoly3PhrasesC1, foundPoly2PhrasesC1, document);

        //C2
        foundListPolyTemp = printPoly(foundPolySentencesC2, foundPoly4PhrasesC2, foundPoly3PhrasesC2, foundPoly2PhrasesC2, document);

        foundListPoly.insert(foundListPoly.end(), foundListPolyTemp.begin(), foundListPolyTemp.end());

        //C3
        foundListPolyTemp = printPoly(foundPolySentencesC3, foundPoly4PhrasesC3, foundPoly3PhrasesC3, foundPoly2PhrasesC3, document);


        foundListPoly.insert(foundListPoly.end(), foundListPolyTemp.begin(), foundListPolyTemp.end());


        Qfound = convertList(foundListPoly);

        //look at setTextColor
        QString myQString = convertToQString(main);

        ui->textEdit->setText(myQString);

    //WORKING BABY
      /* for (auto& Qfound : Qfound)
        {
            QString line = Qfound.second + "\n";
            ui->textEdit->append(line);
        }*/
    ////////////////////////////////////////////////
    //highlight is carshing the program
        highlightText(Qfound, ui->textEdit);


    //couts the raw found to the text edit
      /*  for (const auto& p : Qfound) {
            QString x =  "(" + p.first + ", " + p.second + ")" + '\n';
            ui->textEdit->append(x);

        }*/


        //fingerprint
        //figure out how to writw this normally
        /* for (auto it = found.begin(); it != found.end(); it++) {
             cout << it->first << '\t' << it->second << endl;

         }*/




          similarityPercent(main, c1, c2, c3);

          //Now I have:
          //Jaccard sim working but i need to understand it
          //RK is working with the things need to find a nice way to priont
          // loop i think is solved
          //multiple docs either need to be the same size or I would need to use seperate fucntion or smth else idk yet    ui->textEdit->setText("Ahmed");
          //QColor yellow(Qt::yellow);
          //QColor red(Qt::red);
          //QColor green(Qt::green);
          /*
          ui->label_6->setText(QString::number(getHighlightedWordsPercentage(ui->textEdit_2,yellow) )+"%"+" of corpus 1");
          ui->label_5->setText(QString::number(getHighlightedWordsPercentage(ui->textEdit_2,red))+"%"+" of corpus 2");
          ui->label_4->setText(QString::number(getHighlightedWordsPercentage(ui->textEdit_2,green))+"%"+" of corpus 3");
          */

}


void MainWindow::on_pushButton_6_clicked()
{
    A=new About;
    A->show();
}


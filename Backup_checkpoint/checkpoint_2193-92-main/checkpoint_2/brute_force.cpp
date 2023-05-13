using namespace std;

#include <iostream>
#include <vector>
#include <string>
#include"mainwindow.h"




   brute_force::brute_force (string xfilename, string yfilename,int thre,QString c)
    {
        setFile_x(xfilename);
        setFile_y(yfilename);
        threshhold=thre;
        readFile();
        color=c;


    }
    vector<int>brute_force:: get_filex_sentences_index()
        {
            for (int i = 0; i < filex.size(); i++)
            {
                if ((filex.at(i) == '.' || filex.at(i) == '?' || filex.at(i) == ',' || filex.at(i) == ';' || filex.at(i) == '!' || filex.at(i) == ':' || i==0 )&& i!=filex.size()-1)
                {
                    if(i==0)
                    {
                        index_sentences_x.push_back(i);
                    }
                    else
                    {
                    index_sentences_x.push_back(i+1);
                    }
                }
            }
            return index_sentences_x;
        }
    vector<int> brute_force::get_filey_sentences_index()
        {
            for (int i = 0; i < filey.size(); i++)
            {
                if ((filey.at(i) == '.' || filey.at(i) == '?' || filey.at(i) == ',' || filey.at(i) == ';' || filey.at(i) == '!' || filey.at(i) == ':' || i==0 )&& i!=filey.size()-1)
                {
                    if(i==0)
                    {
                        index_sentences_y.push_back(i);
                    }
                    else
                    {
                    index_sentences_y.push_back(i+1);
                    }
                }
            }
            return index_sentences_y;
        }
    void brute_force::push_storage(vector<logs> x)
       {
           storage.push_back(x);
       }
    void brute_force::readFile()
    {
       cout<<"first file content: \n";
        char tempc;
        int countspace = 0;

        while (getFile_x().get(tempc))
        {

            if (tempc == '\n')
            {
                tempc = ' ';
            }
            {
                if (tempc == ' ')
                {
                    countspace++;
                }
                else
                {
                    countspace = 0;
                }
            }
            if (countspace < 2 )
            {
                filex.push_back(tempc);
                cout << tempc;
            }

        }
        for(int i=0;i<filex.size();i++)
        {
            if(filex[i]=='.')
            {
                int j=i+1;
                while(filex[j]==' ' && j < filex.size())
                {
                    filex.erase(filex.begin() + j);
                    i--;
                    j++;
                }
                int m=i-1;
                while(filex[m]==' ')
                {
                    filex.erase(filex.begin() + m);
                    i--;
                    m--;
                }
            }
        }
        countspace = 0;
        cout << endl;
        cout << endl << endl << endl;
        cout << "file 2 content: " << endl;
        while (getFile_y().get(tempc))
        {
            if (tempc == '\n')
            {
                tempc = ' ';
            }
            {
                if (tempc == ' ')
                {
                    countspace++;
                }
                else
                {
                    countspace = 0;
                }
            }
            if (countspace < 2)
            {
                filey.push_back(tempc);
                cout << tempc;
            }

        }
        for(int i=0;i<filey.size();i++)
        {
            if(filey[i]=='.')
            {
                int j=i+1;
                while(filey[j]==' ' && j < filey.size())
                {
                    filey.erase(filey.begin() + j);
                    i--;
                    j++;
                }
                int m=i-1;
                while(filey[m]==' ')
                {
                    filey.erase(filey.begin() + m);
                    i--;
                    m--;
                }
            }
        }
    }
    bool  brute_force::ishamming(string x, string y, int threshold)
    {
        int mismatches = 0;

        if (x.length() == y.length())
        {
            for (int i = 0; i < y.size(); i++)
            {
                if (tolower(x.at(i)) != tolower(y.at(i)) && x.at(i) != ' ')
                {
                    mismatches++;
                }
            }
            return mismatches < threshold;
        }
        return false;
cout<<endl;
cout<<"comparing: "<<x<<"    with:  "<<y<<"  "<<endl;
    }

   void brute_force:: trial(vector<char> tempy, vector<char> tempx,int index_x,int index_y,vector<logs> &plagiarized)
    {

        string text = "", pattern = "", temps = "";
        if (tempx.size() > tempy.size())
        {
            for (int i = 0; i < tempy.size(); i++)
            {
                pattern += tempy[i];
            }
            for (int i = 0; i < tempx.size(); i++)
            {
                text += tempx[i];
            }
        }
        else if (tempx.size() <= tempy.size())
        {
            for (int i = 0; i < tempy.size(); i++)
            {
                text += tempy[i];
            }
            for (int i = 0; i < tempx.size(); i++)
            {
                pattern += tempx[i];
            }
        }
        int count_phrases = 0, wordsp = 0, wordst = 0;
        for (int i = 0; i < pattern.length(); i++)
        {
            if (pattern.at(i) == ' ')
            {
                wordsp++;
            }
        }
        wordsp++;
        for (int i = 0; i < text.length(); i++)
        {
            if (text.at(i) == ' ')
            {
                wordst++;
            }
        }
        wordst++;
        logs m;
        for (int i = 1; i <= wordsp - 2; i++)
        {
            for (int z = 1; z <= wordst - 2; z++)
            {


                if (ishamming(getphrase(pattern, i), getphrase(text, z), threshhold))
                {
                    if (tempx.size() > tempy.size())
                    {
                        m.texty = getphrase(pattern, i);
                        m.textx = getphrase(text, z);
                        m.word_index_x = z;
                        m.word_index_y =i ;
                        m.sentence_x=index_x;
                        m.sentence_y=index_y;
                        m.start_x=getWordIndex(tempx,m.word_index_x);
                        m.start_y=getWordIndex(tempy,m.word_index_y);
                        plagiarized.push_back(m);
                        newx.append(QPair<QString, QString>(QString::fromStdString(m.textx), color));
                        newy.append(QPair<QString, QString>(QString::fromStdString(m.texty), color  ));
                        cout<<"plagiarism found and pushed index :"<<m.start_x<<" as the starting index of plagiarised phrase of x"<<endl;
                    }

                    else if(tempx.size()<=tempy.size())
                    {

                        m.texty = getphrase(text, z);
                         m.textx = getphrase(pattern, i);
                            m.word_index_x = i;
                            m.word_index_y = z;
                            m.sentence_x=index_x;
                            m.sentence_y=index_y;
                            m.start_x=getWordIndex(tempx,m.word_index_x);
                            m.start_y=getWordIndex(tempy,m.word_index_y);
                            newx.append(QPair<QString, QString>(QString::fromStdString(m.textx), color));
                            newy.append(QPair<QString, QString>(QString::fromStdString(m.texty), color));
                           plagiarized.push_back(m);
                           cout<<"plagiarism found and pushed index :"<<m.start_x<<" as the starting index of plagiarised phrase of x"<<endl;
                    }
                }
            }
        }


    }
   QList<QPair<QString, QString>>brute_force:: getnewx()
   {
       return newx;
   }
   QList<QPair<QString, QString>>brute_force:: getnewy()
   {
       return newy;
   }

   int brute_force::getWordIndex(vector<char> x, int index) {
       int spaces=0;
       int temp=-1;
       if(index==1)
       {
           return 0;
       }
       for(int i=0;i<x.size();i++)
       {

           if(x.at(i)==' ')
           {
               spaces++;
               if(spaces==index-1)
               {
                   return temp=i+1;
               }
           }
       }

   }

    string brute_force::getword(string x, int z)
    {
        vector<int> index;
        int temp = 0;
        index.push_back(0);

        for (int i = 0; i < x.length(); i++)
        {
            if (x.at(i) == ' ')
            {
                temp++;
                index.push_back(i + 1);
            }
        }
        temp++;

        for (int i = 1; i <= temp; i++)
        {
            if (z == i)
            {
                int c = 1;
                int h = index[i - 1];
                while (h < x.length() && x.at(h) != ' ')
                {
                    h++;
                    c++;
                }
                return x.substr(index[i - 1], c-1);
            }
        }

        return "";
    }

    string brute_force::getphrase(string x, int z)
    {
        int temp = 0;
        string h;
        for (int i = 0; i < x.length(); i++)
        {
            if (x.at(i) == ' ')
            {
                temp++;
            }
        }
        temp++;
        for (int i = 1; i <= temp - 2; i++)
        {
            if (i == z)
            {
                h = getword(x, i) + ' ' + getword(x, i + 1) + ' ' + getword(x, i + 2);
                return h;
            }
        }
    }

    vector<char> brute_force::getsentence_filex(int z)
    {
        vector<char> tempv;
        int sentencecount = 0, end = -1, l = 0;
        for (int i = 0; i < filex.size(); i++)
        {
            if (filex.at(i) == '.' || filex.at(i) == '?' || filex.at(i) == ',' || filex.at(i) == ';' || filex.at(i) == '!' || filex.at(i) == ':')
            {
                sentencecount++;
                if (sentencecount == z)
                {
                    end = i - 1;
                }
            }

        }

        if (end != -1)
        {
            int j = end;
            while (j >= 0 && filex.at(j) != '.' && filex.at(j) != '?' && filex.at(j) != ',' && filex.at(j) != ';' && filex.at(j) != '!' && filex.at(j) != ':')
            {
                j--;
            }
            j++;
            while (filex.at(j) == ' ')
            {
                j++;
            }
            while (filex.at(end) == ' ')
            {
                end--;
            }
            for (int i = j; i <= end; i++)
            {
                tempv.push_back(filex[i]);
            }
            return tempv;
        }


    }
    vector<char>  brute_force::getsentence_filey(int z)
    {
        vector<char> tempv;
        int sentencecount = 0, end = -1, l = 0;
        for (int i = 0; i < filey.size(); i++)
        {
            if (filey.at(i) == '.' || filey.at(i) == '?' || filey.at(i) == ',' || filey.at(i) == ';' || filey.at(i) == '!' || filey.at(i) == ':')
            {
                sentencecount++;
                if (sentencecount == z)
                {
                    end = i - 1;
                }
            }

        }

        if (end != -1)
        {
            int j = end;
            while (j >= 0 && filey.at(j) != '.' && filey.at(j) != '?' && filey.at(j) != ',' && filey.at(j) != ';' && filey.at(j) != '!' && filey.at(j) != ':')
            {
                j--;
            }
            j++;
            while (filey.at(j) == ' ')
            {
                j++;
            }
            while (filey.at(end) == ' ')
            {
                end--;
            }
            for (int i = j; i <= end; i++)
            {
                tempv.push_back(filey[i]);
            }
            return tempv;
        }


    }
    int brute_force::number_of_phrases_filex()
    {
        int count = 0;
        for (int i = 0; i < filex.size(); i++)
        {
            if (filex.at(i) == '.' || filex.at(i) == '?' || filex.at(i) == ',' || filex.at(i) == ';' || filex.at(i) == '!' || filex.at(i) == ':')
                count++;
        }
        return count;
    }
    int brute_force:: number_of_phrases_filey()
    {
        int count = 0;
        for (int i = 0; i < filey.size(); i++)
        {
            if (filey.at(i) == '.' || filey.at(i) == '?' || filey.at(i) == ',' || filey.at(i) == ';' || filey.at(i) == '!' || filey.at(i) == ':')
                count++;
        }
        return count;
    }

    vector<char>brute_force:: getfilex()
    {
        return filex;
    }
    vector<char> brute_force:: getfiley()
    {
        return filey;
    }
   vector <vector<logs> >brute_force:: getstorage()
   {
       return storage;
   }
vector<char> brute_force::getfilex_vector()
{
    return filex;
}
vector<char> brute_force::getfiley_vector()
{
    return filey;
}
bool brute_force::filex_authentication()
{
    return isfilexopen();
}
bool brute_force::filey_authentication()
{
    return isfileyopen();
}

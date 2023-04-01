#ifndef DVD_H
#define DVD_H

#include "item.h"
#include <string>
//using namespace std;



class dvd: public item {

  private:
    string Title;
    string Category;
    int Runtime;
    string Studio;
    string ReleaseDate;

  public:

     void setTitle(string title);
    string getTitle();

    void setCategory(string category);
    string getCategory();

    void setRuntime(int runtime);
    int getRuntime();

    void setStudio(string studio);
    string getStudio();

    void setReleasedate(string date);
    string getReleasedate();


dvd();
dvd(int id , float cost , itemstatus status, int time, string title, string category , int runtime, string studio, string date);

void print();


};

#endif
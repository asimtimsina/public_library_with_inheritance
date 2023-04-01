#ifndef AUDIO_H
#define AUDIO_H

#include "item.h"
#include <string>
using namespace std;



class audio: public item {
//defining all of the data in private
  private: 
    string Artist;
    string Title;
    int NoofTracks;
    string ReleaseDate;
    string Genre;

  public:

    void setArtist(string artist);
    string getArtist();

    void setTitle(string title);
    string getTitle();

    void setNooftracks(int no);
    int getNooftracks();

    void setReleasedate(string date);
    string getReleasedate();

    void setGenre(string genre);
    string getGenre();

    void print();


audio();
audio(int id , float cost , itemstatus status, int time, string artist, string title, int no , string date, string genre);



};


#endif
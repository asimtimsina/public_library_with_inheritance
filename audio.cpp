#include <iostream>
#include <string>
#include "audio.h"
#include "item.h"
using namespace std;



void audio::setArtist(string artist){Artist = artist ;}
    string audio::getArtist(){return Artist ;}

    void audio::setTitle(string title){Title = title ;}
    string audio::getTitle(){return Title;}

    void audio::setNooftracks(int no){NoofTracks = no ;}
    int audio::getNooftracks(){return NoofTracks ;}

    void audio::setReleasedate(string date) {ReleaseDate = date;}
    string audio::getReleasedate(){return ReleaseDate;}

    void audio::setGenre(string genre){Genre = genre;}
    string audio::getGenre(){return Genre ;}

  
      void audio::print(){
      item::print();
      cout <<"Artist: " << Artist << endl;
      cout <<"Title: " << Title << endl;
      cout <<"No of Tracks: "  << NoofTracks << endl;
      cout <<"Genre: " << Genre << endl;
      cout << endl;
    }



audio::audio() :item(){
  Artist = "None";
  Title = "None";
  NoofTracks =0;
  ReleaseDate = "None";
  Genre = "None"; 
}


audio::audio(int id , float cost , itemstatus status, int time, string artist, string title, int no , string date, string genre):item( id ,  cost ,  status,  time){
Artist = artist;
  Title = title;
  NoofTracks =no;
  ReleaseDate = date;
  Genre = genre;
}
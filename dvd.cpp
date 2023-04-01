#include <iostream>
#include <string>
#include "dvd.h"
#include "item.h"
using namespace std;

// defination of accessors and mutators

  void dvd:: setTitle(string title){Title = title;}
    string dvd:: getTitle(){return Title;}

    void dvd:: setCategory(string category){Category = category ;}
    string dvd:: getCategory(){return Category;}

    void dvd:: setRuntime(int runtime){Runtime = runtime ;}
    int dvd:: getRuntime(){return Runtime ;}

    void dvd:: setStudio(string studio){Studio = studio;}
    string dvd:: getStudio(){return Studio;}

    void dvd:: setReleasedate(string date){ReleaseDate =date;}
    string dvd:: getReleasedate(){return ReleaseDate ;}


    dvd::dvd():item(){
      Title = "none";
      Category = "none";
      Runtime = 0;
      Studio = "None";
      ReleaseDate ="None";

    }
dvd::dvd(int id , float cost , itemstatus status, int time, string title, string category , int runtime, string studio, string date): item( id ,  cost ,  status,  time){
      Title = title;
      Category = category;
      Runtime = time;
      Studio = studio;
      ReleaseDate =date ;
}


void dvd::print(){
  item::print();
  cout <<"Title: " << Title << endl;
  cout <<"Category: " << Category << endl;
  cout <<"Runtime: " << Runtime << endl;
  cout <<"Studio: " << Studio << endl;
  cout <<"ReleaseDate: " << ReleaseDate << endl;
  cout << endl;
  }




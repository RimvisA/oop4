#ifndef SONG_H
#define SONG_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

#define QUANTITY 14
#define CURRENT_YEAR 2021
#define FIRST_SONG_EVER 0

namespace song{

class Song {

private:
        static int id;
        int SongID;
        string name;
        string artist;
        string writer;
        string genre;
        int year;



        const string LIST_OF_SONG_GENRES[QUANTITY]//14
        {
        "Hip Hop" , "Electronic", "Jazz", "Punk", "Metal", "Disco", "Classical",
        "Rap", "Indie", "Rock", "Country", "Techno", "Pop", "Urban"
        };

public:

        Song(){
        }

        Song(string name);

        ~Song(){
        }

        bool reviewSongYear (int year);
        bool reviewSongName (string name);

        void setName(string n) {
            name = n;
            }
        string getName(){
            return name;
            }

        void setPerformed(string p) {
            artist = p;
            }
        string getPerformed(){
            return artist;
            }

        void setWritten(string w){
            writer = w;
            }
        string getWritten(){
            return writer;
            }

        void setGenre(string g){
            genre = g;
            }
        string getGenre(){
            return genre;
            }

        void setYear(int y){
            year = y;
            }
        int getYear(){
            return year;
            }

        string toString();

        bool operator == (const Song&) const;
        bool operator != (const Song&) const;
        bool operator < (const Song&) const;
        bool operator <= (const Song&) const;
        bool operator > (const Song&) const;
        bool operator >= (const Song&) const;

        Song& operator ++ ();
        Song operator ++ (int);


        friend ostream& operator << (ostream& out, const Song& song);
        friend istream& operator >> (istream& in, Song& song );


    };

}

#endif // SONG

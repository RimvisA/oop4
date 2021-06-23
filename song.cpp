#include "song.h"

using namespace song;

int song::Song::id = 01250;

 Song::Song(string n){
    this->name = n;
    this->SongID = id;
    ++id;
}

bool song::Song::reviewSongName (string name)
{
    for (unsigned int i = 0; i < name.length(); ++i)
    {
        if ((!(isupper(name[0])) && !isalpha(name[i]) && name[i] != ' '))
        {
            throw invalid_argument ("Invalid name");
        }
    }
    return true;
}

bool Song::Song::reviewSongYear (int year)
{
    if (year <= CURRENT_YEAR && year >= FIRST_SONG_EVER)
    {
        return true;
    }
    else
    {
        throw invalid_argument ("Invalid year");
    }
}


string song::Song::toString ()
{
    stringstream ss;

    ss << name << endl;
    ss << " " << artist << endl;
    ss << " " << writer << endl;
    ss << " " << genre << endl;
    ss << " " << year << endl;

    return ss.str();
}

bool song::Song::operator== (const Song &obj) const
{
    if (this-> name == obj.name && this-> artist == obj.artist && this-> writer == obj.writer && this -> genre == obj.genre && this -> year == obj.year){
        return 1;
        }
    return 0;
}

bool song::Song::operator!=(const Song &obj) const
{
    return !(*this == obj);
}

bool song::Song::operator<(const Song &obj) const
{
    if (this->year < obj.year)
    {
        return 1;
    }
    return 0;
}

bool song::Song::operator<=(const Song &obj) const
{
    if (*this < obj || *this == obj)
    {
        return 1;
    }
    return 0;
}

bool song::Song::operator>(const Song &obj) const
{
    return !(*this < obj);
}

bool song::Song::operator>=(const Song &obj) const
{
    return (*this > obj || *this == obj);
}

Song &Song::operator++()
{
    this->year++;
    return *this;
}

Song Song::operator++(int)
{
    Song temp = *this;
    this->year++;
    return temp;
}

istream &song::operator>>(istream &in, Song &obj)
{
    Song temp;
    in >> temp.name >> temp.artist >> temp.writer >> temp.genre >> temp.year;
    obj.name = temp.name;
    obj.artist = temp.artist;
    obj.writer = temp.writer;
    obj.genre = temp.genre;
    obj.year = temp.year;
    return in;
}

ostream &song::operator<<(ostream &out,const Song &obj)
{
    out << obj.SongID << " Name: " << obj.name << " Artist: "  << obj.artist << " Writer: " << obj.writer << " Genre: " << obj.genre << " Year: " << obj.year;
    return out;
}


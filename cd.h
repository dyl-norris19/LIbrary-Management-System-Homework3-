/* Dylan Norris
 * 10/12/22
 * David Keathly
 * 
 */

#ifndef CD_h
#define CD_h

#include "libraryItem.h"
#include <iostream>
#include <string>

class AudioCD : public LibraryItem {
    private:
        string artist;
        string title;
        int numTracks;
        string releaseDate;
        string genre;

    public:
        AudioCD(int bNumber);

        string getArtist();
        void setArtist(string a);

        string getTitle();
        void setTitle(string t);

        int getNumTracks();
        void setNumTracks(int n);

        string getReleaseDate();
        void setReleaseDate(string d);

        string getGenre();
        void setGenre(string g);
};

#endif
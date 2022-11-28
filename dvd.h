/* Dylan Norris
 * 10/12/22
 * David Keathly
 * 
 */

#ifndef DVD_h
#define DVD_h

#include "libraryItem.h"
#include <iostream>
#include <string>

using namespace std;

class Dvd : public LibraryItem {
    private:
        string title;
        string category;
        int runTime;
        string studio;
        string releaseDate;

    public:
        Dvd(int bNumber);

        string getTitle();
        void setTitle(string t);

        string getCategory();
        void setCategory(string c);

        int getRunTime();
        void setRunTime(int r);

        string getStudio();
        void setStudio(string s);

        string getReleaseDate();
        void setReleaseDate(string d);
};

#endif
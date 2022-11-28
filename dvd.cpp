/* Dylan Norris
 * 10/12/22
 * David Keathly
 * 
 */

#include "dvd.h"

using namespace std;

Dvd::Dvd(int bNumber) {
    title = "none";
    category = "none";
    runTime = 0;
    studio = "unknown";
    releaseDate = "unknown";
    setId(264000 + bNumber); //????
    setCost(0);
    setStatus("In");
    setLoanPeriod(0);
}

string Dvd::getTitle() {return title;}
void Dvd::setTitle(string t) {title = t;}

string Dvd::getCategory() {return category;}
void Dvd::setCategory(string c) {category = c;}

int Dvd::getRunTime() {return runTime;}
void Dvd::setRunTime(int r) {runTime = r;}

string Dvd::getStudio() {return studio;}
void Dvd::setStudio(string s) {studio = s;}

string Dvd::getReleaseDate() {return releaseDate;}
void Dvd::setReleaseDate(string d) {releaseDate = d;}
/* Dylan Norris
 * 10/12/22
 * David Keathly
 * 
 */

#include "cd.h"

using namespace std;

AudioCD::AudioCD(int bNumber) {
    artist = "unknown";
    title = "none";
    numTracks = 0;
    releaseDate = "Janurary 1st, 1970";
    genre = "none";
    setId(264000 + bNumber); //????
    setCost(0);
    setStatus("In");
    setLoanPeriod(0);
}

string AudioCD::getArtist() {return artist;}
void AudioCD::setArtist(string a) {artist = a;}

string AudioCD::getTitle() {return title;}
void AudioCD::setTitle(string t) {title = t;}

int AudioCD::getNumTracks() {return numTracks;}
void AudioCD::setNumTracks(int n) {numTracks = n;}

string AudioCD::getReleaseDate() {return releaseDate;}
void AudioCD::setReleaseDate(string d) {releaseDate = d;}

string AudioCD::getGenre() {return genre;}
void AudioCD::setGenre(string g) {genre = g;}
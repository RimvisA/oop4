#include "song.h"

using namespace std;
using namespace song;


int main (){

    try{
        Song song1;
        song1.setName("Still D.R.E");
        song1.setPerformed("Dr.Dre, Snoop Dogg");
        song1.setWritten("Andre R.Young, Melvin Charles Bradford, Scott Storch, Shawn Carter");
        song1.setGenre("Hip Hop");
        song1.setYear(2022);

        song1.reviewSongYear(-2);

         ///parodyt kad veikia exception su antru objektu
    }

    catch (logic_error &e){
        cerr << "Logic error! : " << e.what() << endl;
    }

    catch (exception &e){
        cerr << "Caught every exception: " << e.what() << endl;
    }

    return 0;
}

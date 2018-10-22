#include "Bitmap/bitmap.h"
#include <iostream>
#include <vector>

using namespace std;

//argc - number of arguments in command
//argv - each argument word, stored in an array
Bitmap image;
int main(int argc, char* argv[])
{
        string filename;
        if(argc!=2){
                cout<<"Please specify one image file!\n";
        }  else{
                filename = argv[1];
        }

        image.open(filename);

        if (image.isImage()){
                vector <vector <Pixel> > imagePixels = image.toPixelMatrix();
                cout<<filename<<" is "<<imagePixels.size()<<" pixels high and "<<imagePixels[0].size()<<" pixels wide\n";
                for(int column = 0; imagePixels.size()>column; column++){
                        for(int row = 0; imagePixels[column].size()>row; row++){
                                Pixel color = imagePixels[column][row];
                                color.green = 0;
                                color.blue = 0;
                                imagePixels[column][row] = color;
                        }
                }
                image.fromPixelMatrix( imagePixels );
                image.save("redness.bmp");

        }else{
                cout<<"Image file must be a bitmap with 24-bit cplor depth.\n";
        }





        return 0;
}

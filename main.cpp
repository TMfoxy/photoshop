#include "Image_Class.h"
#include <iostream>

using namespace std;

int main() {
    bool continueProgram = true;

    while (continueProgram) {
        string filename;
        cout << "Pls enter colored image name: ";
        cin >> filename;

        int choice;

        cout << "Menu:\n";
        cout << "1. Convert Image to Grayscale\n";
        cout << "2. Invert Image\n";
        cout << "3. Flip Image\n";
        cout << "4. Merge Images\n";
        cout << "5. Crop Image\n";
        cout << "6. Exit\n";
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Image cm(filename);

                if (cm.loadNewImage(filename)) {
                    cout << "loaded successfully" << endl;
                };

                for (int i = 0; i < cm.width; ++i) {
                    for (int j = 0; j < cm.height; ++j) {
                        unsigned int avg = 0;
                        for (int k = 0; k < cm.channels; ++k) {
                            avg += cm(i, j, k);
                        }
                        avg = avg / 3;
                        for (int k = 0; k < 3; ++k) {
                            cm(i, j, k) = avg;
                        }
                    }
                }

                cout << "Pls enter image name to store new image\n";
                cout << "and specify extension .jpg, .bmp, .png, .tga: ";
                cin >> filename;
                cm.saveImage(filename);
                break;
            }
            case 2: {
                Image cm(filename);

                if (cm.loadNewImage(filename)) {
                    cout << "loaded successfully" << endl;
                }

                for (int i = 0; i < cm.width; ++i) {
                    for (int j = 0; j < cm.height; ++j) {
                        for (int k = 0; k < cm.channels; ++k) {
                            cm(i, j, k) = 255 - cm(i, j, k);
                        }
                    }
                }

                cout << "Pls enter image name to store new image\n";
                cout << "and specify extension .jpg, .bmp, .png, .tga: ";
                cin >> filename;
                cm.saveImage(filename);
                break;
            }
            case 3: {
                Image cm(filename);

                if (cm.loadNewImage(filename)) {
                    cout << "loaded successfully" << endl;
                }

                int width = cm.width;
                int height = cm.height;

                Image flippedImage(width, height);

                for (int i = 0; i < width; ++i) {
                    for (int j = 0; j < height; ++j) {
                        for (int k = 0; k < cm.channels; ++k) {
                            flippedImage(i, j, k) = cm(width - i - 1, j, k);
                        }
                    }
                }

                cout << "Pls enter image name to store new image\n";
                cout << "and specify extension .jpg, .bmp, .png, .tga: ";
                cin >> filename;
                flippedImage.saveImage(filename);
                break;
            }
            case 4: {
                cout << "Pls enter first colored image name: ";
                cin >> filename;
                string filename2;
                cout << "Pls enter second colored image name: ";
                cin >> filename2;
                Image cm(filename);
                Image cena(filename2);

                if (!cm.loadNewImage(filename) || !cena.loadNewImage(filename2)) {
                    cout << "Error: Unable to load one or both images." << endl;
                    return 1;
                }

                int width = cm.width;
                int height = cm.height;

                Image mergedImage(width, height);

                for (int i = 0; i < width; ++i) {
                    for (int j = 0; j < height; ++j) {
                        for (int k = 0; k < mergedImage.channels; ++k) {
                            mergedImage(i, j, k) = (cm(i, j, k) + cena(i, j, k)) / 2;
                        }
                    }
                }

                cout << "Pls enter image name to store new image\n";
                cout << "and specify extension .jpg, .bmp, .png, .tga: ";
                cin >> filename;
                mergedImage.saveImage(filename);
                cout << "Merged image saved successfully." << endl;
                break;
            }
            case 5: {
                Image cm(filename);
                int width, height;
                cout << "Enter width for cropping: ";
                cin >> width;
                cout << "Enter height for cropping: ";
                cin >> height;
                int x = 100; // assuming x and y starting positions
                int y = 100;

                Image croppedImage(width, height);

                for (int i = 0; i < width; ++i) {
                    for (int j = 0; j < height; ++j) {
                        for (int k = 0; k < cm.channels; ++k) {
                            croppedImage(i, j, k) = cm(x + i, y + j, k);
                        }
                    }
                }

                cout << "Pls enter image name to store new image\n";
                cout << "and specify extension .jpg, .bmp, .png, .tga: ";
                cin >> filename;

                int z = croppedImage.saveImage(filename);
                cout << "Cropped image saved successfully." << endl;
                cout << z;
                break;
            }
            case 6:
                continueProgram = false;
                break;
            default:
                cout << "Invalid choice! Please select a number between 1 and 6." << endl;
        }
    }

    return 0;
}

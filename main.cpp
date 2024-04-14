//name: mohamed abdelaziz /ID 20231246 /filter 1 2 3 4 
//name: basil hossam eldin adham /ID 20230545 /filter 5 6 7 8
//name: hossam anwar al sayed /ID 20227032 /filter 9 10 11 12 








#include "Image_Class.h"
#include <iostream>
#include <cmath>

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
        cout << "6. Darken and Lighten Image \n";
        cout << "7. Adding a Frame to the Picture \n";
        cout << "8. Black and White \n";
        cout << "9 Rotate Image \n";
        cout << "10 Detect Image Edges \n";
        cout << "11 Resizing Images \n";
        cout << "12 Blur Images \n";
        cout << "13. Exit\n";
        cout << "Enter your choice (1-13): ";
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
            case 6:{
                Image cm(filename);

                if (cm.loadNewImage(filename)) {
                    cout << "Image loaded successfully" << endl;

                    string filterType;
                    cout << "Choose filter type ('darken' or 'lighten'): ";
                    cin >> filterType;

                    if (filterType == "darken") {
                        for (int i = 0; i < cm.width; ++i) {
                            for (int j = 0; j < cm.height; ++j) {
                                for (int k = 0; k < cm.channels; ++k) {
                                    cm(i, j, k) /= 2; // Darken pixel values by dividing by 2
                                }
                            }
                        }
                        cout << "Image darkened by 50%" <<endl;
                    } else if (filterType == "lighten") {
                        for (int i = 0; i < cm.width; ++i) {
                            for (int j = 0; j < cm.height; ++j) {
                                for (int k = 0; k < cm.channels; ++k) {
                                    cm(i, j, k) =min(255, cm(i, j, k) * 2); // Lighten pixel values by multiplying by 2
                                }
                            }
                        }
                        cout << "Image lightened by 50%" <<endl;
                    } else {
                        cerr << "Invalid filter type!" <<endl;
                        return 1;
                    }

                    string outputFilename;
                    cout << "Enter the output image filename with extension (.jpg, .bmp, .png, .tga): ";
                    cin >> outputFilename;

                    if (cm.saveImage(outputFilename)) {
                        cout << "Filtered image saved successfully as " << outputFilename <<endl;
                    } else {
                        cerr << "Error saving filtered image!" <<endl;
                    }
                } else {
                    cerr << "Error loading image!" <<endl;
                }
                break;
            }
            case 7:{
                Image cm(filename);
                if (cm.loadNewImage(filename)) {
                    cout << "Image loaded successfully" << endl;

                    int frameSize;
                    cout << "Enter frame size in pixels: ";
                    cin >> frameSize;


                    int choice;
                    cout << "1.White\n";
                    cout << "2.Black\n";
                    cout << "3.Gray scale\n";
                    cout << "4.Pink\n";
                    cout << "5.Bright blue \n";
                    cout << "6.red \n";
                    cout << "7.Yellow \n ";
                    cout << "Enter your choice (1-7): ";
                    cin >> choice;




                    switch (choice) {
                        case 1:{

                            for (int i = 0; i < cm.width; ++i) {
                                for (int j = 0; j < cm.height; ++j) {
                                    if (i < frameSize || i >= cm.width - frameSize ||
                                        j < frameSize || j >= cm.height - frameSize) {

                                        cm(i, j, 0) = 255;
                                        cm(i, j, 1) = 255;
                                        cm(i, j, 2) = 255;
                                    }
                                }
                            }
                            break;
                        }

                        case 2:{
                            for (int i = 0; i < cm.width; ++i) {
                                for (int j = 0; j < cm.height; ++j) {
                                    if (i < frameSize || i >= cm.width - frameSize ||
                                        j < frameSize || j >= cm.height - frameSize) {

                                        cm(i, j, 0) = 0;
                                        cm(i, j, 1) = 0;
                                        cm(i, j, 2) = 0;
                                    }
                                }
                            }
                            break;
                        }
                        case 3: {
                            for (int i = 0; i < cm.width; ++i) {
                                for (int j = 0; j < cm.height; ++j) {
                                    if (i < frameSize || i >= cm.width - frameSize ||
                                        j < frameSize || j >= cm.height - frameSize) {

                                        cm(i, j, 0) = 124;
                                        cm(i, j, 1) = 124;
                                        cm(i, j, 2) = 124;
                                    }
                                }
                            }
                            break;
                        }
                        case 4 : {
                            for (int i = 0; i < cm.width; ++i) {
                                for (int j = 0; j < cm.height; ++j) {
                                    if (i < frameSize || i >= cm.width - frameSize ||
                                        j < frameSize || j >= cm.height - frameSize) {

                                        cm(i, j, 0) = 255;
                                        cm(i, j, 1) = 0;
                                        cm(i, j, 2) = 255;
                                    }
                                }
                            }
                            break;
                        }
                        case 5 : {
                            for (int i = 0; i < cm.width; ++i) {
                                for (int j = 0; j < cm.height; ++j) {
                                    if (i < frameSize || i >= cm.width - frameSize ||
                                        j < frameSize || j >= cm.height - frameSize) {

                                        cm(i, j, 0) = 0;
                                        cm(i, j, 1) = 255;
                                        cm(i, j, 2) = 255;
                                    }
                                }
                            }
                            break;
                        }
                        case 6 :{
                            for (int i = 0; i < cm.width; ++i) {
                                for (int j = 0; j < cm.height; ++j) {
                                    if (i < frameSize || i >= cm.width - frameSize ||
                                        j < frameSize || j >= cm.height - frameSize) {

                                        cm(i, j, 0) = 255;
                                        cm(i, j, 1) = 0;
                                        cm(i, j, 2) = 0;
                                    }
                                }
                            }
                            break;
                        }
                        case 7 : {
                            for (int i = 0; i < cm.width; ++i) {
                                for (int j = 0; j < cm.height; ++j) {
                                    if (i < frameSize || i >= cm.width - frameSize ||
                                        j < frameSize || j >= cm.height - frameSize) {

                                        cm(i, j, 0) = 255;
                                        cm(i, j, 1) = 255;
                                        cm(i, j, 2) = 0;
                                    }
                                }
                            }
                            break;
                        }
                    }

                    string outputFilename;
                    cout << "Enter the output image filename with extension (.jpg, .bmp, .png, .tga): ";
                    cin >> outputFilename;

                    if (cm.saveImage(outputFilename)) {
                        cout << "Image with frame saved successfully as " << outputFilename << endl;
                    } else {
                        cerr << "Error saving image with frame!" << endl;
                    }
                } else {
                    cerr << "Error loading image!" << endl;
                }

                return 0;
            }
            case 8:{
                Image cm(filename);

                if (cm.loadNewImage(filename)) {
                    cout << "Image loaded successfully" << endl;
                } else {
                    cout << "Error loading image" << endl;
                    return 1;
                }

                for (int i = 0; i < cm.width; ++i) {
                    for (int j = 0; j < cm.height; ++j) {
                        unsigned int avg = 0;
                        for (int k = 0; k < cm.channels; ++k) {
                            avg += cm(i, j, k);
                        }
                        avg = avg / cm.channels;
                        unsigned int threshold = 128;
                        unsigned int newValue = (avg < threshold) ? 0 : 255;
                        for (int k = 0; k < cm.channels; ++k) {
                            cm(i, j, k) = newValue;
                        }
                    }
                }

                cout << "Please enter the image name to store the new black and white image" << endl;
                cout << "and specify the extension (.jpg, .bmp, .png, .tga): ";
                cin >> filename;
                cm.saveImage(filename);

                break;
            }
            case 9:{
                Image cm(filename);

                if (cm.loadNewImage(filename)) {
                    cout << "Image loaded successfully" << endl;
                } else {
                    cerr << "Error loading image" << endl;
                    return 1;
                }

                int angle;
                cout << "Enter the rotation angle (90, 180, or 270): ";
                cin >> angle;

                if (angle != 90 && angle != 180 && angle != 270) {
                    cerr << "Invalid angle. Please enter 90, 180, or 270." <<endl;
                    return 1;
                }

                int newWidth = cm.width;
                int newHeight = cm.height;

                if (angle == 90 || angle == 270) {
                    swap(newWidth, newHeight);
                }

                Image rotatedImage(newWidth, newHeight);

                for (int i = 0; i < cm.width; ++i) {
                    for (int j = 0; j < cm.height; ++j) {
                        for (int k = 0; k < cm.channels; ++k) {
                            int x = i, y = j;
                            if (angle == 90) {
                                x = j;
                                y = cm.width - i - 1;
                            } else if (angle == 180) {
                                x = cm.width - i - 1;
                                y = cm.height - j - 1;
                            } else if (angle == 270) {
                                x = cm.height - j - 1;
                                y = i;
                            }
                            rotatedImage(x, y, k) = cm(i, j, k);
                        }
                    }
                }

                string outputFilename;
                cout << "Please enter the image name and specify extension .jpg, .bmp, .png, .tga: ";
                cin >> outputFilename;

                rotatedImage.saveImage(outputFilename);

                cout << "Image rotated and saved successfully." << endl;

                break;
            }
            case 10:{
                Image cm(filename);

                if (cm.loadNewImage(filename)) {
                    cout << "Image loaded successfully" << endl;
                } else {
                    cerr << "Error loading image" << endl;
                    return 1;
                }

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


                int sobelX[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
                int sobelY[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
                int threshold = 100;

                Image edges(cm.width, cm.height);

                for (int x = 1; x < cm.width - 1; ++x) {
                    for (int y = 1; y < cm.height - 1; ++y) {
                        int gradientX = 0, gradientY = 0;

                        for (int i = -1; i <= 1; ++i) {
                            for (int j = -1; j <= 1; ++j) {
                                int pixelX = x + i;
                                int pixelY = y + j;
                                int pixelVal = cm(pixelX, pixelY, 0); // Assuming grayscale image

                                gradientX += pixelVal * sobelX[i + 1][j + 1];
                                gradientY += pixelVal * sobelY[i + 1][j + 1];
                            }
                        }

                        int gradientMagnitude = abs(gradientX) + abs(gradientY);

                        if (gradientMagnitude > threshold) {
                            edges(x, y, 0) = 255;
                        } else {
                            edges(x, y, 0) = 0;
                        }
                    }
                }

                string outputFilename;
                cout << "Please enter the image name to save the edges image and specify extension .jpg, .bmp, .png, .tga: ";
                cin >> outputFilename;

                edges.saveImage(outputFilename);

                cout << "Edges image saved successfully." << endl;

                break;

            }
            case 11:{
                Image originalImage(filename);

                int width, height;
                char choice;
                cout << "Do you want to enter new dimensions (N) or use reduction/increase ratio (R)? ";
                cin >> choice;

                if (toupper(choice) == 'N') {
                    cout << "Enter the new width and height for resizing: ";
                    cin >> width >> height;
                } else if (toupper(choice) == 'R') {
                    float ratio;
                    cout << "Enter the reduction/increase ratio (e.g., 0.5 for 50% reduction, 2.0 for 200% increase): ";
                    cin >> ratio;
                    width = static_cast<int>(originalImage.width * ratio);
                    height = static_cast<int>(originalImage.height * ratio);
                } else {
                    cerr << "Invalid choice! Exiting..." << std::endl;
                    return 1;
                }

                Image resizedImage(width, height);

                // Simple nearest-neighbor interpolation for resizing
                float scaleX = (float)originalImage.width / width;
                float scaleY = (float)originalImage.height / height;

                for (int x = 0; x < width; ++x) {
                    for (int y = 0; y < height; ++y) {
                        for (int c = 0; c < resizedImage.channels; ++c) {
                            int nearestX = static_cast<int>(x * scaleX);
                            int nearestY = static_cast<int>(y * scaleY);
                            resizedImage(x, y, c) = originalImage(nearestX, nearestY, c);
                        }
                    }
                }

                std::string outputFilename;
                std::cout << "Enter the output filename for the resized image and specify extension .jpg, .bmp, .png, .tga: ";
                std::cin >> outputFilename;

                resizedImage.saveImage(outputFilename);

                std::cout << "Resized image saved successfully." << std::endl;

                break;

            }
            case 12:{
                Image img(filename);

                int width = img.width;
                int height = img.height;
                int channels = img.channels;

                unsigned char* tempImageData = (unsigned char*)malloc(width * height * channels);
                unsigned char* finalImageData = (unsigned char*)malloc(width * height * channels);

                int blurPasses = 30;

                for (int pass = 0; pass < blurPasses; ++pass) {
                    for (int x = 3; x < width - 3; ++x) {
                        for (int y = 3; y < height - 3; ++y) {
                            for (int c = 0; c < channels; ++c) {
                                int sum = 0;

                                for (int dx = -3; dx <= 3; ++dx) {
                                    for (int dy = -3; dy <= 3; ++dy) {
                                        sum += img.getPixel(x + dx, y + dy, c);
                                    }
                                }

                                tempImageData[(y * width + x) * channels + c] = sum / 49;
                            }
                        }
                    }

                    memcpy(finalImageData, tempImageData, width * height * channels);
                }

                memcpy(img.imageData, finalImageData, width * height * channels);

                cout << "Enter the output filename to store the new image: ";
                cin >> filename;
                img.saveImage(filename);

                cout << "Image blurred and saved as '" << filename << "' successfully." << endl;

                free(tempImageData);
                free(finalImageData);

                break;

            }

            case 13:
                continueProgram = false;
                break;
            default:
                cout << "Invalid choice! Please select a number between 1 and 6." << endl;
        }
    }

    return 0;
}

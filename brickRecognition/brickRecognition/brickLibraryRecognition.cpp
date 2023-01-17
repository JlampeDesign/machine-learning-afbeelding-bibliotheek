#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

using namespace cv;
using namespace std;

/// course lesson licence plate recognition ///

void brickRecognition() {

	for (int i = 0; i < 10; i++) {

		string path[] = {
			{"images/pic1.png"},
			{"images/pic2.png"},
			{"images/pic3.png"},
			{"images/pic4.png"},
			{"images/pic5.png"}, 
			{"images/pic6.png"}, 
			{"images/pic7.png"},
			{"images/pic8.png"},
			{"images/pic9.png"},
			{"images/pic10.png"}, 
		};

		Mat img = imread(path[i]);
		string objectType = "brick";

		CascadeClassifier brickCascade;
		brickCascade.load("source/brickCascade.xml");

		if (brickCascade.empty()) { cout << "XML file not found" << endl; }

		vector<Rect> bricks;
		brickCascade.detectMultiScale(img, bricks, 1.1, 10); // look up detectMultiScale for more setting options

			for (int j = 0; j < bricks.size(); j++) {
				Mat imgCrop = img(bricks[j]);
				//imshow(to_string(i), imgCrop);
				imwrite("recogniced/" + to_string(i) + ".png", imgCrop);
				rectangle(img, bricks[j].tl(), bricks[j].br(), Scalar(255, 0, 255), 3);
				putText(img, objectType, { bricks[j].x, bricks[j].y - 8 }, FONT_HERSHEY_PLAIN, 2, Scalar(0, 255, 0), 2);
			}

		imshow("Image", img);
		waitKey(25);

		}

}

/// main function ///

int main() {

	brickRecognition();

}
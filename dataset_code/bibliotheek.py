import os

def generate_negative_description_file():

    with open('neg.txt', 'w') as f:
        for filename in os.listdir('negative'):
            f.write('negative/' + filename + '\n')

            # C:/Users/JobMM/openCV/opencv/build/x64/vc15/bin/opencv_annotation.exe --annotations=pos.txt --images=positive/

            # C:/Users/JobMM/openCV/opencv/build/x64/vc15/bin/opencv_createsamples.exe -info pos.txt -w 20 -h 20 -num 1000 -vec pos.vec

            # C:/Users/JobMM/openCV/opencv/build/x64/vc15/bin/opencv_traincascade.exe -data cascade/ -vec pos.vec -bg neg.txt -w 20 -h 20 -numPos 100 -numNeg 200 -numStages 10
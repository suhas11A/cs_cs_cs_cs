g++ cache-size-pred.cpp -o cache-size-pred -O0
./cache-size-pred > data.txt 
python plotter.py --filename data.txt 
mkdir build
cd build
cmake ..
make
cd ..
python3 setup.py build_ext -i

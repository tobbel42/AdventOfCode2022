name="day$1"
mkdir $name
cp ./dummyFile.cpp ./$name/$name.cpp
sed "s/day01/$name/g" ./dummyMakefile > ./$name/Makefile
#!/bin/bash
name=$(basename $PWD)
if [ "$name" == "skeleton" ]
then
  echo will not overwrite default skeleton directory!
  exit
fi
echo initializing project $name
# replace project names

fs="README.md src/* include/* docs/*"
for f in $fs
do
  find $f -exec sed -i -r "s/skeleton/$name/g" {} \;
  find $f -exec sed -i -r "s/Skeleton/$name/g" {} \;
done

./setver.bash 0 1 0

# recompile docs
cd docs
./make_doc.bash
cd ..

# decouple from git
rm -rf .git .gitignore

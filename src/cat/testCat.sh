./my_cat ../2.txt > myFileTest.txt
cat ../2.txt > catFileTest.txt

./my_cat ../1.txt ../2.txt >> myFileTest.txt
cat ../1.txt ../2.txt >> catFileTest.txt

./my_cat -n ../3.txt >> myFileTest.txt
cat -n ../3.txt >> catFileTest.txt

./my_cat -b ../3.txt >> myFileTest.txt
cat -b ../3.txt >> catFileTest.txt

./my_cat -E ../3.txt >> myFileTest.txt
cat -E ../3.txt >> catFileTest.txt

./my_cat -T ../3.txt >> myFileTest.txt
cat -T ../3.txt >> catFileTest.txt

./my_cat -e ../file.txt >> myFileTest.txt
cat -e ../file.txt >> catFileTest.txt

./my_cat -t ../file.txt >> myFileTest.txt
cat -t ../file.txt >> catFileTest.txt

./my_cat -s ../3.txt >> myFileTest.txt
cat -s ../3.txt >> catFileTest.txt

./my_cat --number-nonblank --number --squeeze-blank -T -E ../3.txt >> myFileTest.txt
cat --number-nonblank --number --squeeze-blank -T -E ../3.txt >> catFileTest.txt

./my_cat -b -T -E ../3.txt >> myFileTest.txt
cat -b -T -E ../3.txt >> catFileTest.txt

./my_cat -b -T -E -n ../3.txt >> myFileTest.txt
cat -b -T -E -n ../3.txt >> catFileTest.txt

./my_cat -b -t -e -n ../file.txt >> myFileTest.txt
cat -b -t -e -n ../file.txt >> catFileTest.txt

./my_cat -b -t -e -n -T -E ../file.txt >> myFileTest.txt
cat -b -t -e -n -T -E ../file.txt >> catFileTest.txt

./my_cat -b -t -e -n -T -E -s ../3.txt >> myFileTest.txt
cat -b -t -e -n -T -E -s ../3.txt >> catFileTest.txt

diff myFileTest.txt catFileTest.txt
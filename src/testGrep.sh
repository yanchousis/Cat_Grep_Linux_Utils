./my_grep test ../2.txt > myFileTest.txt
grep test ../2.txt > grepFileTest.txt

./my_grep test ../1.txt ../2.txt >> myFileTest.txt
grep test ../1.txt ../2.txt >> grepFileTest.txt

./my_grep -e test -e as ../1.txt ../2.txt >> myFileTest.txt
grep -e test -e as ../1.txt ../2.txt >> grepFileTest.txt

./my_grep -e TeSt -e as -i ../1.txt ../2.txt >> myFileTest.txt
grep -e TeSt -e as -i ../1.txt ../2.txt >> grepFileTest.txt

./my_grep -e TeSt -e as -i -n ../1.txt ../2.txt >> myFileTest.txt
grep -e TeSt -e as -i -n ../1.txt ../2.txt >> grepFileTest.txt

./my_grep -v TeSt -i ../1.txt ../2.txt >> myFileTest.txt
grep -v TeSt -i ../1.txt ../2.txt >> grepFileTest.txt

./my_grep -e TeSt -c -i ../1.txt ../2.txt >> myFileTest.txt
grep -e TeSt -c -i ../1.txt ../2.txt >> grepFileTest.txt

./my_grep te -v -c ../1.txt ../2.txt >> myFileTest.txt
grep te -v -c ../1.txt ../2.txt >> grepFileTest.txt

./my_grep -v -e TeSt -c -i ../1.txt ../2.txt >> myFileTest.txt
grep -v -e TeSt -c -i ../1.txt ../2.txt >> grepFileTest.txt

./my_grep TeSt -l -i ../1.txt ../2.txt >> myFileTest.txt
grep TeSt -l -i ../1.txt ../2.txt >> grepFileTest.txt

./my_grep TeSt -l -i -n ../1.txt ../2.txt >> myFileTest.txt
grep TeSt -l -i -n ../1.txt ../2.txt >> grepFileTest.txt

./my_grep -e TeSt -e As -i -n -v -c ../1.txt ../2.txt >> myFileTest.txt
grep -e TeSt -e As -i -n -v -c ../1.txt ../2.txt >> grepFileTest.txt

./my_grep -e TeSt -e As -i -n -v -c -l ../1.txt ../2.txt >> myFileTest.txt
grep -e TeSt -e As -i -n -v -c -l ../1.txt ../2.txt >> grepFileTest.txt

./my_grep test -h ../2.txt >> myFileTest.txt
grep test -h ../2.txt >> grepFileTest.txt

./my_grep -h -e as -e all ../2.txt ../1.txt >> myFileTest.txt
grep -h -e as -e all ../2.txt ../1.txt >> grepFileTest.txt

./my_grep -s -e as -e all ../2.txt wq >> myFileTest.txt
grep -s -e as -e all ../2.txt wq >> grepFileTest.txt

./my_grep -f ../Ftest1.txt ../2.txt >> myFileTest.txt
grep -f ../Ftest1.txt ../2.txt >> grepFileTest.txt

./my_grep -f ../Ftest1.txt -f ../Ftest2.txt ../2.txt >> myFileTest.txt
grep -f ../Ftest1.txt -f ../Ftest2.txt ../2.txt >> grepFileTest.txt

./my_grep -f ../Ftest1.txt -f ../Ftest2.txt -e test ../2.txt >> myFileTest.txt
grep -f ../Ftest1.txt -f ../Ftest2.txt -e test ../2.txt >> grepFileTest.txt

./my_grep -e TeSt -e As -i -n -v -c -l -f ../Ftest1.txt -h rq -s ../1.txt ../2.txt >> myFileTest.txt
grep -e TeSt -e As -i -n -v -c -l -f ../Ftest1.txt -h rq -s ../1.txt ../2.txt >> grepFileTest.txt

./my_grep te -o ../2.txt >> myFileTest.txt
grep te -o ../2.txt >> grepFileTest.txt

./my_grep te -o -n ../2.txt ../1.txt >> myFileTest.txt
grep te -o -n ../2.txt ../1.txt >> grepFileTest.txt

./my_grep te -o -n ../2.txt ../1.txt >> myFileTest.txt
grep te -o -n ../2.txt ../1.txt >> grepFileTest.txt

./my_grep -e te -e al -o ../2.txt >> myFileTest.txt
grep -e te -e al -o ../2.txt >> grepFileTest.txt

./my_grep -e te -e al -o ../1.txt ../2.txt >> myFileTest.txt
grep -e te -e al -o ../1.txt ../2.txt >> grepFileTest.txt

./my_grep -e te -e al -o -h -n ../1.txt ../2.txt >> myFileTest.txt
grep -e te -e al -o -h -n ../1.txt ../2.txt >> grepFileTest.txt

./my_grep -e te -e al -o -h -n -s abc ../1.txt ../2.txt >> myFileTest.txt
grep -e te -e al -o -h -n -s abc ../1.txt ../2.txt >> grepFileTest.txt

./my_grep te -o -v ../2.txt >> myFileTest.txt
grep te -o -v ../2.txt >> grepFileTest.txt

./my_grep te -o -v ../2.txt ../1.txt >> myFileTest.txt
grep te -o -v ../2.txt ../1.txt >> grepFileTest.txt

./my_grep te -o -l ../2.txt ../1.txt >> myFileTest.txt
grep te -o -l ../2.txt ../1.txt >> grepFileTest.txt

./my_grep te -o -l -v ../2.txt ../1.txt >> myFileTest.txt
grep te -o -l -v ../2.txt ../1.txt >> grepFileTest.txt

./my_grep te -o -c -v ../2.txt ../1.txt >> myFileTest.txt
grep te -o -c -v ../2.txt ../1.txt >> grepFileTest.txt

./my_grep te -o -c -v -l ../2.txt ../1.txt >> myFileTest.txt
grep te -o -c -v -l ../2.txt ../1.txt >> grepFileTest.txt

./my_grep -e TeSt -e As -i -n -v -c -f ../Ftest1.txt -h rq -s -o -l ../1.txt ../2.txt >> myFileTest.txt
grep -e TeSt -e As -i -n -v -c -f ../Ftest1.txt -h rq -s -o -l ../1.txt ../2.txt >> grepFileTest.txt

cat ../2.txt ../1.txt | ./my_grep -e TeSt -e As -i -n -v -c -f ../Ftest1.txt -h rq -s -o -l >> myFileTest.txt
cat ../2.txt ../1.txt | grep -e TeSt -e As -i -n -v -c -f ../Ftest1.txt -h rq -s -o -l >> grepFileTest.txt

cat ../3.txt | ./my_grep -i Rr >> myFileTest.txt
cat ../3.txt | grep -i Rr >> grepFileTest.txt

cat ../3.txt | ./my_grep -i -o -n Rr >> myFileTest.txt
cat ../3.txt | grep -i -o -n Rr >> grepFileTest.txt

cat ../2.txt | ./my_grep -o -v -n te >> myFileTest.txt
cat ../2.txt | grep -o -v -n te >> grepFileTest.txt

cat ../2.txt ../1.txt | ./my_grep -o -n -c te >> myFileTest.txt
cat ../2.txt ../1.txt | grep -o -n -c te >> grepFileTest.txt

cat ../2.txt ../1.txt | ./my_grep -o -n -c -i -h tE >> myFileTest.txt
cat ../2.txt ../1.txt | grep -o -n -c -i -h tE >> grepFileTest.txt

cat ../2.txt ../1.txt | ./my_grep -on -ci -h tE >> myFileTest.txt
cat ../2.txt ../1.txt | grep -on -ci -h tE >> grepFileTest.txt

cat ../2.txt ../1.txt | ./my_grep -on -ci -hl tE >> myFileTest.txt
cat ../2.txt ../1.txt | grep -on -ci -hl tE >> grepFileTest.txt

cat ../2.txt ../1.txt | ./my_grep -on -ci -hl -v tE >> myFileTest.txt
cat ../2.txt ../1.txt | grep -on -ci -hl -v tE >> grepFileTest.txt

diff myFileTest.txt grepFileTest.txt
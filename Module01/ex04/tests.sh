echo ">>> ./replace 1 2"
./replace 1 2

echo "\n>>> ./replace nofile a b" 
./replace nofile a b

echo "\n>>> touch test.replace
>>> chmod -w test.replace
>>> ./replace test a b"
touch test.replace
chmod -w test.replace
./replace test a b
echo ">>> rm -rf test.replace"
rm -rf test.replace

echo "\n>>> ./replace test a B" 
./replace test a B
echo ">>> cat test.replace" 
cat test.replace

echo "\n>>> ./replace test l LL" 
./replace test l LL
echo ">>> cat test.replace" 
cat test.replace

echo "\n>>> ./replace test \"l
dquote> l\" I" 
./replace test "l
l" I
echo ">>> cat test.replace" 
cat test.replace

echo "\n>>> ./replace test lol lal" 
./replace test lol lal
echo ">>> cat test.replace" 
cat test.replace
echo ">>> ./replace test.replace lal LAL" 
./replace test.replace lal LAL
echo ">>> cat test.replace.replace" 
cat test.replace.replace

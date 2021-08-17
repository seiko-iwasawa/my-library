./compile.sh gen
./compile.sh solve
./compile.sh stupid
# ./compile.sh check

for t in $(seq 1 1000000); do
  echo "TEST $t"
  ./gensrc $t || break
  ./solvesrc || break
  ./stupidsrc || break
  diff test.out test_a.out || break
done